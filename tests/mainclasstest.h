/*
 * File:   mainclasstest.h
 * Author: eaton
 *
 * Created on Sep 17, 2014, 5:19:58 PM
 */

#ifndef MAINCLASSTEST_H
#define	MAINCLASSTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Source/NOR.h"
#include "../Source/main.h"

class mainclasstest : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE(mainclasstest);

	CPPUNIT_TEST(testRead_data);
	CPPUNIT_TEST(testSave_data);
	CPPUNIT_TEST(testSave_dataim);
	CPPUNIT_TEST(testRead_data2dim);
	CPPUNIT_TEST(testCorrelate);
	
	CPPUNIT_TEST_SUITE_END();

public:
	mainclasstest();
	virtual ~mainclasstest();
	void setUp();
	void tearDown();

private:
	void testRead_data();
	void testSave_data();
	void testSave_dataim();
	void testRead_data2dim();
	void testCorrelate();
};

#endif	/* MAINCLASSTEST_H */

