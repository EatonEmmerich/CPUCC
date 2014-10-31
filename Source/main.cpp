#include "main.h"
using namespace std;

#define OPTIONSIZE 8
#define DEFAULT_THREADS 4
#define DEFAULT_BITS 16  //This is mere for display, will later on check to see how we can overcome this obstacle..
#define DEFAULT_WINDOW_SIZE 4096
#define DEFAULT_SIGS 20

const char * options[OPTIONSIZE] = {"/bitdepth", "/bd", "/windowsize", "/ws", "/numsig", "/ns", "/numthreads", "/nt"};

// program variables:
int numthreads = DEFAULT_THREADS;
int numbits = DEFAULT_BITS;
int numwindowssize = DEFAULT_WINDOW_SIZE;
int numsignals = DEFAULT_SIGS;
double convtoSec = 1000000;

//timing variables
int64 t_start;
int64 t_total;
double totaltime = 0;
int64 ppf_start;
int64 ppf_stop;
double totalppf = 0;
int64 fft_start;
int64 fft_stop;
double totalfft = 0;
int64 correlate_start;
int64 correlate_stop;
double totalcorrelate = 0;
int64 startcpyinputs;
int64 stopcpyinputs;
double totalcpy = 0;
int64 startcpyinputs2 = 0;
int64 stopcpyinputs2 = 0;


void executeCrossCorrelation(vector<double> prefilter,vector<vector<double> > Data){
    vector<double> pffout1;
    vector<double> pffout2;
    vector<complex> Output1;
    vector<complex> Output2;
        
    ppf_start = GetTimeMs64();
    cout << "\nPPF";
    ppf(pffout1,numwindowssize*2,prefilter,Data[0]);
    ppf(pffout2,numwindowssize*2,prefilter,Data[1]);
    ppf_stop = GetTimeMs64();
    //convert to complex type.
    startcpyinputs = GetTimeMs64();
    vector<complex> complexV1;
    copy_(complexV1,pffout1);
    vector<complex> complexV2;
    copy_(complexV2,pffout2);
    stopcpyinputs = GetTimeMs64();
    //complex type pointers.
    //**create threads for each fft**
    complex * fft1 = &(complexV1[0]);
    fft_start = GetTimeMs64();
    cout << "\nCFFT";
    CFFT::Forward(fft1,(numwindowssize));
    complex * fft2 = &(complexV2[0]);
    CFFT::Forward(fft2,(numwindowssize));
    fft_stop = GetTimeMs64();
    //multiply
    //**create threads for multiply**
    cout << "\nCorrelateStart";
    correlate_start = GetTimeMs64();
    Output1 = FDCorrelate(fft1,fft2,numwindowssize);
    Output2 = FDCorrelate(fft2,fft1,numwindowssize);
    correlate_stop = GetTimeMs64();
    Save_data("ProgramOutput1.csv",Output1);
    Save_data("ProgramOutput2.csv",Output2);
    t_total = GetTimeMs64();
    
    //Determine timing total
    totaltime += ((double)(t_total-t_start)/convtoSec);
    totalppf += ((double)(ppf_stop-ppf_start)/convtoSec);
    totalfft += ((double)(fft_stop-fft_start)/convtoSec);
    totalcorrelate += ((double)(correlate_stop-correlate_start)/convtoSec);
    totalcpy += ((double)(stopcpyinputs-startcpyinputs)/convtoSec);
}

int main(int argc, const char * argv[]) {

    //check input paramaters set into program.
    string *a = new string [argc];
    int M = 0;
    int step = 0;
    vector<vector<double> > Data;
    vector<double> prefilter;
    int64 ppfPref_start;
    int64 ppfPref_stop;
    
    
    for (int x = 0; x < argc; x++){
        a[x] = argv[x];
        
    }
    step = parse_arguments(argc, a);
    t_start = GetTimeMs64();
    //if all is fine. continue to data reading phase.
    if (step == 1) {
        string filename = argv[1];
        
        Read_data(Data, filename);
    }
    else{
        return -1;
    }
    
    
    cout << "\nnew prefilter";
    M = Data[0].size();
    ppfPref_start = GetTimeMs64();
    prefilter_window(prefilter,numwindowssize*2,M);
    ppfPref_stop = GetTimeMs64();
    
    //get instructions into cache:
    for(int x = 0; x < 5; x++){
        executeCrossCorrelation(prefilter,Data);
    }
    
    //Avg after 100 runs.
    totaltime = 0;
    totalppf = 0;
    totalfft = 0;
    totalcorrelate = 0;
    totalcpy = 0;
    int numit = 100;
    for(int x = 0; x < numit; x++){
        executeCrossCorrelation(prefilter,Data);
    }
    totaltime = totaltime/numit;
    totalppf = totalppf/numit;
    totalfft = totalfft/numit;
    totalcorrelate = totalcorrelate/numit;
    totalcpy = totalcpy/numit;
    //print timing results
    int64 totalflop = 0.00;
    cout << "\ntotal time to execute:                   " << NumberToString<double>(totaltime);
    double timet = ((double)(ppfPref_stop-ppfPref_start)/convtoSec);
    cout << "\ntotal time to calculate prefilter        " << NumberToString<double>(timet);
    
    cout << "\ntotal time to apply Polyphasefilter      " << NumberToString<double>(totalppf);
    
    cout << "\ntotal time to apply FFT                  " << NumberToString<double>(totalfft);
    
    cout << "\ntotal time to apply Correlation Process  " << NumberToString<double>(totalcorrelate);
    
    cout << "\ntotal time to copy in                    " << NumberToString<double>(totalcpy);
//    timet = ((double)(stopcpyinputs2-startcpyinputs2)/convtoSec);
//    cout << "\ntotal time to copy out                   " << NumberToString<double>(timet);

    cout << "\ntotal clicks                             " << NumberToString<double>(t_total-t_start);
    cout << "\nclocks per second                        " << NumberToString<double>(CLOCKS_PER_SEC);
    cout << "\n";

    //done, save output.
    
    
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
        return 1;
    } else {
        if (argc == 1) {
            print_readme();
            return 0;
        }
        cout<< NumberToString<int>(argc);
    }
    return 1;
    
}

void print_parse_error(std::string err) {
    cout << "Error parsing option \"" << err << "\"\n";
}



bool is_valid_name(std::string in) {
    for (int x = 0; x < OPTIONSIZE; x++) {
        if (in.compare(options[x]) == 0) {
            return true;
        }
    }
    return false;
}

void print_readme() {
    std::ifstream myfile;
    string line;
    try {
        myfile.open("Resources/ReadMe.txt", ios::in);
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                cout << line << '\n';
            }
        } else {
            //cout << "thaterror";
            throw FileNotFoundException();
        }
    } catch (exception& e) {
        cout << e.what() << "\nPlease contact the author.\n";
    }
    myfile.close();
}

void getdata(vector<vector<double> >& Data, ifstream &myfile, unsigned int axis1, unsigned int axis2) {
    string line;
    Data.resize(axis1,vector<double>(axis2, 0.00));   //maybe make this rather a double vector? YES!
    int i = 0;
    int j = 0;
    stringstream lineStream;
    while (getline(myfile, line)) {
        lineStream << line;
        string ex2;
        while (getline(lineStream, ex2, ',')) {
            double temp = StringToNumber<double>(ex2);
            Data[i][j] = temp;
            j++;
            
        }
        j = 0;
        i++;
        lineStream.str("");
        lineStream.clear();
    }
}

bool checkaxis2(stringstream &lineStream, unsigned int * axis2) {
    string line;
    vector<string> result;
    string cell;
    while (getline(lineStream, cell, ',')) {
        result.push_back(cell);
    }
    if ((*axis2) != result.size()) {
        return false;
    }
    return true;
}

void checkformat(ifstream &file, unsigned int * axis1, unsigned int * axis2) {
    // first line axis2 should be equal throughout the file.
    // comma separated file.
    vector<string> result;
    string line;
    getline(file, line);
    stringstream lineStream(line);
    string cell;
    while (getline(lineStream, cell, ',')) {
        result.push_back(cell);
    }
    *axis2 = result.size();
    (*axis1)++;
    while (getline(file, line)) {
        stringstream lineStream(line);
        if (checkaxis2(lineStream, axis2)) {
            (*axis1)++;
        } else {
            //not same sizes.
            cout << "Error at line number:" << ((*axis1) + 1) << "\n";
            throw NotSameLengthException();
        }
    }

}

void Read_data(vector<vector<double> >& Data,const string filename) {
    unsigned int axis1 = 0;
    unsigned int axis2 = 0;
    std::ifstream myfile;
    try {
        myfile.open(filename.c_str(), ios::in);
        if (myfile.is_open()) {
            checkformat(myfile, &axis1, &axis2);
            myfile.close();
            myfile.open(filename.c_str(), ios::in);
            getdata(Data, myfile, axis1, axis2);
            myfile.close();
        } else {
            throw FileNotFoundException();
        }
    } catch (exception& e) {
        cout << e.what() << "\nPlease contact the author.";
    }
}

void Save_data(const string filename, vector <complex>& data){
    std::fstream myfile;
    try {
        myfile.open(filename.c_str(),ios::out);
        if (myfile.is_open()){
            for(unsigned int x = 0; x < data.size()-1; x++){
                myfile << toString((data[x])) + ",";
            }
            myfile << toString((data[(data.size()-1)]));
            myfile.close();
        }
    } catch (exception& e) {
        cout << e.what() << "\nPlease contact the author.";
    }
}

std::string toString(complex in){
    std::string out = "";
    out = out + NumberToString<double>(in.re()) + " " + NumberToString<double>(in.im()) + "i";
    return out;
}
	
std::string toStringVect(complex in){
    std::string out = "";
    double amp = sqrt((in.re()*in.re())+(in.im()*in.im()));
    double angle = atan(in.im()/in.re());
    out = out + NumberToString<double>(amp) + "e^-i" + NumberToString<double>(angle);
    return out;
}

vector<complex> FDCorrelate(complex * A,complex * B, unsigned int N){
    vector<complex> output(N,complex());
    for(int x = 0; x < N; x++){
        output[x] = A[x] * (B[x].conjugate());
    }
    return output;
}
