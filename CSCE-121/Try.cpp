#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
   double a = 10.20000;
   int b =a/1;
   cout << to_string(b) << endl;
   cout << a << std::setprecision(2) << endl;
   return 0;
}