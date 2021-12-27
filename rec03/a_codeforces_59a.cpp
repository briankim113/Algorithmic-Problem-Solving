//as little as possible letters should be changed in the word
//For example, the word HoUse must be replaced with house, and the word ViP — with VIP.
//If a word contains an equal number of uppercase and lowercase letters, you should replace all the letters with lowercase ones.

#include <iostream>
using namespace std;

int main(){
    string s; cin>>s;
    int lower_count, upper_count;

    for (int i=0; i<s.size(); i++){
        if ('a' <= s[i] && s[i] <= 'z') lower_count++;
        else if ('A' <= s[i] && s[i] <= 'Z') upper_count++;
    }

    if (lower_count >= upper_count){
        for (int i=0; i<s.size(); i++){
            cout<<(char) tolower(s[i]);
        }
    } else {
        for (int i=0; i<s.size(); i++){
            cout<<(char) toupper(s[i]);
        }
    }

    return 0;
}