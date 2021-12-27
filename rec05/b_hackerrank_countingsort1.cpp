#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin>>n; //n is the max of the counts we are doing
    int* arr = new int[n]; //index is the number of interest, value is the number of times this number appeared
    fill_n(arr, n, 0); //initially 0

    while (cin){
        int num; cin>>num;
        // cout<<num<<' ';
        if (num < n) { //throw away other numbers above n because we don't care
            arr[num] += 1;
        }
    }

    //how many times does this number appear?
    // for (int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // } cout<<endl;

    vector<int> res;
    //if we want to "sort" this array
    for (int i=0; i<n; i++){
        int times = arr[i];
        for (int t=0; t<times; t++){
            res.push_back(i);
        }
    }

    for (int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    } cout<<endl;

    return 0;
}