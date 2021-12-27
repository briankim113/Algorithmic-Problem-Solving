//Input
//One line with 4 numbers (a, b, mod, K) separated by space.
//0 < a, b < 65535
//2 < mod < (2^32)-1
//1 < K < 5x10^6

//Output
//K-th smallest number of all the generated numbers.

//2 3 100000007 23
//434

//quick select algorithm
#include <iostream>
using namespace std;

unsigned n = 5000000;
unsigned arr[5000000];

void randomize(unsigned a,unsigned b,unsigned mod){
	for(int i=0 ; i<n ; i++){
		a = 31014 * (a & 65535) + (a >> 16);
		b = 17508 * (b & 65535) + (b >> 16);
		arr[i] = ((a << 16) + b) % mod;
	}
}

//https://www.geeksforgeeks.org/quickselect-algorithm/
//getting timeout error?

// It considers the last element as pivot and moves all smaller element to left of it and greater elements to right
int partition(int l, int r){
    int x = arr[r];
    int i = l;
    for (int j = l; j <= r-1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kthSmallest(int l, int r, int k){
    // Partition the arr around last element and get position of pivot element in sorted arr
    int index = partition(l, r);

    // If position is same as k
    if (index - l == k - 1) return arr[index];

    // If position is more, recur for left subarray
    if (index - l > k - 1) return kthSmallest(l, index-1, k);

    // Else recur for right subarray
    return kthSmallest(index+1, r, k-index+l-1);
}

int main(){
    unsigned a, b, mod, k;
    cin>>a>>b>>mod>>k;
    randomize(a, b, mod);
    cout<<kthSmallest(0, n-1, k)<<endl;

    return 0;
}