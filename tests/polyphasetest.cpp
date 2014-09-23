/*
 * File:   polyphasetest.cpp
 * Author: eaton
 *
 * Created on Sep 17, 2014, 9:38:55 PM
 */

#include "polyphasetest.h"
#include "Source/main.h"


CPPUNIT_TEST_SUITE_REGISTRATION(polyphasetest);

polyphasetest::polyphasetest() {
}

polyphasetest::~polyphasetest() {
}

void polyphasetest::setUp() {
}

void polyphasetest::tearDown() {
}

void polyphasetest::testprefilter() {
    //test by manually creating then double check on octave
    vector<double> a;
    prefilter_window(a, 1024,4096*4);
    vector<vector<double> > b1;
    vector<complex> b;
    Read_data(b1,"Resources/prefilter.csv");
    
    copy_(b,a);
    Save_data("Resources/prefilter2.csv",b);
    CPPUNIT_ASSERT(round(a[2048]*1000) == round(b1[0][2048]*1000));
}

void polyphasetest::testPolyThread(){
    vector<double> a;
    prefilter_window(a, 1024,4096*4);
    vector<vector<double> > b1;
    vector<complex> b;
    Read_data(b1, "Resources/inputtest.csv");
    vector<double> input = b1[0];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    int N = 1024;
    int start = N+1;
    int stop = start + N;
    vector<double> answr(N,0.00);
    struct arg_type * inputargs = new struct arg_type(a, input);

    inputargs->N = N;
    inputargs->start = start;
    inputargs->stop = stop;
    pthread_t thread;
    int rc = pthread_create(&thread,NULL,polyphaseThread,(void *) inputargs);
    thread_return_data * ret;
    rc = pthread_join(thread, (void**)&(ret));
    answr = ret->result;
    copy_(b,answr);
    Save_data("Resources/outtest1.csv",(b));
    
    CPPUNIT_ASSERT(rc==0);
}

void polyphasetest::testPffTest() {
    vector<vector<double> > b1;
    vector<complex> b;
    Read_data(b1, "Resources/inputtest.csv");
    vector<double> input = b1[0];
    //Save_data("Resources/inputvalid.csv",input);
    vector<double> answr;
    ppf(answr,1024,input);
    copy_(b,answr);
    Save_data("Resources/answr1.csv",b);
    CPPUNIT_ASSERT(true);
}