#include <SSPInstanceGenerator.h>


void SSPInstanceGenerator::generate(long size, std::vector< long> &input,  long &value) {
    input.resize(size,0);
    if ((_alg == "RAND") || (_alg == "RAND*"))
            fillRAND(size,input,value);
    else if (_alg[0] == 'P') {
            assert(isdigit(_alg[1]) && "the instance generator name must have the format P<digit> example: P3");
            fillP((_alg[1]-'0'),size,input,value); }
    else if ((_alg == "EVOD") || (_alg == "EVOD*"))
            fillEvenOdd(size,input,value);
    else if ((_alg == "TODD") || (_alg == "TODD*"))
            fillTodd(size,input,value);
    else if ((_alg == "AVIS") || (_alg == "AVIS*"))
            fillAvis(size,input,value);
    else
            assert(false && "SSP called with invalid algorithm name");
    
    SortAndCutXAboveCapacity(input,value);
    
    if (_alg.back() == '*' ) // last char * means it will change the value to have a solution
        forceSolution(size,input,value);
    
}// generate

/// changes value to force the instance to have a solution
/// generates a random vector and a threshold, so that each element of input may be summed into the new value
void SSPInstanceGenerator::forceSolution(long size, std::vector<long> &input,  long &value, bool verbose) {
    //#include <random> #include <algorithm> #include <iterator> #include <iostream>
    
    //// CAKE RECIPE TO RANDOM GENERATOR
    // First create an instance of an engine.
    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    std::uniform_real_distribution<> dist(0.1, 0.9);
    
    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };
    /////// END OF CAKE RECIPE
    std::vector<float> rvec(input.size());
    std::generate(begin(rvec), end(rvec), gen); //RANDOM VECTOR
    float threshold = gen(); // RANDOM THRESHOLD
    
    
    long newvalue = 0; int idx = 0;
    // each element of input may be added to value
    for ( idx = 0; idx < input.size() ; idx++ ) {
        if (rvec[idx] > threshold) newvalue += input[idx];
    }//for
    if (newvalue < 0.1f ) newvalue = input[0]; // I do not want zero capacity.  
    value = newvalue;
    
    if (verbose) { // debug: printout all stuff
        std::stringstream ss;
        streamSSP(ss,input,value);
        for ( idx = 0; idx < input.size() ; idx++ ) { // change rvec to binary showing if element was added
            if (rvec[idx] > threshold) rvec[idx] = 1; else rvec[idx] = 0;;
        }//for
        // print threshold and show wich elements were added
        ss << "thr: " << threshold << " rvec [" ;
        for (float ff : rvec ) ss << " " << ff; 
        ss << " ]"<< std::endl;
        std::cout << ss.str();
    }//verbose
}//forceSolution


void SSPInstanceGenerator::fillRAND(long size, std::vector< long> &input,  long &value) {
    unsigned long int i, k, st = 0, ed = 5, inc;
    std::uniform_int_distribution<long> distrib(1, 1e10);
    for (i = 0; i < input.size() ; i++) {
        input[i] = (distrib(_gen) % (ed + 1 - st) + st) + 1;
        st += 6;
        ed = st + 5;
    }
    value = (input[input.size()-1] + input[input.size()-1]/3 )  ; // value is third above of the largest value in input
}//fillrand


void SSPInstanceGenerator::fillP(int order, long size, std::vector< long> &input,  long &value) {
     long i, k, st = 0, ed = 5, inc;
     long tenpower = std::pow(10,order);
    inc = (tenpower + input.size() - 1) / ( long)input.size();
    std::uniform_int_distribution<long> distrib(1, tenpower);
    //std::cerr << " \n inc " << inc << "  tp: " << tenpower;
    
    //st = 1, ed = inc;
    for (i = 0; i < input.size(); i++) {
        input[i] = distrib(_gen);
        //input[i] = (random() % (ed + 1 - st) + st);
        //st += inc + 1;
        //ed = st + inc;
    }//for
    
    value = input.size() * (tenpower / 4);
}//fillP

void SSPInstanceGenerator::fillEvenOdd(long size, std::vector< long> &input,  long &value) {
    long i, k, st = 0, ed = 5, inc;
    int arrSize = input.size();
    inc = (1e3 + arrSize - 1) / arrSize;
	//st = 1, ed = inc;
    std::uniform_int_distribution<long> distrib(1, 1000);
	for (i = 0; i < arrSize; i++) {
        input[i] = distrib(_gen);
        //input[i] = ((st / 2) + random() % ((ed - st + 2) / 2)) * 2;
		//st += inc + 1;
		//ed = st + inc;
    }//for
    value = (input.size() * (1000 / 4)) + 1;
}//fillEvenOdd

void SSPInstanceGenerator::fillTodd(long size, std::vector< long> &input,  long &value) {
    long i, k, st = 0, ed = 5, inc;
    int arrSize = input.size();
    k = floor(log2(arrSize));
	for (i = 0; i < arrSize; i++) {
		input[i] = std::pow(2, k + arrSize + 1) + std::pow(2, k + i) + 1;
	}//for
	
    value = (input.size() + 1) * std::pow(2, k + input.size()) - std::pow(2, k) + floor(input.size() / 2);
}//fillTodd

void SSPInstanceGenerator::fillAvis(long size, std::vector< long> &input,  long &value) {
    long i, k, st = 0, ed = 5, inc;
    int arrSize = input.size();

    for (i = 0; i < arrSize; i++) {
			input[i] = arrSize * (arrSize + 1) + i;
	}
	value =  floor((input.size() - 1) / 2) * input.size() * (input.size() + 1)
				+ (fatorial(input.size()) / (fatorial(2) * fatorial(input.size() - 2)));
}

		
/////////// AUXILIARY FUNCTIONS ///////////

void SortAndCutXAboveCapacity(std::vector< long> &input, const  long &value) {
    std::sort(input.begin(), input.end());
    bool cut = false;
     long i;
    for ( i = 0 ; i < input.size() ; i++)
        if (input[i] > value) { cut = true; break; }
    if (cut) {
        input.resize(i-1);
    }
}//cutXAboveCapacity

void streamSSP(std::ostream &os, const std::vector< long> &input, const  long &value) {
    os << std::endl << "INP("<< input.size() << ") [ " ;
    for (int i : input) 
        os << i << " " ;
    os << "] "<< std::endl <<  "val: " << value << std::endl ;
}//streamSSP


// version that includes solution
void streamSSP(std::ostream &os, const std::vector< long> &input,const  long &value,      
               const std::vector<char> &x) {
    streamSSP(os,input,value);
    os << "ans: [ " ;
    long sumsol = 0;
    for (int i=0; i < x.size(); i++) {
        if (x[i]) os << i; else os << '.'; 
        os << " " ;
        if (x[i]) sumsol+=input[i];
    }//for
    os << "] "<< std::endl <<  "sum: " << sumsol << std::endl ;
}//streamSSP

double fatorial(int n) {
    //https://en.cppreference.com/w/cpp/numeric/math/tgamma
    return std::tgamma((double)n+1); // this is factorial
}


