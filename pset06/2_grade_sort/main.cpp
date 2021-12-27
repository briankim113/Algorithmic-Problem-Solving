/*
given midterm exam scores for all students 0<= score <= 100
report all scores in asscending order
*/

/*
INPUT
Line 1: 1 <= N <= 10,000,000 - N integers indicating the grades
Line 2: N integers indicating the grades

OUTPUT
N space separated integers in ascending order

EXAMPLE
Input:
4
50 60 100 90
Output:
50 60 90 100

Input:
6
99 92 93 92 93 91
Output:
91 92 92 93 93 99
*/

/*
requires fast IO operations - counting sort?
*/

#include <iostream>
#include <vector>
using namespace std;

#define SIZE 101

int main(){
    int count_arr[SIZE]; //index is the grade, value is the number of times
    fill_n(count_arr, SIZE, 0); //initially 0

    int n; cin>>n;

    for (int i=0; i<n; i++){
        int grade; cin>>grade;
        count_arr[grade] += 1;
    }

    //how many times does this grade appear?
    // for (int i=0; i<SIZE; i++){
    //     cout<<count_arr[i]<<" ";
    // } cout<<endl;

    vector<int> res;
    //"sort" this array
    for (int i=0; i<SIZE; i++){
        int times = count_arr[i];
        for (int t=0; t<times; t++){
            res.push_back(i);
        }
    }

    for (int i=0; i<res.size()-1; i++)
        cout<<res[i]<<' ';

    cout<<res[res.size()-1]<<endl;

    return 0;
}