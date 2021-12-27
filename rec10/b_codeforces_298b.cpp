/*
The polar bears are going fishing. They plan to sail from (sx, sy) to (ex, ey). However, the boat can only sail by wind. At each second, the wind blows in one of these directions: east, south, west or north. Assume the boat is currently at (x, y).

If the wind blows to the east, the boat will move to (x + 1, y).
If the wind blows to the south, the boat will move to (x, y - 1).
If the wind blows to the west, the boat will move to (x - 1, y).
If the wind blows to the north, the boat will move to (x, y + 1).
Alternatively, they can hold the boat by the anchor. In this case, the boat stays at (x, y). Given the wind direction for t seconds, what is the earliest time they sail to (ex, ey)?

The first line contains five integers t, sx, sy, ex, ey (1 ≤ t ≤ 105,  - 109 ≤ sx, sy, ex, ey ≤ 109). The starting location and the ending location will be different.
The second line contains t characters, the i-th character is the wind blowing direction at the i-th second. It will be one of the four possibilities: "E" (east), "S" (south), "W" (west) and "N" (north).

If they can reach (ex, ey) within t seconds, print the earliest time they can achieve it. Otherwise, print "-1" (without quotes).

5 0 0 1 1
SESNW

4

10 5 3 3 6
NENSWESNEE

-1
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t, sx, sy, ex, ey;
    cin>>t>>sx>>sy>>ex>>ey;
    int dx = ex-sx, dy = ey-sy;
    // cout<<dx<<dy;
    vector<int> narr;
    vector<int> earr;
    vector<int> warr;
    vector<int> sarr;

    for (int i=1; i<=t; i++){
        char c; cin>>c;
        if (c == 'N') narr.push_back(i);
        else if (c == 'E') earr.push_back(i);
        else if (c == 'W') warr.push_back(i);
        else sarr.push_back(i);
    }

    int ihor = 0, iver = 0;
    //check if we can move horizontally
    if (dx > 0) {
        if (dx > earr.size()){
            cout<<-1<<endl;
            return 0;
        } else {
            ihor = earr[dx-1];
        }
    }
    else if (dx < 0) {
        dx *= -1;
        if (dx > warr.size()){
            cout<<-1<<endl;
            return 0;
        } else {
            ihor = warr[dx-1];
        }
    }

    //check if we can move vertically
    if (dy > 0) {
        if (dy > narr.size()){
            cout<<-1<<endl;
            return 0;
        } else {
            iver = narr[dy-1];
        }
    }
    else if (dy < 0) {
        dy *= -1;
        if (dy > sarr.size()){
            cout<<-1<<endl;
            return 0;
        } else {
            iver = sarr[dy-1];
        }
    }

    int res = (ihor > iver) ? ihor : iver;
    cout<<res<<endl;

    return 0;
}