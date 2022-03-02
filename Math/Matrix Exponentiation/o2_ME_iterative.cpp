/*
* Author: BrownFalcon
*/

//Time Complextiy: O(k^3 * log n) ; where we have a k*k matrix
//Space Complextiy: O(k^3)

#include<bits/stdc++.h>
using namespace std;

struct matrix {
    int mat[2][2];
};

matrix mul(matrix A, matrix B) {
    matrix C;
    for(int row = 0; row<2; row++) {
        for(int col = 0; col<2; col++) {
            int x = 0;
            for(int i=0;i<2;i++) {
                x+= A.mat[row][i] * B.mat[i][col];
            }
            C.mat[row][col] = x;
        }
    }
    return C;
}

matrix identity() {
    matrix C;
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            if(i==j) C.mat[i][j] = 1;
            else C.mat[i][j] = 0;
        }
    }
    return C;
}

int main() {
    matrix A;
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            cin>>A.mat[i][j];
        }
    }
    int n;cin>>n;

    matrix ans = identity();
    
    while(n) {
        if(n%2) ans = mul(ans, A);
        n = n >> 1;
        A = mul(A, A); 
    } 

    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            cout<<ans.mat[i][j]<<' ';
        }
        cout<<endl;
    }
}
 
