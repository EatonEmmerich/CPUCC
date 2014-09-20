#include "PolyphaseFilter.h"
/*
 * Apply default polyphasefilter on one stream.
 */
SingleVector ppf(unsigned int N, SingleVector input){
    ppf(N,prefilter_window(N,input.getSize()),input);
}


SingleVector ppf(unsigned int N,SingleVector custom_Window, SingleVector input){
    unsigned int M = input.getSize();
    SingleVector result = SingleVector(N);
    int x = 0;
    unsigned int num_thread = M/N;
    pthread_t * threads = new pthread_t [num_thread];
    DoubleVector temp = DoubleVector(num_thread,N);
    while(x < M){
        int start = x;
        x = x + M;
        int stop = x;
        struct arg_type inputargs(&custom_Window, &input);
        inputargs.N = N;
        inputargs.start = start;
        inputargs.stop = stop;
        inputargs.temp = &(temp);
        inputargs.x = x;
        int rc = pthread_create(threads,NULL,polyphaseThread,(void *) &inputargs);
        if(rc){
            std::cout << "could not create thread " << rc;
        }
    }

    return result;
}

void * polyphaseThread(void * threadarg){
    struct arg_type * inputargs;
    inputargs = (struct arg_type *) threadarg;
    SingleVector * const custom_Window = inputargs->custom_Window;
    SingleVector * const input = inputargs->input;
    DoubleVector * temp = inputargs->temp;
    unsigned int x = inputargs->x;
    unsigned int N = inputargs->N;
    unsigned int start = inputargs->start;
    unsigned int stop = inputargs->stop;
    SingleVector par_Window = SingleVector(N);
    SingleVector par_input = SingleVector(N);
    
    int y = 0;
    for(int x = start; x < stop; x++){
        par_Window.setEntry(custom_Window->getEntry(x),y);
        par_input.setEntry(input->getEntry(x),y);
        y++;
    }
    for(y = 0; y < N; y++){
        temp->setEntry(par_input.getEntry(y)*par_Window.getEntry(y),x,y);
    }
    
    //*(temp) *= par_Window;
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
        result.setEntry(temp2*temp1,x);
    }
    return result;
}