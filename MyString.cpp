//
// Created by Hugo Valle on 11/12/17.
//
#include <memory>
#include "MyString.h"

MyString::MyString()
{}

MyString::MyString(const char *cString)
{
    nlength = getNlength(cString);
    internalCString = make_unique<char[]>(nlength);
    for(int i = 0; i < nlength; i++)
    {
        internalCString[i] = cString[i];
    }

}

int MyString::getNlength(string x) const
{
    int i = 0;
    do
    {
        i++;
        x[i];

    }while(x[i] != '\0');
    return i;
}

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
char *MyString::getInternalCString() const
{
    return internalCString.get();
}

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
