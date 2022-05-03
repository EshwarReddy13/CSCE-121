// TODO: Implement this header file
#include <iostream>
#ifndef MYSTRING_H
#define MYSTRING_H
using std::istream;
using std::ostream;
 
class MyString {
    public:
    
        MyString();
        MyString(MyString& mystr);
        MyString(const char* charStr);
        ~MyString();
        void resize(size_t sizeToResize);
        size_t capacity() const; 
        size_t size() const; 
        size_t length() const; 
        const char* data() const;
        bool empty() const;
        const char& front() const;
        const char& at(size_t index) const;
        void clear();
        MyString& operator = (const MyString& mystr);
        MyString& operator += (const MyString& mystr);
        size_t find(const MyString& mystr, size_t position = 0) const;   
        
    private:
        size_t sizeStr;
        char* arr;
        size_t storage;
        

       
};

ostream& operator << (ostream& outputStr, const MyString& mystr);
MyString operator + (const MyString& lhs, const MyString& rhs);
bool operator == (const MyString& lhs, const MyString& rhs);

 
#endif
