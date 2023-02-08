#include<bits/stdc++.h>
using namespace std;

struct item {
    int name, price, weight;
    void input() {
        cin >> name >> price >> weight;
    }
};

int main() {
    int n, sz;
    cin >> n >> sz;

    item arr[n];
    for(int i=1; i<=n; i++) arr[i].input();

    int row = n+1;
    int col = sz+1;
    int ans[row][col];
    memset(ans, 0, sizeof(ans));

    for(int i=1; i<row; i++) {
        for(int j=1; j<col; j++) {
            if(j-arr[i].weight < 0) ans[i][j] = max(ans[i][j-1], ans[i-1][j]);
            else ans[i][j] = max(ans[i-1][j], ans[i-1][j-arr[i].weight]+arr[i].price);
        }
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++)
            cout <<ans[i][j] <<" ";
        cout << endl;
    }

    cout << "Max Profit : " << ans[row-1][col-1] << endl;

    vector<int> v;
    row--, col--;
    while(sz>0 && row>0 && col>0) {
        if(ans[row][col]==ans[row-1][col]) {
            v.push_back(arr[row-1].name);
            sz -= arr[row-1].weight;
            col -= arr[row-1].weight;
            row--;
        }
        else {
            v.push_back(arr[row].name);
            sz -= arr[row].weight;
            col -= arr[row].weight;
            row--;
        }
    }

    reverse(v.begin(), v.end());

    for(auto u:v) cout << u << " ";
    cout << endl;
}


/*
5 6
1 25 3
2 20 2
3 15 1
4 40 4
5 50 5
ans = mf -> 65
items ->3,5

5 10
1 4 6
2 9 4
3 5 3
4 2 3
5 1 1
ans = mf -> 16
items -> 2, 3, 4
*/
