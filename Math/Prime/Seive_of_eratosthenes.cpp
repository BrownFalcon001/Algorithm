/*
* Author: BrownFalcon
*/
// Time Complexity: O(n log log n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

bool primes[MAXN];

void sieve(int n) {
    for(int i=2;i<=n;i++) {
        if(primes[i] && (long long) i*i <= n) {
            for(int j = i*i;j<=n;j+=i) {
                primes[j] = false;
            }
        } 
    }
}

int main() {
    memset(primes, 1, sizeof(primes));
    primes[0] = primes[1] = 0;

    int n;cin>>n;

    sieve(n);

    for(int i=1;i<=n;i++) cout<<primes[i]<<' ';cout<<endl;
}
