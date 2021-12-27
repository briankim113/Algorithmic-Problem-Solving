#include <iostream>
#include <vector>

using namespace std;

// 5 3 1 3 4
// 10 4 9 8 4 2
// 20 4 10 5 7 4
// 90 8 10 23 1 2 3 4 5 7
// 45 8 4 10 44 43 12 9 8 2

// 1 4 sum:5
// 8 2 sum:10
// 10 5 4 sum:19
// 10 23 1 2 3 4 5 7 sum:55
// 4 10 12 9 8 2 sum:45

vector<int> cd, p, bestPerm;
int target, len, bestSum;

void rec(int i, int sum, vector<int> perm) {
    // cout<<"sum "<<sum<<"\tbestSum "<<bestSum<<"\ttarget "<<target<<endl;
    if (sum == target){
        // cout<<"sum == target"<<endl;
		for (int idx=0; idx<perm.size(); idx++){
            cout<<perm[idx]<<" ";
        }
    }

	if (sum >= bestSum && sum < target){
        // cout<<"bestSum < sum < target"<<endl;
        bestSum = sum;
		bestPerm = perm;
    }
		
	if (sum > target){
        // cout<<"sum > target"<<endl;
    }

	for (int j=i+1; i<len; i++){
        // cout<<j<<'\t';
		rec(j, sum, perm);
        vector<int> takeAtI = perm;
        takeAtI.push_back(cd[i]);
        rec(j, sum + cd[i], takeAtI);
    }
}    

int main(){
    cin>>target>>len;
    for(int i=0; i<len; i++){
        int c; cin>>c;
        cd.push_back(c);
    }
	rec(0, 0, p);

    //does not handle prints properly or when target is actually not being met
    return 0;
}