#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    int m; cin>>m;
    int numPlayers = pow(2, n);
    int count = 0;
    
    int missingPlayers[m];
    for (int i=0; i<m; i++) cin>>missingPlayers[i];
    int missingIdx = 0;
    int nextMissing = missingPlayers[missingIdx++];

    vector<int> bitArray;
    for (int curr=0; curr<numPlayers; curr++){
        int player = curr+1;
        if (player == nextMissing) {
            bitArray.push_back(0);
            nextMissing = missingPlayers[missingIdx++];
        } else {
            bitArray.push_back(1);
        }
    }

    for (int l=0; l<n; l++){ // number of layers in the championship
        vector<int> nextArray;
        for (int i=0; i<numPlayers; i+=2){
            int matchOccurred = (bitArray[i] || bitArray[i+1]);
            nextArray.push_back(matchOccurred);
            if (matchOccurred) { //match
                if (bitArray[i] && bitArray[i+1]) { //regular
                    continue;
                } else { //walkover
                    count++;
                }
            }
        }

        bitArray.clear();
        for (int i=0; i<nextArray.size(); i++){
            bitArray.push_back(nextArray[i]);
        }

        numPlayers /= 2;
    }

    cout<<count;

    return 0;
}