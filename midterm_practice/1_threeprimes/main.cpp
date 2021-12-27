#include <iostream>
using namespace std;

//oneprimes = primes last digit 1
//twoprimes = digit 2
//threeprimes =...

//input 1<=N<=20000000 (20 mil)
//output number of threeprimes smaller than N

int main(){
    int n; cin>>n;
    int result = 0;

    if (n>=3) {
        // Sieve Of Eratosthenes
        bool* prime = new bool[n+1];
        fill_n(prime, n+1, true);

        prime[0] = false; prime[1] = false; //these two are not
    
        for (int p=2; p*p < n+1; p++) {
            if (prime[p] == true){ //this is definitely prime
                for (int i=p*2; i < n+1; i+=p) //update all multiples of p
                    prime[i] = false; //this is not prime
            }
        }

        //check every 10 numbers for ones to be 1
        for (int i=3; i<=n; i+=10){
            if (prime[i]) result++;
        }

        delete [] prime;
    }

    cout<<result<<endl;
    return 0;
}