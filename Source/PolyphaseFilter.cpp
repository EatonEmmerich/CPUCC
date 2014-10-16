#include "PolyphaseFilter.h"
#include "main.h"
/*
 * Apply default polyphasefilter on one stream.
 */
void ppf(vector<double>& output ,unsigned int N, vector<double> input){
    vector<double> preWindow;
    prefilter_window(preWindow, N, input.size());
    ppf(output, N, preWindow, input);
}


void ppf(vector<double>& result,unsigned int N,vector<double> custom_Window, vector<double> input){
    unsigned int M = input.size();
    if(M != custom_Window.size()){
        std::cout << "error, filter and input mismatch";
        exit(-1);
    }
    int amountrunning = 0;
    int amountrun = 0;
    pthread_attr_t attr;
    unsigned int num_thread = M/N;
//    std::cout << "numthread \n" << NumberToString<unsigned int>(num_thread);
    pthread_t * threads = new pthread_t [NUM_THREADS];
    int currentFrame = 0;
    int start = 0;
    int stop = start + N;
    int ran = 0;
    
    result.resize(N,0.00);
    vector<vector<double> > temp(num_thread,vector<double>(N,0.00));
       
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    while(amountrun < num_thread){

        for(unsigned int x = 0; (x < NUM_THREADS)&&(amountrun<num_thread); x++){
            struct arg_type * inputargs = new struct arg_type(custom_Window, input);
            inputargs->N = N;
            inputargs->start = start;
            inputargs->stop = stop;
            start = stop;
            stop = start + N;
            int rc = pthread_create(&threads[x],NULL,polyphaseThread,(void *) inputargs);
            if(rc){
                std::cout << "could not create thread " << rc;
            }
            amountrunning ++;
            amountrun ++;
        }
        for(unsigned int x = 0; x < amountrunning; x++){
            pthread_attr_destroy(&attr);
            thread_return_data * ret;
            int rc = pthread_join(threads[x], (void**)&(ret));
            temp[ran] = ret->result;
            if (rc) {
                cout << "Error:unable to join," << rc << endl;
                exit(-1);
            }
            amountrunning --;
            ran ++;
            delete(ret);
            pthread_attr_init(&attr);
            pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
        }
    }
    //delete thread datastructs
    delete[](threads);
    //done applying, now sum.
    for(unsigned int x = 0; x < num_thread; x++){
        std::transform(result.begin(),result.end(), temp[x].begin(),result.begin(),std::plus<double>());
    }
}

void * polyphaseThread(void * threadarg){
    arg_type * inputargs;
    inputargs = (arg_type *) threadarg;
    thread_return_data * answr = new thread_return_data();
    answr->result.resize(inputargs->N);
//        inputargs->custom_Window;
//        inputargs->input;
//        inputargs->temp;
//        inputargs->x;
//        inputargs->N;
//        inputargs->start;
//        inputargs->stop;
    if(inputargs->stop >= inputargs->input.size()){
        std::cout << "not multiple of each other";
        exit (-1);
    }
    vector<double> par_Window(inputargs->N);
    vector<double> par_input(inputargs->N);
    //std::cout << "sizes: " << NumberToString<unsigned int>(inputargs->N)<< " " << NumberToString<unsigned int>(inputargs->stop-inputargs->start);
    int y = 0;
    for(int x = inputargs->start; x < inputargs->stop; x++){
        par_Window[y] = inputargs->custom_Window[x];
        par_input[y] = inputargs->input[x];
        y++;
    }
    for(y = 0; y < inputargs->N; y++){
        (answr)->result[y] = par_Window[y]*par_input[y];
    }
    delete((arg_type *)(threadarg));
    pthread_exit(answr);
    return 0;
}

/*
 * Default prefilter window
 */
void prefilter_window(vector<double>& result,unsigned int N,unsigned int M){
    result.resize(M);
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
        result[x]=(temp2*temp1);
    }
}