/*
* Author: BrownFalcon
*/

//Time Complextiy: O(log n)
//Space Complextiy: O(1)

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
    int n;cin>>n;

    matrix fib;
    fib.mat[0][0] = 1, fib.mat[0][1] = 1;
    fib.mat[1][0] = 1, fib.mat[1][1] = 0;

    if(n<=2) cout<<"1\n";
    else {
        n-=2;
        matrix ans = identity();
        while(n) {
            if(n%2) ans = mul(ans, fib);
            n = n >> 1;
            fib = mul(fib, fib); 
        }
        cout<<ans.mat[0][0]+ ans.mat[0][1] <<endl;
    }
}
 
