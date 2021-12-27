#include <iostream>
using namespace std;

//fib1 = 0, fib2 = 1, fib3 = 1, fib4 = 2, fib5 = 3, add the previous two terms
//input = N for the Nth fibonacci term
//output = value
// e.g. 1 -> 0, 4 -> 2

//memoization
unsigned long long fib(int n){ // int will overflow
    unsigned long long f[n+1]; //since we start with 1 and not 0
    f[1]=0; f[2]=1;
 
    //fill the array with the values up to nth term
    for(int i=3; i<=n; i++){
       f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}