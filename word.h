#pragma once

#include "DSString.h"
#include "DSVector.h"

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
    void incPos();
    void incNeg();
    void reset();

    DSString getString();
    int getSenti();

    word& operator=(const DSString &rhs);
    word& operator=(const char* &rhs);
    
};
