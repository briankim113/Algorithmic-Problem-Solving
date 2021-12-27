//each person belongs to exactly one friend group
//if a person arrives to be added to the queue and they are the first one
    //they join the queue at the very end
//otherwise, if some friends are already in the queue
    //they join that friend-group (queue up after the last of their friends)
//dequeueing works the same as in the standard queue

//push - new element/friend added to the queue
//pop - dequeues an element/friend

//input
//1<=n<=1000 to the number of friend groups
//n group descriptions, one per line
    //each group: k for number of friends in the group, followed by k integers identifying all the friends
    //friends are identified by their unique id's [0, 999999]
    //single friend group may consist of up to 1000 friends
    //hence n=1000, and every group is 1000 friends, up to 999999

//list of test instructions
    //Push id - add the person with the given id to the friend-queue
    //Pop - print the id of the first element/friend and remove them from the friend-queue
    //Shutdown - stop your processing the friend-queue - end of input

//output
//for each pop instruction, print the id of the element/friend removed

// 2
// 3 1 2 3
// 3 4 5 6
// Push 1
// Push 4
// Push 2
// Push 5
// Push 3
// Push 6
// Pop
// Pop
// Pop
// Pop
// Pop
// Pop
// Shutdown

// 1 2 3 4 5 6 - new lines

// 2
// 3 1 2 3
// 3 4 5 6
// Push 1
// Push 2
// Push 4
// Pop
// Pop
// Push 3
// Push 5
// Pop
// Pop
// Push 6
// Pop
// Pop
// Shutdown

// 1 2 4 5 3 6 - new lines
    
#include <iostream>
#include <sstream>
#include <unordered_map> //amortized O(1) lookup
#include <unordered_set> //amortized O(1) lookup
#include <queue>
#include <vector>
using namespace std;

int main(){
    unordered_map<int, int> friend_to_group; //tracks which group a friend belongs to

    int g; cin>>g; //number of friend groups
    for (int i=0; i<g; i++){
        int f; cin>>f; //number of friends
        for (int j=0; j<f; j++){
            int p; cin>>p; //read each person
            friend_to_group[p] = i; //assigned to group id
        }
    }

    // unordered_map<int, int>::iterator itr;
    // for (itr = friend_to_group.begin(); itr != friend_to_group.end(); ++itr) {
    //     cout << itr->first << '\t' << itr->second << '\n';
    // }
    // cout << endl;
    // cout<<"finished reading data"<<endl;

    unordered_set<int> group_in_queue;      //tracks which groups are in the queue right now
    queue<int> order_of_groups;             //tracks which groups came in which order
    vector< queue<int> > queue_vec(g);      //our main "friend queue" where index is the friend's group id

    cin.ignore(); //to ignore some whitespace issue
    while(cin){
        //read the entire line
        string s; getline(cin, s);

        //and break it down
        stringstream ss(s);
        string op; ss>>op;
        
        if (op == "Shutdown") { //stop
            break;
        } else {
            int p; ss>>p;
            if (op == "Push") { //push
                int gid = friend_to_group[p];               //1. what is this friend's group id?
                queue_vec[gid].push(p);                     //2. we push the friend to its group queue inside our vector   

                //3. is this friend the only one in the group in the queue?
                if (group_in_queue.find(gid) == group_in_queue.end()){
                    order_of_groups.push(gid);                      //a. we add the group id to our order_of_groups queue
                    group_in_queue.insert(gid);                     //b. and we add it to our group_in_queue set
                }
            }
            else { //pop
                int first_group = order_of_groups.front();  //1. which group is the first in queue?
                cout<<queue_vec[first_group].front()<<endl; //2. print and pop out the first friend in that group
                queue_vec[first_group].pop();

                //3. if now that friend group queue is empty
                if (queue_vec[first_group].empty()) {           
                    order_of_groups.pop();                          //a. we erase the group id from our order_of_groups queue
                    group_in_queue.erase(first_group);              //b. and we erase it from our group_in_queue set
                }
            }
        }
    }

    return 0;
}