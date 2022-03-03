/*
Find number of natura; numbers <=N which are almost prime. 
A number is almost prime if it is of the form p1*p2.
where p1 != p2 and p1 and p2 are primes.
N<=3000
*/

// Time Complexity: O(n sqrt(n))
// in worst case 1.6e5
// awesome it will pass
// What if we had N<=1e5 !!!!

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n<=1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=3;i*i<=n;i+=2) 
        if(n%i==0) return false;

    return true; 
}

bool isAlmostPrime(int n) {
    int LIM = sqrt(n);
    for(int i=2;i<=LIM;i++) {
        if(n%i==0) {
            if(isPrime(i) && isPrime(n/i) && i!= (n/i)) {
                return true;
            } 
            return false;
        }
    }
    return false;
}

int main() {
    int n;cin>>n;
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        if(isAlmostPrime(i)) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
