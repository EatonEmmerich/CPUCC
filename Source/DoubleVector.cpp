/* 
 * File:   DoubleVector.cpp
 * Author: eaton
 * 
 * Created on August 11, 2014, 12:16 PM
 */

#include "DoubleVector.h"

std::string DoubleVector::printData() {
	std::string out = "";
	for (unsigned int x = 0; x < axis1; x++) {
		for (unsigned int y = 0; y < axis2; y++) {
			std::ostringstream convert;
			convert << data[x * axis2 + y].re() << " + " << data[x * axis2 + y].im() << "j";
			out = out + convert.str() + " ";
		}
		out = out + "\n";
	}
	return out;
}

void DoubleVector::setEntry(complex input, unsigned int axis1, unsigned int axis2){
	data[axis1*this->axis2+axis2] = input;	
}

//returns vector along axis 2 for specified axis 1 value.
SingleVector DoubleVector::getSingleVector(unsigned int index1){
    SingleVector out = SingleVector(axis2);
    for(int x = 0; x < axis2; x++){
        out.setEntry((data[index1*axis2+x]),x);
    }
    return out;
}

complex DoubleVector::getEntry(unsigned int axis1, unsigned int axis2){
    return data[axis1*this->axis2+axis2];
}