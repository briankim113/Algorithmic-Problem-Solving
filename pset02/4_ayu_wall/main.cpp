// input
    //1. number of columns (1 <= N <= 50)
    //2. N numbers, each representing #boxes in each column (1 <= #boxes <= 100)
    // total number of boxes IS divisible by the number of columns to make all columns the same height
// output
    //"The minimum number of moves is k." , where k is the minimum number of boxes to be moved

// #columns becomes denominator
// go through the second line to determine total#boxes which becomes nominator
// we know the #boxes each column should have (num/denom)
// so we can just add the "differences" for the columns with more than #boxes needed

// example 1
// 6
// 5 2 4 1 7 5
// total -> 24
// each -> 4
// 1 0 0 0 3 1
// min_moves -> 5
// read through the second line twice

#include <iostream>
using namespace std;

int main(){
    int col; cin>>col;

    int numBoxes[col];
    int total = 0;
    for (int i=0; i<col; i++){
        cin >> numBoxes[i];
        total += numBoxes[i];
    }
    int expectedNum = total / col;

    int min_move = 0;
    for (int i=0; i<col; i++){
        if (numBoxes[i] > expectedNum){
            min_move += (numBoxes[i] - expectedNum);
        }
    }

    cout<<"The minimum number of moves is "<<min_move<<"."<<endl;

    return 0;   
}