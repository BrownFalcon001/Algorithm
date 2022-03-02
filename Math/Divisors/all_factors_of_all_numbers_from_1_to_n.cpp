/*
* Author: BrownFalcon
*/

// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int factors[MAXN+1];

void all_factors_1_to_n(int n) {
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j+=i) {
            factors[j]++;
        }
    }
}

int main() {
    int n;cin>>n;
    memset(factors, 0, sizeof(factors));
    all_factors_1_to_n(n);

    for(int i=1;i<=n;i++) {
        cout<<i<<' '<<factors[i]<<endl;
    }
} 
