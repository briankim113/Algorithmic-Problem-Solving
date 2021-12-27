/*
bcacbcabbaccbab
bccabccbbabacbc
a1b2c3d4e
zz1yy2xx3ww4vv
abcdgh
aedfhr
abcdefghijklmnopqrstuvwxyz
a0b0c0d0e0f0g0h0i0j0k0l0m0n0o0p0q0r0s0t0u0v0w0x0y0z0
abcdefghijklmnzyxwvutsrqpo
opqrstuvwxyzabcdefghijklmn

11
4
3
26
14
*/

#include <iostream>
#include <algorithm>
// #include <vector>
using namespace std;

int dp[1001][1001]; //size for string x and y limited at 1000

int main(){
    string x, y;
    // vector<int> v;

    while(cin>>x){
        cin>>y;

        int m = x.length(), n = y.length();
        // int dp[m+1][n+1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                else if (x[i-1] == y[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
    
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout<<dp[m][n]<<'\n';
        // v.push_back(dp[m][n]);
    }

    // for (int i=0; i<v.size()-1; i++) cout<<v[i]<<'\n';
    // cout<<v[v.size()-1];

    return 0;
}