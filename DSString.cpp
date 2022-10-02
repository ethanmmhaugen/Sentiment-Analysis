//
// Created by mark on 6/2/2021.
//

#include "DSString.h"
#include <string.h>
#include <stdexcept>

DSString::DSString(){
    string = nullptr;
}

DSString::DSString(const char *x)
{
    this->string = new  char[strlen(x)+1];
    strcpy(this->string, x);
    this->string[strlen(x)]='\0';
}

DSString::DSString(const DSString &rhs){
    this-> string = new char[strlen(rhs.string)+1];
    strcpy(this-> string, rhs.string);
    this->string[strlen(rhs.string)]='\0';
}


DSString &DSString::operator=(const char* rhs)
{
    this->string = new char[strlen(rhs)+1];
    strcpy(this->string, rhs);
    this->string[strlen(rhs)]='\0';
    return *this;
}

DSString &DSString::operator=(const DSString& rhs)
{
    this->string = new char[strlen(rhs.string)+1];
    strcpy(this->string, rhs.string);
    this->string[strlen(rhs.string)]='\0';
    return *this;
}

size_t DSString::getLength(){
    size_t length = strlen(string);
    return length;
}

DSString DSString::operator+(const DSString &rhs)
{
    DSString x;
    x.string = new char[strlen(rhs.string)+strlen(this->string)+1];
    strcat(x.string, this -> string);
    strcat(x.string, rhs.string);
    x.string[strlen(x.string)]='\0';
    return x;
}

/**
 * Standard relational operators.  Feel free to add additional.
 **/
bool DSString::operator==(const DSString &rhs)
{
    int compare;
    compare = strcmp(this->string, rhs.string);
    if (compare == 0){
        return true;
    }
    else{
        return false;
    }
}

bool DSString::operator==(const char* rhs)
{
    int compare;
    compare = strcmp(this->string, rhs);
    if (compare == 0){
        return true;
    }
    else{
        return false;
    }
}

bool DSString::operator<(const DSString &rhs) const
{
    int compare;
    compare = strcmp(this->string, rhs);
    if(compare<0){
        return true;
    }
    else{
        return false; 
    }
}

bool DSString::operator>(const DSString &rhs) const
{
    int compare;
    compare = strcmp(this->string, rhs);
    if(compare>0){
        return true;
    }
    else{
        return false; 
    }
}

/**
 * The substring method returns a string object that contains a
 * sequence of characters from this string object.
 *
 * param start - the index of where to start
 * param numChars - the number (count) of characters to copy into
 *    the substring
 * @return a DSString object containing the requested substring
 **/
DSString DSString::substring(size_t start, size_t numChars) const
{
    if (start + numChars > size())
        throw std::runtime_error("out of bounds!");

    DSString tmp;
    tmp.resize(numChars);

    for (size_t i = 0; i < numChars; ++i)
    {
        tmp[i] = (*this)[start + i];
    }
    return tmp;
}

/**
 * the c_str function returns a null-terminated c-string holding the
 * contents of this object.
 **/
const char *DSString::c_str() const
{
    // I would need to keep an extra `\0` to make this work.
    return this->string;
}

/**
 * Overloaded stream insertion operator to print the contents of this
 * string to the output stream in the first argument.
 **/
std::ostream &operator<<(std::ostream &out, const DSString &x)
{
    for (const auto &c : x)
        out << c;

    return out;
}

DSString& addSentiment(int senti){
    DSString x;
    x = new char[strlen(this->string)+2];
    if(senti == 0){
        x[0] = '0';
    }
    else if (senti == 4){
        x[0] = '4';
    }
    x[1] = ',';

    for(int i = 0; i<strlen(this->string); i++){
        x[2+i]=string[i];
    }
    x.string[strlen(x.string)]='\0';
    this->string = new char[strlen(x.string)];
    for(int i =0; i<strlen(x.string);i++){
        this->string[i]=x.string[i];
    }
    return *this;
}
