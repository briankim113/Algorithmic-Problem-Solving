#include <iostream>
using namespace std;

int main(){
    string a;
    getline(cin, a);

    char c;
    int count=0;
    bool sawLetter = false;

    for (int i=0; i<a.size(); i++){
        if (i == a.size()-1) { //we've reached the end
            if (sawLetter) count++;
            continue;
        }

        c = a[i];
        //upper case
        if (c >= 'A' && c <= 'Z') {
            sawLetter = true;
            continue;
        }
        //lower case
        else if (c >= 'a' && c <= 'z') {
            sawLetter = true;
            continue;
        }
        //not an alphabet letter
        else {
            if (sawLetter) count++;
            sawLetter = false;
        }
    }

    cout<<count<<endl;

    return 0;
}