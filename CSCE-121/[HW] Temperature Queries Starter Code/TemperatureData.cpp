/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#include "TemperatureData.h"

TemperatureData::TemperatureData(): id(), year(), month(), temperature() {} //initialize everything

TemperatureData::TemperatureData(string id, int year, int month, double temperature): id(id), year(year), month(month), temperature(temperature) {} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	// Implement this
	if(b.id > this->id){
		return true;
	}else{
		if(b.id == this->id){
			if(b.year > this->year){
				return true;
			}else if(b.year == this->year){
				if(b.month > this->month){
					return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else{
			return false;
		}
	}
}    