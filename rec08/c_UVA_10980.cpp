/*
22.00 2
2 22.00
4 60.00
2 4
25.00 2
2 48.00
2 46.00
2
22.00 2
2 22.00
4 40.00
1 2 3

Case 1:
Buy 2 for $22.00
Buy 4 for $44.00
Case 2:
Buy 2 for $46.00
Case 3:
Buy 1 for $22.00
Buy 2 for $22.00
Buy 3 for $40.00
*/

#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;

float dp[101]; //what happens if buying 100 is cheaper by buying 150?
//dp[i] is the min price of buying exactly i items
map<int,float> m;
set<int> want;
            
//returns the best min price for buying exactly i items
//memo with recursion is one way of dynamic programming
//in order to return best, I have to store the result first
float p(int i){
    //already memo'd
    if (dp[i] != INFINITY) return dp[i];

    float best = INFINITY;
    for (map<int,float>::iterator it = m.begin(); it != m.end(); it++){
        if (it->first > i){
            dp[i] = best; return dp[i];
        }
        best = min(best, p(i-it->first) + it->second);
    }

    dp[i] = best; return dp[i];
}

//after p() -> dp[0, 24.0, 22.0, 46.0, 44.0]
//after printSolution() -> dp[0, 22.0, 22.0, 44.0, 44.0]

int main(){
    int cas=0;
    string str;
    while(getline(cin, str)){ //for each test case
        // "reset" all variables (cas, dp, m, want)
        cas++;
        dp[0] = 0; //impossible price up to 100 K integers
        for (int i=1; i<101; i++) dp[i] = INFINITY;
        m.clear(); want.clear();

        stringstream ss(str);
        int n;
        ss>>m[1]>>n; //unit price and number of price deals

        for (int i=0; i<n; i++){ //for other price deals
            getline(cin, str);
            stringstream ss1(str);
            int unit; float price;
            ss1>>unit>>price;
            //check if there is no price for this unit already
            if (m.find(unit) == m.end()){
                m[unit] = price;
            }
            //else there is a price for this unit already so take the smallest
            else {
                if (price < m[unit]) m[unit] = price;
            }
        }

        //how many do we need to buy
        getline(cin, str);
        stringstream ss2(str);
        while (ss2) {
            int unit; ss2>>unit;
            want.insert(unit);
        }

        p(100); // float?

        // cout<<"after fillDP: ";
        // for (int i=0; i<=100; i++){
        //     cout<<dp[i]<<' ';
        // } cout<<endl;

        // going from back to front to check for cheaper price for buying more than i items
        for (int i=99; i>=0; i--){
            dp[i] = min(dp[i+1], dp[i]);
        }

        // cout<<"after check: ";
        // for (int i=0; i<=100; i++){
        //     cout<<dp[i]<<' ';
        // } cout<<endl;

        cout<<"Case "<<cas<<":\n";
        for (set<int>::iterator it = want.begin(); it != want.end(); it++){
            cout<<"Buy "<<*it<<" for $";
            cout<<fixed<<setprecision(2)<<dp[*it]<<'\n';            
        }
    }

    return 0;
}