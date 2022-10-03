#include "myModel.h"

using namespace std;

int main(){
    myModel done;

    DSVector<word> dictionary;
    DSVector<tweet> tweets;
    done.train(dictionary);
    tweets = done.test(dictionary);
    done.check(tweets);

    return 0;
}