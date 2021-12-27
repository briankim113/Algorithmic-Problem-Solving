#include <iostream>
using namespace std;

//helper functions
string switch_sign(string s){
    string res;
    if (s[0] == '+') res = '-'; else res = '+'; res += s[1];
    return res;
}

string compare_sign(char curr, char bend){
    if (curr != bend) return "+x";
    else return "-x";
}

int main(){
    int len; cin>>len;
    string curr_dir; cin>>curr_dir; if (curr_dir == "No") curr_dir = "+x";

    for (int i=2; i<len; i++){
        string bend_dir; cin>>bend_dir;

        // update curr_dir unless bend_dir is "No"
        if (bend_dir != "No"){
            //curr_dir -> x
            if (curr_dir[1] == 'x'){
                if (curr_dir[0] == '+') curr_dir = bend_dir;
                else if (curr_dir[0] == '-') curr_dir = switch_sign(bend_dir);
            }

            //curr_dir -> y
            else if (curr_dir[1] == 'y'){
                if (bend_dir[1] == 'z') continue;
                else curr_dir = compare_sign(curr_dir[0], bend_dir[0]);
            }

            //curr_dir -> z
            else if (curr_dir[1] == 'z'){
                if (bend_dir[1] == 'y') continue;
                else curr_dir = compare_sign(curr_dir[0], bend_dir[0]);
            }
        }
    }

    cout<<curr_dir;
    return 0;
}