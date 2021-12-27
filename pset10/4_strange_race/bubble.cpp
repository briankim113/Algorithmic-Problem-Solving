#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int* a = new int[n];
    for (int i=0; i<n; i++) cin>>a[i];

    long res=0;
    //https://gateoverflow.in/14398/Number-swappings-bubble-least-possible-shortcut-available

    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (a[i] > a[j]) res++;
        }
    }

    cout<<res<<'\n';

    return 0;
}