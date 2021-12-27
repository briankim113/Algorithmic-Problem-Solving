// Guy-Manuel and Thomas have an array a of n integers [a1,a2,…,an].
//In one step they can add 1 to any element of the array.
//Formally, in one step they can choose any integer index i (1≤i≤n) and do ai:=ai+1.

// If either the sum or the product of all elements in the array is equal to zero,
// Guy-Manuel and Thomas do not mind to do this operation one more time.

// What is the minimum number of steps they need to do to make
//both the sum and the product of all elements in the array different from zero?
//Formally, find the minimum number of steps to make a1+a2+ … +an≠0 and a1⋅a2⋅ … ⋅an≠0.

// INPUT
//Each test contains multiple test cases.
// The first line contains the number of test cases t (1≤t≤103). The description of the test cases follows.
// The first line of each test case contains an integer n (1≤n≤100) — the size of the array.
// The second line of each test case contains n integers a1,a2,…,an (−100≤ai≤100) — elements of the array .

// OUTPUT
//For each test case, output the minimum number of steps required
//to make both sum and product of all elements in the array different from zero.


// 4
// 3
// 2 -1 -1
// 4
// -1 0 0 1
// 2
// -1 2
// 3
// 0 -2 1

// 1
// 2
// 0
// 2

// In the first test case, the sum is 0.
// If we add 1 to the first element, the array will be [3,−1,−1],
// the sum will be equal to 1 and the product will be equal to 3.

// In the second test case, both product and sum are 0.
//If we add 1 to the second and the third element, the array will be [−1,1,1,1],
//the sum will be equal to 2 and the product will be equal to −1. It can be shown that fewer steps can't be enough.

// In the third test case, both sum and product are non-zero, we don't need to do anything.
// In the fourth test case, after adding 1 twice to the first element the array will be [2,−2,1], the sum will be 1 and the product will be −4.


// read the elements and keep track of sum
// if you encounter a 0, add 1 to the number of steps -> no more 0 as product

#include <iostream>
using namespace std;

int main(){
    int t; cin>>t;
    for (int n=0; n<t; n++){ //for all test cases
        int result=0, sum=0;
        int size; cin>>size;
        for (int i=0; i<size; i++){ //for all elements in each test case
            int curr; cin>>curr;
            if (curr==0){result++; sum++;}
            else sum+=curr;
        }
        if (sum==0) result++;
        cout<<result<<endl;
    }
    return 0;
}