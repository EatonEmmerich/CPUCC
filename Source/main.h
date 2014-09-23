#ifndef MAIN_H
#define	MAIN_H
#include "NOR.h"
#include "PolyphaseFilter.h"
#include "fft.h"
using namespace std;

class FileNotFoundException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "The file could not be read";
	}
};

// Function prototypes:
void Save_data(const string filename, vector <complex>& data);
int parse_arguments(int argc, std::string argv[]);
void print_parse_error(std::string err);
void print_readme();
bool is_valid_name(std::string in);
void checkformat(ifstream &file, unsigned int * axis1, unsigned int * axis2);
void getdata(vector<vector <double> >& Data, ifstream &myfile, unsigned int axis1, unsigned int axis2);
void Read_data(vector<vector <double> >& Data, const string filename);
std::string toString(complex in);
vector<complex> FDCorrelate(complex * A,complex * B, unsigned int N);

#endif /* MAIN_H */