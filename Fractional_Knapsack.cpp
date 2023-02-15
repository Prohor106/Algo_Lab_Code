/*
Question:
A. What is the max total profit?
B. Print the Selected Items.
C. What is the max profit from any seleted items?
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

struct item {
    string name;
    double weight, price;
    void input() {
        cin >> name >> weight >> price;
    }

    double unit_price;
    void output() {
        cout << name << " " << weight << " " << price << " " << unit_price << endl;
    }
};

void bubble_sort(item arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j].unit_price < arr[j+1].unit_price)
                swap(arr[j], arr[j+1]);
        }
    }
}

void selection_sort(item arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int start = i;
        for(int j=start+1; j<n; j++) {
            if(arr[j].unit_price > arr[start].unit_price)
                start = j;
        }
        swap(arr[i], arr[start]);
    }
}

bool cmp(item a, item b) {
    return a.unit_price > b.unit_price;
}

void solve(ll cs) {
    int n;
    double capacity;
    cout << "Enter number of items and Bag capacity " << endl;
    cin >> n >> capacity;

    item arr[n];
    cout << "Enter name , weight and prices of Items : " << endl;
    for(int i=0; i<n; i++) {
        arr[i].input();
        arr[i].unit_price = arr[i].price / arr[i].weight;
    }

    //যেকোনো একটা দিয়ে করলেই হবে।
    // sort(arr, arr+n, cmp);
    // bubble_sort(arr, n);
    selection_sort(arr, n);

    for(int i=0; i<n; i++) arr[i].output();

    double profit = 0, max_profit = 0;
    vector<string>selected_items;

    for(int i=0; i<n; i++) {
        if(capacity <= 0) break;

        double temp_capacity = min(capacity, arr[i].weight);

        double temp_profit = temp_capacity * arr[i].unit_price;
        if(max_profit < temp_profit) max_profit = temp_profit;

        profit += temp_capacity*arr[i].unit_price;
        capacity -= temp_capacity;
        selected_items.push_back(arr[i].name);
    }

    cout << "Max Total Profit is " << profit << endl;

    cout << "Selected Items are \n";
    for(auto u:selected_items) cout << u << " ";
    cout << endl;

    cout << "Max profit from any selected item is " << max_profit << endl;
}

int main() {

    //ios_base::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);

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
6 22
a 3 15
b 7 30
c 4.5 27
d 5 24
e 2 20
f 6 32
*/
