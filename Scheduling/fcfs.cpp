#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<pair<int, int>> p;
    int i, n, btt, att;
    cin>>n;
    for(i = 0; i < n; i++) {
        cout<<"Enter P"<<i<<" Burst time and arrival time: ";
        cin>>btt>>att;
        p.push_back({btt, att});
    }
    sort(p.begin(), p.end(), [&] (auto a, auto b) {
        if(a.second == b.second) 
            return a.first < b.first;
        return a.second < b.second;
    });
    int cTime = 0;
    cTime = p[0].second;
    vector<pair<int, int>> res;
    for(i = 0; i < n; i++) {
        if(cTime < p[i].second)
            cTime = p[i].second;
        res.push_back({cTime, cTime + p[i].first});
        cTime += p[i].first;
    }
    float rt = 0, wt = 0, sum = 0;
    vector<int> tat(n);
    for(i = 0; i < n; i++) {
        rt += res[i].first - p[i].second;
        tat[i] = res[i].second - p[i].second;
        wt += tat[i] - p[i].first; 
    }
    cout<<"Avg response time: "<<rt/n<<endl;
    cout<<"Avg waiting time: "<<wt/n<<endl;
    for(i = 0; i < n; i++)
        sum += tat[i];
    cout<<"Avg turn around time: "<<sum/n<<endl;
}