/*
Worked with Lauren Gatesman (lkg282)

For a large enough board, the number of moves a knight can make is eight (ignoring water and outside of the board).
But, if M=0, N=0, M=N, the number of possible moves decreases to four. 

RxC chess board has some squares filled with water
A knight can move M squares horizontally and N squares vertically (or VICE VERSA) in a single step.
In other words:
    A knight can jump from (a,b) to (c,d) if
    1) |a-c| = N && |b-d| = M OR
    2) |a-c| = M && |b-d| = N
A knight obviously cannot jump to water squares or out of the board

A square (i, j) is considered valid if it can be reached by a knight from the start at (1,1) with a finite number of jumps.
For each valid square (i,j), we count the number of valid squares (x,y) s.t. the knight can jump from (x,y) to (i,j) in one step
If this count is even, (i,j) is an "even valid square", otherwise, (i,j) is an "odd valid square"

Print out the number of even valid squares and odd valid squares

First line contains R, C, M, N
    1 < R,C <= 100
    0 <= M,N <= 50
    M+N > 0

Next line contains W, number of distinct squares filled with water
    0 <= W < R*C

Each of W lines contain a pair of int x and y, (x, y) is filled with water
    1<=x<=R
    1<=y<=C
    x+y > 2

Input:
3 3 2 1
0
Output:
8 0

Input:
4 4 1 2
2
4 4
2 2
Output:
4 10

Input:
3 3 1 1
0
Output:
1 4

Input: -> M and N are the same
4 4 1 1
0
Output:
6 2

Input: -> (1,1) is the only valid square
3 3 1 1
1
2 2
Output:
1 0

Input:
4 4 1 3
0
Output:
6 0

Input:
4 4 1 3
2
1 3
3 1
Output:
1 2

Input: -> M is 0
4 4 0 1
0
Output:
8 8

Input: -> N is 0
4 4 1 0
0
Output:
8 8
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int R, C, M, N, W;
int stop = 0;

//1,1 = 0... R,C = R*C-1
int cellify(int i, int j){
    int x = (i-1)*C+j-1;
    // cout<<"inside cellify: "<<i<<','<<j<<" to "<<x<<'\n';
    return x;
}

//0 = 1,1... R*C-1 = R,C
pair<int, int> coordify(int x){
    int i = x/C+1;
    int j = x%C+1;
    // cout<<"inside coordify: "<<x<<" to "<<i<<','<<j<<'\n';
    return make_pair(i, j);
}

class Graph {
public:
    //index is cell number
    vector<int> visited;                //0 not visited, 1 visited, -1 water-filled
    vector< unordered_set<int> > adj;   //set of "adjacent" (valid) squares
   
    pair<int, int> moves[8] = {
        make_pair(M,N), make_pair(-M,N), make_pair(M,-N), make_pair(-M,-N),
        make_pair(N,M), make_pair(N,-M), make_pair(-N,M), make_pair(-N,-M)
    };

    Graph(){
        for (int i=0; i<R*C; i++){
            visited.push_back(0);
            adj.push_back(unordered_set<int>());
        }
    };

    void fillWater(int x, int y){
        int c = cellify(x,y);
        visited[c] = -1;
    }
  
    int nextCell(pair<int, int> fromCoor, pair<int, int> toCoor){
        int x = fromCoor.first + toCoor.first;
        int y = fromCoor.second + toCoor.second;

        if (1 <= x && x <= R && 1 <= y && y <= C) {
            return cellify(x,y);
        } else {
            return -1;
        }
    }

    //visit all valid squares
    void validate(int v){
        visited[v] = 1;
        pair<int, int> fromCell = coordify(v);

        for (int i=0; i<8; i++){
            pair<int, int> moveToTry = moves[i];
            int cellToTry = nextCell(fromCell, moveToTry);
            //valid cellToTry
            if (cellToTry != -1) {
                //neither visited nor water-filled
                if (visited[cellToTry] == 0) {
                    validate(cellToTry);
                }
            }
        }
    }

    //count and add v into set for cellToTry
    void count(int v){
        //if this is visited
        if (visited[v] == 1) {
            pair<int, int> fromCell = coordify(v);
            for (int i=0; i<8; i++){
                pair<int, int> moveToTry = moves[i];
                int cellToTry = nextCell(fromCell, moveToTry);
                //valid cellToTry
                if (cellToTry != -1) {
                    //also visited
                    if (visited[cellToTry] == 1) {
                        adj[cellToTry].insert(v);
                    }
                }
            }
        }
    }

    void output(){
        int even=0, odd=0;

        for (int v=0; v<R*C; v++) {
            //should be visited only
            if (visited[v] == 1) {
                if (adj[v].size() % 2 == 0){
                    even++;
                } else {
                    odd++;
                }
            }
        }

        cout<<even<<' '<<odd<<'\n';
    }
};

int main(){
    cin>>R>>C>>M>>N>>W;
    Graph g;

    //fill water based on input
    for (int i=0; i<W; i++){
        int x, y; cin>>x>>y;
        g.fillWater(x,y);
    }

    //visit all possible squares starting at cell 0 = (1,1)
    g.validate(0);

    //count for each square how many valid squares there are
    for (int v=0; v < R*C; v++){
        g.count(v);
    }

    g.output();
    return 0;
}