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

void compute_primes() {
    for(int i=0;i<MAXN;i++) primes[i] = true;
    primes[1] = false;
    int LIM = sqrt(MAXN);
    for(int i=2;i<=LIM ;i++) {
        if(primes[i]) {
            for(int j = i*i;j<MAXN;j+=i) {
                primes[j] = false;
            }
        }
    }
}

int compute_ans(int n) {
    int ans = 0;
    for(int i=2;i<=n;i++) {
        if(primes[i]) {
            for(int j = i;j<=n;j+=i) {
                if(primes[j/i] && i!=j/i) {
                    ans++;
                }
            }
        }
    }
    return ans/2;
}

int main() {
    int n;cin>>n;
    // we wil use sieve here
    compute_primes();
    cout<<compute_ans(n)<<endl;
    return 0;
}
