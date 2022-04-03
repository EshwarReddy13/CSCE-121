#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {

    string input;
    cout << "Please enter the sentence: ";
    getline(cin,input);

    string rep;
    cout << "Please enter the filter word: ";
    cin >> rep;

    string use = input;
    int size = rep.size();
    string repl;
    for(int i=0;i< size;i++){
        repl.append("#");
    }
    while(true){
        int b = use.find(rep);
        if(b == -1){
            break;
        }else{
            use.replace(b,size,repl);
        }
    }
    cout << "Filtered sentence: " << use;
    return 0;
}
