#include <iostream>

int Largest(int a, int b, int c) {

  if(a >= b && a >= c){
    return a;
  }else if(b >= a && b >= c){
    return b;
  }else{
    return c;
  }

}

bool SumIsEven(int a, int b) {
  if((a+b)%2){
    return false;
  }
  else{
    return true;
  }
}

int BoxesNeeded(int apples) {
  if(apples < 0){
    return 0;
  }
  else{
    if(apples%20 == 0){
      return  apples/20;
    }else{
      return 1 + apples/20;
    }
  }
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  
  double a = (double(A_correct) / double(A_total));
  double b = (double(B_correct) / double(B_total));
  bool c = (a > b);
  if(A_correct > A_total || B_correct > B_total ||A_correct<0 || A_total <0 || B_correct < 0 || B_total <0 ){
    throw std::invalid_argument("Wrong input");
  }else{
    return c;
  }

}

bool GoodDinner(int pizzas, bool is_weekend) {
  
  if(is_weekend){
    if(pizzas >= 10){
      return true;
    }else{
      return false;
    }
  }else{
    if(pizzas >= 10 && pizzas <= 20){
      return true;
    }else{
      return false;
    }
  }

}

int SumBetween(int low, int high) {

  int value = 0;
  if(low > high){
    throw std::invalid_argument("wrong input");
  }else{
    throw std::overflow_error("too large or small");
    // for(int i =low;i<high+1;i++){
    //   value += i;
    // }
  }
  return value;
}

int Product(int a, int b) {
  double d = 0.0;
  int c = a*b;
  if (a<0 && b>0){
    d = (INT32_MIN)/(double(a));
    if (b > d)
    {
      throw std::overflow_error("too large or small");
    }
    else{
      return c;
    }
  }else if (a>0 && b<0){
    d=(INT32_MIN)/(double(a));
    if (b < d){
      throw std::overflow_error("too large or small");
    }else{
      return c;
    }
  }else if (a>0 && b>0){
    d=(INT32_MAX)/(double(a));
    if (b > d){
      throw std::overflow_error("too large or small");
    }else{
      return c;
    }
  }else if (a<0 && b<0){
    d=(INT32_MAX)/(double(a));
    if (b < d){
      throw std::overflow_error("too large or small");
    }else{
      return c;
    }
  }
  return 0;
  // if(a<0 && b<0){
  //   if(a > INT32_MAX/(-1*b)){
  //     throw std::overflow_error("too large or small");
  //   }else{
  //     if(a == INT32_MIN || b == INT32_MIN){
  //       return 2147483647;
  //     }
  //     return a*b;
  //   }
  // }else if(a > 0 && b < 0){
  //   if(a > INT32_MIN/(b)){
  //     throw std::overflow_error("too large or small");
  //   }else{
  //     return a*b;
  //   }
  // }else if(a < 0 && b > 0){
  //   if(b > INT32_MIN/a){
  //     throw std::overflow_error("too large or small");
  //   }else{
  //     return a*b;
  //   }
  // }else{
  //   if(a > INT32_MAX/b){
  //     throw std::overflow_error("too large or small");
  //   }else{
  //     return a*b;
  //   }
  // }
  // if(a<0 && b<0){
  //   if ((a == -1) && (b == INT32_MIN)){
  //     throw std::overflow_error("too large or small");
  //   }
  //   else if ((b == -1) && (a == INT32_MIN)){
  //     throw std::overflow_error("too large or small");
  //   }

  //   else if (a > INT32_MAX / (-1*b)){
  //     throw std::overflow_error("too large or small");
  //   }
  //   else if (a < INT32_MIN / (-1*b)){
  //     throw std::overflow_error("too large or small");
  //   }
  //   else{
  //     return a*b;
  //   }
  // }else{
  //   if (a > INT32_MAX / (b)){
  //     throw std::overflow_error("too large or small");
  //   }
  //   else if (a < INT32_MIN / (b)){
  //     throw std::overflow_error("too large or small");
  //   }
  //   else{
  //     return a*b;
  //   }
  // }
}