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
    
}

void testSingleVector::tearDown() {
    
}

void testSingleVector::testMethod() {
    SingleVector a = SingleVector(VectorLength);
    SingleVector b = SingleVector(VectorLength);
    a.setEntry(0.50,0);
    double ans = a.getEntry(0).re();
    CPPUNIT_ASSERT(ans == 0.50);
}

void testSingleVector::testGetAndSet() {
    SingleVector a = SingleVector(VectorLength);
    SingleVector b = SingleVector(VectorLength);
    complex dat = complex(5,2);
    a.setEntry(dat,0);
    complex test = a.getEntry(0);
    CPPUNIT_ASSERT(dat == test);
}

void testSingleVector::testGetAndSet2() {
    SingleVector a = SingleVector(VectorLength);
    SingleVector b = SingleVector(VectorLength);
    complex dat = complex(5,2);
    a.setEntry(dat,0);
    complex test = complex(5,3);
    CPPUNIT_ASSERT(!(dat == test));
}

void testSingleVector::testAdd(){
    SingleVector a = SingleVector(VectorLength);
    SingleVector b = SingleVector(VectorLength);
    a.setEntry(1,1,0);
    a.setEntry(1,1,1);
    b.setEntry(1,1,0);
    SingleVector ans1 = SingleVector(VectorLength);
    SingleVector ans = SingleVector(VectorLength);
    ans1.setEntry(2,2,0);
    ans1.setEntry(1,1,1);
    ans1.setEntry(0,0,2);
    ans = (a+b);
    CPPUNIT_ASSERT(ans1 == ans);

}

void testSingleVector::testCompareEq() {
    SingleVector a = SingleVector(VectorLength);
    SingleVector b = SingleVector(VectorLength);
    a.setEntry(1,1,0);
    a.setEntry(1,1,1);
    a.setEntry(5.5,5.5,VectorLength-1);
    b.setEntry(1,1,0);
    b.setEntry(1,1,1);
    b.setEntry(5.5,5.5,VectorLength-1);
    bool f ;
        std::cout << "no2";
    CPPUNIT_ASSERT((a == b));
}

void testSingleVector::testCompareEq2(){
    SingleVector a = SingleVector(VectorLength);
    SingleVector b = SingleVector(VectorLength);
    a.setEntry(1,1,0);
    a.setEntry(1,1,1);
    a.setEntry(3.5,5.5,VectorLength-1);
    b.setEntry(1,1,0);
    b.setEntry(1,1,1);
    b.setEntry(5.5,5.5,VectorLength-1);
    CPPUNIT_ASSERT(!(a == b));
}

void testSingleVector::testElMultiply(){
    SingleVector a = SingleVector(VectorLength);
    SingleVector b = SingleVector(VectorLength);
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