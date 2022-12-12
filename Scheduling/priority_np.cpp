#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;

class Process {
    public:
    int pid;
    int prio;
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
        cout<<"Enter burst time, arrival time and priority for process "<<i<<" : ";
        cin>>p[i].bt>>p[i].at>>p[i].prio;
    }
    sort(p, p+n, [](auto& a, auto &b) {
        if(a.at == b.at)
            return a.prio < b.prio;
        return a.at < b.at;
    });
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    int cTime = p[0].at, i = 1;
    pq.push(make_tuple(p[0].prio, p[0].bt, p[0].at, p[0].pid));
    while(!pq.empty()) {
        auto temp = pq.top();
        int id = get<3>(temp);
        int arrival = get<2>(temp);
        int burst = get<1>(temp);
        pq.pop();
        cout<<cTime<<" ";
        p[id].st = cTime;
        p[id].ct = cTime + burst;
        cTime = cTime + burst;
        cout<<cTime<<endl;
        while(i < n and p[i].at <= cTime) {
            pq.push(make_tuple(p[i].prio, p[i].bt, p[i].at, p[i].pid));
            i++;
        }
    }
    float rt = 0, wt = 0;
    for(int i = 0; i < n; i++) {
        cout<<wt<<" ";
        wt += p[i].ct - p[i].at - p[i].bt;
    }
    cout<<"\nAvg waiting time: "<<wt/n<<endl;
}