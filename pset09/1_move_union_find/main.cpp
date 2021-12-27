/*
Discussed with Adilet Majit

1 a b
-Union the sets containing a and b.
-If a and b are already in the same set, ignore this command
2 a b
-Move the element a to the set containing b.
-If a and b are already in the same set, ignore this command
3 a
-Return the number of elements and the sum of elements in the set containing a


Union - same as regular DisjSet
Move - shifts one element to a given set - O(1)
Sum - returns sum of all elements in a given set - O(1)
    Maintain a sum array, which is updated when we do a move and a union

Input:
5 5
1 1 2
2 3 4
1 3 5
2 4 1
3 1
Output:
3 7

Input:
3 2
1 1 2
3 1
Output:
2 3

Input:
5 5
1 1 2
1 3 5
3 1
1 2 4
3 1
Output:
2 3
3 7

Input:
5 5
1 1 2
3 1
2 2 3
3 1
3 2
Output:
2 3
1 1
2 5

*/

#include <iostream>
using namespace std;

class DisjSet {
    int *parent_old, *parent_new, *size, n;
    long *sum;
  
public:
    // Constructor to create and initialize sets of n items
    DisjSet(int n){
        parent_old = new int[n+1]; //used for children to keep track of correct set
        parent_new = new int[n+1]; //updated after move operation
        size = new int[n+1];
        sum = new long[n+1];
        this->n = n;

        //each element is their own set
        for (int i=1; i<=n; i++) { 
            parent_old[i] = i;
            parent_new[i] = i;
            size[i] = 1;
            sum[i] = i;
        }
    }

    int findUptoRoot(int x){
        if (parent_old[x] != x) {
            parent_old[x] = findUptoRoot(parent_old[x]);
        }
        return parent_old[x];
    }

    int find(int x){
        parent_new[x] = findUptoRoot(parent_new[x]);
        return parent_new[x];
    }
  
    //join the set containing x and the set containing y
    void Union(int x, int y){
        int xset = find(x);
        int yset = find(y);
  
        if (xset == yset) return;
  
        //xset has fewer elements than yset -> xset joins yset
        if (size[xset] < size[yset]) {
            parent_old[xset] = yset;
            parent_new[xset] = yset;
            size[yset] += size[xset];
            sum[yset] += sum[xset];
        }

        //yset has fewer or equal elements than xset -> yset joins xset
        else {
            parent_old[yset] = xset;
            parent_new[yset] = xset;
            size[xset] += size[yset];
            sum[xset] += sum[yset];
        }

    }

    //move x into the set containing y
    void Move(int x, int y){
        int xset = find(x);
        int yset = find(y);
        
        if (xset == yset) return;

        parent_new[x] = yset;

        //take out from old
        size[xset]--;
        sum[xset] -= x;

        //put into new
        size[yset]++;
        sum[yset] += x;
    }

    void Print(int x){
        int xset = find(x);
        cout<<size[xset]<<' '<<sum[xset]<<'\n';
    }
};

int main(){
    int n, d; cin>>n>>d;
    DisjSet ds(n);

    for (int i=0; i<d; i++){
        int c; cin>>c;

        //UNION
        if (c==1) {
            int a, b; cin>>a>>b;
            ds.Union(a,b);
        }
        //MOVE
        else if (c==2) {
            int a, b; cin>>a>>b;
            ds.Move(a,b);
        }
        //PRINT
        else {
            int a; cin>>a;
            ds.Print(a);
        }
    }

    return 0;
}