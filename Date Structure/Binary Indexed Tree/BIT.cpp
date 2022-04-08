/*
* author : brownFalcon
*/

// Time Complexity: O(nlogn) [build], O(logn) [query], O(logn) [update]

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> A, tree;

void build() {
    for(int i=0;i<n;i++) {
        int x = i+1;
        while(x<=n) {
            tree[x] += A[i];
            x += (-x&x);
        }
    }
}
int query(int i) {
    int sum = 0;
    while(i> 0) {
        sum +=tree[i];
        i -= (-i&i);
    }
    return sum;
}

void update(int i, int val) {
    while(i<=n) {
        tree[i] +=val;
        i +=(-i&i);
    }
} 

int main() {
    cin>>n;
    A.resize(n+1);
    tree.resize(n+1);
    for(int i=0;i<n;i++) cin>>A[i];
    build();
    int q;cin>>q;
    while(q--) {
        int x;cin>>x;
        if(x == 1) {
            // range sum
            int l, r;cin>>l>>r;
            l = query(l);
            r = query(r+1);
            cout<<r - l<<endl;
        }
        else {
            // update
            int pos, val;cin>>pos>>val;
            update(pos+1, val - A[pos]);
        }
    }
}

// resources: 
// 1. https://www.youtube.com/watch?v=CWDQJGaN1gY
// 2. https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees
