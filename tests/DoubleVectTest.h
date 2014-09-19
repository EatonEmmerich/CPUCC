/*
 * File:   DoubleVectTest.h
 * Author: eaton
 *
 * Created on Sep 19, 2014, 12:20:00 AM
 */

#ifndef DOUBLEVECTTEST_H
#define	DOUBLEVECTTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Source/NOR.h"

class DoubleVectTest : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE(DoubleVectTest);

	CPPUNIT_TEST(testInit);
	CPPUNIT_TEST(testComplex);
	CPPUNIT_TEST(testSingleExtract);

	CPPUNIT_TEST_SUITE_END();

public:
	DoubleVectTest();
	virtual ~DoubleVectTest();
	void setUp();
	void tearDown();

private:
	void testInit();
	void testComplex();
	void testSingleExtract();
};

#endif	/* DOUBLEVECTTEST_H */

