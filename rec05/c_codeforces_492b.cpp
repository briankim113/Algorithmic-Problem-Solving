//Vanya walks late at night along a straight street of length l, lit by n lanterns.
//Consider the coordinate system with the beginning of the street corresponding to the point 0,
    //and its end corresponding to the point l.
    //Then the i-th lantern is at the point ai.
//The lantern lights all points of the street that are at the distance of at most d from it,
    //where d is some positive number, common for all lanterns.

//Vanya wonders: what is the minimum light radius d should the lanterns have to light the whole street?

// The first line contains two integers n, l (1 ≤ n ≤ 1000, 1 ≤ l ≤ 109)
// the number of lanterns and the length of the street respectively.
// The next line contains n integers ai (0 ≤ ai ≤ l).
// Multiple lanterns can be located at the same point. The lanterns may be located at the ends of the street.

// Print the minimum light radius d, needed to light the whole street.
// The answer will be considered correct if its absolute or relative error doesn't exceed 10^-9.

// 7 15
// 15 5 3 7 9 14 0

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int n, l;
    cin>>n>>l;
    multiset<int> lanternPos;

    //each number here represents their position
    for (int i=0; i<n; i++){
        int pos; cin>>pos;
        lanternPos.insert(pos); //O(n log n) because we sort
    }

    for (int pos : lanternPos){
        cout << pos << ' ';
    }

    float max_dist = 0; //will be twice our output bc we want radius

    for (set<int>::iterator it=lanternPos.begin(); it!=lanternPos.end(); it++){
        int curr=*it; int next=*it++;
        float dist=next-curr;
        max_dist = max(max_dist, dist);
    }

    cout<<max_dist/2<<endl;

    return 0;
}
