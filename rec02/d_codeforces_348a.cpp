// One day n friends gathered together to play "Mafia".
// During each round of the game some player must be the supervisor and other n - 1 people take part in the game.
// For each person we know in how many rounds he wants to be a player, not the supervisor: the i-th person wants to play ai rounds.
// What is the minimum number of rounds of the "Mafia" game they need to play to let each person play at least as many rounds as they want?

// input: The first line contains integer n (3 ≤ n ≤ 105).
// The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 109)
// The i-th number in the list is the number of rounds the i-th person wants to play.

// output: In a single line print a single integer — the minimum number of game rounds the friends need to let the i-th person play at least ai rounds.

// 3
// 3 2 2
// -> 4

// 4
// 2 2 2 2
// -> 3

// so then we can just take the biggest number and +1 it? -> wrong
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float n; cin>>n;
    long long sum = 0;
    int y = 0;

    for (int i=0; i<n; i++){
        int curr; cin>>curr;
        sum += curr;
        // cout<<sum<<endl;
        if (curr > y) y = curr;
    }

    // cout<<sum/(n-1)<<endl;
    int x = ceil(sum/(n-1));
    cout<<max(x,y);

    return 0;
}