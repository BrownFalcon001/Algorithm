/*
Given N<=10^12 tell if it has exactly 3 positive divisors.
there are T(<=10^5) test cases
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+2;
bool primes[MAXN];

void prime_sieve() {
    for(int i=1;i<MAXN;i++) {
        primes[i] = true;
    }
    primes[1] = false;

    for(int i = 2;i*i<=MAXN;i++) {
        if(primes[i]) {
            for(int j = i*i;j<=MAXN;j+=i) {
                primes[j] = false;
            }
        }
    }
}



int main() {
    prime_sieve();
    int t;cin>>t;
    while(t--) {
        long long n;cin>>n;
        long long root = sqrt(n);
        if(root*root == n && primes[root]) {
            cout<<"YES\n";
        }
        else cout<<"No\n";
    }
    return 0;
}
