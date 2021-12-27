#include <iostream>
#include <sstream>
using namespace std;

//runtime error - Test 15

//each connection is bi-directional
//two computers interconnected if directly or interconnected with same computer
    //any computer is directly connected with itself
//two given computers are interconnected at a particular moment

//count the number of successful and unsuccessful answers to the questions of the kind:
    //is computer ci interconnected with computer cj?

//sounds like a disjoint set problem?

//input
//1st line - 1<=n<=10^6 (num of computers)
//initially no direct connection bw any computers
//following lines contain commands
    //c ci cj - new direct link between ci and cj
    //q ci cj - asks if they are connected

// https://www.geeksforgeeks.org/disjoint-set-data-structures/
class DisjSet {
    int *rank, *parent, n;
  
public:
    // Constructor to create and initialize sets of n items
    DisjSet(int in){
        rank = new int[in+1];
        parent = new int[in+1];
        n = in;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
  
    // path compression improvement
    int find(int x){
        if (parent[x] == x) return x;
        x = find(parent[x]);
        return parent[x];
    }

    // rank merging improvement
    void join(int x, int y){
        int xset = find(x);
        int yset = find(y);
  
        if (xset != yset) {
            if (rank[xset] <= rank[yset]) {
                parent[xset] = yset;
                rank[yset] += rank[xset];
            }
            else if (rank[xset] > rank[yset]) {
                parent[yset] = xset;
                rank[xset] += rank[yset];
            }
        }
    }
};

int main(){
    int n; cin>>n; cin.ignore();
    DisjSet obj(n);

    int suc=0, fail=0;

    string s;
    while(getline(cin, s)) {
        stringstream ss(s);

        char com; ss>>com; 
        int c1, c2; ss>>c1>>c2;

        if (com == 'c') { // connection made
            obj.join(c1, c2);
        }
        else { // query about connection
            if (obj.find(c1) == obj.find(c2)) suc++;
            else fail++;
        }
    }

    cout<<suc<<','<<fail<<endl;
    return 0;
}