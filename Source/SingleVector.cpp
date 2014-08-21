/*
 *
 *
 *
 */


#include "SingleVector.h"

std::string SingleVector::printData(){
    
}

SingleVector::~SingleVector(){
    
}

SingleVector::SingleVector(unsigned int length) {
    this->length = length;
    data = new complex * [length];
}


