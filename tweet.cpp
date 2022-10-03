#include "tweet.h"

tweet::tweet(){

}

tweet::tweet(DSString x){
    data = x;
}

tweet::tweet(const tweet &rhs){
    data = rhs.data;
}

DSString tweet::getData(){
    return data;
}

void tweet::setData(DSString x){
    data = x;
}

void tweet::setSentiment(int x){
    sentiment = x;
}

void tweet::setId(size_t x){
    id = x;
}

int tweet::getSentiment(){
    return sentiment;
}

size_t tweet::getId(){
    return id;
}