//For same arrival time of all processes
// #include<iostream>
// #include<vector>
// using namespace std;

// int main() {
//     vector<pair<int, int>> v;
//     int n, at, bt;
//     cout<<"Print no of processes : ";
//     cin>>n;
//     for(int i = 0; i < n; i++) {
//         cout<<"Enter burst time and arrival time for "<<i<<" process : ";
//         cin>>bt>>at;
//         v.push_back({bt, at});
//     }
//     for(int i = 0; i < n - 1; i++) {
//         for(int j = i + 1; j < n; j++) {
//             if(v[i].first > v[j].first) {
//                 int temp = v[i].first;
//                 v[i].first = v[j].first;
//                 v[j].first = temp;
//             }
//         }
//     }
//     vector<pair<int, int>> res;
//     int cTime = v[0].second;
//     for(int i = 0; i < n; i++) {
//         if(cTime < v[i].second)
//             cTime = v[i].second;
//         res.push_back({cTime, cTime + v[i].first});
//         cTime += v[i].first;
//     }
//     float rt = 0, wt = 0, tat = 0;
//     for(int i = 0; i < n; i++) {
//         rt += res[i].first - v[i].second;
//         tat += res[i].second - v[i].second;
//         wt += res[i].second - v[i].second - v[i].first;
//     }
//     cout<<"Average respone time : "<<rt/n<<endl;
//     cout<<"Average waiting time : "<<wt/n<<endl;
//     cout<<"Average turn around time : "<<tat/n<<endl;
// }

//For different arrival time of all processes
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Process {
    public:
    int pid;
    int bt;
    int at;
    int st;
    int ct;
};

int main() {
    int n;
    cout<<"Enter number of processes : ";
    cin>>n;
    Process p[n];
    for(int i = 0; i < n; i++) {
        p[i].pid = i;
        cout<<"Enter burst time and arrival time for process "<<i<<" : ";
        cin>>p[i].bt>>p[i].at;
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].at > p[j].at) {
                swap(p[i].at, p[j].at);
                swap(p[i].bt, p[j].bt);
                swap(p[i].pid, p[j].pid);
            }
        }
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int cTime = p[0].at, i = 1;
    pq.push({p[0].bt, {p[0].at, p[0].pid}});
    while(!pq.empty()) {
        int id = pq.top().second.second;
        int arrival = pq.top().second.first;
        int burst = pq.top().first;
        pq.pop();
        p[id].st = cTime;
        p[id].ct = cTime + burst;
        cTime = cTime + burst;
        while(i < n and p[i].at <= cTime) {
            pq.push({p[i].bt, {p[i].at, p[i].pid}});
            i++;
        }
    }
    float rt = 0, wt = 0;
    for(int i = 0; i < n; i++) {
        rt += p[i].st - p[i].at;
        wt += p[i].ct - p[i].at - p[i].bt;
    }
    cout<<"Avg response time: "<<rt/n<<endl;
    cout<<"Avg waiting time: "<<wt/n<<endl;
}