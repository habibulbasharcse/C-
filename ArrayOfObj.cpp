#include <bits/stdc++.h>
using namespace std;

class Student {
    public :
    
    string name;
    int roll;
    int marks;
    
};

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
    
    for(int i = 0;i < n;i++) {
        cout << student[i].name <<" " <<  student[i].roll << " "<<  student[i].marks << endl;
    }

    return 0;
}