#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  char a;
  int i=0;
  while(a != '\0'){
    a = str[i];
    i++;
  }
  i--;
  return i;
}

unsigned int find(char str[], char character) {
  // returns 
  //  - the index of the firsddddddddddddddddddddddddddddt occurence of character in str
  //  - the size if the character is not found
  int size = length(str);
  int a;
  if(str[0] == ' '){
    return 0;
  }
  for(int i =0;i<size;i++){
    a = i;
    if(str[i] == character){
      break;
    }
  }
  if(a == size-1){
    if(str[a]==character){
      return a;
    }else{
      return size;
    }
  }else{
    return a;
  }

}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  if(str1[0]==' ' &&str2[0] ==' '){
    return true;
  }else if(str1[0]==' ' || str2[0] ==' '){
    return false;
  }else{
    int size = length(str1);
    int a=0;
    for(int i =0;i<size;i++){
      if(str1[i] == str2[i]){
        a++;
      }
    }
    if(a == size){
      return true;
    }else{
      return false;
    }
  }
  //   if(a == size1){
  //     return true;
  //   }else{
  //     return false;
  //   }
  // }else{
  //   return false;
  // }
}