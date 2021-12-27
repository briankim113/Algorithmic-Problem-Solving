//algorithm discussed with Lauren Gatesman (Java)

#include <iostream>
using namespace std;

int main(){
    unsigned long n, l, r; cin>>n>>l>>r; //0~4,294,967,295
    char nc[32], lc[32], rc[32];

    //insert data - bit shift discussed in class
    for (int k=31; k>=0; k--){
        if (n & (1<<k)) nc[31-k]='1'; else nc[31-k]='0';
    }
    for (int k=31; k>=0; k--){
        if (l & (1<<k)) lc[31-k]='1'; else lc[31-k]='0';
    }
    for (int k=31; k>=0; k--){
        if (r & (1<<k)) rc[31-k]='1'; else rc[31-k]='0';
    }

    //check data
    // for (int k=0; k<32; k++){
    //     cout<<nc[k];
    // } cout<<endl;
    // for (int k=0; k<32; k++){
    //     cout<<lc[k];
    // } cout<<endl;
    // for (int k=0; k<32; k++){
    //     cout<<rc[k];
    // } cout<<endl;

    string res;
    int i=0;
    bool defAboveL = false; //we put 1 for x when L was 0
    bool defBelowR = false; //we put 0 for x when R was 1
    
    while (i<32){
        if (defAboveL && defBelowR) { //always within range
            // cout<<"within range"<<endl;
            //fill in the complement of N
            if (nc[i] == '0') res += '1';
            else res += '0';
        }        
        else { //gotta be careful!
            // cout<<"gotta be careful"<<endl;
            if (nc[i] == '0') { //x wants to be 1 -> but will putting 1 make us go OVER R?
                if (rc[i] == '1'){ // it won't go over
                    res += '1';
                    if (lc[i] == '0') defAboveL = true; //we put 1 for x when L was 0
                }
                else { // it will go over if we are NOT defBelowR
                    if (!defBelowR) res += '0';   
                    else {
                        res += '1';
                        if (lc[i] == '0') defAboveL = true; //we put 1 for x when L was 0
                    }
                }
            }
            else { //nc[i] == '1' - x wants to be 0 -> but will putting 0 make us go UNDER L?
                if (lc[i] == '0'){ // it won't go under
                    res += '0';
                    if (rc[i] == '1') defBelowR = true; //we put 0 for x when R was 1
                }
                else { // it will go under if we are NOT defAboveL
                    if (!defAboveL) res += '1';
                    else {
                        res += '0';
                        if (rc[i] == '1') defBelowR = true; //we put 0 for x when R was 1
                    }   
                }
            } 
        }
        i++;
    }

    // cout<<res<<endl;
	unsigned long number=stoul(res, nullptr, 2); //https://www.cplusplus.com/reference/string/stoul/
    cout<<number<<endl;

    return 0;
}

// test cases

// 0 0 0
// 0

// 15 0 271
// 256

// 10 10 10
// 10

// 100 50 60
// 59

// 109 2 39
// 18

// 10 4294967290 4294967295
// 4294967293

// 1005 10 14
// 10

// 55 10 800
// 776

// 4294967295 4294967295 4294967295
// 4294967295

// 0 0 64
// 64

// 80 30 70
// 47

// 10 30 40
// 37