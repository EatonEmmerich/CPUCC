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
    unsigned int axis1;
    unsigned int axis2;
public:
    short ** data;
    DoubleVector(unsigned int, unsigned int);
    virtual ~DoubleVector();
    std::string printData();
};

#endif	/* DOUBLEVECTOR_H */

