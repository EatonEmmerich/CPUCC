/*
 * File:   polyphasetest.h
 * Author: eaton
 *
 * Created on Sep 17, 2014, 9:38:55 PM
 */

#ifndef POLYPHASETEST_H
#define	POLYPHASETEST_H

#include <cppunit/extensions/HelperMacros.h>

class polyphasetest : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE(polyphasetest);

	CPPUNIT_TEST(testMethod);
	CPPUNIT_TEST(testFailedMethod);

	CPPUNIT_TEST_SUITE_END();

public:
	polyphasetest();
	virtual ~polyphasetest();
	void setUp();
	void tearDown();

private:
	void testMethod();
	void testFailedMethod();
};

#endif	/* POLYPHASETEST_H */

