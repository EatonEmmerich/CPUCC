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
    SingleVector a = prefilter_window(1024,4096*4);
    SingleVector b = Read_data("Resources/prefilter.csv")->getSingleVector(0);
    CPPUNIT_ASSERT(round(a.getEntry(2048).re()*1000) == round(b.getEntry(2048).re()*1000));
}

void polyphasetest::testFailedMethod() {
    DoubleVector * b = Read_data("Resources/inputtest.csv");
    SingleVector input = b->getSingleVector(0);
    delete(b);
    SingleVector answr = ppf(1024,input);
    CPPUNIT_ASSERT(false);
}

