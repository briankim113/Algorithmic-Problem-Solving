/*
Remember that adding a lot of small floating point numbers together may result in rounding errors.
This may be a problem to use integers instead of floating point numbers.
-> meaning we should use cents (int) instead of dollars (float)

$5, $10, $20, $50, $100 bills
5c, 10c, 20c, 50c, $1, $2 coins

How many ways can we make a given amount?

INPUT: 0.00 < M <= 300.00 with two decimal places
OUTPUT: one line consisting
a. M with two decimal places (right justified in a field of width 6)
b. number of ways in which M may be made up (right justified in a field of width 17)

0.20
0.20 4 - with justification

2.00
2.00 293 - with justification

0.01 up to 0.04 -> 0
0.05 -> 1
0.10 -> 2

300.00

0.00
0.00 0
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//https://www.educative.io/edpresso/coin-change-problem-2-finding-the-number-of-ways-to-make-a-sum
int main(){
    int size = 11;
    const int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

    double input; cin>>input;
    //rounding instead of casting
    int sum = round(input * 100);
    // int sum = (input + 0.001) * 100;

    long answer;

    if (sum < 5) { //less than 5c - nothing
        answer = 0;
    } else {
        //DEFINE MEMO
        long **memo = new long*[size+1]; //row = up to how many coins we take into consideration
        for(int i=0; i < size+1; i++) 
            memo[i] = new long[sum+1]; //col = up to what sub-sum we take into consideration
        
        //INITIALIZE MEMO
        // A sum of 0 (j=0) can only be made one possible way {0}
        for(int i=0; i < size+1; i++) memo[i][0] = 1;
        // No coins (i=0) make up a sum of 0
        for(int j=0; j < sum+1; j++) memo[0][j] = 0;
        
        //FILL MEMO
        for(int i=1; i < size+1; i++)
            for(int j=1; j < sum+1; j++)
                //if this_coin (coins[i-1]) is bigger than the current sub-sum (j)
                //then the number of ways is the same as previous number of coins (i-1) for this sub-sum (j)
                if(coins[i-1] > j)
                    memo[i][j] = memo[i-1][j];
                //else the number of ways is the sum of previous number of coins (i-1) for this sub-sum (j)
                //+ however many ways we have for this number of coins (i) at the "j-this_coin" sub-sum value
                else
                    memo[i][j] = memo[i-1][j] + memo[i][j-coins[i-1]];
    
        //RETURN ANSWER
        answer = memo[size][sum]; //when we consider max sub-sum with max num of coins
        
        // Freeing memory from heap
        for(int i = 0; i < size + 1; i++)
            delete[] memo[i];
        delete[] memo;
    }

    cout<<right<<setw(6)<<fixed<<setprecision(2)<<input;
    cout<<right<<setw(17)<<answer<<'\n';

    return 0;
}