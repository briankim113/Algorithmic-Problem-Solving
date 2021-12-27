#include <iostream>
#include <vector>
using namespace std;

// 4 6 4 3 2 2 1 1
// 5 3 2 1 1
// 400 12 50 50 50 50 50 50 25 25 25 25 25 25
// 0 0

// Sums of 4:
// 4
// 3+1
// 2+2
// 2+1+1
// Sums of 5:
// NONE
// Sums of 400:
// 50+50+50+50+50+50+25+25+25+25
// 50+50+50+50+50+25+25+25+25+25+25

int t, n; //fill it with input
int ans = 0;
vector<int> used; //fill everything with 0
vector<int> A; //fill it with input
vector<int> choice;

void recur(int pos, int sum) {
    //base case
    if (pos >= n) {
        if (sum >= ans) {
            ans = sum;
            choice.clear();
            for (int i=0; i<n; i++) {
                if (used[i]){
                    choice.push_back(A[i]);
                }
            }
            for (int i=0; i<choice.size()-1; i++){
                cout<<choice[i]<<'+';
            } cout<<choice[choice.size()-1]<<endl;
        }
        return;
    }

    //choose A[i] or not choose A[i]
    if (used[pos]==0 && A[pos]+sum <= t) { //is choosing A[i] valid?
        used[pos] = 1; //mark A[i]
        recur(pos+1, A[pos]+sum);
        used[pos] = 0; //unmark A[i]
    }
    recur(pos+1, sum); //not choosing A[i] is always valid
}

int main(){
    cin>>t>>n;
    for (int i=0; i<n; i++){
        used.push_back(0);
        int c; cin>>c;
        A.push_back(c);
    }

    cout<<"Sums of "<<t<<':'<<endl;
    recur(0,0); //starting from the first element with the current sum be 0
    
    //not dealing with NONE or repeats or reading the input until EOF signaled by n=0

    return 0;
}