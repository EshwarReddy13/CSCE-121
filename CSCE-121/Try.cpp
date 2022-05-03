#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
int main(){
   string a,b,c,d;
   vector<string> loc;
   vector<string> mon;
   vector<string> date;
   vector<string> temp;
   ifstream file("esh.txt");
   if(file.is_open()){
      while(!file.eof()){
         file >> a >> b >> c >> d;

         loc.push_back(a);
         mon.push_back(b);
         date.push_back(c);
         temp.push_back(d);
      }
   }

   //cout << a;
   for(int i=0;i<loc.size();i++){
      cout << temp[i] << endl;
   }
   return 0;
}