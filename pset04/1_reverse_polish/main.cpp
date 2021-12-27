#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//implemented code from the algorithm provided in class

// 4 + ( 5 * 6 ) / ( 1 + 2 + 3 )
// 456*12+3+/+
// ( 1 + 1 ) * ( 4 * 5 + 1 ) - 4
// 11+45*1+*4-

int precedence(char ch){
    if (ch == '*' || ch == '/') return 2;
    else return 1;
}

int main(){
    vector<char> vec; char c; string s;
    while (cin>>c) vec.push_back(c);
    stack<char> opStack;

    for (int i=0; i<vec.size(); i++){
        char curr = vec[i];

        //0-9
        if (isdigit(curr))      s += curr;

        //braces
        else if (curr == '(')   opStack.push(curr);
        else if (curr == ')'){
            while (opStack.top() != '('){
                s += opStack.top(); opStack.pop();
            }
            opStack.pop();
        }

        //+,-,*,/
        else {
            while (!opStack.empty() && opStack.top() != '('
                && precedence(curr) <= precedence(opStack.top())){
                s += opStack.top(); opStack.pop();
            }
            opStack.push(curr);
        }
    }

    while (!opStack.empty()){
        s += opStack.top(); opStack.pop();
    }

    cout<<s<<endl;

    return 0;
}