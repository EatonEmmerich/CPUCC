/*
 * File:   testSingleVector.h
 * Author: eaton
 *
 * Created on Aug 22, 2014, 2:45:14 PM
 */

#ifndef TESTSINGLEVECTOR_H
#define	TESTSINGLEVECTOR_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Source/SingleVector.h"
//#include <iostream>
//#include <sstream>
//#include <fstream>
#define VectorLength 5
class testSingleVector : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE(testSingleVector);

	CPPUNIT_TEST(testMethod);
	CPPUNIT_TEST(testGetAndSet);
	CPPUNIT_TEST(testGetAndSet2);
	CPPUNIT_TEST(testCompareEq);
	CPPUNIT_TEST(testCompareEq2);
	CPPUNIT_TEST(testAdd);
	CPPUNIT_TEST(testElMultiply);

	CPPUNIT_TEST_SUITE_END();

public:
	testSingleVector();
	virtual ~testSingleVector();
	void setUp();
	void tearDown();

private:
	void testMethod();
	void testGetAndSet();
	void testAdd();
	void testElMultiply();
	void testGetAndSet2();
	void testCompareEq();
	void testCompareEq2();
	SingleVector a;
	SingleVector b;
};

#endif	/* TESTSINGLEVECTOR_H */

