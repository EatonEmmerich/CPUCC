#include "PolyphaseFilter.h"
/*
 * Apply default polyphasefilter on one stream.
 */
SingleVector ppf(unsigned int N, SingleVector input){
    ppf(prefilter_window(N,input.getSize()),input);
}

SingleVector ppf(SingleVector custom_Window, SingleVector input){
    unsigned int M = input.getSize();
    unsigned int N = custom_Window.getSize();
    SingleVector result = SingleVector(N);
    int x = 0;
    while(x < M){
        SingleVector temp = SingleVector(N);
        for(int y = 0; y < N; y++){
            temp.setEntry(input.getEntry(x),y);
            x++;
        }
        temp = temp*custom_Window;
        result += temp;
    }
    return result;
}

/*
 * Default prefilter window
 */
SingleVector prefilter_window(unsigned int N,unsigned int M){
    SingleVector result = SingleVector(M);
    double Nd = (double) N;
    double Md = (double) M;
    for(unsigned int x = 0; x < M; x++){
        double xd = (double) x;
        double temp3 = (2 * M_PI * (xd / Md));
        double temp1 = 0.5-0.5*cos(temp3); // hamming window
        double temp2 = 0;
        
        double temp4 = (xd-Md/2)/Nd;
        if(temp4 != 0){
            temp2 = sin(temp4)/(temp4);      // sinc function
        }
        else{
            temp2 = 1;
        }
        result.setEntry(temp2,x);
    }
    return result;
}