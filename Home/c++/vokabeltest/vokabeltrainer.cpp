#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

string print_menu(){
    string option;
    
    cout << "Vokabeltrainer\n";
    cout << "Bitte treffe eine Auswahl:\n";
    cout << "(1) neue Vokabel hinzufügen\n";
    cout << "(2) Vokabeltest starten\n";
    
    cin >> option; //getline(cin, option); //cin= character in = eingabe ; eingabe in name rein
    cout << "Deine Auswahl: " + option + "\n";
    return option;
}

vector<string> loadTxtFile(string textFile){
    string str;
    vector<string> newVector;// so ähnlich wie ein array nur unbegrenzt
    ifstream in(textFile);

    while (getline(in, str))
    {
        if(str.size() > 0)
            newVector.push_back(str);
    }
    return newVector;

}

void save_vector_to_txt_file(string text, vector<string> newVector){
    //in texdatei importieren 
        ofstream output_file(text, ios::app); //in welche texdatei
        ostream_iterator<string> output_iterator(output_file, "\n"); // alle werte kommen in die Datei, jede neue Vokabel wird in eine neue zeile gespeicher 
        copy(newVector.begin(), newVector.end(), output_iterator); // zeile für zeile in die texdatei
}

void ask_word(vector<string> voc_german,vector<string> voc_viet){
    cout << "Vokabeltest wird gestartet...\n";
        int random = rand() % voc_german.size(); // zufälige zahl zwischen 0 und der größe des vektors
        string sel_elem = voc_german[random];
        string sel_translation = voc_viet[random];
        cout << "Bitte übersetze folgendes Wort: " + sel_elem + "\n";
        string userinput;
        cin >> userinput;
        if(userinput== sel_translation ){
            cout << "Alles richtig\n";
        } else {
            cout << "Leider falsch\n";
        }
}

int main(){
    string german;
    string viet;

    vector<string> voc_viet = loadTxtFile("viet_vokabeln.txt");
    vector<string> voc_german = loadTxtFile("german_vokabeln.txt");

    string option = print_menu();

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

        save_vector_to_txt_file("./viet_vokabeln.txt",voc_viet);
        save_vector_to_txt_file("./german_vokabeln.txt",voc_german);

    } else {
        int i=0;
        while(i<10){
        ask_word(voc_german, voc_viet);
        i++;
        }
    }

    return 0;
}

