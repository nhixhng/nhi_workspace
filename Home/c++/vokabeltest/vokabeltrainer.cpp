#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

int main(){
    vector<string> voc_german; // so ähnlich wie ein array nur unbegrenzt
    vector<string> voc_viet;

    string option;
    string german;
    string viet;
    string str;

    ifstream in("viet_vokabeln.text");
    ifstream in2("german_vokabeln.txt");
    
    while (getline(in, str))
    {
        if(str.size() > 0)
            voc_viet.push_back(str);
    }

    while (getline(in2, str))
    {
        if(str.size() > 0)
            voc_german.push_back(str);
    }

    cout << "Vokabeltrainer\n";
    cout << "Bitte treffe eine Auswahl:\n";
    cout << "(1) neue Vokabel hinzufügen\n";
    cout << "(2) Vokabeltest starten\n";


    cin >> option; //getline(cin, option); //cin= character in = eingabe ; eingabe in name rein
    cout << "Deine Auswahl: " + option + "\n";

    if (option == "1"){
        cout << "Bitte Deutsche Vokabel eingeben\n";
        cin >> german;
        cout << "wie lautet die uebersetzung\n";
        cin >> viet;
        cout << german + " lautet auf vietnamesisch " +  viet + "\n";
        
        
        // deutsches Wort hinzufügen
        voc_german.push_back(german);

        voc_viet.push_back(viet);

        cout << "Vokabel wurde hinzugefügt\n"; 
        cout << "hinzugefügte Vokabeln: " + to_string(voc_german.size()) + "\n";

        //in texdatei importieren 
        ofstream output_file("./viet_vokabeln.txt", ios::app); //in welche texdatei
        ostream_iterator<string> output_iterator(output_file, "\n"); // alle werte kommen in die Datei, jede neue Vokabel wird in eine neue zeile gespeicher 
        copy(voc_viet.begin(), voc_viet.end(), output_iterator); // zeile für zeile in die texdatei

        
        ofstream output_file2("./german_vokabeln.txt"); 
        ostream_iterator<string> output_iterator2(output_file2, "\n"); 
        copy(voc_german.begin(), voc_german.end(), output_iterator2); 

    } else {
        cout << "Vokabeltest wird gestartet...\n";
        

    }

    return 0;
}