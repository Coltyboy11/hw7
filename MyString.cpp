//
// Created by Hugo Valle on 11/12/17.
//
#include <memory>
#include "MyString.h"

/*!
 * MyString constructor with no arguments
 */
MyString::MyString()
{}

/*!
 * MyString constructor with one argument
 * @param cString : Pointer for char array
 */
MyString::MyString(const char *cString)
{
    nlength = getNlength(cString);
    internalCString = make_unique<char[]>(nlength);            //(size_t) cString
    for(int i = 0; i < nlength + 1; i++)
    {
        internalCString[i] = cString[i];
    }
}

/*!
 * Getter for the length of the string
 * @param x : variable for the string
 * @return : Returns the integer length
 */
int MyString::getNlength(const char* x) const
{
    int i = 0;
    do
    {
        i++;
        x[i];

    }while(x[i] != '\0');
    return i;
}

/*!
 * Method to reverse the string
 */
void MyString::reverseit()
{
    char temp;
    for (int i = 0; i < (nlength)/2; i++)
    {
        temp = internalCString[i];
        internalCString[i] = internalCString[nlength-i-1];
        internalCString[nlength-i-1] = temp;
    }
}

/*!
 * Getter for the internalCString
 * @return : internalCString in MyString class
 */
char *MyString::getInternalCString() const
{
    return internalCString.get();
}

/*!
 * Method to compare two strings
 * @param lhs : The left/first string being compared
 * @param rhs : The right/second string being compared
 * @return : 1 if left bigger, -1 if right bigger,
 *           -2 if same length, 0 if same length and characters
 */
int MyString::compareStr(const MyString &lhs, const MyString &rhs)
{
    int right = rhs.nlength;
    int left = lhs.nlength;

    if(left > right)
    {
        return 1;
    }
    if(left < right)
    {
        return -1;
    }
    if(right == left && *lhs.getInternalCString() == *rhs.getInternalCString())
    {
        return 0;
    }
    if(right == left && lhs.getInternalCString() != rhs.getInternalCString())
    {
        return -2;
    }
}

/*!
 * Output operator for MyString class
 * @param os : Variable to hold desired output
 * @param myString : String being displayed
 * @return : Variable holding the string output
 */
ostream &operator<<(ostream &os, const MyString &myString)
{
    os << myString.getInternalCString();
    return os;
}
