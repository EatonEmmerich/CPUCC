/* 
 * File:   DoubleVector.h
 * Author: eaton
 *
 * Created on August 11, 2014, 12:16 PM
 */

#ifndef DOUBLEVECTOR_H
#define	DOUBLEVECTOR_H
#include <string>
#include <iostream>
#include <sstream>

template <typename T>
class DoubleVector {
    unsigned int axis1;
    unsigned int axis2;
	T * data;
public:
    DoubleVector(unsigned int, unsigned int);
    virtual ~DoubleVector();
    std::string printData();
	Entry()
};

template <typename T>
DoubleVector::DoubleVector(unsigned int axis1, unsigned int axis2){
	this->axis1 = axis1;
	this->axis2 = axis2;
	data = new T [axis1*axis2];
}

//DoubleVector::DoubleVector(const DoubleVector& orig) {
//}

template <typename T>
DoubleVector::~DoubleVector() {
	// TODO- deconstruct the data
}

template <typename T>
std::string DoubleVector::printData(){
	std::string out = "";
	for (unsigned int x = 0; x < axis1; x++){
		for (unsigned int y = 0; y < axis2; y++){
			std::ostringstream convert;
			convert << data[x*axis2+y];
			out = out + convert.str();
		}
		out = out + "\n";
	}
	return out;
}

#endif	/* DOUBLEVECTOR_H */

