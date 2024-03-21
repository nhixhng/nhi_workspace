#include <iostream>
using namespace std;

int main(){
    string line;
    char c;

    while (cin.get(c)&& c!= '\n'){ //ein einzelnes Zeichen (einschließlich Leerzeichen und Zeilenumbrüche)
        line= line +c;
    }
    cout << line << '\n';

    // getline(cin,line) liest ganze Zeile 
}