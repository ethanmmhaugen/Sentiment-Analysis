#include <iostream>
#include <algorithm>
#include "DSVector.h"
#include "DSString.h"
#include "word.h"
#include <fstream>
#include "main.h"

using namespace std;

int main()
{ 
DSVector<word> disctionary;
ifstream file("train_dataset_20k.csv");

word tmp;

for(int i=0; i<10; i++){
    char buff[500];
    int tmpSent;

    file.getline(buff, 500, ',');
    tmpSent = (int)(unsigned char)buff[0];
    cout << tmpSent << endl;

    for(int j = 0; j<4; ++j){
        file.getline(buff, 1000, ',');
    }

    file.getline(buff,1000);

    char* word = strtok(buff, " ");

    while(word != nullptr){
        DSString temp2 = word;
        tmp = temp2;
        tmp.setSenti(tmpSent);
        int index = search(dictionary, temp2);
        if(index < 0){
            dictionary.push_back(tmp);
        }
        else {
            (tmpSent ==4) ? dictionary[index].addPositive():dictionary[index].addNegative();
        }
        word = strtok(buff, " ");

    }

}

for(auto &words : dictionary){
    cout << words.getWord().c_str() << endl;
    words.calcSentiment();
    if(words.getSenti()==4){
        cout << "pos"<<endl;
    }
    else{
        cout << "neg" << endl;
    }

}

cout<<"Training Done!!!!!!!"<<endl;

DSVector<tweet> tweets;

ifstream test("data/test_dataset_10k.csv");
if(!test.is_open()){
    cout << "File not open" << endl;
}

word temp2;
word tweet;

for(int i = 0; i<looper; ++i){
    char buff[1000];
    test.getLine(buff, 1000, ',');

    char* word = strtok(buff, " !@#$%^&*()");
    int posCount = 0;
    int negCount = 0;

    while(word != nullptr){
        int index = search(dictionary, word);

        if(index > 0){
            if(dictionary[index].getSenti() == 4){
                posCount++;
            }
            else if (dictionary[index].getSenti() == 0{
                negCount++;
            }
        }

        word = strtok(nullptr, " ");
    }

    if(posCount>negCount){
        tw.setSenti(4);
    }
    else if (negCount>posCount){
        tw.setSenti(0);
    }
    else if (posCount == negCount){
        tw.setSenti(-1);
    }

    tweets.push_back(tw);


}

test.close();

ifstream checker;
checker.open();

if(!checker.is_open()){
    cout << "File is not open" << endl;
}

charfl[50];
checker.getline(fl,50,'\n');

DSVector<int> correct;

for(int i = 0; i<looper; ++i){
    checker.getline(fl,50,',');
    correct.push_back(static_cast<int>(strtol(fl, nullptr,10)));
    checker.getline(fl,50,'\n');
}

int counter = 0;
int sent;

for(size_t i = 0; i<correct.size();++i){
    if(tweets[i].getSenti() == correct[i]){
        counter++;
    }
}
double accuracy = counter/looper;
cout << accuracy << endl;


return 0;
}



/*get file ifstream

read all of the tweet data into a tweet object 
break down tweet part into individual words
tally positive and negative words
calculate sentiment, store in to the tweet
create file/print vector
compare file/compare vector to answer key
calculate accuracy

*/


