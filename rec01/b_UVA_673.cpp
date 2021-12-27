//Wrong Answer

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int num;
    cin>>num;
    cin.ignore(); //skip after number is read

    //for each string
    for(int line=0; line<num; line++){ //could this be switched into while getline?
        string s;
        getline(cin, s);
        stack<char> st; //create a new stack

        //for each character
        for (int i=0; i<s.length(); i++){
            char curr = s[i]; //go thru each char

            //open parenthesis
            if (curr == '(' || curr == '[') st.push(curr); 

            //close parenthesis
            else { 
                //st is empty -> error
                if (st.empty()) {cout<<"No empty"<<endl; break;}
                //st is not empty -> check to see if top is a match
                else { 
                    if (curr==']') { // ] requires [
                        if (st.top() != '[') {cout<<"No"<<endl; break;}
                    } else { // ) requires (
                        if (st.top() != '(') {cout<<"No ("<<endl; break;}
                    }
                }
                st.pop(); //there was a match for close parenthesis -> now next char
            }
        }
        //finished iterating through the string
        cout<<"Yes"<<endl;
    }
    return 0;
}