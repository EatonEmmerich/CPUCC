/* 
 * File:   DoubleVector.cpp
 * Author: eaton
 * 
 * Created on August 11, 2014, 12:16 PM
 */

#include "DoubleVector.h"
#include "NOR.h"


DoubleVector::DoubleVector(unsigned int axis1, unsigned int axis2) {
	this->axis1 = axis1;
	this->axis2 = axis2;
	data = new short [axis1 * axis2];
}

//DoubleVector::DoubleVector(const DoubleVector& orig) {
//}

DoubleVector::~DoubleVector() {
	// TODO- deconstruct the data
}

std::string DoubleVector::printData() {
	std::string out = "";
	for (unsigned int x = 0; x < axis1; x++) {
		for (unsigned int y = 0; y < axis2; y++) {
			std::ostringstream convert;
			convert << data[x * axis2 + y];
			out = out + convert.str() + " ";
		}
		out = out + "\n";
	}
	return out;
}

void DoubleVector::setEntry(short input, unsigned int axis1, unsigned int axis2){
	data[axis1*this->axis2+axis2] = input;	
}

//returns vector along axis 2 for specified axis 1 value.
short * DoubleVector::getSingleVector(unsigned int index1){
        
}




