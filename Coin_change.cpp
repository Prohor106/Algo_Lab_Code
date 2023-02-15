/*
1. Minimum number of needed
2. Maximum number of ways
*/

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

    int cc1[n+1][amount+1], cc2[n][amount+1];

    for(int i=0; i<n+1; i++) cc1[i][0] = 0,cc2[i][0] = 1;;
    for(int j=1; j<amount+1; j++) cc1[0][j] = amount+1;

    //for minimum number of coin
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<amount+1; j++) {
            if((j-coin[i-1] < 0)) cc1[i][j] = cc1[i-1][j];
            else cc1[i][j] = min(cc1[i-1][j], cc1[i][j-coin[i-1]]+1);
        }
    }

    //for number of ways
    for(int i=0; i<n; i++) {
        for(int j=1; j<=amount; j++) {
            if(i==0) {
                if(j%coin[i]) cc2[i][j] = 0;
                else cc2[i][j] = 1;
            }
            else if(j-coin[i]<0) cc2[i][j] = cc2[i-1][j];
            else cc2[i][j] = cc2[i-1][j]+cc2[i][j-coin[i]];
        }
    }


    /* for(int i=0; i<n+1; i++) {
         for(int j=0; j<amount+1; j++) {
             cout << cc[i][j] << " ";
         }
         cout << endl;

     }
     cout << endl;

     for(int i=0; i<n; i++) {
         for(int j=0; j<amount+1; j++) {
             cout << cc1[i][j] << " ";
         }
         cout << endl;
     }*/
    cout << endl;

    //coin piciking
    vector<int> ans;
    int row = n, col = amount;
    while(row>0 && col>0) {
        if(cc1[row][col] == cc1[row-1][col]) row--;
        else {
            ans.push_back(coin[row-1]);
            col -= coin[row-1];
        }
    }
    reverse(ans.begin(), ans.end());


    cout << "Number of Coins Needed : " << cc1[n][amount] << endl;
    cout << "Number of Ways : " << cc2[n-1][amount] << endl;

    cout << "Coins Picked : ";
    for(auto u:ans) cout << u << " ";
    cout << endl;

    return 0;

}

