/*
 * File:   polyphasetest.cpp
 * Author: eaton
 *
 * Created on Sep 17, 2014, 9:38:55 PM
 */

#include "polyphasetest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(polyphasetest);

polyphasetest::polyphasetest() {
}

polyphasetest::~polyphasetest() {
}

void polyphasetest::setUp() {
}

void polyphasetest::tearDown() {
}

void polyphasetest::testMethod() {
    CPPUNIT_ASSERT(true);
}

void polyphasetest::testFailedMethod() {
    CPPUNIT_ASSERT(false);
}

