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
    this->len = strlen(x);
    strcpy(this->string, x);
    this->string[strlen(x)]='\0';
}

DSString::DSString(const DSString &rhs){
    this-> string = new char[strlen(rhs.string)+1];
    this->len = strlen(rhs.string);
    strcpy(this-> string, rhs.string);
    this->string[strlen(rhs.string)]='\0';
}


DSString &DSString::operator=(const char* rhs)
{
    delete[] string;
    string = new char[strlen(rhs)+1];
    strcpy(string, rhs);
    string[strlen(rhs)]='\0';
    return *this;
}

DSString &DSString::operator=(const DSString& rhs)
{
    delete[] string;
    string = new char[strlen(rhs.string)+1];
    strcpy(string, rhs.string);
    string[strlen(rhs.string)]='\0';
    return *this;
}

size_t DSString::getLength() const{
    size_t length = strlen(string);
    return length;
}

DSString DSString::operator+(const DSString &rhs)
{
    DSString x(*this);
    strcat(x.string, rhs.string);
    x.len = strlen(x.string);
    return x;
}

/**
 * Standard relational operators.  Feel free to add additional.
 **/
bool DSString::operator==(const DSString &rhs)
{
    int compare;
    compare = strcmp(string, rhs.string);
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
    compare = strcmp(string, rhs);
    if (compare == 0){
        return true;
    }
    else{
        return false;
    }
}

bool DSString::operator<(const DSString& rhs)
{
    int compare;
    compare = strcmp(string, rhs.string);
    if(compare<0){
        return true;
    }
    else{
        return false;
    }
}

bool DSString::operator>(const DSString &rhs)
{
    int compare;
    compare = strcmp(string, rhs.string);
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
    if (start + numChars > len) {
        throw std::runtime_error("out of bounds!");
    }
    DSString tmp;
    delete tmp.string;
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
const char* DSString::c_str() const
{
    if (string != nullptr)
    {
        size_t length = strlen(string);
        char* cstr = new char[length + 1];
        strcpy(cstr, string);
        return cstr;
    }
    else
    {
        // Handle the case where the string is nullptr (empty string)
        char* cstr = new char[1];
        cstr[0] = '\0';
        return cstr;
    }
}

/**
 * Overloaded stream insertion operator to print the contents of this
 * string to the output stream in the first argument.
 **/
std::ostream &operator<<(std::ostream &out, const DSString &x)
{
    for (size_t i = 0; i<x.getLength(); i++){
        out << x[i];
    }

    return out;
}

char &DSString::operator[](const size_t num) const {
    if(string != nullptr){
        return string[num];
    }
    else{
        throw std::runtime_error("String doesn't exist!");
    }
}

void DSString::resize(size_t length) {
    delete[] string;
    string = new char[length+1];
    string[length] = '\0';
}


