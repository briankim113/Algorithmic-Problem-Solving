/*
DP and String

In other words, what is the length of the longest common subsequence?

From slides
given two strings x and y
lcs(i,j) returns length of the LCS of the prefixes x[0...i] and y[0...j]
lcs(i,j) =
	lcs(0,j) = lcs(i,0) = 0 //base case (if we run out of letters)
	lcs(i-1,j-1) + 1  //when x[i-1]=y[j-1] (there is a match)
	max( lcs(i-1,j), lcs(i,j-1) ) //else use the previous LCS (there is no match)


From PDF
Input:
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
Output:
11
4
3
26
14

Mine
Input:
abc
def
abcde
a1c2e
abcdefg
bfc

Output:
0
3
2
*/



#include <iostream>
using namespace std;

string s1, s2;

int max(int a, int b){
    return (a > b) ? a : b;
}
 
int lcs(int m, int n){
    int dp[m+1][n+1];
    
    for (int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            //base case, length is obviously 0 at start
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            }
            //if at the previous idx, the char is the same, then we add one to the length
            else if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            //otherwise, we take the max length we can
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
        
    return dp[m][n];
}
 
int main(){
    while(getline(cin, s1)) {
        getline(cin, s2);
        int l = lcs(s1.length(), s2.length());
        cout<<l<<'\n';
    }
    return 0;
}