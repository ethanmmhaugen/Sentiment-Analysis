#pragma once
#include "DSVector.h"
#include "word.h"
#include "tweet.h"
#include <fstream>

class myModel{


    public:
        DSVector<word> train(DSVector<word> &dictionary, unordered_map<string, int>& visited);
        DSVector<tweet> test(DSVector<word> &dictionary, unordered_map<string, int>& visited);
        void check(DSVector<tweet> &tweets);
        int search(DSVector<word> w, const DSString &find);
};