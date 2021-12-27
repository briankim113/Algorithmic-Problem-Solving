/*
This is not a graph problem (nor is it DP). 

rearrange the cubes as fast as possible such that the numbers on the cubes appear in increasing order from left to right
only allowed action is to swap the position of two consecutive cubes
what is the minimum number of moves required?

N, number of cubes, 1 <= N <= 10000000
Each of N lines has one integer x, 1 <= x <= 1,000,000,000
GUARANTEED no duplicate cube numbers

Sounds like a bubble sort - just count the number of steps?
Time out on 27~32 - O(n^2) is not good enough?
NOT bubble sort - confirmed in class
Merge-sort, divide-and-conquer, count the number of steps?
//https://www.geeksforgeeks.org/counting-inversions/

Input:
3
3
1
2
Output:
2

Input:
5
100
2
93
1
99
Output:
6

Input:
8
8
22
7
9
31
19
5
13
Output:
14
*/

#include <iostream>
using namespace std;

long merge(int arr[], int temp[], int left, int mid, int right){
    long count = 0;
 
    int i = left; /* left subarray*/
    int j = mid; /* right subarray*/
    int k = left; /* merged subarray, start at left*/

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            //If a[i] is greater than a[j], then there are (mid – i) inversions
            temp[k++] = arr[j++];
            count += (mid - i);
        }
    }
 
    //any remaining in left
    while (i <= mid - 1) temp[k++] = arr[i++];
 
    //any remaining in right
    while (j <= right) temp[k++] = arr[j++];
 
    //copy merged to original
    for (i = left; i <= right; i++) arr[i] = temp[i];
 
    return count;
}
 
long mergeSort(int arr[], int temp[], int left, int right){
    long count = 0;

    if (right > left) {
        //divide array into half
        int mid = (right + left) / 2;
 
        //count in left-part, right-part, and merging
        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid + 1, right);
    }

    return count;
}

int main(){
    int n; cin>>n;
    int* arr = new int[n];
    int* temp = new int[n];

    for (int i=0; i<n; i++) cin>>arr[i];

    long ans = mergeSort(arr, temp, 0, n-1);
    cout << ans << '\n';
    return 0;
}