//first is the one that has the highest amount paid
//second is the one that has the lowest amount paid
//person who paid the highest amount gets the prize equal to the difference between their bill and the lowest bill
//The selected forms are discarded, but the other ones remain in the pool for the next day
//compute how much money Trader Jane’s pays out in prizes

// 1 <= n <= 5000 on the first line (# of days in the promotion)
// for the next n lines
    // 0 <= k <= 100,000 to indicate the number of forms submitted
    // next k numbers specify the bill amounts for the daily drawing that day
    // each bill amount (as well as total amount of bills) is no larger than 1,000,000

// 2
// 2 1 2
// 2 1 2

// 2

// 2
// 2 1 1
// 2 2 2

// 0

// 2
// 3 10 5 1
// 1 9
// 13

// 4
// 4 10 5 1 2
// 0
// 3 9 1 7
// 2 3 2
// 9+3+8+5=25

// 5
// 3 1 2 3
// 2 1 1
// 4 10 5 5 1
// 0
// 1 2

// 2+1+9+4+3=19

//priority queue seems challenging bc we need to implement our own min-max heap
//then some sort of sorted vector/deque -> but I could use set instead for that
//how about a multiset that sorts and allows duplicates?

#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main(){
    int n;
    // cin>>n;
    string s1; getline(cin, s1);
    stringstream ss1(s1); ss1 >> n;
    multiset<int> ms; //low to high

    long sum = 0;
    for (int d=0; d<n; d++){
        // cout<<"day "<<d<<"\t";

        //read the entire line
        string s2; getline(cin, s2);

        //and break it down
        stringstream ss2(s2);
        int k; ss2 >> k;
        
        //put each bill into our ms
        int bill;
        while (ss2 >> bill) ms.insert(bill);

        // int k; cin>>k;

        // for (int i=0; i<k; i++) {
        //     int bill; cin>>bill;
        //     ms.insert(bill);
        // }

        // for (multiset<int>::iterator it=ms.begin(); it!=ms.end(); ++it)
        //     cout << ' ' << *it;
        // cout << '\n';

        //at the end of the day, draw low (first) and high (last)
        multiset<int>::reverse_iterator last = ms.rbegin(); //https://www.geeksforgeeks.org/multiset-rbegin-and-rend-function-in-c-stl/
        multiset<int>::iterator first = ms.begin();
        int diff = *last - *first;
        sum += diff;

        // cout<<"high "<<*last<<'\t';
        // cout<<"low "<<*first<<'\t';
        // cout<<"diff "<<diff<<'\t';
        // cout<<"sum "<<sum<<endl;

        ms.erase(first);
        ms.erase(next(last).base()); //https://stackoverflow.com/questions/1830158/how-to-call-erase-with-a-reverse-iterator
    }

    cout<<sum<<endl;
    return 0;
}