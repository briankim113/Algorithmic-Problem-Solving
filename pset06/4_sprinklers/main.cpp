/*
Resubmitted after cleaning up comments and code
Discussed with Lauren Gatesman (lkg282) in Java

Field forms a horizontal strip l meters long and w meters wide

n sprinklers installed at the horizontal center line of the strip
for each sprinkler you are given its radius of operation and its position as the distance from the left end of the center line
turn on as few sprinklers as possible to save water

INPUT
first line - n, l, and w - 1<=n<=10000, 1<=l<=10000000, 1<=w<=100
each of the next n lines - x and r - 0<=x<=l and 1<=r<=1000 of a sprinkler

OUTPUT
one integer followed by a newline - minimum number of sprinklers needed to water the entire strip
if imposssible, output -1

INPUT
8 20 2
5 3
4 1
1 2
7 2
10 2
13 3
16 2
19 4

OUTPUT
6

INPUT
3 10 1
3 5
9 3
6 1

OUTPUT
2

INPUT
3 10 1
5 3
1 1
9 1

OUTPUT
-1
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int minSprinklers(vector< pair<float, float> > vec, int n, int l){
    int i=0;
    pair<float, float> leftSpr = make_pair(-l,-l); //set to "invalid"

    //if there are multiple that catches the leftmost edge
    while (vec[i].first <= 0) {
        //take the one that goes to the farthest
        if (vec[i].second > leftSpr.second){
            leftSpr = vec[i];
        }
        i++;
    }

    //never found a sprinkler that catches the leftmost edge
    if (leftSpr.first==-l && leftSpr.second==-l) {
        return -1;
    }

    //we took one sprinkler at (now i-1) so we set these variables to the next index
    int res = 1;
    float maxRight = leftSpr.second;

    pair<float, float> rightSpr = make_pair(-l,-l); //set to "invalid"
    pair<float, float> nextSpr = make_pair(-l,-l); //set to "invalid"

    //go through all the sprinklers in our vector
    while (i<vec.size()) {
        rightSpr = vec[i];

        if (i == vec.size()-1) { //we are at the last sprinkler
            if (rightSpr.second >= l){ //we have reached the end
                return res + 1;
            } else { //we have not reached the end and thus is impossible
                return -1;
            }
        }

        //leftSpr and rightSpr meet and rightSpr reaches farther
        if (leftSpr.second >= rightSpr.first && rightSpr.second >= maxRight) {
            //update maxRight and nextSpr so we can compare current rightSpr to other sprinklers
            maxRight = rightSpr.second;
            nextSpr = rightSpr;

            //we have reached the end
            if (rightSpr.second >= l){
                return res + 1;
            }
        }
    
        //leftSpr and rightSpr do not meet
        else if (leftSpr.second < rightSpr.first) {
            //the nextSpr is not assigned meaning there was no rightSpr taken which leaves a gap thus impossible
            if (nextSpr.first == -l && nextSpr.second == -l) {
                return -1;
            }
            //otherwise we have met the sprinkler we want so we "reset" the variables 
            leftSpr = nextSpr;
            nextSpr = make_pair(-l,-l); //set to "invalid"
            rightSpr = make_pair(-l,-l); //set to "invalid"
            res++;
            continue;
        }

        i++;
    }

    return res;
}

int main(){
    float n, l, w; cin>>n>>l>>w;
    vector< pair<float, float> > vec;
    for (int i=0; i<n; i++){
        float center, radius; cin>>center>>radius;
        if (radius*2 > w) { //ignore sprinklers that cannot cover the entire width
            // calculate leftmost and rightmost points
            float x = sqrt(pow(radius,2) - pow(w/2,2));
            float left = center-x;
            float right = center+x;
            vec.push_back(make_pair(left, right));
        }
    }

    sort(vec.begin(), vec.end()); //start with leftmost sprinkler
    cout<<minSprinklers(vec, n, l)<<'\n';

    return 0;
}

