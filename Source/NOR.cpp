#include "NOR.h"

void copy_(std::vector<complex>& out,std::vector<double>& in){
    out.resize(in.size());
    std::copy(in.begin(),in.end(),out.begin());
}

void copy_(std::vector<std::vector<complex> >& out,std::vector<std::vector<double> >& in){
    out.resize(in.size());
    std::vector<std::vector<double> >::iterator it = in.begin();
    std::vector<std::vector<complex> >::iterator itout = out.begin();
    while(it != in.end()){
        itout->resize(it->size());
        std::copy(it->begin(),it->end(),itout->begin());
        ++it;
        ++itout;
    }
}