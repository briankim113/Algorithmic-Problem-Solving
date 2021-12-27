/*
DISJOINT SET

basically the same problem as Stars with DisjSet

Input:
5 1.5
1.0 0.1
2.0 0.0
5.0 0.2
6.0 0.4
3.0 -0.1
Output:
2

Input:
3 4.0
121.12 254.06
645.04 301.85
912.49 568.96
Output:
3
*/

#include <iostream>
#include <math.h>
#include <unordered_set>
using namespace std;

class DisjSet {
    int *rank, *parent, n;
  
public:
    // Constructor to create and initialize sets of n items
    DisjSet(int n){
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
  
    // Creates n single item sets
    void makeSet(){
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
  
    // Finds the representative of the set that x is an element of
    int find(int x){
        // if x is not the parent of itself, then there is a different 'parent'
        // so we recursively call find on until we reach the 'root'
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // rank merging improvement
    void Union(int x, int y){
        int xset = find(x);
        int yset = find(y);
  
        if (xset == yset) return;
  
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

int main(){
    int n; float d;
    cin>>n>>d;
    float* x = new float[n];
    float* y = new float[n];
    for (int i=0; i<n; i++) {
        cin>>x[i]>>y[i];
    }

    DisjSet ds(n);
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            double dist = sqrt((x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i]));
            if (dist <= d) {
                ds.Union(i,j);
            }
        }
    }

    unordered_set<int> uset;
    for (int i=0; i<n; i++) {
        uset.insert(ds.find(i));
    }
    cout<<uset.size();

    return 0;
}