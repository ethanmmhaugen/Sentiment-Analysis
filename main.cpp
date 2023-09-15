#include "myModel.h"

using namespace std;

int main(){
    /*myModel done;

    DSVector<word> dictionary;
    DSVector<tweet> tweets;
    done.train(dictionary);
    tweets = done.test(dictionary);
    done.check(tweets);
    */
    char chars[] = {"hello"};
    DSString word(chars);
    cout << word;
    cout << word.substring(2,3) << endl;

    DSString word2(word);
    cout << word2;
    cout << (word==word2) << endl;
    cout << (word+word2);
    return 0;
}