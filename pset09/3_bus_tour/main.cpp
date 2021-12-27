/*
GREEDY

Resubmitted to clean up code and comments

If more than one segment is equally maximally nice, choose the one with the longest bus ride (largest number of stops, j - i).
To break ties further in longest maximal segments, choose the segment that begins with the earliest stop (lowest i).

Discussed with Lauren Gatesman
Consulted https://www.geeksforgeeks.org/size-subarray-maximum-sum/

Input
3
-2
5
Output
The nicest part of Y1 is between stops 2 and 3

Input
5
-2
5
-3
5
Output
The nicest part of Y1 is between stops 2 and 5

Input
5
-2
5
5
-3
Output
The nicest part of Y1 is between stops 2 and 4

Input
4
-1
-1
-1
Output
Yet another overrated tourist destination

MY TEST CASES

Input
5
2
-3
1
1
Output
The nicest part of Y1 is between stops 3 and 5

Input
4
2
-1
1
Output
The nicest part of Y1 is between stops 1 and 4

Input
6
1
1
-3
1
1
Output
The nicest part of Y1 is between stops 1 and 3

Input
4
2
-2
2
Output
The nicest part of Y1 is between stops 1 and 4

CRAIG'S TEST CASES

7
100
5
3
-100
-7
107
The nicest part of Y1 is between stops 1 and 7

7
100
5
3
-100
-8
107
The nicest part of Y1 is between stops 1 and 4

7
100
5
3
-100
-9
109
The nicest part of Y1 is between stops 6 and 7

DEKUN'S TEST CASES

5
8
-19
5
-4
The nicest part of Y1 is between stops 1 and 2

6
8
-19
5
-4
20
The nicest part of Y1 is between stops 3 and 6
3 and 7

6
5
4
-1
7
8
The nicest part of Y1 is between stops 1 and 6

10
-2
1
-3
4
-1
2
1
-5
4
The nicest part of Y1 is between stops 4 and 8
*/
#include <iostream>
#include <climits>
using namespace std;

int main(){
    //read input
    int n; cin>>n;
    int* a = new int[n];
    for (int i=0; i<n-1; i++) cin>>a[i];

    long max_so_far = LONG_MIN, max_ending_here = 0;
    long start = 0, end = 0, s = 0;
 
    for (int i=0; i<n-1; i++) {
        //consider this number
        max_ending_here += a[i];

        //update our max and indices if
        //1. max_so_far is strictly smaller OR
        //2. max_so_far is less than or equal and this is a longer subarray
        if (
            max_so_far < max_ending_here ||
            (max_so_far <= max_ending_here && ((i-s) > (end-start)))
        ) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        //we have reached a negative, so we reset and start at the next one
        if (max_ending_here < 0){
            max_ending_here = 0;
            s = i+1;
        }
    }
   
    if (max_so_far <= 0) {
        cout<<"Yet another overrated tourist destination\n";
    } else {
        cout<<"The nicest part of Y1 is between stops "<<start+1<<" and "<<end+2<<'\n';
    }
}