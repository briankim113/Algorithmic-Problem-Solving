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
word transformation

11
dip
lip
mad
map
may
pad
pip
pod
pop
sap
sip
4
may mad
map map
pip pod
mad dip

1
0
2
4
*/

int main(){  
    int dictNum;
    cin >> dictNum;

    vector<string> words;
    
    for (int i=0; i<dictNum; i++){
        string word;
        cin >> word;
        words.push_back(word);
    }

    int lineNum;
    cin >> lineNum;
    cin.ignore();

    for (int l=0; l<lineNum; l++){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string s, t;
        ss >> s >> t;

        // BFS
        queue<string> q;
        map<string, int> trans;

        trans[s] = 0;
        q.push(s);

        while (!q.empty() && trans.count(t) == 0) {
            string u = q.front();
            q.pop();
            
            // loop over every word in the dictionary
            for (int i = 0; i < words.size(); i++){
                const string &v = words[i];
                if (! trans.count(v) && u.length() == v.length()){
                    int diff = 0;
                    for (int j = 0; j < u.length(); j++)
                        if (u[j] != v[j])
                            ++diff;
                    if (diff == 1){
                        trans[v] = trans[u] + 1;
                        q.push(v);
                    }
                }
            }
        }    
        cout << trans[t] << endl;
    }

    return 0;
}