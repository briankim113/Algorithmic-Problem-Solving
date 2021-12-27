/*
Wrong answer - Test 14
Runtime errors - Test 18

BFS

Remember that in a 3D labyrinth there are six possible neighbors for each cell.
Be aware of possible cycles. 

Every cell is either empty or filled by rock
Every minute, you can travel in any direction parallel to the edge by one cell (N, S, E, W, Up, Down)
Not allowed to step onto a rock cell or go out of the labyrinth without the exit point

Minimum time needed to escape the labyrinth

K, N, M - layers, rows, and columns (1 <= K,N,M, <= 30)
K blocks of N lines each containing M characters
    Each block/layer is demarcated by a blank line
# indicates a cell of rock, . indicates an empty cell
S indicates starting point, E indicates exit
    Guaranteed to be distinct locations, always exactly one

Output "Escaped in x minute(s)." where x is the min time to escape
OR "Trapped!" if it is impossible to escape

Input:
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E
Output:
Escaped in 11 minute(s).

Input:
1 3 3
S##
#E#
###
Output:
Trapped!

Input:
3 3 3
###
#S#
###

###
#.#
###

###
#E#
###
Output:
Escaped in 2 minute(s).
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Point {
public:
    int l;
    int r;
    int c;
    int t;

    Point () {}
    Point (int l, int r, int c, int t) {
        this->l = l;
        this->r = r;
        this->c = c;
        this->t = t;
    }
};

int L, R, C;
vector< vector < vector<char> > > labyrinth;
vector< vector < vector<bool> > > visited;
Point start;
queue<Point> q;

//in all 6 directions, increasing timer by 1
Point moves[6] = {
    Point(1, 0, 0, 1), Point(-1, 0, 0, 1),
    Point(0, 1, 0, 1), Point(0, -1, 0, 1),
    Point(0, 0, 1, 1), Point(0, 0, -1, 1)
};

Point nextPoint(Point a, Point b){
    int l = a.l + b.l;
    int r = a.r + b.r;
    int c = a.c + b.c;
    int t = a.t + b.t;
    // cout<<"nextPoint is "<<l<<','<<r<<','<<c<<endl;
    return Point(l, r, c, t);
}

// check if we can visit this cell
bool isValid(int layer, int row, int col){
    // cout<<"inside isValid\n";
    // cout<<layer<<','<<row<<','<<col<<' ';

    // not if cell is out of bounds
    if (layer < 0 || row < 0 || col < 0 || 
        layer >= L || row >= R || col >= C){
        // cout<<"out of bounds\n";
        return false;
    }

    // not if cell is '#'
    if (labyrinth[layer][row][col] == '#'){
        // cout<<"cell is #\n";
        return false;
    }

    // not if cell is already visited
    if (visited[layer][row][col]){
        // cout<<"already visited\n";
        return false;
    }
 
    // good to visit
    // cout<<"good to visit\n";
    return true;
}

void BFS() {
    while (!q.empty()) { 
        Point cell = q.front();
        int l = cell.l, r = cell.r, c = cell.c;
        // cout << labyrinth[l][r][c] << " ";

        if (labyrinth[l][r][c] == 'E') {
            cout<<"Escaped in "<<cell.t<<" minute(s).\n";
            return;
        }
 
        q.pop();
 
        // Go to the adjacent cells
        for (int i = 0; i < 6; i++) {
            Point move = moves[i];
            // cout<<"trying move "<<move.l<<','<<move.r<<','<<move.c<<endl;
            Point nextCell = nextPoint(cell, move);
 
            if (isValid(nextCell.l, nextCell.r, nextCell.c)) {
                // cout<<"visiting "<<nextCell.l<<','<<nextCell.r<<','<<nextCell.c<<" at time "<<nextCell.t<<endl;
                q.push(nextCell);
                visited[nextCell.l][nextCell.r][nextCell.c] = true;
            }
        }
    }

    //if we reached here, it means we never found E
    cout<<"Trapped!\n";
}

int main(){
    cin>>L>>R>>C;

    for (int i=0; i<L; i++) {
        vector <vector<char> > layer;
        vector <vector<bool> > visitLayer;

        for (int j=0; j<R; j++) {
            vector <char> row;
            vector <bool> visitRow;

            for (int k=0; k<C; k++) {
                char c; cin>>c;
                if (c == 'S'){
                    start = Point(i, j, k, 0);
                    q.push(start);
                }
                row.push_back(c);
                visitRow.push_back(false);
            }
            layer.push_back(row);
            visitLayer.push_back(visitRow);
        }
        labyrinth.push_back(layer);
        visited.push_back(visitLayer);
        cin.ignore(); //skip the line break
    }

    // cout<<start.l<<start.r<<start.c<<endl;

    visited[start.l][start.c][start.r] = true;
    BFS();

/*
    // check labyrinth input

    for (int i=0; i<L; i++) {
        for (int j=0; j<R; j++) {
            for (int k=0; k<C; k++) {
                cout<<labyrinth[i][j][k];
            } cout<<endl;
        } cout<<endl;
    }

    cout<<start.x<<start.y<<start.z<<start.time<<endl;
    cout<<end.x<<end.y<<end.z<<start.time<<endl;
*/

    return 0;
}