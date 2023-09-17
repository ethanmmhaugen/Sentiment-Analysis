#pragma once
#include "DSString.h"
#include "word.h"
#include <iostream>

class tweet{
    private:
        DSString data;
        size_t len;
        int sentiment;
        size_t id{};
    
    public:
        tweet();
        tweet(DSString x);
        tweet(const tweet &rhs);

        ~tweet() = default;
        DSString getData();
        void setData(DSString x);
        void setSentiment(int x);
        void setId(size_t x);

        tweet &operator=(const tweet &rhs);

        int getSentiment();
        size_t getId();

};