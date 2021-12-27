/*
This is going back to the basics in terms of choice of data structure.
Be careful with handling the ends.

Linear formation of soldiers, each of whom protects their two nearest neighbors called "pals"
Leftmost soldier does not have a left pal, and the rightmost no right pal
If either of the pals of a soldier is killed, then the next living neighbor to the left/right becomes that soldier's new pal
Update the soldiers about the new pals after receiving each loss report

INPUT
First line: 1 <= N <= M <= 100,000, N soldiers in the line, M number of loss reports
- soldiers are numbered from 1 (left) to N (right) according to their positions
Each of next M lines: 1 <= L <= R <= N, soldiers from L to R were killed
- it is guaranteed that these soldiers were alive until that moment

OUTPUT
Print M lines for the M loss reports
In the ith line, print the new pal relationships formed
That means for every loss report L R, print:
- the first living soldier to the left of L
- the first living soldier to the right of R
if there is no surviving soldier in some direction, print * instead

EXAMPLES
Input:
1 1
1 1
Output:
* *

Input:
10 4
2 5
6 9
1 1
10 10
Output:
1 6
1 10
* 10
* *

Input:
5 1
1 1
Output:
* 2

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M; cin>>N>>M;
    vector<int> v(N); //index 0 to N-1, value soldier 1 to N
    for (int i=0; i<v.size(); i++) v[i] = i+1;

    for (int m=0; m<M; m++){ //for every loss report
        // for (int i=0; i<v.size(); i++){
        //     cout<<v[i]<<' ';
        // } cout<<'\n';

        int l, r; cin>>l>>r;

        //shouldn't need error handling
        vector<int>::iterator first = find(v.begin(), v.end(), l);
        vector<int>::iterator last = find(first, v.end(), r);
        // cout<<*first<<' '<<*last<<'\n';

        if (first!=v.begin()){
            cout<<*prev(first);
        } else {
            cout<<'*';
        } cout<<' ';

        if (last!=v.end()-1){
            cout<<*next(last);
        } else {
            cout<<'*';
        } cout<<'\n';

        v.erase(first, last+1); //in order to delete the last elem as well
        // cout<<'\n';
    }

    return 0;
}