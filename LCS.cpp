#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int row = s1.size()+1;
    int col = s2.size()+1;

    int arr[row][col];
    char tracker[row][col];
    memset(arr, 0, sizeof(arr));

    for(int i=1; i<row; i++) {
        for(int j=1; j<col; j++) {
            if(s1[i-1] == s2[j-1]) {
                arr[i][j] = arr[i-1][j-1]+1;
                tracker[i][j] = 'D';
            }
            else {
                if(arr[i-1][j] >= arr[i][j-1]) {
                    arr[i][j] = arr[i-1][j];
                    tracker[i][j] = 'U';
                }
                else {
                    arr[i][j] = arr[i][j-1];
                    tracker[i][j] = 'L';
                }
            }
        }
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for(int i=1; i<row; i++) {
        for(int j=1; j<col; j++)
            cout << tracker[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    cout << arr[row-1][col-1] << endl;
    row--, col--;

    string ans = "";

    while(row>0 && col>0){
        if(tracker[row][col]=='D'){

            ans += s1[row-1];
            row--;
            col--;
        }
        else if(tracker[row][col]=='U') row--;
        else col--;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}

/*
abcbdab
bdcaba


ACTAGCTA
TCAGGTAT
*/
