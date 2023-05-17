#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter Number of Coins : ";
    cin >> n;

    int coin[n+1];
    cout << "Enter Coins : ";
    for(int i=1; i<=n; i++) cin >> coin[i];

    int amount;
    cout << "Enter Amount : ";
    cin >> amount;

    int row = n+1;
    int col = amount+1;
    int mat[row][col];

    //initializing full matrix to 0;
    memset(mat, 0, sizeof(mat));

    //initializing 1st row to amount+1 , from 2nd column
    for(int i=1; i<col; i++) mat[0][i] = amount+1;

    //for minimum number of coin
    for(int i=1; i<row; i++) {
        for(int j=1; j<col; j++) {
            if((j-coin[i] < 0)) mat[i][j] = mat[i-1][j];
            else mat[i][j] = min(mat[i-1][j], mat[i][j-coin[i]]+1);
        }
    }

    cout << "Minimum Number of Coins Needed : " << mat[row-1][col-1] << endl;

    //coin piciking
    vector<int> ans;
    row--, col--;
    while(row>0 && col>0) {
        if(mat[row][col] == mat[row-1][col]) row--;
        else {
            ans.push_back(coin[row]);
            col -= coin[row];
        }
    }
    reverse(ans.begin(), ans.end());


    cout << "Coins Picked : ";
    for(auto u:ans) cout << u << " ";
    cout << endl;

    return 0;

}
