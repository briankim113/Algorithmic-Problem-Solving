/*
https://vjudge.net/contest/472513#problem/A

Astronomers often examine star maps where stars are represented by points on a plane and each star has Cartesian coordinates.
Let the level of a star be an amount of the stars that are not higher and not to the right of the given star.
Astronomers want to know the distribution of the levels of the stars.

For example, look at the map shown on the figure above.
Level of the star number 5 is equal to 3 (it's formed by three stars with a numbers 1, 2 and 4).
And the levels of the stars numbered by 2 and 4 are 1.
At this map there are only one star of the level 0, two stars of the level 1, one star of the level 2, and one star of the level 3.

You are to write a program that will count the amounts of the stars of each level on a given map.

Input
The first line of the input file contains a number of stars N (1<=N<=15000). 
The following N lines describe coordinates of stars (two integers X and Y per line separated by a space, 0<=X,Y<=32000).
There can be only one star at one point of the plane.
Stars are listed in ascending order of Y coordinate.
Stars with equal Y coordinates are listed in ascending order of X coordinate.

Output
The output should contain N lines, one number per line.
The first line contains amount of stars of the level 0, the second does amount of stars of the level 1 and so on, the last line contains amount of stars of the level N-1.

INPUT is in y ascending order
How many elements are <= this one's x?
5
1 1 -> query sum of tree (0 to 1) -> level 0 -> tree[1]++
5 1 -> query sum of tree (0 to 5) -> level 1 -> tree[5]++
7 1 -> query sum of tree (0 to 7) -> level 2 -> tree[7]++
3 3 -> query sum of tree (0 to 3) -> level 1 -> tree[3]++
5 5 -> query sum of tree (0 to 5) -> level 3 -> tree[5]++

//level array               tree array
0, 1, 2, 3, 4               1, 2, 3, 4, 5, 6, 7
[1, 0, 0, 0, 0]             [1, 0, 0, 0, 0, 0, 0]
[1, 1, 0, 0, 0]             [1, 0, 0, 0, 1, 0, 0]
[1, 1, 1, 0, 0]             [1, 0, 0, 0, 1, 0, 1]
[1, 2, 1, 0, 0]             [1, 0, 1, 0, 1, 0, 1]
[1, 2, 1, 1, 0]             [1, 0, 1, 0, 2, 0, 1]

1
2
1
1
0
*/

#include <iostream>
#include <algorithm>
#define LSB(i) ( (i) & -(i) ) //least significant bit of i
using namespace std;

int tree[32001];

//range sum from 0 to i
int prefix_sum(int i){
    int sum = tree[0];
    for (; i!= 0; i -= LSB(i))
        sum += tree[i];
    return sum;
}

int main(){
    int SIZE; cin>>SIZE;
    int *level = new int[SIZE];

    //fill tree and level with 0
    fill_n(tree, 32001, 0);
    fill_n(level, SIZE, 0);

    //query then update
    for (int t=0; t<SIZE; t++){
        int x, y; cin>>x>>y; //y is not used
        int lvl = prefix_sum(x);
        level[lvl]++;
        tree[x]++;
    }

    for (int l=0; l<SIZE; l++){
        cout<<level[l]<<'\n';
    }

    return 0;
}