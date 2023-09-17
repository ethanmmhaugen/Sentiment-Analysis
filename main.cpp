#include "myModel.h"

using namespace std;

void testing(){
    char chars[] = {"hello"};
    DSString word(chars);


    DSString word2(word);

    DSVector<DSString> vector;
    vector.push_back(word);
    vector.push_back(word);
    vector.push_back(word2+word);
    cout << vector.size() << " " << vector[2] << endl;
    DSVector<DSString> vector2(vector);
    cout << vector2.size() << " " << vector2[1] << endl;
    cout << vector.empty() << " " << vector.capacity() << endl;
    cout << vector.size() << " " << vector[2] << endl;
}

int main(){
    myModel done;

    DSVector<word> dictionary;
    DSVector<tweet> tweets;
    unordered_map<string, int> visited;
    done.train(dictionary, visited);
    tweets = done.test(dictionary, visited);
    done.check(tweets);

    //testing();
    return 0;
}