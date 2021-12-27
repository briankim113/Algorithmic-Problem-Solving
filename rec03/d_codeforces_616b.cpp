//Munhattan consists of n streets and m avenues
//There is exactly one restaurant on the intersection of each street and avenue
//The streets are numbered with integers from 1 to n and the avenues are numbered with integers from 1 to m.
//The cost of dinner in the restaurant at the intersection of the i-th street and the j-th avenue is cij.

//Jack and Emma decide to choose the restaurant in the following way.
//Firstly Emma chooses the street to dinner and then Jack chooses the avenue.
//Emma and Jack makes their choice optimally: Emma wants to maximize the cost of the dinner, Jack wants to minimize it.
//Emma takes into account that Jack wants to minimize the cost of the dinner. Find the cost of the dinner for the couple in love.

//The first line contains two integers n, m (1 ≤ n, m ≤ 100) — the number of streets and avenues in Munhattan.
//Each of the next n lines contains m integers cij (1 ≤ cij ≤ 10^9) — the cost of the dinner in the restaurant on the intersection of the i-th street and the j-th avenue.

// ex 1 -> 2
// 3 4
// 4 1 3 5
// 2 2 2 2
// 5 4 5 1

//if Emma chooses the first or the third streets Jack can choose an avenue with the cost of the dinner 1.
//So she chooses the second street and Jack chooses any avenue. The cost of the dinner is 2.


// ex 2 -> 1
// 3 3
// 1 2 3
// 2 3 1
// 3 1 2

//In the second example regardless of Emma's choice Jack can choose a restaurant with the cost of the dinner 1.


#include <iostream>
#include <vector>
using namespace std;

int main(){
    int sts, avs; cin>>sts>>avs;
    vector<int> sts_avoid;
    vector<int> inputNum;

    int cheapest = 1000000000;
    for (int st=0; st<sts; st++){
        for (int av=0; av<avs; av++){
            int curr; cin>>curr;
            inputNum.push_back(curr);
            if (curr < cheapest){ //want to avoid
                cheapest = curr;
                sts_avoid.clear();
                sts_avoid.push_back(st);
            } else if (curr == cheapest) {
                if (find(sts_avoid.begin(), sts_avoid.end(), st) == sts_avoid.end())
                    sts_avoid.push_back(st);
            } else {
                continue;
            }
        }
    }

    for (int i=0; i<sts_avoid.size(); i++){
        cout<<sts_avoid[i]<<endl;
    }

    if (sts_avoid.size()==sts) cout<<cheapest; //like example 2

    else {
        int costWeWant = 1000000000;
        for (int st=0; st<sts; st++){
            for (int av=0; av<avs; av++){
                if (find(sts_avoid.begin(), sts_avoid.end(), st) == sts_avoid.end()) { //this is a potential one
                    int i = (avs*st) + av;
                    int curr = inputNum[i];
                    if (curr < costWeWant) costWeWant = curr;
                }
            }
        }
        cout<<costWeWant;
    }

    return 0;
}