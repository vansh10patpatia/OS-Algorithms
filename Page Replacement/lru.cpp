// #include<iostream>
// #include<unordered_map>
// using namespace std;

// int main() {
//     string s;
//     cout<<"Enter reference string : ";
//     cin>>s;
//     int faults = 0, frames = 3;
//     unordered_map<int, int> m;
//     for(int i = 0; i < s.size(); i++) {
//         int page = s[i] - '0';
//         if(m.size() < frames) {
//             if(m.find(page) == m.end()) {
//                 faults++;
//             }
//             for(auto &i : m)
//                 i.second++;
//             m[page] = 0;
//         } else {
//             if(m.find(page) == m.end()) {
//                 faults++;
//                 int key = -1, mx = -1;
//                 for(auto &i : m) {
//                     if(i.second > mx) {
//                         key = i.first;
//                         mx = i.second;
//                     }
//                 }
//                 m.erase(key);
//                 for(auto &i : m)
//                 i.second++;
//                 m[page] = 0;
//             } else {
//                 for(auto &i : m)
//                     i.second++;
//                 m[page] = 0;
//             }
//         }
//     }
//     cout<<"Total faults : "<<faults;
// }


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
                dq.push_back(page);
            } 
            else {
                for(auto it = dq.begin(); it != dq.end(); it++) {
                    if(*it == page)
                        dq.erase(it);
                }
                dq.push_back(page);
            }
        } else {
            if(set.find(page) == set.end()) {
                faults++;
                set.erase(dq.front());
                dq.pop_front();
                set.insert(page);
                dq.push_back(page);
            }else {
                for(auto it = dq.begin(); it != dq.end(); it++) {
                    if(*it == page)
                        dq.erase(it);
                }
                dq.push_back(page);
            }
        }
    }
    cout<<"Total faults : "<<faults;
}