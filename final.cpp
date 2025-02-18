#include <bits/stdc++.h>
using namespace std;

class Student {
    public :
    
    string nm;
    int cls;
    char s;
    int id;
    int math_marks;
    int eng_marks;;
    
};

bool cmp(Student l,Student r) {
    return l.math_marks + l.eng_marks >= r.math_marks+r.eng_marks;
}

int main() {
    int n ;
    cin >> n;
    cin.ignore();
    
    
    Student stdnt[n];
    
    for(int i = 0;i < n;i++) {
        cin >> stdnt[i].nm >> stdnt[i].cls >> stdnt[i].s >> stdnt[i].id >> stdnt[i].math_marks >> stdnt[i].eng_marks;
        cin.ignore();
    }
    
    sort(stdnt,stdnt+n,cmp);
    
    for(int i = 0;i < n;i++) {
        cout << stdnt[i].nm << " " << stdnt[i].cls << " " << stdnt[i].s << " " << stdnt[i].id <<" " << stdnt[i].math_marks << " " << stdnt[i].eng_marks << endl;
       
    }
    


    return 0;
}