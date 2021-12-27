#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int S; //number of courses that can be taken in one semester
int N; //number of courses Ayu must take to complete her major

class Graph {
public:
    priority_queue< int, vector<int>, greater<int> > pq; //smallest course id first
    vector<int> edgesIn;
    vector < vector<int> > children;

    Graph(){
        edgesIn.resize(N+1); //for direct index access inside addEdge()
        children.resize(N+1);

        fill(edgesIn.begin(), edgesIn.end(), 0); //initially 0
    }
  
    //edge from course v to course w, where v is prereq to w
    void addEdge(int v, int w){
        children[v].push_back(w);
        edgesIn[w]++;
    }

    void traverse() {
        // for (int i=1; i<=N; i++){
        //     cout<<edgesIn[i]<<" ";
        //     for (int j=0; j<children[i].size(); j++){
        //         cout<<children[i][j]<<" ";
        //     } cout<<endl;
        // }

        int semester = 0;
        while (!pq.empty()) {
            semester++;
            cout<<"Sem"<<semester<<":";

            vector<int> coursesToAddLater;
            
            // take as many courses you can in that semester
            int count = 0;
            while (!pq.empty() && count < S){
                int n = pq.top();
                cout<<" "<<n;
                // cout<<n<<" pop\n";

                //get all the course n's children and subtract one from their edgesIn
                for (int i=0; i<children[n].size(); i++){
                    int child = children[n][i];
                    // cout<<"edgesIn[child] before: "<<edgesIn[child];
                    edgesIn[child]--;
                    // cout<<"edgesIn[child] after: "<<edgesIn[child];
                    if (edgesIn[child] == 0) {
                        coursesToAddLater.push_back(child);
                    }
                }
                pq.pop();
                count++;
            }            
    
            // push into our priority queue any courses we can visit now
            for (int i=0; i < coursesToAddLater.size(); i++){
                // cout<<coursesToAddLater[i]<<" push\n";
                pq.push(coursesToAddLater[i]);
            }
            cout<<endl;
        }
    }
};

int main(){
    cin>>S>>N;

    Graph g;

    //for each course i
    for (int i=1; i<=N; i++){
        // cout<<"------course "<<i<<"-------\n";
        int P; //number of pre-reqs for this course
        cin>>P;

        if (P==0) g.pq.push(i); //course i can be taken from the beginning

        for (int p=1; p<=P; p++){
            int id; //course id of the pre-req to course i
            cin>>id;
            g.addEdge(id, i); //taking course id leads to course i;
            // cout<<id<<" ";
        }
        // cout<<'\n';
    }

    g.traverse();
}