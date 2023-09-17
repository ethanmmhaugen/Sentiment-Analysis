#include "word.h"

word::word(){
    positiveCount = 0;
    negativeCount = 0;
    myString = nullptr;
}

word::word(const DSString& x){
    delete myString;
    myString = new DSString(x);
    positiveCount = 0;
    negativeCount = 0;

}

word::word(const word &rhs){
    myString = new DSString(*(rhs.myString));
    positiveCount = rhs.positiveCount;
    negativeCount = rhs.negativeCount;
}

void word::setString(const DSString& x){
    delete myString;
    myString = new DSString(x);
}

void word::setString(word x){
    myString = x.myString;
}

void word::setSenti(int sentiment){
    senti = sentiment;
}

void word::setSenti(){
    if(positiveCount>negativeCount){
        senti = 4;
    }
    else if(negativeCount>positiveCount){
        senti = 0;
    }
    else senti = -1;
}

DSString word::getString(){
    return *myString;
}

int word::getSenti() const{
    return senti;
}

void word::incPos(){
    positiveCount++;
}
void word::incNeg(){
    negativeCount++;
}
void word::reset(){
    positiveCount = 0;
    negativeCount = 0;
}

void word::calcSenti(){
    if(positiveCount>negativeCount){
        senti = 4;
    }
    else{
        senti = 0;
    }
}

word &word::operator=(const DSString &rhs){
    delete myString;
    myString = new DSString(rhs);
    return *this;
}

word &word::operator=(const char* &rhs){
    if (myString != nullptr) {
        delete myString;
        myString = nullptr;
    }

    if (rhs != nullptr) {
        myString = new DSString(rhs);
    }

    return *this;
}
