#include <bits/stdc++.h>
using namespace std;

class Student {
    public :
    
    string name;
    int roll;
    int marks;
    
};

bool cmp(Student l,Student r) {
    return l.marks < r.marks;
}

int main() {
    int n ;
    cin >> n;
    cin.ignore();
    
    
    Student student[n];
    
    for(int i = 0;i < n;i++) {
        getline (cin,student[i].name );
        cin >> student[i].roll >> student[i].marks;
        cin.ignore();
    }
    Student mn;
    mn.marks = INT_MAX;;
    sort(student,student+n,cmp);
    
    for(int i = 0;i < n;i++) {
        cout << student[i].name <<" " <<  student[i].roll << " "<<  student[i].marks << endl;
        if(student[i].marks < mn.marks) {
            mn = student[i];
        }
       
    }
    
    cout << "name: "<< mn.name << " roll: "<< mn.roll<< " marks: " << mn.marks <<endl;


    return 0;
}