#pragma once

#include "DSString.h"

class word{
    private: 

    DSString spell;
    bool sentiment;
    size_t posCount;
    size_t negCount;

    public:

    word();
    word(DSString x);
    word(const word &rhs);

    
}
