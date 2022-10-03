#include "word.h"

word::word(){
    myString = nullptr;
    positiveCount = 0;
    negativeCount = 0;
}

word::word(DSString x){
    myString=x.c_str();
    positiveCount = 0;
    negativeCount = 0;

}

word::word(const word &rhs){
    myString = rhs.myString;
    positiveCount = 0;
    negativeCount = 0;
}

void word::setString(DSString x){
    myString = x;
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
    return myString;
}

int word::getSenti(){
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
    myString = rhs;
    return *this;
}

word &word::operator=(const char* &rhs){
    if(rhs == nullptr){
        myString = nullptr;
    }
    else{
        this->myString = new char[strlen(rhs)+1];
        for(int i = 0; i<myString.size(); i++){
            myString[i] = rhs[i];
        }
        myString[myString.size()]='\0';
    }
    return *this;
}
