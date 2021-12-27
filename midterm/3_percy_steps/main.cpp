// 4 2

// 0011
// 0101
// 0110
// 1001
// 1010
// 1100

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m; cin>>n>>m;
    string io_string = string(n-m, '0') + string(m, '1');
    cout<<io_string<<endl;

    while (next_permutation(io_string.begin(),io_string.end())){
        cout<<io_string<<endl;
    }

    return 0;
}

/*
other approaches

1. backtrack
for each bit, check whether we can put 0 or 1
we can put a 0 if the number of remaining length is larger than that of available number of 1
we can put a 1 if the number of remaining 1 is larger than that of 0
when n=m=0, reach the base case and print

void percyStr(int n, int m, string bitstring){
    if (n==0) {
        cout<<bitstring<<endl;
        return;
    }
    if (n > m) { //we put a 0 and the length goes down
        percyStr(n-1, m, bitstring+"0");
    }
    if (m > 0) { //we put a 1 and both the length and number of 1 go down
        percyBitString(n-1, m-1, bitstring+"1");
    }
}
percyStr(n, m, "");

2. iteration
for (int i=0; i<(1<<n); i++) { //loop from 1 to 2^N-1
    int count = 0;
    for (int j=0; j<n; j++) {
        if (i & (1<<j) > 0) count++; //j bit of i is 1
    }
    if (count == m) { //this is a valid string - output binary representation
        int num = i;
        string ans = "";
        while (num > 0) { //lowbit to highbit
            ans += char((num%2)+'0');
            num /= 2;
        }
        reverse(ans.begin(), ans.end()); //and reverse
        cout<<ans<<endl;
    }
}
*/