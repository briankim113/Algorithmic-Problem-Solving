//in:
//1. contains an integer m (7<=m<=3650) for the # of days for calculation
//2. contains another integer n (1<=n<=100) representing the number of labor unions
//3. the ith of the next n lines contain a positive integer s_i (never a multiple of 7) giving the striking period of labor union i
//out: total number of days with strikes<<endl;

//a few notes
//day 1 is always Sunday
//subways don't work if at least one of the unions is on strike EXCEPT Fridays and Saturdays
//make sure you think of more than one week worth of repeats

//example 1
//14
//3
//4
//3
//8

//14 - num of days
//3 - num of unions
//4 - 4, 8, 12
//3 - 3, 6, 9, 12
//8 - 8
//Fri/Sat - 6, 7, 13, 14
//3, 4, 8, 9, 12
//out -> 5

//example 2
//100
//4
//12
//15
//25
//40

//100 - num of days
//4 - num of unions
//12 - 12, 24, 36, ... 96
//15 - 15, 30, 45, ... 90
//25 - 25, 50, 75, 100
//40 - 40, 80
//Fri/Sat - 6, 7, 13, 14, 20, 21, 27, 28, 34, 35, 41, 42, 48, 49, 55, 56, 62, 63, 69, 70, 76, 77, 83, 84, 90, 91, 97, 98
//12, 15, 24, 25, 30, 36, 40, 45, 50, 60, 72, 75, 80, 96, 100
//out -> 15

//test 1
//7
//1
//1

//1, 2, 3, 4, 5, 6, 7
//Fri/Sat - 6, 7
//1, 2, 3, 4, 5
//out -> 5

//test 2
//7 -> days
//5 -> unions
//6
//5
//4
//3
//2

//Fri/Sat - 6, 7
//2, 3, 4, 5, 6
//2, 3, 4, 5
//out -> 4

#include <iostream>
#include <set>
using namespace std;

bool isWeekend(int i){
    if (i % 7 == 0){
        return true;
    } else if (i % 7 == 6) {
        return true;
    } else {
        return false;
    }
}

int main(){
    int totalDays; cin>>totalDays;
    int unionNum; cin>>unionNum;

    set<int> strikeDays;
    int count=0;

    for (int i=0; i<unionNum; i++){ //for each line of union
        int repeat; cin>>repeat;
        for (int day=repeat; day<=totalDays; day+=repeat){
            if (!isWeekend(day)){ //not weekend
                if (strikeDays.find(day) == strikeDays.end()){ //day doesn't exist
                    strikeDays.insert(day); //insert and count
                    count++;
                }
            }
        }
    }

    cout<<count<<endl;

    return 0;
}