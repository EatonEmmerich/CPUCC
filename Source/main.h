#ifndef MAIN_H
#define	MAIN_H
#include "NOR.h"
#include <math.h>
using namespace std;

class FileNotFoundException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "The file could not be read";
	}
};

// Function prototypes:
void Save_data(const string filename, SingleVector data);
int parse_arguments(int argc, std::string argv[]);
void print_parse_error(std::string err);
void print_readme();
bool is_valid_name(std::string in);
void checkformat(ifstream &file, unsigned int * axis1, unsigned int * axis2);
DoubleVector * getdata(ifstream &myfile, unsigned int axis1, unsigned int axis2);
DoubleVector * Read_data(const string filename);
std::string toString(complex in);

#endif /* MAIN_H */