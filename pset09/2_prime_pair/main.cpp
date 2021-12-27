/*
A prime pair is a pair of the form (p, p + 2) where p and (p + 2) are both prime. The first few prime pairs are (3, 5), (5, 7), (11, 13).
In this problem, you are given an integer N and you should find the N’th prime pair.

The input will contain a single integer N (1 <= N <= 100,000).

The output should be a single line, the N’th prime pair formatted as (p1, p2) (there is a space after the comma).
It is guaranteed that primes in the 100,000th prime pair are less than 20,000,000.
*/

#include <iostream>
#include <vector>
#include <math.h> //sqrt
#define LOW 2
#define HIGH 20000000
using namespace std;

// adapted from pset4 prime gap problem

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
void segmentedSieve(){
    //first uses fillPrimes function to create an allPrimes vector up to sqrt(high)
    bool* mark = new bool[HIGH-LOW+1];
    fill_n(mark, HIGH-LOW+1, true);

    vector<int> allPrimes;
    fillPrimes(allPrimes, HIGH);

    //then uses allPrimes and get their multiples to get the primes in range low to high
    for (int i : allPrimes) {
        int lower = (LOW / i);
        if (lower <= 1)     lower = i+i;                //if low <= primeOfInterest
        else if (LOW % i)   lower = (lower * i) + i;
        else                lower = (lower * i);        //low % primeOfInterest == 0
        
        for (int j=lower; (j >= 0) && (j <= HIGH); j+=i) { //j >= 0 included to account for overflow
            mark[j-LOW] = false; //not prime because it is a multiple of a prime
        }
    }
   
    for (int i = LOW; (i >= 0) && (i <= HIGH); i++) { //i >= 0 included to account for overflow
        if (mark[i-LOW]) {
            rangePrimes.push_back(i); //these are all the primes in range low to high
        }
    }
}

int main(){
    segmentedSieve();
    // cout<<rangePrimes[0]<<endl;
    // for (int i : rangePrimes) cout<<i<<'\t';

    int n; cin>>n;
    int i=0;
    int idx=0;
    int first, second;
    while (i != n) {
        // cout<<idx<<endl;
        first = rangePrimes[idx++];
        // cout<<idx<<endl;
        second = rangePrimes[idx];
        if (second - first == 2) {
            i++;
        }
    }
    cout<<'('<<first<<", "<<second<<")\n";

    return 0;
}