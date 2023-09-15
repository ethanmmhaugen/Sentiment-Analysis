#ifndef DSSTRING_H
#define DSSTRING_H
#include <iostream>
#include <cstring>
#include <set>
#include "DSVector.h"

class DSString {

private:
    char* string;  // a pointer to a character array containing the string
    size_t len;      // the length of the string 
public:
    /**
     * Make sure you implement the rule of 3 and use proper memory management.
     * To help you get started, you can implement the following:
     **/

    DSString();
    DSString(const char *); // constructor that converts a cstring
    
    // rule of 3
    DSString(const DSString & rhs);  // copy constructor
    ~DSString() = default;  // destructor
    DSString &operator=(const char* rhs);
    DSString &operator=(const DSString &);
    

    // you can also implement the move versions for the big 5 (C+11)

    // implement some useful methods
    void resize(size_t length);
    size_t getLength() const;

    /**
     * Overloaded non-modifying string concat
     */
    DSString operator+(const DSString &rhs);
    //DSString operator+(const char* line);

    /**
     * Standard relational operators to compare and order your strings.  
     * Feel free to add additional.
     **/
    bool operator==(const DSString &rhs);
    bool operator==(const char* rhs);
    //bool operator==(const char*)const;
    bool operator<(DSString);
    bool operator>(const DSString &);

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString substring(size_t start, size_t numChars) const;

    char& operator[] (const size_t num) const;

    /**
     * the c_str function returns a pointer a null-terminated c-string holding the
     * contents of this object. It would be smart to always have an extra `\0`
     * at the end of the string in DSString so you can just return a pointer to the
     * objects. 
     **/
    const char *c_str() const;

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument. `DSString&`
     * could be const, but then we would have to implement a const interator in
     * DSVector.
     **/
    friend std::ostream &operator<<(std::ostream &, const DSString &);

    // You are free to add more functionality to the class.  For example,
    // you may want to add a find(...) function that will search for a
    // substring within a string or a function that breaks a string into words.
};

#endif