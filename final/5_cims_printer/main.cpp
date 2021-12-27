#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

/*
CIMS printer - resubmitted for cleaner code and comments

Input:
6 0
1 1 9 1 1 1
Output:
5

Input:
4 2
1 2 3 4
Output:
2

Input:
1 0
5
Output:
1

5 1
1 1 1 9 1

4

5 2
9 1 1 8 4

5

5 2
9 1 2 8 4

4

5 3
9 1 2 8 4

2

4 0
1 1 3 4

3

4 1
1 1 3 4

4

6 1
1 1 1 9 1 1

5

4 1
1 3 3 4

2

4 2
1 3 3 4

3

4 0
3 2 4 5

3

4 1
3 2 4 5

4

6 2
9 8 9 8 9 8

2

*/

int main(){
    queue<int> q; //printer
    map<int, int, greater<int> > m; //priority, count (large to small by priority)

    //read input
    int N, myJobIdx; cin>>N>>myJobIdx;
    int myJob;

    for (int i=0; i<N; i++){
        int job; cin>>job;

        if (i == myJobIdx){
            myJob = job;
        }

        if (m.find(job) != m.end()){
            m[job]++;
        } else {
            m.insert(make_pair(job, 1));
        }

        q.push(job);
    }



    int count = 0; //increase by 1 if print 
    bool done = false;

    while (!done){
        map<int, int>::iterator it = m.begin(); //highest priority

        //there is a higher priority in the queue
        while (q.front() != it->first) {
            //don't print but move
            int pop = q.front();
            q.pop(); q.push(pop);

            //myJobIdx (loop back if needed)
            myJobIdx--;
            if (myJobIdx == -1){
                myJobIdx = q.size()-1;
            }
        }

        //we have reached highest priority (it->first)

        //but this priority is not the priority of myJob
        if (it->first != myJob){
            while (it->second != 0){

                //print
                if (q.front() == it->first){ 
                    q.pop(); it->second--;
                    count++;
                }
                
                //don't print but move
                else {
                    int pop = q.front();
                    q.pop(); q.push(pop); //move to end
                }
                
                //myJobIdx (loop back if needed)
                myJobIdx--;
                if (myJobIdx == -1){ //To-do : while should not exit immediately so it should be ok?
                    myJobIdx = q.size()-1;
                }
            }

            m.erase(it); //this priority is done
        }
        
        //and this priority is the priority of myJob
        else {
            //myJob is not at the front
            while (myJobIdx != 0){

                //print
                if (q.front() == it->first){ 
                    q.pop(); it->second--;
                    count++;
                }
                
                //don't print but move
                else {
                    int pop = q.front();
                    q.pop(); q.push(pop); //move to end
                }

                myJobIdx--; //no loop needed
            }

            //finally myJobIdx == 0 so we can print
            count++;
            done = true;
        }
    }

    cout<<count<<endl;

    return 0;
}