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
SingleVector prefilter_window(unsigned int N,unsigned int M);
SingleVector ppf(unsigned int N, SingleVector input);
SingleVector ppf(unsigned int N, SingleVector custom_Window, SingleVector input);

#endif	/* POLYPHASEFILTER_H */

