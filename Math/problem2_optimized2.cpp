/*
Find number of natura; numbers <=N which are almost prime. 
A number is almost prime if it is of the form p1*p2.
where p1 != p2 and p1 and p2 are primes.
N<=1e5
*/

// Time Complexity: O(n log n)

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+2;
bool primes[MAXN];
int spf[MAXN]; //smallest prime factor

void prime_sieve() {
    for(int i=1;i<MAXN;i++) {
        primes[i] = true;
    }
    primes[1] = false;
    int LMT = sqrt(MAXN);
    for(int i=2;i<=LMT;i++) {
        if(primes[i]) {
            spf[i] = i;
            for(int j = i*i;j<MAXN;j+=i) {
                spf[j] = i;
                primes[j] = false;
            }
        }
    }
}



int main() {
    memset(spf, 0, sizeof(spf));
    spf[1] = 1;
    int n;cin>>n;

    prime_sieve();
    int ans = 0;
    for(int i=1;i<=n;i++) {
        int a = spf[i];
        int b = spf[i/a];
        if(primes[a] && primes[b] && a*b == i && a!=b) {
            ans++;
        }
    }
    cout<<ans<<endl;
}
