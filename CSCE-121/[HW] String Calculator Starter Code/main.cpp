#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;

    bool isQuit = false;

    while(!isQuit){

        cout << ">> ";
        string input;
        getline(cin,input);

        if(input == "quit" || input == "q"){
            isQuit = true;
        }else{
    
            string num1;
            string num2;
            char op;
            int opPosition;
            int inputLen = input.length();
            for(int i=0;i<inputLen;i++){
                if(input.at(i) == ' '){
                    opPosition = i;
                    i = inputLen;
                }if(i == inputLen){
                    continue;
                }else{
                    num1.push_back(input.at(i));
                }
            }
            op = input.at(opPosition+1);
            for(int i=opPosition+3;i<inputLen;i++){
                num2.push_back(input.at(i));
            }

            string ans;
            if(op == '+'){
                ans = add(num1, num2);
            }
            if(op == '*'){
                ans = multiply(num1, num2);
            }
            cout << endl;
            cout << "ans =" << endl;
            cout << endl;
            cout << "    " << ans << endl;
            cout << endl;
        }
    }
    cout << endl;
    cout << "farvel!" << endl;
}

