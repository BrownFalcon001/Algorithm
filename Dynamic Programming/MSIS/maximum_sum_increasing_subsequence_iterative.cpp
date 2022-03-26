/*
 *   author: brownFalcon
 */
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^2)

vector<int> A;

int MSIS() {
    int n = A.size();
    vector<int> dp(n);
    dp[n-1] = A[n-1];
    for(int i=n-2;i>=0;i--) {
        dp[i] = A[i];
        for(int j = i+1;j<n;j++) {
            if(A[i] < A[j]) dp[i] = max( dp[i], A[i] + dp[j]);
        }
    }
    return dp[0];
}

int main()
{
    int n;cin>>n;
    A.resize(n);

    for(int i=0;i<n;i++) cin>>A[i];

    cout<<MSIS()<<endl;

    return 0;   
}
