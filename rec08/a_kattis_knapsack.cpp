/*
Each item can be either picked once or not picked. Find the maximum value.

DEFINE DP
dp[i][j], 1 to i items, 1 to j sub-capacity
value is the max value of items in the knapsack from considering i number of items for j sub-capacity

INITIALIZE DP
when cap is 0, we cannot put any item into the knapsack, so all dp[i][0] = 0
when item is 0, we cannot put any item into the knapsack, so all dp[0][j] = 0
Also, in this problem, we find the maximum value of items, so we can initialize all dp[i][j] = 0 (which is always less than max value)
Sometimes, -1 might be more useful, depending on what the problem is, so just keep that in mind.

FORMULA DP
1) we do not pick item i
- dp[i][j] = dp[i-1][j];
2) we pick item i, and guarantee j - w[i] >= 0 (w[i] is the weight of i item)
- dp[i][j] = dp[i-1][j-w[i]] + v[i]; (v[i] is the value of i item)
final)
if (j-w[i] < 0) //cannot pick item i
dp[i][j] = dp[i-1][j];
else //can pick item i so take the max value of picking or not picking item i
dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);

GET ANSWER
answer = max(dp[n][j]) where i<=j<=m
*/

/*
c for capacity, n for number of objects
each of n lines, value and weight
5 3
1 5
10 5
100 5
6 4
5 4
4 3
3 2
2 1

for each test case:
- number of items chosen
- indices of the chosen items (index starts at 0) - can be given in any order

1
2 -> for 5 3 test case, we choose [2] which is at value 100 with capacity 5
3
1 2 3 -> for 6 4 test case, we choose [1, 2, 3] which is at value 9 with capacity 6
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){ //each test case
        stringstream ss(str);
        int c, n; ss>>c>>n;

        //define DP
        int **dp = new int*[n+1]; //rows = num of items
        for (int i=0; i<=n; i++) {
            dp[i] = new int[c+1]; //columns = knapsack capacity
            dp[i][0] = 0; //initialize
        }
        for (int j=0; j<=c; j++) {
            dp[0][j] = 0; //initialize
        }        

        int* valueArr = new int[n+1];
        int* weightArr = new int[n+1];

        for (int x=1; x<=n; x++){ //save all objects in this test case
            getline(cin, str);
            stringstream ss1(str);
            int v, w; ss1>>v>>w;
            valueArr[x] = v;
            weightArr[x] = w;
        }

        for (int j=1; j<=c; j++){
            for (int i=1; i<=n; i++){
                if (j-weightArr[i]<0){
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weightArr[i]] + valueArr[i]);
                }
            }
        }

        //https://stackoverflow.com/questions/23186171/printing-items-that-are-in-sack-in-knapsack
        int res = dp[n][c];
        vector<int> v;
        int w=c;

        for (int i=n; i > 0 && res > 0; i--) { //top-down
            if (res == dp[i-1][w])
                continue;
            else {
                v.push_back(i-1);
                res -= valueArr[i];
                w -= weightArr[i];
            }
        }
        cout<<v.size()<<endl;

        for (int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        } cout<<endl;
    }

    return 0;
}