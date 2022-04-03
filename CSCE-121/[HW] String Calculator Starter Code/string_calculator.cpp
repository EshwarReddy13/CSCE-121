#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    int ans = digit - '0';
    if(ans > 10 || ans < 0){
        throw std::invalid_argument("Wrong input");
    }else{
        return ans;
    }
    
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    char a;
    if(decimal > 10){
        throw std::invalid_argument("Wrong input");
    }else{
        a = '0' + decimal;
        return a;
    }
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    string ans;
    bool zero = true;
    int size = num.size();
    if(num.at(0) == '-'){
        ans.append("-");
        for(int i =1;i<size;i++){
            if((digit_to_decimal(num.at(i))==0 || num.at(i)=='-') && zero == true){
                continue;
            }else{
                zero = false;
                ans.push_back(num.at(i));
            }
        }
    }else{
        for(int i =0;i<size;i++){
            if((zero == true) && (digit_to_decimal(num.at(i))==0 || num.at(i)=='-')){
                continue;
            }else{
                zero = false;
                ans.push_back(num.at(i));
            }
        }
    }
    if(zero == true){
        ans = "0";
    }
    return ans;
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    string a = trim_leading_zeros(lhs);
    string b = trim_leading_zeros(rhs);
    bool isNeg = false;
    if(a.at(0) == '-'){
        a.erase(0,1);
        isNeg = true;
    }
    if(b.at(0) == '-'){
        b.erase(0,1);
        isNeg = true;
    }
    if (a.length() > b.length()){
        swap(a, b);
    }

    int carryForward = 0;
    int sum;
    string ans;
    int aLength = a.length();
    int bLength = b.length();
    int diff = bLength - aLength;

    for(int i = aLength-1;i>=0;i--){

        int c = digit_to_decimal(a.at(i));
        int d = digit_to_decimal(b.at(i+diff));
        sum = carryForward + c + d;
        ans.push_back(decimal_to_digit(sum%10));
        carryForward = sum/10;
    
    }
    //sum = 0;
    for (int i=diff-1; i>=0; i--){

        int e = digit_to_decimal(b.at(i));
        sum = e + carryForward;
        ans.push_back(decimal_to_digit(sum%10));
        carryForward = sum/10;

    }
    if(carryForward){
        ans.push_back(decimal_to_digit(carryForward));
    }

    string finalAns;
    if(isNeg){
        finalAns.push_back('-');
    }
    for(int i=ans.length()-1;i >=0;i--){
        finalAns.push_back(ans.at(i));
    }
    
    return finalAns;
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement
    string a = trim_leading_zeros(lhs);
    string b = trim_leading_zeros(rhs);
    bool is_a_neg = false;
    bool is_b_neg = false;

    if(a.at(0) == '-'){
        a.erase(0,1);
        is_a_neg = true;
    }
    if(b.at(0) == '-'){
        b.erase(0,1);
        is_b_neg = true;
    }

    bool isNeg = false;
    
    if(is_a_neg == true && is_b_neg == true){
        isNeg = false;
    }else if(is_a_neg==true){
        isNeg = true;
    }else if(is_b_neg==true){
        isNeg = true;
    }else{
        isNeg = false;
    }
    
    int aSize = a.length();
    int bSize = b.length();

    if(a == "0" || b == "0"){ 
      return "0"; 
      
    }else{
        string mult(aSize + bSize, 0); 

        for(int i = aSize - 1; i >= 0; i--){ 
            for(int j = bSize - 1; j >= 0; j--){ 
                int c = digit_to_decimal(a.at(i));
                int d = digit_to_decimal(b.at(j));
                int e = (c*d) + mult[i + j + 1]; 
                mult[i + j + 1] = e % 10; 
                mult[i + j] += e / 10;
            }
        } 

        int size = mult.size();
        string finalAns;
        for(int j = 0; j < size; j++){
            finalAns.push_back(decimal_to_digit(mult.at(j)));
        } 
        if(finalAns.at(0) == '0'){ 
            finalAns = finalAns.substr(1); 
        } 
        if(isNeg){
            finalAns.insert(0,"-");
        }
        return finalAns; 
    }
    
}


