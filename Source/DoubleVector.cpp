/* 
 * File:   DoubleVector.cpp
 * Author: eaton
 * 
 * Created on August 11, 2014, 12:16 PM
 */

#include "DoubleVector.h"


DoubleVector::DoubleVector(unsigned int axis1,unsigned int axis2){
    this->axis1 = axis1;
    this->axis2 = axis2;
    data = new short * [this->axis1];
    for(int x = 0; x < axis2; x++)
	data[x] = new short[axis2];
}

//DoubleVector::DoubleVector(const DoubleVector& orig) {
//}

DoubleVector::~DoubleVector() {
    // TODO- deconstruct the data
}

std::string DoubleVector::printData(){
    std::string out = "";
    std::ostringstream convert;
    for (unsigned int x = 0; x < axis1;x++){
        for (unsigned int y = 0; y < axis2; y++){
            convert <<  data[x][y];
            out = out + convert.str();
        }
        out = out + "\n";
    }
}

