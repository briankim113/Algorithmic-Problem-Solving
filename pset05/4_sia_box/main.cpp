//determine what is really hidden in the box
    //stack
    //queue
    //max priority queue
    //impossible (none of the above)
    //not sure (could be more than one)

// input
// 1<=N<=1000 - number of operations
// each in N lines - single oepration
    //1 x - put the number x into the box
    //2 - take out a number from the box
        //there is an additional x (1<=x<=100) indicating the result of the operation

// 6
// 1 1
// 1 2
// 1 3
// 2 1
// 2 2
// 2 3
// queue

// 6
// 1 1
// 1 2
// 1 3
// 2 3
// 2 2
// 2 1
// not sure
// could be either stack or priority queue

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    stack<int> st;
    queue<int> q;
    priority_queue<int> pq;

    int n; cin>>n;
    bool itsST = true;
    bool itsQ = true;
    bool itsPQ = true;

    int tracker=0;

    for (int i=0; i<n; i++){ //for each operation
        int op; cin>>op;
        if (op==1) {
            tracker+=1;
            int in; cin>>in;
            st.push(in); q.push(in); pq.push(in);
        } else {
            tracker-=1;
            if (tracker < 0) { //taking out on empty structures
                cout<<"impossible"<<endl;
                return 0;
            }
            int out; cin>>out;
            int st_out = st.top(); st.pop();
            int q_out = q.front(); q.pop();
            int pq_out = pq.top(); pq.pop();
            if (st_out != out) itsST = false;
            if (q_out != out) itsQ = false;
            if (pq_out != out) itsPQ = false;
        }
    }

    int count=0;
    if (itsST){
        // cout<<"it can be a stack"<<endl;
        count++;
    }
    if (itsQ){
        // cout<<"it can be a queue"<<endl;
        count++;
    }
    if (itsPQ){
        // cout<<"it can be a priority queue"<<endl;
        count++;
    }

    if (count > 1) cout<<"not sure"<<endl;
    else if (count == 0) cout<<"impossible"<<endl;
    else {
        if (itsST) cout<<"stack"<<endl;
        if (itsQ) cout<<"queue"<<endl;
        if (itsPQ) cout<<"priority queue"<<endl; 
    }

    return 0;
}