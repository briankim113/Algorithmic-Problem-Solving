//resubmitted to delete unnecessary comments
//algorithm discussed with Lauren Gatesman (Java)

#include <iostream>
#include <queue>

using namespace std;
int main(){
    int capacity, minutes, totalNum;
    queue< pair<int, int> > leftQ, rightQ; // <index, arrivalTime>

    //for the boat initial data - updated as we cross / wait
    string currSide = "left";
    int currTime = 0;
    // int carsTransported = 0; //total - cannot exceed totalNum - is it needed?    

    cin>>capacity>>minutes>>totalNum;
    string ln;
    int i=0;
    while (getline(cin, ln)){
        int car_time; string car_side; cin>>car_time>>car_side;
        pair<int, int> currCar = make_pair(i, car_time);
        if (car_side=="left") leftQ.push(currCar);
        else rightQ.push(currCar);
        i++;
    }

    // cout<<"left:";
    // while(!leftQ.empty()){
	// 	cout<<" "<<leftQ.front().first;
    //     cout<<" "<<leftQ.front().second;
	// 	leftQ.pop();
	// }
    // cout<<"right:";
    // while(!rightQ.empty()){
	// 	cout<<" "<<rightQ.front().first;
    //     cout<<" "<<rightQ.front().second;
	// 	rightQ.pop();
	// }

    // is there a car waiting on my side?
    // YES - load until A: reach capacity / B: no more
    // NO - is there a car on the other side?
        // 	YES - cross the river, log and repeat
        // 	NO - wait until next car arrives

    int* outputs = new int[totalNum];

    while (!leftQ.empty() || !rightQ.empty()){
        // cout<<"currSide, currTime "<<currSide<<currTime<<endl;

        //using pointers * and references & to ensure that thisQ and thatQ are actually changing the leftQ and rightQ data
        //needed because thisQ and thatQ are local variables that will get deleted
        queue< pair<int, int> > *thisQ, *thatQ;

        if (currSide == "left") {
            thisQ = &leftQ;
            thatQ = &rightQ;
        } else {
            thatQ = &leftQ;
            thisQ = &rightQ;
        }

        if (!thisQ->empty() && currTime >= thisQ->front().second) { //is there a car waiting on my side?
            // cout<<"there is a car on my side"<<endl;
            int carsLoaded = 0; //per trip - cannot exceed capacity
            //yes so load until we reach capacity or there is no more car waiting on this side
            while (!thisQ->empty() && carsLoaded < capacity && currTime >= thisQ->front().second) {
                pair<int, int> currCar = thisQ->front();
                outputs[currCar.first] = currTime+minutes;
                thisQ->pop();
                carsLoaded++;
            }
            // cout<<"loaded "<<carsLoaded<<" cars"<<endl;
            //"unload" - update time and switch side
            currTime += minutes;
            currSide = (currSide=="left") ? "right" : "left";
        } else { //no there is no car here
            // is there a car on the other side?
            // cout<<"there is no car on my side"<<endl;
            if (!thatQ->empty() && currTime >= thatQ->front().second) { //YES then cross empty handed
                // cout<<"there is a car on the other side so cross"<<endl;
                currTime += minutes;
                currSide = (currSide=="left") ? "right" : "left";
            } else { //NO then we wait
                // cout<<"there is no car on the other side either so wait"<<endl;
                if (thisQ->empty()) currTime = thatQ->front().second;
                else if (thatQ->empty()) currTime = thisQ->front().second;
                else currTime = min(thisQ->front().second, thatQ->front().second);
            }
        }
        // cout<<"endSide, endTime "<<currSide<<currTime<<endl<<endl;
    }
    //we are done with transporting everything
    //now go through outputs and print in order
    for (int idx=0; idx<totalNum; idx++){
        cout<<outputs[idx]<<endl;
    }

    return 0;
}