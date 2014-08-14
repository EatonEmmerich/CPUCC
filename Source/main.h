#ifndef MAIN_H
#define	MAIN_H
#include "DoubleVector.h"
#include "NOR.h"

class FileNotFoundException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "The file could not be read";
	}
};

#endif /* MAIN_H */