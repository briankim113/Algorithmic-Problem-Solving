/*
Make sure not to flip the sorted stack.
You do not need to look for an optimal way to flip the pancakes (whatever the optimal might actually mean). 

You are given a stack of integers and asked to sort that stack in ascending order from top to bottom.
Allowed operation <flip(t)> is to flip all elements from the t-th elements to the top upside down
The 1st element is the bottom element, the Nth element is the top element (where N=size of the stack)

We need to figure out a sequence of flip operations that transforms the given stack into a sorted one!

Input - stack of integers given from top to bottom, size is between 1 and 30, integers are between 1 and 100
Output - one line containing (K+1) flip operations
    - among the first K integers, the i-th integer specifices the t value of the i-th flip operation
    - the last K+1-th integer should always be 0
    - output any of the multiple solutions

Input:
1 2 3 4 5
Output:
0

Input:
5 4 3 2 1
Output:
1 0

Input:
5 1 2 3 4
Output:
1 2 0

Input:
3 5 2 1 7 6 4
Output:
3 1 6 2 5 3 4 6 0

https://www.geeksforgeeks.org/pancake-sorting/
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> flipvec;

void flip(int i){
    int temp, start = 0;
    while (start < i){
        temp = vec[start];
        vec[start] = vec[i];
        vec[i] = temp;
        start++;
        i--;
    }
}
 
// Returns index of the maximum element in arr[0..n-1]
int findMax(int n){
    int mi = 0;
    for (int i = 0; i < n; ++i)
        if (vec[i] > vec[mi])
            mi = i;
    return mi;
}
 
// The main function that sorts given array using flip operations
void pancakeSort(){
    // Start from the complete array and one by one reduce current size by one
    for (int curr_size = vec.size(); curr_size > 1; --curr_size){
        // Find index of the maximum element in arr[0..curr_size-1]
        int mi = findMax(curr_size);
 
        // Move the maximum element to end of current array if it's not already at the end
        if (mi != curr_size-1) {
            // To move at the end, first move maximum number to beginning
            flip(mi);
            if (mi != 0)
                flipvec.push_back(vec.size()-mi);
 
            // Now move the maximum number to end by reversing current array
            flip(curr_size-1);
            flipvec.push_back(vec.size()-(curr_size-1));
        }
    }
}
 
int main(){
    //read input
    int i;
    while (cin>>i) vec.push_back(i);

    pancakeSort();

    for (int i = 0; i < flipvec.size(); ++i)
        cout<< flipvec[i]<<" ";
    cout<<"0\n";
 
    return 0;
}