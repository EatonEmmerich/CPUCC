/* 
 * File:   NOR.h
 * Author: eaton
 *
 * Created on August 11, 2014, 12:15 PM
 */

#ifndef NOR_H
#define	NOR_H
#define NUM_THREADS 3
#include <string>
#include <exception>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <locale>
#include <functional>


class NotSameLengthException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "The file vectors are not all the same length.";
	}
};

template <typename T>
T StringToNumber(const std::string &in) {
    std::stringstream ss(in);
    T result;
    return ss >> result ? result : 0;
}

template <typename T>
std::string NumberToString(const T in) {
    std::ostringstream convert;
    convert << in;
    std::string result;
    result = convert.str();
    return result;
}

#include "complex.h"
#include "SingleVector.h"
#include "DoubleVector.h"

#endif	/* NOR_H */

