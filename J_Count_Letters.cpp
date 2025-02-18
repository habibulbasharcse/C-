#include<bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;
    int len = str.size();

    vector<int> count(26);

    for(int i = 0; i < 26;i++) {
        for(int j = 0; j < len; j++ ) {
            int ascii = str[j];
            if((i + 97) == ascii) {
                count[i] += 1; 
            }
        }
    } 

    for(int i = 0; i < 26;i++) {
        if(count[i] > 0) {
            char alphabet = (i + 97);
            cout << alphabet <<" : " << count[i] << endl;
        }
    }
}       