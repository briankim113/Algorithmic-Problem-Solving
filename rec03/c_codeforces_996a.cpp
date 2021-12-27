//n dollars in the bank, he wants to withdraw it in cash
//denominations for dollar bills are 1, 5, 10, 20, 100
//What is the minimum number of bills Allen could receive after withdrawing his entire balance?

//The first and only line of input contains a single integer n (1≤n≤10^9).

//ex 1
//125 -> 3 (100, 20, 5)

//ex 2
//43 -> 5 (20, 20, 1, 1, 1)

//ex 3
//1000000000
//10000000

#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int count = 0;

    while (n>0) {
        if (n>=100) {
            count += n/100;
            n -= 100*(n/100);
        }
        else if (n>=20) {
            count += n/20;
            n -= 20*(n/20);
        }
        else if (n>=10) {
            count += n/10;
            n -= 10*(n/10);
        }
        else if (n>=5) {
            count += n/5;
            n -= 5*(n/5);
        }
        else {
            count += n;
            n -= n;
        }
    }

    cout<<count;

    return 0;
}