/*
Resubmitted for adding/deleting comments
Use smart trial and error with a simulation to verify the solution.
(Although there are other approaches that work.)

Initially Poppi is on the ground and she cannot skip any rungs
Initial strength of the rocket is k
As long as her jumps are strictly < k, her rocket strength remains at k
If her jump is ever = k, her rocket strength decreases by 1
She can never jump > k

For example:
Rung heights are 2, 7, 8, 12, 14
Initial rocket strength k = 5
#1 - jump 2 (from 0 to 2) - k still 5
#2 - jump 5 (from 2 to 7) - k decreases to 4
#3 - jump 1 (from 7 to 8) - k still 4
#4 - jump 4 (from 8 to 12) - k decreases to 3
#5 - jump 2 (from 12 to 14) - k still 3

What is the minimum initial strength k for the rocket to reach the top rung?
Does this mean we just need to store the least gap?
But what happens if that least gap exist another time?
That means we need to increase 1 since it decreases.
*/

/*
5
2 7 8 12 14
->5
3
2 7 12
->6
5
1 2 3 4 5
->2
6
5 9 12 13 14 16
->5
6
5 9 12 14 15 21
-> 6
5
5 9 12 14 15
->5
6
5 9 12 14 15 16 22
->6
6
5 9 12 14 15 16
->6
*/

/*
6
5 9 12 14 15 16

ALGORITHM A) find "k"
k=0
1) 0 to 5 - jump=5
-> if (k<jump) k=jump -> k=5
2) 5 to 9 - jump=3
3) 9 to 12 - jump=3
4) 12 to 14 - jump=2
5) 14 to 15 - jump=1
6) 15 to 16 - jump=1
return k=5
**BUT if we work it through, we notice that at 15 to 16 k=0!
**k needs to be 6... trial and error?

ALGORITHM B) trial and error
**Notice that any number from 16 to 19 should have k to be 6 but is getting 5
**20 will result in k to be 6 from the above algorithm
origk=k (origk=5)
1) 0 to 5 -> k=4
2) 5 to 9 -> k=3
3) 9 to 12 -> k=2
4) 12 to 14 -> k=1
5) 14 to 15 -> k=0
**NOW k=0 so we have to increase once
15 to 16 -> origk++
return origk=6
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;

    //find "k"
    int k=0;
    vector<int> v(n+1); v[0]=0;
    for (int i=1; i<=n; i++){
        cin>>v[i];
        int jump = v[i]-v[i-1];
        if (k<jump) k=jump;
        else if (k==jump) k=jump+1;
    }

    //trial and error
    int origk=k;
    for (int i=1; i<=n; i++){
        int jump = v[i]-v[i-1];
        if (jump==k) k--;
        else if (k==0) origk++;
    }
    cout<<origk<<'\n';
    
    return 0;
}