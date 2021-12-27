/*
This should be easy once you work out some examples.

There are N problems for this week.
It takes Amadeus ai seconds to solve ith problem.
It takes Gradescope bi seconds to evaluate and accept correct solution for ith problem.
Amadeus cannot work on multiple problems simultaneously.
Gradescope can evaluate multiple solutions at the same time.
Once a problem is solved, solution is submitted to Gradescope (which is always going to be correct).
He continues to next problem.

What is the optimal order?

INPUT
First line: N = number of problems, 1<=N<=1000
Following N lines: ith line contains a pair of integers ai and bi for Amadeus and Gradescope (1<=ai, bi<=10000)

OUTPUT
One number followed by a newline, indicating total number of seconds
Amadeus solves, submits, and gets accept verdict for all problems if order is optimal
The actual order is irrelevant, as long as it is optimal

EXAMPLE
3
2 1
2 5
3 2

Optimal order of problems - 2, 3, 1

Amadeus
Time 0 - start problem 2
Time 2 - end problem 2, start problem 3
Time 5 - end problem 3, start problem 1
Time 7 - end problem 1

Gradescope
Time 2 - receive problem 2
Time 5 - receive problem 3
Time 7 - return problem 2, return problem 3, receive problem 1
Time 8 - return problem 1

TEST CASES
3
2 1
2 5
3 2
->8

2
100 200
1 99
->300

1
1 1
->2

2
1 1
1 1
->3

1000
1 * 2000 (2000 1's with a space in between)
->1001
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    /*
    Optimal order: in decreasing order of Gradescope
    BUT if we rethink the problem:
    When does Gradescope return the last problem?
    This is essentially the sum of all ai + the least gradescope bi
    NO, look at test case below
    2
    100 200
    1 99
    ->should return 300 but returning 200 (100+1+99)
    ->order should be 100 200 then 1 99
    -> 0+100+200 = 300
    -> 100+1+99 = 200
    Then can we also update maxSingle that adds ai and bi and update if it's greater
    And compare this with suma+minb and take the largest?
    */
   
    int n; cin>>n;
    int suma = 0;
    int maxSingle = 0; //at least 2
    int minb = 10001; //at most 10000
    for (int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
        suma += a;
        if (b < minb) minb = b;
        if (a+b > maxSingle) maxSingle = a+b;
    }

    cout<<max(suma+minb, maxSingle)<<'\n';
    return 0;
}