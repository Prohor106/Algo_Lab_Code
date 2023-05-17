#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) (v).begin(),(v).end()

struct item{
    int name, price, weight;
    void input(){
        cin >> name >> price >> weight;
    }
};

int main() {

   int n, sz;
    cin >> n >> sz;
    item arr[n+1];
    for(int i=1; i<=n; i++) arr[i].input();

    int row = n+1;
    int col = sz+1;
    int mat[row][col];
    memset(mat, 0, sizeof(mat));

    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            if(j-arr[i].weight < 0) mat[i][j] = mat[i-1][j];
            else mat[i][j] = max(mat[i-1][j], mat[i-1][j-arr[i].weight]+arr[i].price);
        }
    }

    cout << "Max Profit : " << mat[row-1][col-1] << endl;
    row--, col--;
    vector<int> ans;
    while(row>0 && col>0){
        if(mat[row][col]==mat[row-1][col]) row--;
        else{
            ans.push_back(arr[row].name);
            col -= arr[row].weight;
            row--;
        }
    }
    reverse(all(ans));
    
    cout << "Selected Items : " << endl;
    for(auto u:ans) cout << u << " ";
        cout << endl;

   return 0;
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
