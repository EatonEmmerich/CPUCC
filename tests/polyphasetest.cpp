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
    SingleVector a = prefilter_window(1024,4096*2);
    Save_data("Resources/prefilter.csv",a);
    CPPUNIT_ASSERT(true);
}

void polyphasetest::testFailedMethod() {
    CPPUNIT_ASSERT(false);
}

