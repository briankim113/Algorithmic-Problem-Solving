//unique subarray is when all elements are unique - no repeated values
//given an array, calculate the max length of a unique subarray

//1<=n<=10^6
//n integers in range [1, 10^9]

// 5
// 4 3 2 2 1
// output - 3
// [4,3,2]

// 6
// 1 1 1 1 1 1
// output - 1
// [1]

// 9
// 4 3 5 3 4 9 7 2 1
// output - 7
// [5, 3, 4, 9, 7, 2, 1]

//modified from https://www.geeksforgeeks.org/largest-sum-contiguous-subarray-having-unique-elements/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> vec;

    int num;
    while (cin >> num) vec.push_back(num);

    int i = 0, j = 1;       // Initialize two pointers
    set<int> set;           // Store unique elements
    set.insert(vec[0]);     // Insert the first element

    int len = 1;            // Initizialize len and maxlen which will be updated as we traverse the array
    int maxlen = len;
 
    while (i < n-1 && j < n){ //traverse through the array and look at subarray [i,j]
        // cout<<vec[i]<<' '<<vec[j]<<' ';
        // cout<<"current length: "<<len<<endl;

        bool duplicate = set.find(vec[j]) != set.end();
        if (duplicate) { //we saw 'j' already in this subarray - we have reached our maxlen for this subarray starting at i
            // remove the ith element from the set and go to the next i position to start a new subarray [i+1, j]
            // since we keep j at its place and just move i over once, we reduce len by 1 and increase i by 1
            len -= 1;
            set.erase(vec[i++]);
        }
        else { //we have not seen 'j' yet in this subarray - we can continue with this subarray starting at i
            // add the jth element to the set and go to the next j position to start a new subarray [i, j+1]
            // since we keep i at its place and just move j over once, we increase len by 1 and increase j by 1
            len += 1;
            maxlen = max(len, maxlen); //and take whatever is max
            set.insert(vec[j++]);
        }
    }

    cout<<maxlen<<endl;

    return 0;
}