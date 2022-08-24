#include "TemperatureDatabase.h"
#include "LinkedList.h"

#include <fstream>
#include <string>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase(): records() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	// ifstream file(filename);
	// if(file.is_open()){
	// 	while(!file.eof()){
	// 		string location;
	// 		string a;
	// 		string b;
	// 		string c;
	// 		file >> location >> a >> b >> c;
	// 		int year = stoi(a);
	// 		int month = stoi(b);
	// 		double temp = stod(c);
			
	// 	}
	// }else{
	// 	cout << "Error: Unable to open "<<filename << endl;
	// }
	LinkedList data;
	string location;
	int year;
	int month;
	double temperature;
	ifstream file(filename);
	if(file.is_open()){
		string a;
		string line;
		int i=0;
		double test;
		while(getline(file,line)){
			if(line.size()==0){
				cout << "Error: Other invalid input" << endl;
			}else{
				istringstream iss(line, istringstream::in);
				while (iss >> a && i < 4){
					switch (i) {
						case 0:
							location = a;
							break;
						case 1:
							year = stoi(a);
							if(year>2022 || year <1800){
								cout << "Error: Invalid year " << a << endl;
							}
							break;
						case 2:
							test = stod(a);
							if(test>12||test<1){
								cout << "Error: Invalid month " << a << endl;
								break;
							}else{
								month = stoi(a);
								break;
							}
						case 3:
							temperature = stod(a);
							if(a.size() == 0){
								cout << "Error: Other invalid input00" << endl;
								break;
							}else if(temperature == -99.99){
								cout << "Error: Other invalid input" << endl;
							}else if(temperature < -50 || temperature > 50){
								cout << "Error: Invalid temperature " << a << endl;
							}
							break;
					}
					i+=1;
				}
				if(i != 4){
					cout << "Error: Other invalid input" << endl;
				}	
				data.insert(location, year, month, temperature);
				i = 0;
			}
		}
	}else{
		cout << "Error: Unable to open " << filename << endl;
	}
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
}
