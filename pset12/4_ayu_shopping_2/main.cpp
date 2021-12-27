#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int maxCapacity; cin>>maxCapacity;
    int numStalls; cin>>numStalls;

    //up to 10 merchant stalls
    //up to 100 items per stall
    int weight[10][100];
    int value[10][100];
    int itemForStall[10];

    for (int i=0; i<numStalls; i++){
        int m; cin>>m;
        itemForStall[i] = m;

        for (int j=0; j<m; j++) {
            int w, v; cin>>w>>v;
            weight[i][j] = w;
            value[i][j] = v;
        }
    }

    //dp stores the max nutritional value, 0 to 10000
    int dp[numStalls][10001];

    //for stall 0
    int numItems = itemForStall[0];
    int i=0;
    for (int j=0; j < numItems; j++){
        //start from max capacity to current item's weight 
        for (int w = maxCapacity; w >= weight[i][j]; w--){
            dp[i][w] = max(dp[i][w], dp[i][w - weight[i][j]] + value[i][j]);
        }
    }

    //similarly for other stalls
    for (int i=1; i < numStalls; i++){

        //same as above
        int numItems = itemForStall[i];
        for (int j=0; j < numItems; j++){
            for (int w = maxCapacity; w >= weight[i][j]; w--) {

                //calculate for prevStall and currStall - not take vs take
                int prevStall = 0, currStall = 0;

                if (dp[i-1][w - weight[i][j]])  prevStall = dp[i-1][w - weight[i][j]] + value[i][j];
                if (dp[i][w - weight[i][j]])    currStall = dp[i][w - weight[i][j]] + value[i][j];

                //and take the greatest, which could mean keep the way it is
                dp[i][w] = max(dp[i][w], max(prevStall, currStall));
            }
        }
    }

    int res = dp[numStalls-1][maxCapacity];
    if (res)    cout<<res<<endl<<endl;
    else        cout<<-1<<endl<<endl;

    return 0;
}