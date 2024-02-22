#include <iostream>
#include <string>
using namespace std;

int main(){

    //char[] name= "nhi";
    string name = "nhi"; // durch include string möglich
    int birth_date= 1991;
    int age = 2022 - 1991;

    cout << "Hallo " + name +  " wie geht es dir?\n";
    cout << "Ich bin " + to_string(age) + " Jahre alt\n"; // eine Zahl in einen string umwandeln


    return 0;
}