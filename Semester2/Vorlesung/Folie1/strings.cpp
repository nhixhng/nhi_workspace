#include <iostream>
#include <string>
using namespace std;

int main(){

    string s = "Hello World"; // String 
    cout << s << '\n'; // String ausgabe

    cout << s[0] << '\n'; // Buchstabe an der Stelle 0 andern , Vektor
    s[0]= 'X';            // Buchstabe ändern
    // s.at(20) = 'X'; Sicherstellen das man im Berreich bleibt
    cout << s << '\n';

    string t= s;
    cout << t + " Again" << '\n';
    
    cout << s.find("World") << '\n';

    s.replace(s.find("World"), s.length(), "NHI"); // string& replace(size_t pos, size_t len, const string& str); 
                                                    //& Referenz, Elemente in Vektor änderbar
    cout << s << '\n';

    return 0;
}
