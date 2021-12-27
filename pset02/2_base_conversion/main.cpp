#include <iostream>
using namespace std;

int main(){
    int origBase, newBase;
    string inputStr;
    cin>>origBase>>newBase>>inputStr;

    //origBase to decimal
    long long resInDec = 0;
    long long digitValue = 1;

    for (int i = inputStr.length()-1; i>=0; i--){
        char curr = inputStr[i]; //take out the least significant digit
        int n;
        if ('0' <= curr && curr <= '9') n = (int)curr-48; //0-9
        else n = (int)curr-55; //A-F

        if (n >= origBase){
            cout<<inputStr<<" is an illegal base "<<origBase<<" number";
            return -1;
        }

        resInDec += n * digitValue; //calculate the ith digit value
        digitValue *= origBase; //calculate the i+1th digit value
    }

    //decimal to newBase
    string resInNew = "";
    if (resInDec == 0) resInNew = "0";
    
    while (resInDec > 0){
        int n = resInDec % newBase; // remainder
        resInDec /= newBase; // calculate what's left

        if (0 <= n && n <= 9) resInNew = (char)(n+48) + resInNew; //0-9
        else resInNew = (char)(n+55) + resInNew; //A-F
    }
 
    cout<<inputStr<<" base "<<origBase<<" = "<<resInNew<<" base "<<newBase;

    return 0;
}