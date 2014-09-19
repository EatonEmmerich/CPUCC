/* 
 * File:   DoubleVector.h
 * Author: eaton
 *
 * Created on August 11, 2014, 12:16 PM
 */

#ifndef DOUBLEVECTOR_H
#define	DOUBLEVECTOR_H
#include "NOR.h"

class SingleVector;

class DoubleVector {
private:
	unsigned int axis1;
	unsigned int axis2;
	complex * data;
public:
	DoubleVector(unsigned int, unsigned int);
	virtual ~DoubleVector();
	std::string printData();
	void setEntry(complex , unsigned int, unsigned int);
	SingleVector getSingleVector(unsigned int);
	complex getEntry(unsigned int,unsigned int);
};


#endif	/* DOUBLEVECTOR_H */

