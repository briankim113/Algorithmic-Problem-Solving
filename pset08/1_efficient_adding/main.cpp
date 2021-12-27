/*
Input:
3
1 2 3
Output:
9

Input:
4
1 2 3 4
Output:
19

Input:
5
7 8 2 2 9
Output:
60

[2, 2, 7, 8, 9]
2 + 2 = 4 gives [4, 7, 8, 9]
4 + 7 = 11 gives [8, 9, 11]
8 + 9 = 17 gives [11, 17]
11 + 17 = 28 gives [28]

Overall cost = 4 + 11 + 17 + 28 = 60 
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n; cin>>n;
    priority_queue<long, vector<long>, greater<long> > pq; //low to high

    //sort the input list of numbers
    for (int i=0; i<n; i++){
        long x; cin>>x;
        pq.push(x);
    }
    
    long result = 0;
    while (pq.size() != 1){
        long first = pq.top(); pq.pop();
        long second = pq.top(); pq.pop();
        // cout<<first<<' '<<second<<'\n';
        long cost = first + second;
        result += cost;
        pq.push(cost);
    }

    cout<<result<<'\n';

    return 0;
}