/*
 * File:   mainclasstest.cpp
 * Author: eaton
 *
 * Created on Sep 17, 2014, 5:19:58 PM
 */

#include "mainclasstest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(mainclasstest);

mainclasstest::mainclasstest() {
}

mainclasstest::~mainclasstest() {
}

void mainclasstest::setUp() {
    
}

void mainclasstest::tearDown() {
}

void mainclasstest::testRead_data() {
    SingleVector * a = Read_data("Resources/test.csv");
    bool right = true;
    if(a[0].getEntry(0).re() != 5) right = false;
    if(a[0].getEntry(1).re() != 20) right = false;
    if(a[0].getEntry(2).re() != 10.0000095) right = false;
    CPPUNIT_ASSERT(right);
}

void mainclasstest::testSave_data() {
    SingleVector b = SingleVector(5);
    b.setEntry(0,0);
    b.setEntry(1,1);
    b.setEntry(2,2);
    b.setEntry(5.5,4);
    Save_data("Resources/test5.csv",b);
    std::fstream myfile;
    bool right = true;
    std::string line;
    std::string test23 = "0 0i,1 0i,2 0i,0 0i,5.5 0i";
    try{
        myfile.open("Resources/test5.csv", ios::in);

        getline(myfile, line);
        myfile.close();
    }
    catch(exception e){
        
    }
    if (line!=test23) right = false;
    Save_data("Resources/test5.csv",b);
    
    CPPUNIT_ASSERT(right);
}

void mainclasstest::testSave_dataim() {
    SingleVector b = SingleVector(5);
    b.setEntry(0,2,0);
    b.setEntry(1,2,1);
    b.setEntry(2,2,2);
    b.setEntry(5.5,2.2,4);
    Save_data("Resources/test57.csv",b);
    std::string filename = "Resources/test57.csv";
    std::fstream myfiles(filename.c_str(),ios::in);
    bool right = true;
    std::string line = " ";
    std::string test23 = "0 2i,1 2i,2 2i,0 0i,5.5 2.2i";
    getline(myfiles, line);
    myfiles.close();
    
    if (line != test23) right = false;
    
    CPPUNIT_ASSERT(right);
}

void mainclasstest::testRead_data2dim() {
    cout << "isrun";
    SingleVector * a = Read_data("Resources/test.csv");
    cout << "linex";
    bool right = true;
    //if(a[0].getEntry(0).re() != 5) right = false;
    //if(a[0].getEntry(1).re() != 20) right = false;
    //if(a[0].getEntry(2).re() != 10.0000095) right = false;
    //if(a[1].getEntry(0).re() != 20) right = false;
    //if(a[1].getEntry(1).re() != 10.095) right = false;
    //if(a[1].getEntry(2).re() != 5) right = false;
    CPPUNIT_ASSERT(right);
}
