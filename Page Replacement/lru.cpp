#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    string s;
    cout<<"Enter reference string : ";
    cin>>s;
    int faults = 0, frames = 3;
    unordered_map<int, int> m;
    for(int i = 0; i < s.size(); i++) {
        int page = s[i] - '0';
        if(m.size() < frames) {
            if(m.find(page) == m.end()) {
                faults++;
            }
            for(auto &i : m)
                i.second++;
            m[page] = 0;
        } else {
            if(m.find(page) == m.end()) {
                faults++;
                int key = -1, mx = -1;
                for(auto &i : m) {
                    if(i.second > mx) {
                        key = i.first;
                        mx = i.second;
                    }
                }
                m.erase(key);
                for(auto &i : m)
                i.second++;
                m[page] = 0;
            } else {
                for(auto &i : m)
                    i.second++;
                m[page] = 0;
            }
        }
    }
    cout<<"Total faults : "<<faults;
}