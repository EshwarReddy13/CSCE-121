#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {

    string input;
    cout << "Please enter obfuscated sentence: ";
    cin >> input;

    string a;
    cout << "Please enter deobfuscation details: ";
    cin >> a;
    

    string ans;
    string use = input;
    int size_a = a.size();
    
    for(int i=0;i<size_a;i++){
        char b = a.at(i);
        int bi = b - '0';
        if(i == (size_a - 1)){
            ans.append(use.substr(0,bi));
        }else{
            ans.append(use.substr(0,bi));
            ans.append(" ");
        }
        use.erase(0,bi);
    }
    cout << "Deobfuscated sentence: " << ans;

    return 0;
}
