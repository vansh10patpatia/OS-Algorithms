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
    queue<int> q;
    for(int i = 0; i < s.size(); i++) {
        int page = s[i] - '0';
        if(set.size() < frames) {
            if(set.find(page) == set.end()) {
                faults++;
                q.push(page);
                set.insert(page);
            }
        } else {
            if(set.find(page) == set.end()) {
                faults++;
                q.push(page);
                set.insert(page);
                set.erase(q.front());
                q.pop();
            }
        }
    }
    cout<<"Total faults : "<<faults;
}