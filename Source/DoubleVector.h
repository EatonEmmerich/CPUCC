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
	unsigned const int axis1;
	unsigned const int axis2;
	complex * data;
public:
	std::string printData();
	void setEntry(complex , unsigned int, unsigned int);
	SingleVector getSingleVector(unsigned int);
	complex getEntry(unsigned int,unsigned int);
	
	DoubleVector(unsigned int _axis1, unsigned int _axis2):axis1(_axis1),axis2(_axis2) {
	data = new complex [axis1 * axis2];
	}

	DoubleVector():axis1(1),axis2(1){
		data = new complex [axis1 * axis2];
	}

	//DoubleVector::DoubleVector(const DoubleVector& orig) {
	//}

	~DoubleVector() {
		delete [] data;
		// TODO- deconstruct the data
	}
	
	DoubleVector& operator= (const DoubleVector & sv) {
		//assume same lengths
		/* make a copy here */
		if((axis1 == sv.axis1) && (axis2 == sv.axis2)){
			for(unsigned int x = 0; x < axis1*axis2; x++){
				data[x] = sv.data[x];
			}
		}
		else{
			//throw something
		}
		return *this;
	}
	
	
};



#endif	/* DOUBLEVECTOR_H */

