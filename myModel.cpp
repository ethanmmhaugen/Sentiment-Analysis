#include "myModel.h"
#include <ostream>

DSVector<word> myModel::train(DSVector<word> &dictionary, unordered_map<string, int>& visited) {
    // Opening the file and checking that the name is correct
    ifstream file;
    file.open("data/train_dataset_20k.csv");
    if (!file.is_open()) {
        cout << "Houston, we have a problem" << endl;
    }

    // This clears out the line with the headers
    char line[100];
    file.getline(line, 100, '\n');
    cout << "Start Training" << endl;

    char* buffer = new char[1000];
    char* tok;
    int count = 0;

    // Encompassing while loop to continue until end of the file
    while (!file.eof()) {
        // First, we get the sentiment and store that for later
        if (count == 119) {
            count++;
        }
        delete[] buffer; // Deallocate the previous buffer
        buffer = new char[1000];
        int senti;
        file.getline(buffer, 1000, ',');
        senti = buffer[0] - '0';

        // This skips the ID, username, and the other useless columns (at least for this project)
        for (int i = 0; i < 4; i++) {
            file.getline(buffer, 1000, ',');
        }

        // Now we take the actual tweet and break it into individual words
        file.getline(buffer, 1000);
        word tmp;
        tok = strtok(buffer, " !@#$%^&*()_+-=,.?1234567890:;/");

        // Loop to assign words to my dictionary and increment their positive or negative counts
        while (tok != nullptr) {
            tok = strtok(nullptr, " !@#$%^&*()_+-=,.?1234567890:;/");
            if(tok == nullptr){
                break;
            }
            DSString placeholder = DSString(tok);

            tmp.setString(placeholder);
            // Excludes words with less than 3 letters
            if (placeholder.getLength() < 3) {
                continue;
            }
            string mapString = tok;
            auto index = visited.find(mapString) != visited.end() ? visited.find(mapString) : visited.end();

            // For not in dictionary, add it and increment once
            if (index == visited.end()) {
                tmp.reset();
                if (senti == 4) {
                    tmp.incPos();
                } else {
                    tmp.incNeg();
                }
                dictionary.push_back(tmp);
                visited[mapString] = dictionary.size() - 1;
            }
                // If already in dictionary, just increment
            else {
                if (senti == 4) {
                    dictionary[index->second].incPos();
                } else {
                    dictionary[index->second].incNeg();
                }
            }
        }

        cout << count << endl;
        count++;
    }
    delete[] buffer; // Deallocate the last buffer
    // Close file and calculate sentiment for each word
    file.close();
    for (int i = 0; i < dictionary.size(); i++) {
        dictionary[i].calcSenti();
    }

    cout << "Training Complete" << endl;

    return dictionary;
}

DSVector<tweet> myModel::test(DSVector<word> &dictionary, unordered_map<string, int>& visited){
    cout << "Let the testing BEGIN" << endl;

    //get the test file, set up vector to store tweets
    DSVector<tweet> tweets;
    cout << "Enter name of test file: \n";
    string input;
    cin >> input;
    ifstream file(input);

    char line[1000];
    file.getline(line, 1000, '\n');

    word tmp;
    tweet twitter;

    //while loop to read the file
    while(!file.eof()){
        char buffer[1000];
        file.getline(buffer, 1000, ',');
        twitter.setId(strtol(buffer, nullptr, 10));

        for (int i = 0; i<3; i++){
            file.getline(buffer, 1000, ',');
        }

        char* tok = strtok(nullptr, "!@#$%^&*()_+-=,.?1234567890:;'/");
        int posCount = 0;
        int negCount = 0;
        twitter.setData(DSString(tok));
        //count positive and negative words
        while(tok != nullptr){
            int index = visited.find(string(tok)) != visited.end() ? visited[string(tok)] : -1;

            if(index>-1){
                if(dictionary[index].getSenti() == 4){
                    posCount++;
                }
                else{
                    negCount++;
                }
            }

            tok = strtok(nullptr, " ");
        }

        //set tweet sentiment
        if(posCount>negCount){
            twitter.setSentiment(4);
        }
        else{
            twitter.setSentiment(0);
        }
        tweets.push_back(twitter);
    }

    file.close();
    cout << "Test Complete" << endl;
    return tweets;
}

void myModel::check(DSVector<tweet> &tweets){
    //gets the user input for the answer key
    cout << "Computing Results" << endl;
    ifstream file;
    string input;
    cout << "Enter file name with correct answers: " << endl;
    cin >> input;
    file.open(input);

    //skip first line
    char line[100];
    file.getline(line, 100, '\n');

    //save into an answer vector
    DSVector<int> ans;
    double ansCount = 0;
    while(!file.eof()){
        file.getline(line, 100, ',');
        ans.push_back(strtol(line, nullptr, 10));
        file.getline(line, 100, '\n');
    }

    //create output file
    file.close();
    double count = 0;
    int senti;
    ofstream out;
    out.open("data/answer.csv");
    out << "Sentiment, ID" << endl;

    //output my answers, calculate accuracy
    for(int i = 0; i<ans.size(); i++){
        out << tweets[i].getSentiment() << ", " << tweets[i].getId() << endl;
        if(ans[i] == tweets[i].getSentiment()){
        count++;
    }
    }
    out.close();
    double accuracy;
    accuracy = count/ansCount;
    cout << accuracy << endl;

    //Create file for 2nd output
    ofstream file2;
    file2.open("data/output.csv");
    file2 << accuracy << endl;

    //loop to show incorrect computations
    for(int i =0; i< ans.size(); i++){
        if(tweets[i].getSentiment() != ans[i]){
            file2 << (tweets[i].getSentiment()) << ", " << ans[i] << ", " << tweets[i].getId() << endl;
        }
    }

    file2.close();


}

int myModel::search(DSVector<word> w, const DSString &find){
    for(int i = 0; i<static_cast<int>(w.size()); i++){
        if(strcmp(w[i].getString().c_str(), find.c_str())==0){
            return i;
        }
        else{
            return -1;
        }
    }

    return -1;
}