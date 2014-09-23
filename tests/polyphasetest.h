/*
 * File:   polyphasetest.h
 * Author: eaton
 *
 * Created on Sep 17, 2014, 9:38:55 PM
 */

#ifndef POLYPHASETEST_H
#define	POLYPHASETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Source/PolyphaseFilter.h"
#include <pthread.h>
class polyphasetest : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE(polyphasetest);

	CPPUNIT_TEST(testprefilter);
	CPPUNIT_TEST(testPffTest);
	CPPUNIT_TEST(testPolyThread);

	CPPUNIT_TEST_SUITE_END();

public:
	polyphasetest();
	virtual ~polyphasetest();
	void setUp();
	void tearDown();

private:
	void testprefilter();
	void testPffTest();
	void testPolyThread();
};

#endif	/* POLYPHASETEST_H */

