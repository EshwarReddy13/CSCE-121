#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>
#include "parallel_tracks.h"

using std::string;


//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the text file given
//---------------------------------------------------------
bool checkTime(string time){
	if(!stod(time) || stod(time) <=0 ){
		return false;
	}else{
		return true;
	}
}

bool checkCountry(string country){
	bool a = true;
	for(int i=0;i<3;i++){
		if(!isupper(country.at(i))){
			a = false;
		}
	}
	if(country.size() !=3){
		return false;
	}else if(!a){
		return false;
	}else{
		return true;
	}
}


void get_runner_data( const std::string& file, double timeArray[], std::string countryArray[], 
		unsigned int numberArray[], std::string lastnameArray[]) 
{
  //TODO
  std::ifstream input(file);
  string str;
  char a;
  int arrNum=0;
  if(input.is_open()){
	while(getline(input,str)){
		int strSize = str.size();
		if(str.size()==0){
			throw std::domain_error("File missing data");
		}
		a = str.at(0);
		int i =0;
		string m;
		while(a != ' '){
			m.push_back(a);
			i++;
			a = str.at(i);
		}
		if(!checkTime(m)){
			throw std::domain_error("File contains invalid data (time)");
		}
		double x1 = stod(m);
		timeArray[arrNum]=x1;

		i++;
		m.clear();
		a = str.at(i);
		while(a != ' '){
			m.push_back(a);
			i++;
			a = str.at(i);
		}
		if(!checkCountry(m)){
			throw std::domain_error("File contains invalid data (country)");
		}
		countryArray[arrNum]=m;
		
		i++;
		m.clear();
		a = str.at(i);
		while(a != ' '){
			m.push_back(a);
			i++;
			a = str.at(i);
		}
		int x2 = stoi(m);
		numberArray[arrNum] =x2;

		i++;
		m.clear();
		while(i != strSize){
			a = str.at(i);
			i++;
			m.push_back(a);
		}
		
		lastnameArray[arrNum] = m;
		arrNum++;
	}
  }else{
	  throw std::invalid_argument("Cannot open file");
  }
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
	int size =9;
	for(int i=0;i<size;i++){
		ary[i] = 0.0;
	}

}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an unsigned int arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	//TODO
	int size = 9;
	for(int i=0;i<size;i++){
		ary[i] = 0;
	}
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	//TODO
	int size = 9;
	for(int i=0;i<size;i++){
		ary[i] = "N/A";
	}
}
//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	//TODO
	int rank;
	int size = 9;
	for(int i =0;i<size;++i){
		rank =1;
		for(int j=0;j<size;j++){
			if(timeArray[j]<timeArray[i]){
				rank++;
			}
		}
		rankArray[i] = rank++;
	}
}

//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}

std::string trim(std::string ret) {
	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}
	
	return ret;
}