#include "NOR.h"
using namespace std;

#define OPTIONSIZE 8
#define DEFAULT_THREADS 2
#define DEFAULT_BITS 16
#define DEFAULT_WINDOW_SIZE 16
#define DEFAULT_SIGS 20

const char * options[OPTIONSIZE] = {"/bitdepth", "/bd", "/windowsize", "/ws", "/numsig", "/ns", "/numthreads", "/nt"};



class NotSameLengthException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "The file vectors are not all the same length.";
  }
};

// Function prototypes:
int parse_arguments(int argc, std::string argv[]);
void print_parse_error(std::string err);
void print_readme();
bool is_valid_name(std::string in);
template <typename T>
T StringToNumber(const string &in);
DoubleVector * Read_data(string filename);

// program variables:
int numthreads = DEFAULT_THREADS;
int numbits = DEFAULT_BITS;
int numwindowssize = DEFAULT_WINDOW_SIZE;
int numsignals = DEFAULT_SIGS;






int main(int argc, const char * argv[]) {
	std::string * argv2 = new std::string[argc];
	for (int x = 0; x < argc; x++) {
		argv2[x] = argv[x];
	}

	int step = parse_arguments(argc, argv2);
	if (step == 1) {
		string filename = argv[1];
		DoubleVector * Data = Read_data(filename);
		string output = Data->printData();
	}

	return 0;
}


int parse_arguments(int argc, std::string argv[]) {
	/*
	 * Help file will be in Readme.txt
	 */
	//verify length
	if (((argc - 1) % 2 == 0)&&(argc > 2)) {
		//verify optionnames
		for (int x = 1; x < argc; x = x + 2) {
			std::string in = argv[x];
			std::transform(in.begin(), in.end(), in.begin(),
					bind2nd(ptr_fun(&tolower<char>), std::locale("")));
			if (!is_valid_name(in)) {
				print_parse_error(argv[x]);
				print_readme();
				return 0;
			}
			if ((in.compare(options[0]) == 0) || (in.compare(options[1]) == 0)) {
				numbits = StringToNumber<int>(argv[x + 1]);
				continue;
			}
			if ((in.compare(options[2]) == 0) || (in.compare(options[3]) == 0)) {
				numwindowssize = StringToNumber<int>(argv[x + 1]);
				continue;
			}
			if ((in.compare(options[4]) == 0) || (in.compare(options[5]) == 0)) {
				numsignals = StringToNumber<int>(argv[x + 1]);
				continue;
			}
			if ((in.compare(options[6]) == 0) || (in.compare(options[7]) == 0)) {
				numthreads = StringToNumber<int>(argv[x + 1]);
				continue;
			}
			throw "No option handler exception";
		}
	} else {
		if (argc == 1) {
			print_readme();
			return 0;
		}
	}
	return 1;
}

void print_parse_error(std::string err) {
	cout << "Error parsing option \"" << err << "\"\n";
}

template <typename T>
T StringToNumber(const string &in) {
	stringstream ss(in);
	T result;
	return ss >> result ? result : 0;
}

bool is_valid_name(std::string in) {
	for (int x = 0; x < OPTIONSIZE; x++) {
		if (in.compare(options[x]) == 0) {
			return true;
		}
	}
	return false;
}

void print_readme(){
	std::ifstream myfile;
	string line;
	try {
		myfile.open("readme.txt", ios::in);
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				cout << line << '\n';
			}
		} else {
			throw std::exception();
		}
	}	catch (std::exception e) {
		cout << e.what() << "\nPlease contact the author.";
	}
}


DoubleVector * getdata(ifstream &myfile,unsigned int axis1,unsigned int axis2){
	string line;
	DoubleVector * result= new DoubleVector(axis1,axis2);
	int i = 0;
	int j = 0;
	
	while (getline(myfile,line)){
		stringstream lineStream(line);
		string ex2;
		while (getline(lineStream,ex2,',')){
			result->data[i][j] = StringToNumber<short>(ex2);
			j++;
		}
		j = 0;
		i++;
	}
	return result;
}


bool checkaxis2(ifstream &file, unsigned int * axis2){
	string line;
	vector<string> result;
	getline(file,line);
	stringstream lineStream(line);
	string cell;
	while(getline(lineStream,cell,','))
	{
		result.push_back(cell);
	}
	if (*axis2 != result.size()){
		return false;
	}
	return true;
}



void checkformat(ifstream &file,unsigned int * axis1,unsigned int * axis2){
	// first line axis2 should be equal throughout the file.
	// comma separated file.
	vector<string> result;
    string line;
    getline(file,line);
	stringstream lineStream(line);
	string cell;
	while(getline(lineStream,cell,','))
	{
		//result.push_back(cell);
	}
	*axis2 = result.size();
	*axis1 ++;
	while(getline(file,line)){
		stringstream lineStream(line);
		if(checkaxis2(file,axis2)){
			(*axis1) ++;
		}
		else{
			//not same sizes.
			cout << "Error at line number:" << ((*axis1)+1);
			throw NotSameLengthException();
		}
	}
	
}


DoubleVector * Read_data(const string filename) {
	DoubleVector * output;
	unsigned int axis1 = 0;
	unsigned int axis2 = 0;
	std::ifstream myfile;
	string line;
	try {
		myfile.open(filename.c_str(), ios::in);
		if (myfile.is_open()) {
			checkformat(myfile ,&axis1,&axis2);
			myfile.seekg(0,myfile.beg);
			output = getdata(myfile,axis1, axis2);
		} else {
			throw std::exception();
		}
	}	catch (std::exception e) {
		cout << e.what() << "\nPlease contact the author.";
	}
	return output;
}