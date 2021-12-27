// https://github.com/andy489/Data_Structures_and_Algorithms_CPP/blob/master/Sparse%20Table/Matchsticks.cpp
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/

#include <iostream>
#include <iomanip> //setprecision
#include <algorithm> //max

using namespace std;

const int mxN = 1e5, K = 17;
int Min[mxN + 1][K + 1],
    Max[mxN + 1][K + 1],
    Log[mxN + 1]; //not sure how this works with building

int getMin(int L, int R) {
    int j = Log[R - L + 1];
    return min(Min[L][j], Min[R - (1 << j) + 1][j]);
}

int getMax(int L, int R) {
    if (L > R)
        return 0;
    int j = Log[R - L + 1];
    return max(Max[L][j], Max[R - (1 << j) + 1][j]);
}

int main() {
    int N; //number of matchsticks
    cin>>N;

    int b; //time to burn
    for (int i = 0; i < N; ++i) {
        cin>>b;
        Min[i][0] = Max[i][0] = b;
    }

    //build the tree
    for (int j = 1; j <= K; ++j)
        for (int i = 0; i <= N - (1 << j); ++i) {
            Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
            Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
        }

    int q; //number of queries
    cin>>q;

    int L, R; //range of burning

    //class algorithm
    while (q--) {
        cin>>L>>R;
        int Min = getMin(L,R);
        int Max1 = getMax(L,R);
        int Max2 = getMax(1,L-1);
        int Max3 = getMax(R+1, N);
        int Ans = Min + max((Max1-Min)/2, max(Max2, Max3));
        cout << setprecision(1) << fixed << Ans / 1.0 << endl;
    }

    return 0;
}
