/*
1. wants to move candies such that each box contains one flavor and no two boxes contain same flavored candies
2. there are three boxes and three flavors
3. minimum number of candy movements?
*/

/*
INPUT
9 integers
    number of banana, number of grape, number of cherrry in each box
    first three integers for the first box
    second three for the second box
    third three for the third box
    b1 g1 c1 b2 g2 c2 b3 g3 c3
total number of candies does not exceed 2^31
OUTPUT
S x
S - string of three letters (B, C, G) indicating the flavor associated with each box at the end
x - minimum number of candy movements

EXAMPLE
Input:
1 2 3 4 5 6 7 8 9
Output:
BCG 30
Input:
5 10 5 20 10 5 10 20 10
Output:
CBG 50
Input:
1 1 1 1 1 1 1 1 1 
Output:
BCG 6
*/

/*
if there is more than one solution, print the alphabetically smallest string as S
that is in order of banana, cherry, and grape
Brute force should work for this problem size.
*/

#include <iostream>
using namespace std;

// int& combs(int* box1, int* box2, int* box3){
//     return combs;
// }

int main(){
    long box1[3], box2[3], box3[3];

    for (int i=0; i<3; i++) cin>>box1[i];
    for (int i=0; i<3; i++) cin>>box2[i];
    for (int i=0; i<3; i++) cin>>box3[i];

    string strs[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    //B -> box[1]+box[2], C -> box[0]+box[1], G -> box[0]+box[2]
    long combs[6];
    combs[0] = box1[1]+box1[2] + box2[0]+box2[1] + box3[0]+box3[2];
    combs[1] = box1[1]+box1[2] + box2[0]+box2[2] + box3[0]+box3[1];
    combs[2] = box1[0]+box1[1] + box2[1]+box2[2] + box3[0]+box3[2];
    combs[3] = box1[0]+box1[1] + box2[0]+box2[2] + box3[1]+box3[2];
    combs[4] = box1[0]+box1[2] + box2[1]+box2[2] + box3[0]+box3[1];
    combs[5] = box1[0]+box1[2] + box2[0]+box2[1] + box3[1]+box3[2];

    string minstr = strs[0];
    long minlong = combs[0];
    for (int i=1; i<6; i++){
        if (combs[i] < minlong){
            minstr = strs[i];
            minlong = combs[i];
        }
    }
    cout<<minstr<<" "<<minlong<<endl;
    return 0;
}