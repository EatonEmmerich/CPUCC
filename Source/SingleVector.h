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
	complex * data;
	unsigned const int length;
public:
	std::string printData();
	void setEntry(complex , unsigned int);
	complex getEntry(unsigned int);
	void setEntry(double, unsigned int);
	void setEntry(double, double, unsigned int);
	
	SingleVector():length(5){
		data = new complex [length];
	}
	
	SingleVector(unsigned int _length): length(_length) {
		data = new complex [length];
	}
	
	virtual ~SingleVector(){
		delete []data;
	}
	SingleVector& operator= (const SingleVector & sv) {
		/* make a copy here */
		return *this;
	}
	
	SingleVector operator+ (const SingleVector& other) const
	{
		SingleVector ans = SingleVector(length);
		for(unsigned int x = 0; x < length; x++)
			(ans.data[x]) = (data[x]) + (other.data[x]);
		return ans;
	}
	
	bool operator== (const SingleVector& other) const
	{
		for( unsigned int x = 0; x < length; x++){
			if(((data[x]) != (other.data[x]))){
				return false;
			}
		}
		return true;
	}
	
	SingleVector operator*(const SingleVector& other) const
	{
		SingleVector out = SingleVector(length);
		for(int x = 0; x < length; x++){
			out.data[x] = data[x] * other.data[x];
		}
		return out;
	}
	
	SingleVector& operator +=(const SingleVector& other){
		for(int x = 0; x < length; x++){
			data[x] += other.data[x];
		}
		return *this;
	}
	
	SingleVector operator*(const double val) const
	{
		SingleVector out = SingleVector(length);
		for(int x = 0; x < length; x++){
			out.data[x] = data[x]*val;
		}
		return out;
	}
	
	SingleVector& operator*=(const double val)
	{
		
		for(int x = 0; x < length; x++){
			data[x] *= val;
		}
		return *this;
	}
};

#endif	/* SINGLEVECTOR_H */

