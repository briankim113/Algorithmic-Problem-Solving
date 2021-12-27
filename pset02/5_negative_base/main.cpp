//input: number in base-10, -1 billion <= N <= 1 billion
//output: corresponding number in base-(-2) with no leading zeros

//base-(-2) works like:
//n = b_0 + b_1*(-2) + b+2*(-2)^2 + b_3*(-2)^3 + ...

//1 -> 1
//-2 -> 10 (0 + -2)
//7 -> 11011 (1 + -2 + 0 + -8 + 16)
//0 -> 0

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int left; cin>>left;
    int b = -2;
    string res = "";

    if (left == 0){ cout<<0; return 0; }
    while (left != 0){
        int r = left % b; // remainder -1, 0, or 1
        left /= b; // calculate what's left
        if (r == -1) left++; // to balance out the floor issue from modulo -> https://torstencurdt.com/tech/posts/modulo-of-negative-numbers/
        res = to_string(abs(r)) + res;
    }
    cout<<res;

    return 0;
}