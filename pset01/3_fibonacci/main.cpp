#include <iostream>
using namespace std;

//fib1 = 1, fib2 = 1, fib3 = 2, fib4 = 3, fib5 = 5, add the previous two terms
//input = N for the Nth fibonacci term
//output = value
// e.g. 1 -> 1, 4 -> 3

int fib(int n){
    if (n == 1 || n == 2) return 1;
    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}