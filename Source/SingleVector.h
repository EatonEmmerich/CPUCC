/* 
 * File:   SingleVector.h
 * Author: eaton
 *
 * Created on August 21, 2014, 4:18 PM
 */

#ifndef SINGLEVECTOR_H
#define	SINGLEVECTOR_H
#include "NOR.h"

class SingleVector {
private:
	complex ** data;
	unsigned int length;
public:
	SingleVector(unsigned int);
	virtual ~SingleVector();
	std::string printData();
};

#endif	/* SINGLEVECTOR_H */

