//repeating tasks with start time 5, end time 8, and repetition interval 100 will occur [5...8], [105...108], [205...208]
//one-time tasks with start time and end time, no repetition

//in:
//N for # of one-time tasks, M for # of repeating tasks
//each of the following N lines contains two integers (start time, end time)
//then each of the following M lines contains three integers (start time, end time, repetition interval)

//out:
//print one line (no endl) containing NO CONFLICT or CONFLICT (if theres at least one)

//note:
//all int are between 0 and 1,000,000
//end time is larger than start time
//repetition interval is positive
//you should be able to represent each time slot with one of two values (hence bitset might come in handy).
//marking calendar with (yes event scheduled or no event not scheduled) - for small memory
    //same for AWESOME numbers problem
//if a task starts before million and ends after million (for the repeating task), still mark it as a scheduled task

//ex 1
//2 0
//10 20
//20 30
//out: NO CONFLICT

//ex 2
//2 0
//10 30
//20 21
//out: CONFLICT

//ex 3
//1 1
//1000 2000
//0 10 1000
//out: CONFLICT
//[0,10], [1000,1010], [1000,2000]

//test case from Morgan
// 1 1
// 20 30
// 5 5 4
// CONFLICT
// 5 5 4 is a conflict with itself

//test case from Morgan
// 2 2
// 30 50
// 70 90
// 20 25 70
// 55 60 100
// NO CONFLICT

#include <iostream>
#include <bitset>
using namespace std;
#define M 1000000 //1000000

int main(){
    int n_one, m_repeat; cin>>n_one>>m_repeat;
    bitset<M> bset;

    for (int i=0; i<n_one; i++){ //read all one-time
        int start, end; cin>>start>>end;
        for (int bit=start; bit<end; bit++){
            if (bset[bit]) {cout<<"CONFLICT"<<endl; return 0;}
            else bset[bit] = 1;
        }
    }

    for (int i=0; i<m_repeat; i++){ //read all repeating
        int start, end, repeat; cin>>start>>end>>repeat;

        int bit=start;

        while (bit<=M) {
            if (bset[bit]) {cout<<"CONFLICT"<<endl; return 0;}
            else bset[bit] = 1;
            bit++;
            if (bit == end) {start += repeat; end+= repeat; bit = start;}
        }
    }
    cout<<"NO CONFLICT"<<endl; return 0;
}