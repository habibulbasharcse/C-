/*
Problem Statement

You will be given a list  of type pairs. Each pair will contain one string  and one unique integer . The string will contain only English lowercase alphabets and no spaces.

You need to sort the pairs according to the string values in ascending order. If there are multiple pairs with the same string, you need to sort them according to the integer value in descending order.

Input Format

First line will contain , the size of the list .
Next  lines will contain pairs of string  and integer .
Constraints

Output Format

Output the final list after sorting according to the question.
Sample Input 0

5
sakib 1
rakib 2
tasfia 3
asfia 4
afia 5
Sample Output 0

afia 5
asfia 4
rakib 2
sakib 1
tasfia 3
Sample Input 1

6
sakib 5
rakib 3
tasfia 2
sakib 6
afia 1
sakib 4
Sample Output 1

afia 1
rakib 3
sakib 6
sakib 5
sakib 4
tasfia 2
*/

#include <bits/stdc++.h>
using namespace std;
class Student {
    public:
        string name;
        int roll;
        
        
        Student( string name,int roll) {
            this->name = name;
            this->roll = roll;
            
        }
    
};
class cmp {
    public:
        bool operator()(Student l,Student r) {
            if(l.name > r.name)return true;
            else if(l.name < r.name) return false;
            else return l.roll < r.roll;
        }
};

int main() {
    priority_queue<Student,vector<Student>,cmp> pq;

    int n;
    cin >> n;
    while(n--) {
        string name;
        int roll;
        cin >> name >> roll;
        Student ob(name,roll);
        pq.push(ob);
    }
    
    while(!pq.empty()) {
        cout << pq.top().name << " " << pq.top().roll <<endl;
        pq.pop();
    }

    return 0;
}
