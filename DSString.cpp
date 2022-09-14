//
// Created by mark on 6/2/2021.
//

#include "DSString.h"
#include <string.h>
#include <stdexcept>

DSString::DSString(){
}

DSString::DSString(const char *x)
{
    array = DSVector(strlen(x));
    for(size_t i = 0; i<array.capacity(); i++){
        objects[i]=x[i];
    }
   
    /*size_t len = strlen(x);
    resize(len);

    for (size_t i = 0; i < len; ++i)
    {
        (*this)[i] = x[i];
    } */
}

DSString::DSString(const DSString & rhs){
    len = rhs.size();
    for (size_t i = 0; i < len; ++i)
    {
        (*this)[i] = rhs[i];
    }
}

DSString::~DSString(){

}

DSString &DSString::operator=(const char *rhs)
{
    size_t size = strlen(rhs);
    resize(size);

    for (size_t i = 0; i < size; ++i)
    {
        (*this)[i] = rhs[i];
    }

    return *this;
}

DSString DSString::operator+(const DSString &rhs) const
{
    //cerr << *this << " + " << rhs << " not implemented!" << endl;
    DSString tmp;
    size_t size = rhs.size()+ len;
    tmp.resize(size);

    for (size_t i = 0; i < len; ++i)
    {
        (tmp)[i] = *this[i];
    }
    for (size_t i = rhs.size(); i < size; ++i)
    {
        (tmp)[i] = rhs[i];
    }
    return tmp;
}

/**
 * Standard relational operators.  Feel free to add additional.
 **/
bool DSString::operator==(const DSString &rhs) const
{
    cerr << "(calling: " << *this << " == " << rhs << ") ";

    if (size() != rhs.size())
        return false;

    for (size_t i = 0; i < size(); ++i)
        if ((*this)[i] != rhs[i])
            return false;

    return true;
}

bool DSString::operator<(const DSString &rhs) const
{
    cerr << "(calling: " << *this << " < " << rhs << ") " << endl;

    size_t compSize = min(size(), rhs.size());
    for (size_t i = 0; i < compSize; ++i)
    {
        if ((*this)[i] < rhs[i])
            return true;
        if ((*this)[i] > rhs[i])
            return false;
    }

    // all were the same so far. We define the shorter string as <
    if (size() < rhs.size())
        return true;

    return false;
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
    cerr << "Not implemented!" << endl;
    return nullptr;
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