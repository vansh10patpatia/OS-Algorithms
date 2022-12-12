#include<iostream>
#include<unordered_set>
#include<queue>
using namespace std;

int main() {
    string s;
    cout<<"Enter reference string : ";
    cin>>s;
    int faults = 0, frames = 3;
    unordered_set<int> set;
    deque<int> dq;
    for(int i = 0; i < s.size(); i++) {
        int page = s[i] - '0';
        if(set.size() < frames) {
            if(set.find(page) == set.end()) {
                faults++;
                set.insert(page);
            }
            dq.push_back(page);
        } else {
            if(set.find(page) == set.end()) {
                faults++;
                set.erase(dq.back());
                dq.pop_back();
                set.insert(page);
            }
            dq.push_back(page);
        }
    }
    cout<<"Total faults : "<<faults;
}