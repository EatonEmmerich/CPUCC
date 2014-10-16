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
    vector<vector<double> > b;
    Read_data(b, "Resources/test.csv");
    vector<vector<complex> > a;
    copy_(a,b);
    bool right = true;
    if(a[0][0].re() != 5) right = false;
    if(a[0][1].re() != 20) right = false;
    if(a[0][2].re() != 10.0000095) right = false;
    CPPUNIT_ASSERT(right);
}

void mainclasstest::testSave_data() {
    vector<double> b(5);
    b[0] = 0;
    b[1] = 1;
    b[2] = 2;
    b[4] = 5.5;
    vector<complex> a;
    copy_(a,b);
    Save_data("Resources/test5.csv",a);
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
    Save_data("Resources/test5.csv",a);
    
    CPPUNIT_ASSERT(right);
}

void mainclasstest::testSave_dataim() {
    vector<complex> b(5);
    b[0] = complex (0,2);
    b[1] = complex(1,2);
    b[2] = complex(2,2);
    b[4] = complex(5.5,2.2);
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
    vector<vector<double> > b;
    Read_data(b, "Resources/test.csv");
    vector<vector<complex> > a;
    copy_(a,b);
    bool right = true;
    if(a[0][0].re() != 5) right = false;
    if(a[0][1].re() != 20) right = false;
    std::cout << "0,1";
    if(a[0][2].re() != 10.0000095) right = false;
    std::cout << "0,2";
    if(a[1][0].re() != 20) right = false;
    std::cout << "1,0";
    if(a[1][1].re() != 10.095) right = false;
    if(a[1][2].re() != 5) right = false;
    CPPUNIT_ASSERT(right);
}

void mainclasstest::testCorrelate() {
    vector<vector<double> > b;
    Read_data(b, "Resources/test.csv");
    vector<vector<complex> > a;
    copy_(a,b);
    vector<complex> a1 = a[0];
    vector<complex> a2 = a[1];
    vector<complex> answr;
    std::cout << "0.001";
    answr = FDCorrelate(&(a1[0]),&(a2[0]), 2048);
    CPPUNIT_ASSERT(true);
}
