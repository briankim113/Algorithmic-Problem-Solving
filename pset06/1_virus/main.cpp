/*
Discussed with Adilet Majit (am10044)

1. if several people show up to a doctor's office at the same time, they form a queue in increasing order (e.g. monk 1 before monk 3)
1b. if there is already a queue, monk lines up in the back (regardless of their number)
2. if the first monk from the queue enters office x at time t, this monk exits the office after one time  unit (at time t+1) and appears at the next office from his list of offices to visit
2b. at time t+1, the next person from the queue enters office x
3. if a monk was supposed to show up at the clinic at time t, then he shows up at the first doctors' office on his list at t

INPUT
first line: 2 numbers, 1 <= n,m <= 10000, n = num of monks, m = num of doctor's offices
each of the following n lines (for each monk):
    sequence of natural numbers: t k g1 g2 ... gk
    monk arrives at time t and has to visit k offices in order of g1 g2 ... gk
    1 <= gj <= m, 0 <= t <= 1,000,000, 1 <= k <= 1,000,000

OUTPUT
one integer = time when the last monk leaves the hospital

EXAMPLE
Input:
5 3
1 3 3 2 1
0 7 2 3 1 1 1 1 2
2 1 1
1 2 3 3
4 3 1 1 1
Output:
12
Input:
5 10
3 1 6
2 3 3 2 8
2 1 4
2 4 7 9 9 6
0 2 8 7
Output:
6
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main(){
    int numMonks, numOffices; cin>>numMonks>>numOffices;

    vector<int> firstVisitTimes(numMonks);              //keep track of when each monk should start queueing
    vector< queue<int> > officesToVisit(numMonks);      //keep track of which offices each monk needs to go in order
    vector< queue<int> > officeQueues(numOffices);      //keep track of which monks are waiting at each office in order
    bool stillInQueue[numMonks];                        //keep track of whether this monk is waiting in queue somewhere or not
    unordered_set<int> remainingMonks;                  //keep track of which monks are still visiting offices

    //initialize data
    for (int monk=0; monk<numMonks; monk++){
        cin>>firstVisitTimes[monk];
        int n; cin>>n;
        for (int i=0; i<n; i++){
            int office; cin>>office;
            officesToVisit[monk].push(office);
        }
        stillInQueue[monk] = false;
        remainingMonks.insert(monk);
    }

    int timer=0;
    while (!remainingMonks.empty()){
        //put all monks in respective queues in order
        for (int monk=0; monk<numMonks; monk++){
            //has this monk arrived yet?
            if (firstVisitTimes[monk] > timer) continue;

            //is this monk done already?
            if (remainingMonks.find(monk) == remainingMonks.end()) continue;

            //should this monk be done?
            if (officesToVisit[monk].empty()){
                remainingMonks.erase(monk);
                continue;
            }

            //is this monk in queue somewhere?
            if (stillInQueue[monk]) continue;

            //otherwise, this monk has a place to go
            int officeToGo = officesToVisit[monk].front() - 1; //index starts at 0 but input starts at 1
            officeQueues[officeToGo].push(monk);
            stillInQueue[monk] = true;
        }

        //first monks in all queues go visit the doctor
        for (int office=0; office<numOffices; office++){
            //is there no one at this office
            if (officeQueues[office].empty()) continue;

            //there is someone waiting in the queue
            int firstMonk = officeQueues[office].front();
            officeQueues[office].pop();         //monk is out of office's queue
            officesToVisit[firstMonk].pop();    //office is out of monk's officesToVisit queue
            stillInQueue[firstMonk] = false;
        }

        timer++; //increase the time
    }

    //decrease time to account for extra loop
    cout<<--timer<<endl;

    return 0;
}