#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

string in, out;
vector<string> seqToTry;

void createSequences(){
    string io_string = string(in.length(), 'i') + string(in.length(), 'o');
    seqToTry.push_back(io_string);

    vector<char> charVector;

    while (next_permutation(io_string.begin(),io_string.end())){
        int count=0;

        for (int i=0; i<io_string.length(); i++){
            if (io_string[i]=='i') count++;
            else count--;

            if (count<0) {charVector.clear(); break;}
            else charVector.push_back(io_string[i]);
        }
        
        //made it without illegal
        string insertToSeq = "";
        for (int i=0; i<charVector.size(); i++) insertToSeq += charVector[i];
        if (insertToSeq != "") seqToTry.push_back(insertToSeq);
        charVector.clear();
    }
}


int main(){
    cin>>in>>out;
    createSequences();

    bool couldBeMatching = true;
    vector<string> matchingSeqs;
    stack<char> st;
    int in_idx=0, out_idx=0;

    for (int idx=0; idx<seqToTry.size(); idx++){
        string currentSeq = seqToTry[idx];

        for (int i=0; i<currentSeq.length(); i++){
            if (currentSeq[i]=='i') {st.push(in[in_idx]); in_idx++;}
            else {
                char toCheck = st.top();
                if (toCheck == out[out_idx]){st.pop(); out_idx++;}
                else {couldBeMatching = false; break;}
            }
        }

        if (couldBeMatching) matchingSeqs.push_back(currentSeq);
        //reset
        in_idx=0, out_idx=0; couldBeMatching = true; while (!st.empty()) st.pop();
    }
    
    //print results
    sort(matchingSeqs.begin(), matchingSeqs.end());

    cout<<"["<<endl;
    for (int i=0; i<matchingSeqs.size(); i++){
        string curr = matchingSeqs[i];
        for (int j=0; j<curr.length(); j++){
            if (j==curr.length()-1) cout<<curr[j];
            else cout<<curr[j]<<" ";
        }
        cout<<endl;
    }
    cout<<"]"<<endl;

    return 0;
}