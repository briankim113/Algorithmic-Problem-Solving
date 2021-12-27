#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> dict;
    string str;

    while (cin >> str) {
        //inspired by https://stackoverflow.com/questions/26920212/c-splitting-string-on-non-alphabetic-characters
        int pos= 0;
        for (int i=0; i<str.length(); i++) str[i]=tolower(str[i]);

        while ((pos=str.find_first_not_of("abcdefghijklmnopqrstuvwxyz"))!=string::npos ) {
            if (pos != 0){
                string potential = str.substr(0,pos);
                if (find(dict.begin(), dict.end(), potential) == dict.end()) dict.push_back(potential);
            }
            str.erase(0, pos+1); //remove pos+1 to get rid of delimiter as well
        }

        // for the last substring left, if there is any
        if (str.length() > 0) { 
            if (find(dict.begin(), dict.end(), str) == dict.end()) dict.push_back(str);
        }
    }

    //sort and print
    sort(dict.begin(), dict.end());
    for (string word : dict) cout<<word<<endl;
    
    return 0;
}