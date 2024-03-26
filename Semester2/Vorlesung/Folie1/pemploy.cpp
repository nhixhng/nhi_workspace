#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(const string& n, const string& v, const vector<int> a, const float s){
    cout<< "name:             " << n << '\n';
    cout<< "First name:       " << v << endl;
    cout<< "Date of Birth:    ";
    cout.width(2);
    cout.fill('0');
    cout << a[2]<< '.';
    cout.width(2);
    cout.fill('0');
    cout << a[1]<< '.' << a[0]<< endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<< "Salary:           " << s << endl;
}

void riseSalary(float& s, const float rise){
    s = s * (1+rise/100);
}



int main(){
    string name= "Mustermann";
    string firstname= "Max";
    vector<int> dateOfBirth = {2004,3,28};
    float salary = 4000.0;

    print(name, firstname, dateOfBirth, salary);

    return 0;
}