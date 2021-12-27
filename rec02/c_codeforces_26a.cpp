// A number is called almost prime if it has exactly two distinct prime divisors.
// For example, numbers 6, 18, 24 are almost prime, while 4, 8, 9, 42 are not.
// Find the amount of almost prime numbers which are between 1 and n, inclusive.

// input: one integer number n (1 ≤ n ≤ 3000).
// output: output the amount of almost prime numbers between 1 and n, inclusive.

// 6 (2,3)
// 10 (2,5)
// 12 (2,3)
// 14 (2,7)
// 15 (3,5)
// 18 (2,3)
// 20 (2,5)
// 21 (3,7)

// 10 -> 2
// 21 -> 8

// i = 1...n, check whether each i is almost prime

#include <iostream>
using namespace std;

int main(){
    // Sieve Of Eratosthenes
    bool prime[3001];
    fill(begin(prime), end(prime), true); //everything is probably prime for now
    prime[0] = false; prime[1] = false; //these two are not
 
    for (int p = 2; p*p < 3001; p++) {
        if (prime[p] == true){ //this is definitely prime
            for (int i = p*2; i < 3001; i+=p) //update all multiples of p
                prime[i] = false; //this is not prime
        }
    }

    int n; cin>>n;

    int res = 0;
    for (int i=6; i<=n; i++) { //start at 6 - smallest almost-prime
        int count = 0; //num of prime factors
        for (int j=2; j * j<=i; j++) { //start at 2 - smallest prime
            if (i % j == 0) { //j is a factor of i
                if (j*j == i) { //j is a sqrt of i
                    if (prime[j]) count++; //only one factor to count up
                }
                else { //j is not a sqrt of i
                    if (prime[j]) count++; //potentially two factors to count up
                    if (prime[i/j]) count++;
                }
            }
        }
        // if i is almost prime number
        if (count == 2) res++;
    }

    cout<<res;
    return 0;
}