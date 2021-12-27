//a number is awesome if it is prime and has 1 in its ones place
//in: 1 <= N <= 20,000,000
//out: one line (no endl) containing a single integer, the number of awesome numbers that are not larger than N

//so can we do a variation of Sieve of Eratosthenes for just the numbers that end with 1 up to N?
//This needs to be done efficiently, otherwise some cases will time out.

//11, 31, 41, 61, 71 - 5
//101, 131, 151, 181, 191 - 10
//211, 241, 251, 271, 281 - 15
//311, 331 - 17
//401, 421, 431, 451, 491 - 22
//521, 541, 571 - 25
//601, 631, 641, 661, 691 - 30
//701, 751, 761 - 33
//811, 821, 881 - 36
//911, 941, 971, 991 - 40
//1021, 1031, 1051, 1061, 1091 - 45


//example 1
//6 -> 0

//example 2
//11 -> 1 (11)

//ex 3
//100 -> 5 (11, 31, 41, 61, 71)
    // for this, we don't need to check 12, 13, 14 if they are prime!
    // just skip to 11, 21, 31, 41, 51, 61, 71, 81, 91 and check these 10

//ex 4
//1 -> 0

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    int result = 0;

    if (n>=11) {
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
        for (int i=11; i<=n; i+=10){
            if (prime[i]) result++;
        }

        delete [] prime;
    }

    cout<<result<<endl;

    return 0;
}