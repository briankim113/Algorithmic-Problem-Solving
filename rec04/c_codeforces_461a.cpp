// Appleman and Toastman play a game.
//Initially Appleman gives one group of n numbers to the Toastman, then they start to complete the following tasks:

//Each time Toastman gets a group of numbers, he sums up all the numbers and adds this sum to the score.
//Then he gives the group to the Appleman.
//Each time Appleman gets a group consisting of a single number,
    //he throws this group out.
//Each time Appleman gets a group consisting of more than one number,
    //he splits the group into two non-empty groups (he can do it in any way) and gives each of them to Toastman.
// After guys complete all the tasks they look at the score value. What is the maximum possible value of score they can get?

// The first line contains a single integer n (1 ≤ n ≤ 3·105).
// The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 106) — the initial group that is given to Toastman.
//Print a single integer — the largest possible score.

//3
//3 1 5
//
//26
//Initially Toastman gets group [3, 1, 5] and adds 9 to the score, then he give the group to Appleman.
//Appleman splits group [3, 1, 5] into two groups: [3, 5] and [1].
//Both of them should be given to Toastman.
//When Toastman receives group [1], he adds 1 to score and gives the group to Appleman (he will throw it out).
//When Toastman receives group [3, 5], he adds 8 to the score and gives the group to Appleman.
//Appleman splits [3, 5] in the only possible way: [5] and [3]. Then he gives both groups to Toastman.
//When Toastman receives [5], he adds 5 to the score and gives the group to Appleman (he will throws it out).
//When Toastman receives [3], he adds 3 to the score and gives the group to Appleman (he will throws it out).
//Finally Toastman have added 9 + 1 + 8 + 5 + 3 = 26 to the score. This is the optimal sequence of actions.
//algorithm sounds like we need to keep the big numbers as big as possible and just take the minimum value out?

#include <iostream>
#include <queue>
using namespace std;

//maybe better to use vector instead so I can iterate through without copying / popping elements?
int main(){
    priority_queue<int, vector<int>, greater<int> > pq;
    int n; cin>>n;
    int score;
    for (int i=0; i<n; i++){
        int curr; cin>>curr;
        score+=curr;
        pq.push(curr);
    }

    //goes from small to big
    for(int i=1; i<=n; i++){
        cout<<score<<endl;
        score += pq.top()*i;
        pq.pop();
    }

    cout<<score<<endl;
    return 0;
}