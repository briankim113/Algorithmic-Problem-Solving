//failing test 2 and test 7

//May be useful to revisit recursion
//Something like stack sounds useful? Like the "rightmost" int smaller than current

//A is the entrance for each train
//B is the exit
//S is the switching track

//coaches of a train can enter the switching track from direction A and must leave in dicrection B
//individual coaches can be disconnected from the rest of the train as they enter S so they can be reorganized before continuing in B
//if a coach enters S from direction A, it must leave in direction B
//if a coach leaves in direction B, it cannot return back to S

//assume that a train consists of n coaches {1, 2, ..., n}
//dispatcher wants to know whether these coaches can pull out at B in the order of {a1, a2, ... an}

//in
//1st line: integer n <= 1000 for # of coaches
//each of the next lines (except last) is the sequence {a1...an} that the dispatcher wants
//last line contains just '0' to indicate the end of input

//out
//result for each permutation (so for every line)
//if the sequence is feasible, print Yes\n
//if not, print No\n

//ex 1
//4
//3 2 4 1
//0

//Yes

//ex 2
//5
//1 2 3 4 5
//4 5 1 3 2
//0

//Yes
//No -> 1 goes in, 2 goes in, 3 goes in, 4 goes in, 4 goes OUT, 5 goes in, 5 goes OUT, want to get 1 out but 3 is on top / then 2 then 1!!

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    int count=0;
    int last_in=0;
    stack<int> coaches;

    while (cin) {
        int num; cin>>num;
        if (num == 0) break;

        if (coaches.empty()){
            for (int i=1; i<num; i++) coaches.push(i);
            last_in=num;
            count++;
        } else {
            if (num == coaches.top()){
                coaches.pop(); //top is out
                count++;
            } else if (num > coaches.top()){
                for (int i=last_in+1; i<num; i++) coaches.push(i);
                last_in=num;
                count++;
            } else { //invalid 
                cout<<"No"<<endl;
                for (int c=count+1; c<n; c++) {int throwaway; cin>>throwaway;}
                stack<int> empty; swap(coaches, empty);
                count=0;
            }
        }

        if (count == n){ //finished
            cout<<"Yes"<<endl;
            stack<int> empty; swap(coaches, empty);
            count=0;
        }
    }

    return 0;
}