#include "PolyphaseFilter.h"
/*
 * Apply default polyphasefilter on one stream.
 */
SingleVector ppf(unsigned int N, SingleVector input){
    ppf(prefilter_window(N),input);
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
SingleVector prefilter_window(unsigned int N){
    SingleVector result = SingleVector(N);
    for(unsigned int x = 0; x < N; x++){
        double temp1 = 1/2-((1/2) * cos(2 * M_PI / N)); // hamming window
        double temp2 = sin((x-N/2)/N)/((x-N/2)/N);
        result.setEntry(temp1*temp2,x);
    }
    return result;
}