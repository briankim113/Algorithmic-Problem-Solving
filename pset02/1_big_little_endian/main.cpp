// what: read a list of integers and report the integers that the binary representations of the input integers would represent on an opposite-endian machine
// tip: This is a quick review of a concept from CSO and an exercise in bit manipulation. You do not really need to convert the values to their binary or hex representation!

// -2147483648 <= n <= 2147483647 -> n is a signed 32-bit int, so we have 4 bytes of 8-bit grouping

// example 3
// 1 in decimal -> 00000000 | 00000000 | 00000000 | 00000001 in little endian
// 00000001 | 00000000 | 00000000 | 00000000 in big endian -> 16777216 in decimal

// '1' <-> '4' 
// get 1 (leftmost in) through input & 0xFF000000
// and move it 3 bytes to the right to make it end up at 4 (rightmost out)
// get 4 (rightmost in) through input & 0x000000FF
// and move it 3 bytes to the left to make it end up at 1 (leftmost out)
// same logic for '2' <-> '3'

#include <iostream>
using namespace std;

int main(){
    int i; cin>>i;
 
    int byte1out = (i & 0x000000FF) << 24; //4 -> 1, move 24 bits left
    int byte2out = (i & 0x0000FF00) << 8; //3 -> 2, move 8 bits left
    int byte3out = (i & 0x00FF0000) >> 8; //2 -> 3, move 8 bits right
    int byte4out = (i & 0xFF000000) >> 24; //1 -> 4, move 24 bits right
 
    int result = (byte1out | byte2out | byte3out | byte4out);
    cout<<i<<" converts to "<<result;

    return 0;
}