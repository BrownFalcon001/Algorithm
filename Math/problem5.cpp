/*
Given A, count the number of right angle triangles with 
integer sides in which the length of a non-hypotenuse ede is A
and 1<=A<=1e5
*/

#include<bits/stdc++.h>
using namespace std;

long long compute_ans(long long A) {
    long long A2 = A*A;
    long long ans = 0;
    for(int i=1;i*i<=A2;i++) {
        if(A2%i==0) {
            int x = i;
            int y = A2/i;
            if(x!=y && x%2 == y%2) { // we have to check x!=y cause x can be equal to y other wise x<y
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int t;cin>>t;
    while(t--) {
        int A;cin>>A;
        cout<<compute_ans(A)<<endl;
    }
    return 0;
}
