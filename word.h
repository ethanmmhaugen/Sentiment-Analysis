#pragma once

#include "DSString.h"

class word{
    private: 

    DSString myString;
    int senti;
    size_t positiveCount;
    size_t negativeCount;

    public:

    word();
    word(DSString x);
    word(const word &rhs);

    ~word()=default;

    void setString(DSString x);
    void setString(word x);
    void setSenti(int sentiment);
    void setSenti();

    DSString getString();
    int getSenti();

    
};
