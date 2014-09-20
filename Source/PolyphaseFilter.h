/* 
 * File:   PolyphaseFilter.h
 * Author: eaton
 *
 * Created on September 15, 2014, 10:28 AM
 */

#ifndef POLYPHASEFILTER_H
#define	POLYPHASEFILTER_H
#include "NOR.h"
#include <math.h>
#include <pthread.h> 
SingleVector prefilter_window(unsigned int N,unsigned int M);
SingleVector ppf(unsigned int N, SingleVector input);
SingleVector ppf(unsigned int N, SingleVector custom_Window, SingleVector input);
void * polyphaseThread(void * arg);

struct arg_type{
	DoubleVector * temp;
	SingleVector *const custom_Window;
	unsigned int N;
	SingleVector *const input;
	unsigned int start;
	unsigned int stop;
	unsigned int x;
	arg_type(SingleVector* const _custom_Window, SingleVector* const _input): input(_input),custom_Window(_custom_Window){
	
	}
};
#endif	/* POLYPHASEFILTER_H */

