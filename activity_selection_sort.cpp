/*
Question:
A. What is the number of max activity that can be performed?
B. Print the selected activities.
C. What is the minimum and maximum ammount of time that any selected activity requries?
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

struct activity{
    string name;
    int start_time , end_time;
    void input(){
        cin >> name >> start_time >> end_time;
    }

    void output(){
        cout << name << " " << start_time << " " << end_time << endl;
    }
};

void bubble_sort(activity arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j].end_time > arr[j+1].end_time)
                swap(arr[j], arr[j+1]);
        }
    }
}

void selection_sort(activity arr[], int n){
    for(int i=0; i<n-1; i++){
        int start = i;
        for(int j=start+1; j<n; j++){
            if(arr[j].end_time < arr[start].end_time)
                start = j;
        }
        swap(arr[i], arr[start]);
    }
}

bool cmp(activity a , activity b){
    return a.end_time < b.end_time;
}

void solve(ll cs) {
    int n;
    cout << "Enter Number of Activity : " << endl;
    cin >> n;

    activity arr[n];

    for(int i=0; i<n; i++) arr[i].input();

    //যেকোনো একটা দিয়ে করলেই হবে।
    //sort(arr, arr+n, cmp);
    bubble_sort(arr, n);
    //selection_sort(arr, n);

    for(int i=0; i<n; i++) arr[i].output();

    int i=0, cnt=1;
    int temp = arr[i].end_time - arr[i].start_time;
    int ma = temp;
    int mi = temp;

    vector<string>nam;
    vector<pair<int,int>>vp;

    nam.push_back(arr[i].name);
    vp.push_back({arr[i].start_time, arr[i].end_time});

    for(int j=1; j<n; j++){
        if(arr[i].end_time <= arr[j].start_time){
            cnt++;

            nam.push_back(arr[j].name);
            vp.push_back({arr[j].start_time, arr[j].end_time});

            int temp1 = arr[j].end_time - arr[j].start_time;
            if(ma<temp1) ma = temp1;
            if(mi>temp1) mi = temp1;

            i=j;
        }       
    }    

    cout << "The Number of Max Activities that can be performed is : " << cnt << endl;
    
    cout << "Selected Activities are : \n"; 
    for(int i=0; i<nam.size(); i++)
        cout << nam[i] << " " << vp[i].first << " " << vp[i].second << endl;
    
    cout << "Minimum Time that any selected activity requires is " << mi << endl;
    cout << "Maximum Time that any selected activity requires is " << ma << endl;

    

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll t=1, cs=1;
    cout << "Enter Testcase : \n";
    cin>>t;
    while(t--) {
        solve(cs++);
    }

    return 0;
}


/*
1
8
a 13 15
b 4 8
c 9 10
d 5 9
e 0 6
f 1 2
g 3 4
h 8 12

*/
