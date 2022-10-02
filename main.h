#pragma once
#include <fstream>
#include "DSVector.h"
#include "word.h"
#include "DSString.h"

int search(DSVector<word> dic, const DSString &target){
    for(int i = 0; i<static_cast<int>(dic.size());i++){
        if(strcmp(dic[i].getString().c_str(),target.c_str())==0){
            return i;
        }
    }
    return -1;
}

void train(DSVector<word> &vec){
    ifstream file;
    file.open("data/train_dataset_20k.csv");
}