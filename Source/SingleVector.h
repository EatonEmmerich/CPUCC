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
	complex getEntry(unsigned int) const;
	void setEntry(double, unsigned int);
	void setEntry(double, double, unsigned int);
	
	SingleVector():length(1){
		data = new complex [length];
	}
	
	SingleVector(unsigned int _length): length(_length) {
		data = new complex [length];
	}
	
	SingleVector(const SingleVector& other):length(other.length){
		data = new complex [length];
		for(int x = 0; x < length; x ++){
			data[x] = other.getEntry(x);
		}
	}
	
	virtual ~SingleVector(){
		delete []data;
	}
	SingleVector& operator= (const SingleVector & sv) {
		//assume same lengths
		/* make a copy here */
		if(length == sv.length){
			for(unsigned int x = 0; x < (sv).length; x++){
				data[x] = sv.getEntry(x);
			}
		}
		else{
			//throw something
		}
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
	
	unsigned int getSize(){
		return length;
	}
	
};

#endif	/* SINGLEVECTOR_H */

