#include<iostream>
#include<map>
#include<unordered_set>
using namespace std;

int helper(unordered_set<int>& set, string& s, int j) {
    map<int, int> m;
    for(auto k : set) {
        int index = INT_MAX;
        for(int i = s.size(); i > j; i--) {
            int p = s[i] - '0';
            if(k == p)
                index = i;
        }
        m[index] = k;
    }
    auto it = --m.end();
    return it->second;
}

int main() {
    string s;
    cout<<"Enter reference string : ";
    cin>>s;
    int faults = 0, frames = 3;
    unordered_set<int> set;
    for(int i = 0; i < s.size(); i++) {
        int page = s[i] - '0';
        if(set.size() < frames) {
            if(set.find(page) == set.end()) {
                faults++;
                set.insert(page);
            }
        } else {
            if(set.find(page) == set.end()) {
                faults++;
                int toDelete = helper(set, s, i);
                set.erase(toDelete);
                set.insert(page);
            }
        }
    }
    cout<<"Total faults : "<<faults;
}