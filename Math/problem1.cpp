/*
    Give an array of integers A1, A2, A3, ......., AN
    N<=1e5
    1<=Ai<=1e5
    find number of pairs i, j where Ai is a multiple of Aj and Ai != Aj
*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;

int main() {
    int n;cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }
    //input done

    vector<int> cnt(MAXN);
    for(int i=0;i<n;i++) {
        cnt[A[i]]++;
    }
    //cnt done

    vector<int> M(MAXN);
    for(int i=1;i<MAXN;i++) {
        for(int j=i*2;j<=MAXN;j+=i) {
            M[i] += cnt[j];
        }
    }
    // m done

    int ans = 0;
    for(int i=0;i<n;i++) {
        ans += M[A[i]];
    }
    cout<<ans<<endl;
}
