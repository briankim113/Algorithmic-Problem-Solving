/*
ith item is always more important than the i+1st item

as soon as she comes to an item that is too large to fit in the remaining space in the boxes,
she skips that item and all the items below

how many items from her list is she able to order?
and which item should be placed into which box?

we are guaranteed two boxes
1<=n<=200 - number of items
1<=w<=10000 - box volume
n integers, each item volume

Input:
5 10
1 2 100 3 4
Output:
2
1st
1st

Input:
7 50
25 30 10 10 15 7 8
Output:
6
1st
2nd
2nd
2nd
1st
1st
*/

#include <iostream>
using namespace std;

int n, w;
int boxes[2]; //remaining capacity for each box
int* items; //values for each item
int* track;
int* maxTrack;
int maxi = 0;

//https://stackoverflow.com/questions/15434664/packing-a-set-of-boxes-with-a-recursive-algorithm
bool fits(int i){
    if (i == n) return true;

    for (int j=0; j<2; j++){ //try for each box
        if (items[i] <= boxes[j]) {
            boxes[j] -= items[i]; //we put in this item in this box
            track[i] = j+1;

            if (fits(i+1)) return true;

            boxes[j] += items[i]; //take it out since it doesn't fit
            track[i] = 0;
        }
    }

    //when it is about to return false
    if (i > maxi){
        maxi = i;
        for (int x=0; x<i; x++) maxTrack[x] = track[x];
    }

    return false;
}

int main(){
    cin>>n>>w;
    boxes[0] = w; boxes[1] = w;
    items = new int[n];
    track = new int[n];
    maxTrack = new int[n];
    for (int i=0; i<n; i++){
        cin>>items[i];
        track[i] = 0;
    }

    int fit = fits(0);
    if (!fit) { //ended somewhere in the middle
        cout<<maxi<<'\n';
        for (int i=0; i<maxi; i++){
            if (maxTrack[i] == 1) cout<<"1st\n";
            else if (maxTrack[i] == 2) cout<<"2nd\n";
        }
    } else { //put everything in
        cout<<n<<'\n';
        for (int i=0; i<n; i++){
            if (track[i] == 1) cout<<"1st\n";
            else if (track[i] == 2) cout<<"2nd\n";
        }
    }

    return 0;
}