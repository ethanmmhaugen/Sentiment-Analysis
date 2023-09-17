#pragma once

#include "DSString.h"
#include "DSVector.h"

class word{
    private: 

    DSString* myString;
    int senti;
    size_t positiveCount;
    size_t negativeCount;

    public:

    word();
    word(const DSString& x);
    word(const word &rhs);

    ~word()=default;

    void setString(const DSString& x);
    void setString(word x);
    void setSenti(int sentiment);
    void setSenti();
    void calcSenti();
    void incPos();
    void incNeg();
    void reset();

    DSString getString();
    int getSenti() const;

    word& operator=(const DSString &rhs);
    word& operator=(const char* &rhs);
    
};
