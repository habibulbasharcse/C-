#include<bits/stdc++.h>
using namespace std;
int main() {
    list<int> myList;
    int size = 0;
    
    while(true) {
        int val;
        cin >> val;
        if(val == -1) {
            break;
        }
        myList.push_back(val);
        size++;

    }
    list<int> myList1;
    int size1 = 0;
    
    while(true) {
        int val;
        cin >> val;
        if(val == -1) {
            break;
        }
        myList1.push_back(val);
        size1++;

    }

    bool isSmae = true;

    auto it = myList.begin();
    auto it1 = myList1.begin();

    while (it != myList.end() && it1 != myList1.end()) {
        if(*it != *it1) {
            isSmae = false;
        }
        it++;
        it1++;
    }
    
    
    if(isSmae && size == size1) {
        cout << "YES";
    }else {
         cout << "NO";
    }
}