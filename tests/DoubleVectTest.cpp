/*
 * File:   DoubleVectTest.cpp
 * Author: eaton
 *
 * Created on Sep 19, 2014, 12:20:01 AM
 */

#include "DoubleVectTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(DoubleVectTest);

DoubleVectTest::DoubleVectTest() {
}

DoubleVectTest::~DoubleVectTest() {
}

void DoubleVectTest::setUp() {
}

void DoubleVectTest::tearDown() {
}

void DoubleVectTest::testInit() {
    DoubleVector a = DoubleVector(2,3);
    bool right = true;
    if(a.getEntry(0,0) != complex()) right = false;
    if(a.getEntry(2,3) != complex()) right = false;
    CPPUNIT_ASSERT(right);
}

void DoubleVectTest::testComplex() {
    DoubleVector a = DoubleVector(2,3);
    a.setEntry(complex(5),0,0);
    bool right = true;
    if(a.getEntry(0,0) != complex(5)) right = false;
    if(a.getEntry(1,2) != complex()) right = false;
    CPPUNIT_ASSERT(right);
}

void DoubleVectTest::testSingleExtract(){
    DoubleVector a = DoubleVector(2,3);
    SingleVector b = SingleVector(3);
    b.setEntry(complex(5),0);
    a.setEntry(complex(5),1,0);
    SingleVector c = a.getSingleVector(1);
    if(!(b==c)){
        CPPUNIT_ASSERT(false);
    }
}

