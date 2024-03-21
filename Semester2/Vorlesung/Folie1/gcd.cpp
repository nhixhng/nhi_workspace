#include <iostream>
using namespace std;

int gcd(int a, int b){
    int tmp;

    while (a != b){
        if (a > b){
            a= a-b;
        } 
        else {
        tmp= a;
        a= b;
        b= tmp;
        } 
    }

    return a;
}

int main(){

    int a,b,ergebniss;
    cout<< "Bitte zwei Zahlen eingeben um den groeßten gemeinsame Teiler zu finden: "<< '\n';
    cin >> a >> b;

    ergebniss= gcd(a,b);
    cout<< "der groeßte gemeinsame Teiler ist " << ergebniss << '\n';
    return 0;
}