/*
INPUT
Line 1: two integers, 1<=S<=1000 and 1<=N<=12, S is target sum, N is number of values in the following line
Line 2: N integers, all between 1 and 100
OUTPUT
One line for every subset satisfying the target sum
For every subset numbers are printed in decreasing order separated by '+'
Subsets themselves are also sorted in decreasing order
Do not print the same subsets (no two lines should be identical)

EXAMPLE
Input: 
4 6
4 3 2 2 1 1
Output:
Sums of 4:
4
3+1
2+2
2+1+1

Input:
5 3
2 1 1
Output:
Sums of 5:
NONE

Input:
400 12
50 50 50 50 50 50 25 25 25 25 25 25
Output:
Sums of 400:
50+50+50+50+50+50+25+25+25+25
50+50+50+50+50+25+25+25+25+25+25

Input:
16 10
15 2 2 2 2 2 2 2 2 1
Output:
Sums of 16:
15+1
2+2+2+2+2+2+2+2
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

//https://stackoverflow.com/questions/18305843/find-all-subsets-that-sum-to-a-particular-value
int target, n;
vector<int> input;
set<string> allSubsets;
string token = "+";

int getSum(string intString){
    int sum=0;
    int pos=0;
    string lookingFor;
    //https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
    while ((pos = intString.find(token)) != string::npos) {
        lookingFor = intString.substr(0, pos);
        sum += stoi(lookingFor);
        intString.erase(0, pos+1);
    }
    return sum;
}

void findTargetSumSubsets(string ramp, int index){
    if (getSum(ramp) == target) {
        ramp.pop_back();
        if (allSubsets.find(ramp) == allSubsets.end()) {
            cout<<ramp<<'\n';
        }
        allSubsets.insert(ramp);
    }

    if (index < n){
        findTargetSumSubsets(ramp + to_string(input[index]) + token, index+1);
        findTargetSumSubsets(ramp, index + 1);
    }
}

int main(){
    cin>>target>>n;
    for (int i=0; i<n; i++){
        int tmp; cin>>tmp;
        input.push_back(tmp);
    }
    sort(input.begin(), input.end(), greater<int>());

    cout<<"Sums of "<<target<<":\n";
    findTargetSumSubsets("", 0);
    if (allSubsets.empty()){
        cout<<"NONE\n";
    }
    
    return 0;
}