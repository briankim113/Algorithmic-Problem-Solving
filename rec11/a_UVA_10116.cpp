/*
3 6 5
NEESWE
WWWESS
SNWWWW
4 5 1
SESWE
EESNW
NWEEN
EWSEN
0 0 0

10 step(s) to exit
3 step(s) before a loop of 8 step(s)
*/

#include <iostream>
#include <vector>
using namespace std;

int c=1;
int R, C, S;

//give me the distance
//& in front of dis?
int recur(vector < vector<char> > board, vector < vector<int> > dis, int i, int j){
    // cout<<"i,j,c "<<i<<','<<j<<','<<c<<'\n';

    //check if we have exited
    if (i<0) {
        // cout<<"i<0\n";
        return dis[i+1][j];
    } else if (i>=R) {
        // cout<<"i>=R\n";
        return dis[i-1][j];
    } else if (j<0) {
        // cout<<"j<0\n";
        return dis[i][j+1];
    } else if (j>=C) {
        // cout<<"j>=C\n";
        return dis[i][j-1];
    }

    //there is a loop?
    if (dis[i][j] != 0) {
        // cout<<"loop\n";
        // cout<<dis[i][j]<<endl;
        return dis[i][j];
    }

    else {
        // cout<<"no loop\n";
        dis[i][j] = c;
        // cout<<"dis[i][j]="<<dis[i][j]<<'\n';
        c++;

        char c = board[i][j];

        if (c=='N') {
            return recur(board, dis, i-1, j);
        }
        else if (c=='E') {
            return recur(board, dis, i, j+1);
        }
        else if (c=='W') {
            return recur(board, dis, i, j-1);
        }
        else {
            return recur(board, dis, i+1, j);
        }
    }
}

int main(){
    cin>>R>>C>>S;

    while (R || C || S) {
        // char** board = new char*[R];
        // int** dis = new int*[R];
        vector < vector<char> > board(R);
        vector < vector<int> > dis(R);
        for (int i=0; i<R; i++){
            board[i] = vector<char>(C);
            dis[i] = vector<int>(C);
            // board[i] = new char[C];
            // dis[i] = new int[C];
        }

        //populate the arrays
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                cin>>board[i][j];
                dis[i][j] = 0;
            }
        }

        // cout<<R<<C<<S;
        // cout<<" done reading input\n";

        int dist = recur(board, dis, 0, S-1);
        // cout<<dist<<','<<c<<endl;

        if (c-1 == dist){
            //no loop, 10 step(s) to exit
            cout<<dist<<" step(s) to exit\n";
        } else {
            //it's a loop, 3 step(s) before a loop of 8 step(s)
            cout<<dist-1<<" step(s) before a loop of "<<c-dist<<" step(s)\n";
        }

        cin>>R>>C>>S;
        c=1;
    }


    return 0;
}