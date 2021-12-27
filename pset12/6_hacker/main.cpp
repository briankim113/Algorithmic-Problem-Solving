//algorithm discussed with Lauren Gatesman on Java

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

class ReceiverInfo{ 
public:
    long p;
    long q;
    int e;
    long long d;
    long long phi;
    long long n;
    
    ReceiverInfo(long p, long q, int e, long long d, long long phi){
        this->p = p;
        this->q = q;
        this->e = e;
        this->d = d;
        this->phi = phi;
        this->n = p*q;
    }
};

class DisjointSet{
public:
    vector<int> parent; //size n+1 for 0 to n, 0 will be ignored

    DisjointSet(int n){
        for (int i=0; i<=n; i++) {
            parent.push_back(i);
        }
    }
 
    int Find(int k){
        if (parent[k] == k) return k;
        return Find(parent[k]);
    }
 
    void Union(int a, int b){
        int x = Find(a);
        int y = Find(b);
        parent[x] = y;
    }
};

//used for decoding the message (long long to char)
//https://stackoverflow.com/questions/2177781/how-to-calculate-modulus-of-large-numbers/8972838#8972838
char modular(long long base, long long exp, long long mod){
    int x = 1;
    long long power = base % mod;

    for (int i = 0; i < sizeof(int) * 8; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }

    return (char) x;
}

int main(){
    int n; cin>>n;  //2<=n<=10

    DisjointSet ds = DisjointSet(n);

    //rinfo[0~9] for user 1~10, hard-coded based on calculations provided by problem statement
    vector<ReceiverInfo> rinfo;
    rinfo.push_back(ReceiverInfo(11, 101, 3, 667, 1000));
    rinfo.push_back(ReceiverInfo(113, 131, 3, 9707, 14560));
    rinfo.push_back(ReceiverInfo(173, 181, 7, 4423, 30960));
    rinfo.push_back(ReceiverInfo(191, 313, 7, 42343, 59280));
    rinfo.push_back(ReceiverInfo(359, 373, 5, 106541, 133176));
    rinfo.push_back(ReceiverInfo(419, 727, 5, 182081, 303468));
    rinfo.push_back(ReceiverInfo(743, 757, 5, 224381, 560952));
    rinfo.push_back(ReceiverInfo(761, 787, 7, 512023, 597360));
    rinfo.push_back(ReceiverInfo(809, 919, 5, 148349, 741744));
    rinfo.push_back(ReceiverInfo(953, 10301, 3, 6537067, 9805600));


    map<int, string> hm;
    int sender, receiver;
    long double message;

    //figure out messages
    while (cin>>sender) {
        cin>>receiver>>message;

        long long d = rinfo[receiver-1].d;
        long long n = rinfo[receiver-1].n;
        char c = modular(message, d, n);
        
        map<int, string>::iterator it = hm.find(receiver);

        //already exists
        if (it != hm.end()) {
            it->second += c;
        } else {
            string s; s.push_back(c);
            hm.insert(make_pair(receiver, s));
        }

        //join sender and receiver as part of one conversation set
        ds.Union(sender, receiver);
    }

    //figure out conversation sets
    map<int, int> foundParents; //key - parent, value - index for setOfUsers
    vector< vector<int> > setOfUsers;

    int idx = 0;
    for (int i=1; i<=n; i++){
        //those with the same root par are in the same conversation set
        int par = ds.Find(ds.parent[i]);

        //first in this conversation set
        if (foundParents.find(par) == foundParents.end()){
            vector<int> v; v.push_back(i);
            setOfUsers.push_back(v);
            foundParents.insert(make_pair(par, idx++));
        }
        //we already found another person in this conversation set
        else {
            setOfUsers[ foundParents[par] ].push_back(i);
        }
    }

    //print conversation sets
    for (int i=0; i<setOfUsers.size(); i++){
        cout<<'[';
        for (int j=0; j<setOfUsers[i].size(); j++){
            cout<<setOfUsers[i][j];
            if (j!=setOfUsers[i].size()-1) cout<<", ";
        }
        cout<<']'<<endl;
    }

    //print messsages
    for (map<int, string>::iterator it = hm.begin(); it != hm.end(); it++){
        cout<<"Person "<<it->first<<" Received: "<<it->second<<endl;
    }

    return 0;
}