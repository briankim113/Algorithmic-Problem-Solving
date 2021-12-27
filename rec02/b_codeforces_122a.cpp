// Petya loves lucky numbers.
// Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7.
// For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.
// Petya calls a number almost lucky if it could be evenly divided by some lucky number.
// Help him find out if the given number n is almost lucky.
// Note that all lucky numbers are almost lucky as any number is evenly divisible by itself.


// Input: The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.
// Output: In the only line print "YES" (without the quotes), if number n is almost lucky. Otherwise, print "NO" (without the quotes).

// 47 -> YES (divisible by itself 47 which is lucky)
// 16 -> YES (divisible by 4 which is lucky)
// 78 -> NO

// the biggest factor is sqrt(1000) = 31...
// so we can put all lucky numbers up to 31 (which is 4 and 7)
// so essentially is it divisible by 4 OR 7 OR it is a lucky number itself
// otherwise NO

// not sure what's wrong with the code below?

#include <iostream>
using namespace std;

bool isLucky(string s){
    for (int i=0; i<s.length(); i++){
        if (s[i] != '4' && s[i] != '7') return false;
    }
    return true;
}

int main(){
    int in; cin>>in;
    string str = to_string(in);
    if (in % 4 == 0 || in % 7 == 0) cout<<"YES";
    else if (isLucky(str)) cout<<"YES";
    else cout<<"NO";

    return 0;
}