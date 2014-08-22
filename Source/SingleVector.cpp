/*
 *
 *
 *
 */


#include "SingleVector.h"

std::string SingleVector::printData(){
    std::string out = "";
    for (unsigned int x = 0; x < length;x ++){
        std::ostringstream convert;
        convert << ((data[x])).re() << " + " << ((data[x])).im() << "j";
        out = out + convert.str() + " ";
    }
    return out;
}
/*
 * 
 */


complex SingleVector::getEntry(unsigned int i){
    return data[i];
}

void SingleVector::setEntry(complex in, unsigned int i){
    data[i] = in;
}

void SingleVector::setEntry(double in, unsigned int i){
    complex d = complex(in);
    data[i] = d;
}

void SingleVector::setEntry(double re, double im, unsigned int i){
    complex d = complex(re,im);
    data[i] = d;
}