#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if( (a >= 10 && b < 10000) && (b > a) ){
		return true;
	}else{
		if(a == b){
			return true;
		}else{
			return false;
		}
	}


}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	const int a = number;
	int digits =0;
    int c = a;
    do {
    digits++; 
    c /= 10;
    }while (c);

    bool isMountain = false;
    bool isValley = false;
    bool value;
	bool isNun = false;

    for(int i =1;i<digits;i++){

		int power1; 
		int power2;
		int num = 1;
		for(int k=0;k < (digits-i);k++){
			num *= 10;
		}
		power1 = num;
		num =1;
		for(int k=0;k<(digits-(i+1));k++){
			num*=10;
		}
		power2 = num;
     	int d = a / power1;
     	int e = a / power2;
         
        if(i == 1){
			if(d%10 < e%10){
				value = true;
			}else if(d%10 > e%10){
				value = false;
			}
        }

        if(d%10 < e%10 && value){  
			if (i == 1){
				isMountain = true;
			}
			value = false;

        }else if(d%10 > e%10 && !value){
            if (i == 1){
               isValley = true;
            }
            value = true;

    	}else{
            isNun = true;
		}

    }

    if(isNun){
    	return 'N';
    }else if(isMountain){
    	return 'M';
    }else if(isValley){
    	return 'V';
    }
	return 'N';
}


void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	int mountains =0;
	int valleys = 0;
	for(int j = a;j<b+1;j++){

		char range = classify_mv_range_type(j);
		if(range == 'M'){
			mountains+=1;
		}else if (range == 'V'){
			valleys += 1;
		}

	}
	std::cout << "There are " << mountains << " mountain ranges and " << valleys << " valley ranges between " << a << " and " << b << "." << std::endl;

}

