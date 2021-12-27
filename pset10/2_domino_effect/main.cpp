/*
DFS

n distinct events
Event i triggers E[i], which triggers E[E[i]], and so on
We choose an event to trigger that will maximize the overall triggered events

First line contains int n
    1<= n < 50000
Each line i of n lines
    ith line contains a single integer E[i]
    event i will trigger E[i]
    1 <= E[i] <= n

If there are more than one of same number of triggered events, choose the one with the smallest value

Essentially:
- Each event is a node and triggers are edges
- Perform a DFS and print out the largest depth

Input:
3
2
3
1
Output:
1
Explanation:
2 -> 3, total of 2 events

Input:
4
2
1
2
3
Output:
4
Explanation:
3 -> 2 -> 1, total of 3 events


My cases

Input:
4
2
4
2
2
Output:
1
Explanation:
Both 1 and 3 trigger (1/3) -> 2 -> 4, so output should be the smaller value 1

Input:
3
2
1
2
Output:
3
Explanation:
1 -> 2
2 -> 1
3 -> 2 -> 1
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

//https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
class Graph {
public:
    map<int, bool> visited;
    map<int, vector<int> > adj;
  
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }
  
    int DFS(int v, int count){
        visited[v] = true;
        count++;
    
        for (vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                return DFS(*i, count);
        
        return count;
    }
};

int main(){
    Graph g;
    int n; cin>>n;
    for (int i=1; i<=n; i++) {
        int t; cin>>t;
        g.addEdge(i, t);
    }

    int event; int maxEvents = 0;

    for (int i=1; i<=n; i++) {
        //reset visited
        for (map<int,bool>::iterator it=g.visited.begin(); it!=g.visited.end(); it++){
            it->second = false;
        }
        
        int curr = g.DFS(i,0);
        if (maxEvents < curr) {
            maxEvents = curr;
            event = i;
        }
    }
    cout << event << '\n';
  
    return 0;
}