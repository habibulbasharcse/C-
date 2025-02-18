#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int>v;
    int val;
    cin  >> val;
     while(val--) {
        int input_value;
        cin >> input_value;
        v.push_back(input_value);
    }
    int insert;
    cin >> insert;
    v.push_back(insert);
    int cur_idx = v.size()-1;
    
    while(cur_idx > 0) {
        int parr_idx = (cur_idx - 1) /2;
        if(v[cur_idx] > v[parr_idx]) {
            swap(v[cur_idx], v[parr_idx]);
        }else {
            break;
        }
        cur_idx = parr_idx;
    }
    
    for(int n : v) {
        cout << n << " ";
    }
    

    return 0;
}
