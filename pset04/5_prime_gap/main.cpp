// resubmitted to delete unnecessary comments and add helpful ones
// algorithm discussed with Lauren Gatesman (Java) and consulted the following:
    // https://en.wikipedia.org/wiki/Prime_gap 
    // https://www.geeksforgeeks.org/segmented-sieve-print-primes-in-a-range/

#include <iostream>
#include <vector>
#include <math.h> //sqrt
using namespace std;

vector<int> rangePrimes; //primes = vector of prime ints within range

// fillPrime function fills primes from 2 to sqrt(high) in vector p
// same as a regular Sieve logic, except we limit it to sqrt(high)
void fillPrimes(vector<int>& p, int high){
    //is int n in range 2 to sqrt(high) a prime?
    int sqrtHigh = sqrt(high);
    bool* ck = new bool[sqrtHigh+1];
    fill_n(ck, sqrtHigh+1, true);
    ck[1] = false; ck[0] = false;

    for (int i=2; i <= sqrtHigh; i++) {
        if (ck[i] == true) {
            for (int j = i*i; j <= sqrtHigh; j+=i) ck[j] = false;
        }
    }

    //push all the marked primes into vector p
    for (int i = 2; i <= sqrtHigh; i++) {
        if (ck[i] == true) p.push_back(i);
    }
}

// segmentedSieve function 
void segmentedSieve(int low, int high){
    //first uses fillPrimes function to create an allPrimes vector up to sqrt(high)
    bool* mark = new bool[high-low+1];
    fill_n(mark, high-low+1, true);

    vector<int> allPrimes;
    fillPrimes(allPrimes, high);

    //then uses allPrimes and get their multiples to get the primes in range low to high
    for (int i : allPrimes) {
        int lower = (low / i);
        if (lower <= 1)     lower = i+i;                //if low <= primeOfInterest
        else if (low % i)   lower = (lower * i) + i;
        else                lower = (lower * i);        //low % primeOfInterest == 0
        
        for (int j=lower; (j >= 0) && (j <= high); j+=i) { //j >= 0 included to account for overflow
            mark[j-low] = false; //not prime because it is a multiple of a prime
        }
    }
   
    for (int i = low; (i >= 0) && (i <= high); i++) { //i >= 0 included to account for overflow
        if (mark[i-low]) {
            rangePrimes.push_back(i); //these are all the primes in range low to high
        }
    }
}


int main(){
    int a, b; cin>>a>>b; if (a<2) a=2;
    segmentedSieve(a, b);

    //if we don't even have 2 primes to get the gap, then we are done
    if (rangePrimes.size()<2) cout<<"-1"<<endl;

    else {
        //check for min and max gap value
        int min = INT32_MAX, max = INT32_MIN;
        pair<int, int> minPair, maxPair;
        for (int i=0; i<rangePrimes.size()-1; i++){
            int curr = rangePrimes[i];
            int next = rangePrimes[i+1];
            if (next-curr < min){
                minPair.first = curr;
                minPair.second = next;
                min = next-curr;
            }
            if (next-curr > max){
                maxPair.first = curr;
                maxPair.second = next;
                max = next-curr;
            }
        }
        cout<<minPair.first<<" "<<minPair.second<<" "<<maxPair.first<<" "<<maxPair.second<<endl;
    }

    return 0;
}