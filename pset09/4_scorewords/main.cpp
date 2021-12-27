/*
7 2
administer 100000
spending 200000
manage 50000
responsibility 25000
expertise 100
skill 50
money 75000
the incumbent will administer the spending of kindergarden milk money
and exercise responsibility for making change he or she will share
responsibility for the task of managing the money with the assistant
whose skill and expertise shall ensure the successful spending exercise
.
this individual must have the skill to perform a heart transplant and
expertise in rocket science
.
Output:
700150
150
*/

#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> dict;
    int m, n; //number of words, number of sentences
    cin>>m>>n;

    for (int i=0; i<m; i++){
        string word; int value;
        cin>>word>>value;
        dict.insert(make_pair(word, value));
    }
    cin.ignore();

    string s;
    long res = 0;
    getline(cin, s);

    for (int i=0; i<n; i++){
        while (s != ".") {
            stringstream ss(s);
            string substr;
            while (ss >> substr) {
                if (dict.find(substr) != dict.end()){
                    res += dict[substr];
                }
            }
            getline(cin,s);
        }
        cout<<res<<'\n';
        res = 0;
        getline(cin,s);
    }

    return 0;
}