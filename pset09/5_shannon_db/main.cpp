/*
Resubmitted after deleting unnecessary code

Character R reverses the input list
Character D drops the first element of the list

Input:
DD
1
[42]
Output:
error

Input:
RDD
4
[1,2,3,4]
Output:
[2,1]

Input:
R
0
[]
Output:
[]
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string instr; getline(cin, instr);

    string num; getline(cin, num);
    int n = stoi(num);

    string lis; getline(cin, lis);
    lis = lis.substr(1, lis.length()-2); //get rid of parentheses

    vector<int> intvec;
    stringstream ss(lis);
    string substr;

    while (getline(ss, substr, ',')) {
        intvec.push_back(stoi(substr));
    }

    for (int i=0; i<instr.length(); i++){
        if (instr[i] == 'D'){ //delete first element
            if (intvec.empty()) {
                cout<<"error\n";
                return 0;
            }
            intvec.erase(intvec.begin());
        }
        else {
            reverse(intvec.begin(), intvec.end());
        }
    }

    if (intvec.size()==0) {
        cout<<"[]\n";
    } else {
        cout<<"[";
        for (int i=0; i<intvec.size()-1; i++) {
            cout<<intvec[i]<<",";
        }
        cout<<intvec[intvec.size()-1]<<"]\n";
    }

    return 0;
}