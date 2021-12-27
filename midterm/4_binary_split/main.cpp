// 1. Transform n into binary representation
//     1. 13 → 1101 = 8 + 4 + 1 = 13
// 2. From the lowbit to highbit, record the indices of bits that are 1
//     1. i1 = 1, i2 = 0, i3 = 1, i4 = 1
//     2. 1 3 4
//     3. j1 = 1, j2 = 3, j3=4
// 3. Compute a(n) and b(n) and directly use the indices above
//     1. a(n) → odd index of j = 2^(j1-1) + 2^(j3-1) = 1 + 8 = 9
//     2. b(n) → even index of j = 2^(j2-1) = 4
//     3. 9 and 4

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int dec; cin>>dec;
    vector<int> vi;
    int index = 1;

    //loop from lowbit to highbit
    while (dec > 0){
        int n = dec % 2; // remainder
        if (n == 1) vi.push_back(index);
        dec /= 2; // calculate what's left
        index++;
    }

    //originally i=even -> a(n) and i=odd -> b(n)
    //we are gonna make it reverse
    int an, bn;
    for (int i=0; i<vi.size(); i+=2)
        an += pow(2, vi[i]-1);
    for (int i=1; i<vi.size(); i+=2)
        bn += pow(2, vi[i]-1);
    cout<<an<<" "<<bn<<endl;

    /*
    //a more direct bit manipulation approach
    int count = 0, a = 0, b = 0;
    for (int i=0; i<31; i++){
        if ((n&(1<<i)) != 0) { //n is 1 at this i index
            if (count % 2 == 0) { //even
                a = a + (1 << i);
            } else { //odd
                b = b + (1 << i);
            }
            count++;
        }
    }
    */

    return 0;
}