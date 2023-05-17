#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter Number of Coins : ";
    cin >> n;

    int coin[n];
    cout << "Enter Coins : ";
    for(int i=0; i<n; i++) cin >> coin[i];

    int amount;
    cout << "Enter Ammount : ";
    cin >> amount;

    int row = n;
    int col = amount+1;
    int mat[row][col];

    //initializing 1st column to 1;
    for(int i=0; i<row; i++) mat[i][0] = 1;

    //for number of ways
    for(int i=0; i<row; i++) {
        for(int j=1; j<col; j++) {
            if(i==0) {
                if(j%coin[i]) mat[i][j] = 0;
                else mat[i][j] = 1;
            }
            else if(j-coin[i]<0) mat[i][j] = mat[i-1][j];
            else mat[i][j] = mat[i-1][j] + mat[i][j-coin[i]];
        }
    }

    cout << "Number of Ways : " << mat[n-1][amount] << endl;

    return 0;
}
