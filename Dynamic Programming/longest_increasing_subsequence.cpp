/*
 *   author: brownFalcon
 */
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^2)

vector<int> A;

int LIS() {
    int n = A.size();
    vector<int> dp(n);
    dp[n-1] = 1;
    for(int i=n-2;i>=0;i--) {
        dp[i] = 1;
        for(int j = i+1;j<n;j++) {
            if(A[i] < A[j]) dp[i] = max( dp[i], 1 + dp[j]);
        }
    }
    return dp[0];
}

int main()
{
    int n;cin>>n;
    A.resize(n);

    for(int i=0;i<n;i++) cin>>A[i];

    cout<<LIS()<<endl;

    return 0;   
}
