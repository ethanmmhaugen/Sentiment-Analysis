#include "tweet.h"

tweet::tweet(){
    len = 0;
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

tweet &tweet::operator=(const tweet &rhs) {
    data = DSString(rhs.data);
    sentiment = rhs.sentiment;
    id = rhs.id;
    return *this;
}
