/* 
 * File:   NOR.h
 * Author: eaton
 *
 * Created on August 11, 2014, 12:15 PM
 */

#ifndef NOR_H
#define	NOR_H
#include <string>
#include <exception>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <locale>
#include <functional>
#include "DoubleVector.h"
#include "complex.h"

class NotSameLengthException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "The file vectors are not all the same length.";
	}
};

#endif	/* NOR_H */

