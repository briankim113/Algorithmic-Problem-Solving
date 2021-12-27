/*
Wrong answer - test 2

DYNAMIC PROGRAMMING

Ayu has M dollars and wants to spend as much as possible
She also wants to only buy one flavor of each kind of dessert

1<=m<=200 - amount of money
1<=n<=20 - number of different kinds of desserts
each of the following N lines has K+1 integers
1<=k<=20, K is the first integer of that line, number of flavors for this kind of dessert
folloing k int are prices for each flavor of dessert

print one line of one integer indicating max amount of money
OR
no solution if there is no solution

similar to wedding shopping example?
*/

#include <iostream>
#include <algorithm>
using namespace std;

int memo[200][20]; //[m][n], row = subamount of money, column = number of dessert kinds considered, value = max price we can spend
int priceList[20][20]; //[n][k], keeps track of the price of every flavor of every dessert kind
int numFlavors[20]; //[k], keeps track of number of flavors of every dessert kind
int m, numKinds;

int dp(int money, int kind){
    if (money < 0) return -1e6; //imposssible
    if (kind == numKinds) return m - money; //our max value
    if (memo[money][kind] != -1) return memo[money][kind];

    int ans = -1e6;
    for (int i=0; i < numFlavors[kind]; i++){
        ans = max(ans, dp(money - priceList[kind][i], kind + 1));
    }

    return memo[money][kind] = ans;
}

int main(){
    cin>>m>>numKinds;

    for (int i=0; i<numKinds; i++){ //each dessert kind
        cin>>numFlavors[i];
        for (int j=0; j<numFlavors[i]; j++){ //each flavor of this dessert kind
            cin>>priceList[i][j];
        }
    }

    //initialize memo
    for (int i=0; i<200; i++)
        for (int j=0; j<20; j++)
            memo[i][j] = -1;

    int ans = dp(m, 0);

    // for (int i=0; i<m; i++){
    //     for (int j=0; j<numKinds; j++){
    //         cout<<memo[i][j]<<' ';
    //     } cout<<'\n';
    // }

    if (ans > 0) cout<<ans<<'\n';
    else cout<<"no solution\n";

    return 0;
}