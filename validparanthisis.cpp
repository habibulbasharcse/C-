#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;

        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                stck.push(c);
            }else {
                if(stck.empty()) {
                    return false;
                }else if(stck.top() == '(' && c == ')' ||
                 stck.top() == '{' && c == '}' || stck.top() == '[' && c == ']') {
                    stck.pop();
                } else {
                    return false;
                }
            }
        }
        return stck.empty();
    }
};

int main(){
    string str ="({{}[]";
    Solution s;
    bool result = s.isValid(str);
    cout << result;
}
