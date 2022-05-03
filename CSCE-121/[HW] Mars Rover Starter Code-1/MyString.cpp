// TODO: Implement this source file
#include <iostream>
#include "MyString.h"
using std::cout;
using std::endl;

MyString::MyString() : sizeStr(0),arr(new char[1]), storage(1){
    arr[0] = '\0';
}

MyString::MyString(MyString& mystr) : sizeStr(mystr.sizeStr), arr(new char[mystr.capacity()]),storage(mystr.sizeStr+1){
    for(size_t i = 0; i < sizeStr; i++){
        arr[i] = mystr.at(i);
    }
    arr[sizeStr] = '\0';
}

MyString::MyString(const char* charStr) : sizeStr(0), arr(nullptr),storage(0) {
    
    if (charStr == nullptr) {
        arr = new char[1];
        sizeStr = 0;
        storage = 1;
        arr[0] = '\0';
        return;
    }
    size_t size = 0;
    while(charStr[size] != '\0'){
        sizeStr++;
        size++;
    }
    
    storage = sizeStr+1;
    arr = new char[storage];
    for (unsigned int i = 0; i < sizeStr; i++) {
        arr[i] = charStr[i];
    }
    
}

MyString::~MyString() {
    delete[] arr;
    sizeStr = 0;
    storage = 0;
}

void MyString::resize(size_t sizeToResize) {
    sizeStr = sizeToResize;
    
    char* arrTemp = new char[sizeToResize];
    for(size_t i = 0; i < storage; i++)  {
        arrTemp[i] = arr[i];
    }

    for(size_t i = storage; i < sizeStr; i++) {
        arrTemp[i] = '\0';
    }

    delete[] arr;
    storage = sizeStr; 
    arr = arrTemp;
}

size_t MyString::capacity() const{
    return this->storage;
}

size_t MyString::size() const {
    return sizeStr;
} 

size_t MyString::length() const {
    return this->sizeStr;
}

const char* MyString::data() const{
    return this->arr;
}

bool MyString::empty() const {
    if(this->sizeStr == 0){
        return true;
    }else{
        return false;
    }
    return false;
}

const char& MyString::front() const {
    return arr[0];
}

const char& MyString::at(size_t index) const{
    if(index >= sizeStr){
        throw std::out_of_range("Out Of Range");
    }
    return arr[index];
}

void MyString::clear() {

    for(size_t i = 0; i < sizeStr; i++){
        arr[i] = '\0';
    }
    sizeStr = 0;
}

MyString& MyString::operator=(const MyString& mystr){
    bool a = (this == &mystr);
    if(!a){
        delete[] arr;
        arr = new char[mystr.size() + 1];
        for(size_t i = 0; i < mystr.size(); i++){
            arr[i] = mystr.at(i);
        }
        this -> storage = mystr.capacity();
        this -> sizeStr = mystr.size();
        this -> arr[this->sizeStr] = '\0';
    }
    return *this;   
}

MyString& MyString::operator+=(const MyString& mystr){

    size_t newSize = sizeStr + mystr.size();
    size_t ogSize = sizeStr;
    size_t newStorage = sizeStr + mystr.size() + 1; 
    if(newStorage > storage){
        resize(newStorage);
    }
    this -> sizeStr = newSize;
    for (size_t i = ogSize; i < newSize; i++) {
        arr[i] = mystr.at(i - ogSize);
    }
    this -> arr[sizeStr] = '\0';

    return *this;
}

size_t MyString::find(const MyString& mystr, size_t position) const {
    
    size_t tempNum = 0;
    size_t a=0;
    for (size_t i = position; i <= sizeStr - mystr.sizeStr; i++) {
        tempNum = 0;
        for (size_t j= i; j < i+ mystr.sizeStr; j++) {
            a = j-i;
            if (mystr.at(a) == arr[a+i]) {
                tempNum++;
            }else {
                break;
            }
        }
        if(tempNum == mystr.sizeStr) {
            return i;
        }
    }
    return -1;
}

ostream& operator<<(ostream& outputStr, const MyString& mystr){
    for(size_t i = 0; i < mystr.size(); i++){
        outputStr << mystr.at(i);
    }
    return outputStr; 
}

MyString operator + (const MyString& lhs, const MyString& rhs){
    MyString sum(lhs.data());
    sum += rhs;
    return sum;
}

bool operator==(const MyString& lhs, const MyString& rhs){
    if (lhs.length() == rhs.length()){
        for (unsigned int i = 0; i < lhs.length(); i++) {
            if (lhs.data()[i] != rhs.data()[i]) {
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
    return false;
}