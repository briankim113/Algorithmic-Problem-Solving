// length of s is less than 10^6
// s will contain only lower case letters, spaces, and the character <

// a<bcd<
// bc

// prind<tf
// printf

// as<d<<
// 

// I add the letter to the result
// if the letter is < then I delete the most recently put in character

#include <iostream>
using namespace std;

int main(){
    char c; string res;
    while(cin.get(c)){
        if (c != '<') res += c;
        else res.pop_back(); //remove last character
    }
    cout<<res;
    return 0;
}