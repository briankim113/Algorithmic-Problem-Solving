//Calvin likes to lie in a field and look at the night sky. Since he doesn’t know any real star constellations,
//he makes them up: if two stars are close to each other, they must belong to the same constellation.
//He wants to name them all, but fears to run out of names. Can you help him and count how many
//constellations there are in the sky?
//Two stars belong to the same constellation if distance between their projections on a two-dimensional
//sky plane isn’t more than D units.

// 2
// 5 1.5
// 1.0 0.1
// 2.0 0.0
// 5.0 0.2
// 6.0 0.4
// 3.0 -0.1
// 3 4.0
// 121.12 254.06
// 645.04 301.85
// 912.49 568.96

// Case 1: 2
// Case 2: 3

//https://www.geeksforgeeks.org/disjoint-set-data-structures/
#include <iostream>
#include <math.h>
using namespace std;

class DisjSet {
    int *rank, *parent, n;
  
public:
    // Constructor to create and
    // initialize sets of n items
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
  
    // Creates n single item sets
    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
  
    // Finds set of given item x
    int find(int x)
    {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {
  
            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = find(parent[x]);
  
            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }
  
        return parent[x];
    }
  
    // Do union of two sets represented
    // by x and y.
    void Union(int x, int y)
    {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);
  
        // If they are already in same set
        if (xset == yset)
            return;
  
        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
  
        // If ranks are same, then increment
        // rank.
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

bool withinDistance(float x1, float y1, float x2, float y2, float dist){
    float deltax = x2-x1; float deltay = y2-y1;
    float hyp = sqrt(deltax*deltax + deltay*deltay);
    if (hyp < dist) return true;
    else return false;
}

int main()
{
    // cout<<withinDistance(1.0, 0.1, 2.0, 0.0, 1.5)<<endl;
    int tests; cin>>tests;
    for (int t=1; t<=tests; t++) {
        int lines, float dist; cin>>lines>>dist;
        float x, y; cin>>x>>y; DisjSet ds1((x,y));
        int numOfSets=1;
        for (int l=1; l<lines; l++) {
            
        }
        cout<<"Case "<<t<<": "<<numOfSets<<endl;
    }
    // DisjSet obj(5);
    // obj.Union(0, 2);
    // obj.Union(4, 2);
    // obj.Union(3, 1);
    // if (obj.find(4) == obj.find(0))
    //     cout << "Yes\n";
    // else
    //     cout << "No\n";
    // if (obj.find(1) == obj.find(0))
    //     cout << "Yes\n";
    // else
    //     cout << "No\n";
    //Yes
    //No
  
    return 0;
}