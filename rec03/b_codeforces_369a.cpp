//m clean bowls and k clean plates
//made an eating plan for the next n days

//he will eat exactly one dish per day
//to eat a dish, he needs exactly one clean plate or bowl

//can cook only two types of dishes
//He can eat dishes of the first type from bowls,
//and dishes of the second type from either bowls or plates.

//Find the minimum number of times Valera will need to wash a plate/bowl

//The first line of the input contains three integers n, m, k (1 ≤ n, m, k ≤ 1000)
//the number of the planned days, the number of clean bowls and the number of clean plates.

//The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 2).
//If ai equals one, then on day i Valera will eat a first type dish. If ai equals two, then on day i Valera will eat a second type dish.

//ex 1 -> 1
// 3 1 1 - 3 days, 1 bowl, 1 plate
// 1 2 1 - b, b/p, b

//ex 2 -> 1
// 4 3 1 - 4 days, 3 bowls, 1 plate
// 1 1 1 1 - b, b, b, b

//ex 3 -> 0
// 3 1 2 - 3 days, 1 bowl, 2 plates
// 2 2 2 - b/p, b/p, b/p

//ex 4 -> 4
// 8 2 2 - 8 days, 2 bowls, 2 plates
// 1 2 1 2 1 2 1 2 - b, b/p, b, b/p, b, b/p, b, b/p

#include <iostream>
using namespace std;

int main(){
    int days, bowls, plates; cin>>days>>bowls>>plates;
    int wash = 0;

    for (int d=0; d<days; d++){
        int dish; cin>>dish;
        if (dish==1) {
            if (bowls > 0) bowls--;
            else wash++;
        } else {
            if (plates > 0) plates--;
            else if (bowls > 0) bowls--;
            else wash++;
        }
    }

    cout<<wash;

    return 0;
}