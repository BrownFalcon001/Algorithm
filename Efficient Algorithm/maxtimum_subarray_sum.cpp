/*
 *   author: brownFalcon
 */
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N)

vector<int> A;

int KadanesAlgo() {
    int n = A.size();
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for(int i=0;i<n;i++) {
        max_ending_here += A[i];
        if(max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        if(max_ending_here<0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int main()
{
    int n;cin>>n;
    A.resize(n);

    for(int i=0;i<n;i++) cin>>A[i];

    cout<<KadanesAlgo()<<endl;

    return 0;   
}
