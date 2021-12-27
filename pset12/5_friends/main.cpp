#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class Graph{
    int V;
    vector < set<int> > children;
    vector <bool> visited;
    vector <int> level;

public:
    Graph(int V){
		this->V = V;

        //all vectors should use 1 to V, where direct index i stands for the friend i
        children.resize(V+1);
        visited.resize(V+1);
        level.resize(V+1);

        for (int i=0; i<=V; i++){
            set<int> s; children[i] = s;
        }
    }

    void addEdge(int v, int w){
        children[v].insert(w);
		children[w].insert(v);
    }

    int traverse(int source, int score) {
        fill(visited.begin(), visited.end(), false);
        fill(level.begin(), level.end(), 0);

        int totalFriends = 0;
        queue<int> q; q.push(source);
		
		while (!q.empty()){
			int curr = q.front();
			visited[curr] = true;
            q.pop();

            //if I should continue BFS
            if (level[curr] < score) {
                //get this node's all children
                set<int> currChildren = children[curr];
                set<int>::iterator it = currChildren.begin();

                int currChild;

                while (it != currChildren.end()){
                    currChild = *it;
                    if (!visited[currChild]){
                        visited[currChild] = true;
                        level[currChild] = level[curr] + 1;
                        q.push(currChild);
                        totalFriends++;
                    }
                    it++;
                }
            }
		}
		return totalFriends;
	}
};

int main(){
    int f; cin>>f;
    int n; cin>>n;

    vector<pair <int, int> > input;
    set<int> users;
    int V = 0;

    //read input
    for (int i=0; i<n; i++){
        int f1; cin>>f1;
        int f2; cin>>f2;
        input.push_back(make_pair(f1, f2));
        users.insert(f1);
        users.insert(f2);

        if (f1 > V) V = f1;
        if (f2 > V) V = f2;
    }

    Graph g = Graph(V);

    for (int i=0; i<n; i++){
        g.addEdge(input[i].first, input[i].second);
    }

    for (set<int>::iterator it=users.begin(); it!=users.end(); it++){
        cout<<*it<<" "<<g.traverse(*it, f)<<'\n';
    }

    return 0;
}