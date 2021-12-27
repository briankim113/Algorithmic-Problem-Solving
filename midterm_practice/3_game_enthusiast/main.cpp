//size of N games and capacity of USB stick
//subset of games to store s.t. leftover unused space is minimum
//not necessarily the max number of games but the max "weight"
//knapsack problem - dynamic programming?

//input
//first line - V and N (1<=V<=10000) (1<=N<=20), capacity of USB and num of games
//second line - N integers indicating the size of each game (bw 1 and 10000 each)

//output
//print a single inteeger W, the total space occupied by the games copied onto the USB stick

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//https://marcodiiga.github.io/knapsack-problem

//define f(i,b) as the maximum sum that we can reach
//with a subset of i elements and provided that this value is ≤b

//v={1,3,7,4}
//f(1,0)=0
//f(1,1)=1
//f(4,1)=1
//f(4,15)=15

void memo(const vector<int>& v, const int& N) {

    //vect(a,b) = create a vector of size a with all values as b
    //in this 2d array
        //row indicates the "subarray"
            //row 1 can only take first item
            //row 2 can take first and/or second
            //row 3 can take first, second, and/or third, etc.
        //column indicates the "subcapacity"

    vector< vector<int> > m(
        v.size()+1, vector<int>(N+1, 0)
    );

    // The line above also took care of the initialization for base cases f(i,0) = 0 and f(0,b) = 0

    for (int i = 1; i <= v.size(); ++i) { // For each subset of elements
        for (int b = 1; b <= N; ++b) { // For each subcapacity
            //either we move on, or grab it and add it - use results of subsets
            //f(i,≤b) = max{f(i−1,b), f(i−1,b−v[i])+v[i]}

            int opt1 = m[i-1][b];
            int opt2 = -1;
            if (b - v[i-1] >= 0) {
                opt2 = m[i-1][b-v[i-1]] + v[i-1];
                if (opt2 > b) opt2 = -1; // Not allowed
            }
            m[i][b] = max(opt1, opt2);
        }
    }

    // for (int i = 1; i<=v.size(); ++i){
    //     for (int b=1; b<=N; ++b){
    //         cout<<m[i][b]<<" ";
    //     } cout<<endl;
    // } cout<<endl;

    cout<<m[v.size()][N]<<endl;
}

int main(){
    int N; cin>>N; //capacity of USB
    int g; cin>>g; //number of games

    vector<int> v;
    for (int i=0; i<g; i++){
        int curr; cin>>curr;
        v.push_back(curr);
    }

    memo(v, N);
    return 0;
}