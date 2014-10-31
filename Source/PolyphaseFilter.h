/* 
 * File:   PolyphaseFilter.h
 * Author: eaton
 *
 * Created on September 15, 2014, 10:28 AM
 */

#ifndef POLYPHASEFILTER_H
#define	POLYPHASEFILTER_H
#include "NOR.h"

#include <pthread.h>
using namespace std;
void prefilter_window(vector<double>& result, unsigned int N,unsigned int M);
void ppf(vector<double>& output ,unsigned int N, vector<double> input);
void ppf(vector<double>& result, unsigned int N, vector<double> custom_Window, vector<double> input);
void * polyphaseThread(void * arg);

struct arg_type{
	vector<double> * custom_Window;
	unsigned int N;
	vector<double> * input;
	unsigned int start;
	unsigned int stop;
	unsigned int inputsize;
	arg_type(vector<double> _custom_Window, vector<double> _input): input(& _input), custom_Window(& _custom_Window), inputsize(_custom_Window.size()){
	}
};

struct thread_return_data{
	vector<double> result;
};
#endif	/* POLYPHASEFILTER_H */

