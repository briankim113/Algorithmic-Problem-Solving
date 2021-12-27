#include <iostream>
using namespace std;

int main(){
    int mo, it;
    float down, loan;
    cin>>mo>>down>>loan>>it;

    int dep_mo[it];
    float dep_perc[it];
    for (int i=0; i<it; i++){cin>>dep_mo[i]>>dep_perc[i];}

    float month_pay = loan/mo;
    float car_value = down+loan;

    int idx = 0;
    int curr_mo = dep_mo[idx];
    float curr_perc = dep_perc[idx];

    //for month 0
    car_value *= (1.0-curr_perc);
    curr_mo++; //gotta erase 1 at the end;

    while (car_value <= loan) {
        if (idx<=it && curr_mo == dep_mo[idx+1]){ //idx<=it check so we can access [idx+1]
            idx++;
            curr_perc = dep_perc[idx];
        }
        car_value *= (1.0-curr_perc);
        loan -= month_pay;
        curr_mo++;
    }

    if (curr_mo-1 == 1) cout<<curr_mo-1<<" month"<<endl;
    else cout<<curr_mo-1<<" months"<<endl;

    return 0;
}