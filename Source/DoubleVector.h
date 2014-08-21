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

class DoubleVector {
private:
	unsigned int axis1;
	unsigned int axis2;
	short * data;
public:
	DoubleVector(unsigned int, unsigned int);
	virtual ~DoubleVector();
	std::string printData();
	void setEntry(short, unsigned int, unsigned int);
	short * getSingleVector(unsigned int index1);
};


#endif	/* DOUBLEVECTOR_H */

