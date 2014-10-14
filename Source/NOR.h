/* 
 * File:   NOR.h
 * Author: eaton
 *
 * Created on August 11, 2014, 12:15 PM
 */

#ifndef NOR_H
#define	NOR_H
#define NUM_THREADS 4
typedef long long int64;
typedef unsigned long long uint64;
#include <string>
#include <exception>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <locale>
#include <functional>
#include <cassert>
#include "complex.h"
#include <math.h>
#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#include <ctime>
#endif


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

void copy_(std::vector<complex>& out,std::vector<double>& in);
void copy_(std::vector<std::vector<complex> >& out,std::vector<std::vector<double> >& in);
int64 GetTimeMs64();
#endif	/* NOR_H */

