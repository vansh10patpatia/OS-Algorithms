//For same arrival time of all processes
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<pair<int, int>> v;
    int n, at, bt;
    cout<<"Print no of processes : ";
    cin>>n;
    for(int i = 0; i < n; i++) {
        cout<<"Enter burst time and arrival time for "<<i<<" process : ";
        cin>>bt>>at;
        v.push_back({bt, at});
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i].first > v[j].first) {
                int temp = v[i].first;
                v[i].first = v[j].first;
                v[j].first = temp;
            }
        }
    }
    vector<pair<int, int>> res;
    int cTime = v[0].second;
    for(int i = 0; i < n; i++) {
        if(cTime < v[i].second)
            cTime = v[i].second;
        res.push_back({cTime, cTime + v[i].first});
        cTime += v[i].first;
    }
    float rt = 0, wt = 0, tat = 0;
    for(int i = 0; i < n; i++) {
        rt += res[i].first - v[i].second;
        tat += res[i].second - v[i].second;
        wt += res[i].second - v[i].second - v[i].first;
    }
    cout<<"Average respone time : "<<rt/n<<endl;
    cout<<"Average waiting time : "<<wt/n<<endl;
    cout<<"Average turn around time : "<<tat/n<<endl;
}