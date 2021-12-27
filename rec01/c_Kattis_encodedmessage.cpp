#include <iostream>
#include <string>
#include <tgmath.h>

using namespace std;

int main(){
    int num;
    cin>>num;
    cin.ignore(); //skip after number is read

    //for each string
    for(int line=0; line<num; line++){
        string s;
        getline(cin, s);

        int n = sqrt(s.length()); // this is the NxN 2d array we need to create
        char table[n][n];

        int curr = 0;
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                table[r][c] = s[curr++];
            }
        }

        //outside column - from n-1 to 0
        //inside row - from 0 to n-1
        for(int c=n-1; c>=0; c--){
            for(int r=0; r<n; r++){
                cout<<table[r][c];
            }
        }
        cout<<endl;
    }
    return 0;
}