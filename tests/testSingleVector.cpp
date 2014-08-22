/*
 * File:   testSingleVector.cpp
 * Author: eaton
 *
 * Created on Aug 22, 2014, 2:45:14 PM
 */

#include "testSingleVector.h"


CPPUNIT_TEST_SUITE_REGISTRATION(testSingleVector);

testSingleVector::testSingleVector() {
}

testSingleVector::~testSingleVector() {
}

void testSingleVector::setUp() {
    
    a = SingleVector(VectorLength);
    b = SingleVector(VectorLength);
    
}

void testSingleVector::tearDown() {
    
}

void testSingleVector::testMethod() {
    a.setEntry(0.50,0);
    double ans = a.getEntry(0).re();
    CPPUNIT_ASSERT(ans == 0.50);
}

void testSingleVector::testGetAndSet() {
    complex dat = complex(5,2);
    a.setEntry(dat,0);
    complex test = a.getEntry(0);
    CPPUNIT_ASSERT(dat == test);
}

void testSingleVector::testGetAndSet2() {
    complex dat = complex(5,2);
    a.setEntry(dat,0);
    complex test = complex(5,3);
    CPPUNIT_ASSERT(!(dat == test));
}

void testSingleVector::testAdd(){
    a.setEntry(1,1,0);
    a.setEntry(1,1,1);
    b.setEntry(0.5,0.5,0);
    b.setEntry(0.5,0.5,2);
    SingleVector ans = SingleVector(VectorLength);
    ans.setEntry(1.5,1.5,0);
    ans.setEntry(1,1,1);
    ans.setEntry(0.5,0.5,2);
    CPPUNIT_ASSERT(ans.getEntry(0)==ans.getEntry(0));
}

void testSingleVector::testCompareEq() {
    a.setEntry(1,1,0);
    a.setEntry(1,1,1);
    a.setEntry(5.5,5.5,VectorLength-1);
    b.setEntry(1,1,0);
    b.setEntry(1,1,1);
    b.setEntry(5.5,5.5,VectorLength-1);
    CPPUNIT_ASSERT(a == b);
}

void testSingleVector::testCompareEq2(){
    a.setEntry(1,1,0);
    a.setEntry(1,1,1);
    a.setEntry(3.5,5.5,VectorLength-1);
    b.setEntry(1,1,0);
    b.setEntry(1,1,1);
    b.setEntry(5.5,5.5,VectorLength-1);
    CPPUNIT_ASSERT(!(a == b));
}

void testSingleVector::testElMultiply(){
    a.setEntry(1,1,0);
    a.setEntry(2,2,1);
    a.setEntry(3.5,5.5,VectorLength-1);
    b.setEntry(1,1,0);
    b.setEntry(2,2,1);
    b.setEntry(5.5,5.5,VectorLength-1);
    SingleVector ans = SingleVector(VectorLength);
    ans.setEntry(0,2,0);
    ans.setEntry(0,8,1);
    ans.setEntry(-11,49.5,VectorLength-1);
    SingleVector c = a*b;
    CPPUNIT_ASSERT(c == ans);
}