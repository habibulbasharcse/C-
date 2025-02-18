#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(10);
    pq.push(1);
    pq.push(20);
    pq.push(30);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    
    return 0;
}
