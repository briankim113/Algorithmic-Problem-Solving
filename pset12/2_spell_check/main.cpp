#include <iostream>
#include <climits>
using namespace std;

//inspired by: https://www.geeksforgeeks.org/edit-distance-dp-using-memoization/

//start from front to back
int editDist(string str1, string str2, int m, int n, int dp[][50]){
    //one of the strings is empty
    if (m == 0) return n;
    if (n == 0) return m;
  
    //use the memo
    if (dp[m-1][n-1] != -1)
        return dp[m-1][n-1];

    //characters are same
    if (str1[m-1] == str2[n-1])
        return dp[m-1][n-1] = editDist(str1, str2, m-1, n-1, dp);

    //characters are not the same
    return dp[m-1][n-1] = 1 + min(
                                editDist(str1, str2, m, n-1, dp), // gap to first string
                                editDist(str1, str2, m-1, n, dp) // gap to second string
                            );
}
  
int main(){
    string target; int n;

    cin>>target;
    cin>>n;

    string res;
    int lowest = INT_MAX;

    for (int i=0; i<n; i++){
        string curr; cin>>curr;

        int dp[50][50];
        for (int i=0; i<50; i++)
            for (int j=0; j<50; j++)
                dp[i][j] = -1;

        int penalty = editDist(target, curr, target.length(), curr.length(), dp);
        // cout<<curr<<"\t"<<penalty<<"\n";

        //closest word
        if (penalty < lowest){
            res = curr;
            lowest = penalty;
        }
        
        //multiple closest words - lexicographically smallest
        else if (penalty == lowest){ 
            if (curr < res) res = curr;
        }
    }

    cout<<res<<endl;
    return 0;
}