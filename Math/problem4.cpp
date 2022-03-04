/*
Given N<=10^12 tell if it has exactly 5 positive divisors.
there are T(<=10^5) test cases
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+2;
bool primes[MAXN];
set<long long> ans;

void prime_sieve() {
    for(int i=1;i<MAXN;i++) {
        primes[i] = true;
    }
    primes[1] = false;

    for(int i=2;i*i<MAXN;i++) {
        if(primes[i]) {
            for(int j = i*i; j<MAXN; j+=i) {
                primes[j] = false;
            }
        }
    }
    for(int i=1;i<MAXN;i++) {
        if(primes[i]) {
            ans.insert(i*i*i*i);
        }
    }
}

int main() {
    prime_sieve();
    int t;cin>>t;
    
    while(t--) {
        long long n;cin>>n;
        if(ans.find(n)!=ans.end()) {
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
} 
