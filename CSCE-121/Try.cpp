#include <iostream>
#include <vector>
using namespace std;
int main(){
   int a;
   cin >> a;
   vector<int> nums;
   for(int i=0;i<a;i++){
      cin >> nums[i];
   }
   int val;
   cin >> val;
   int k=1;
   for(int i=0;i<nums.size();i++){
      if(nums[i] == val){
         while(true){
            if(nums[nums.size()-k]==nums[i]){
               k+=1;
            }else{
               break;
            }
         }
         swap(nums[i],nums[nums.size()-k]);
      }
   }
   for(int i=0;i<a;i++){
      cout << nums[i] << " ";
   }
   return 0;
}