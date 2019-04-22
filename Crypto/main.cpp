#include <iostream>
using namespace std;

string encrypt_Caeser(string text, int s){
    string result = "";
    
    for (int i=0;i<text.length();i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i]+s-65)%26 +65);
        else
            result += char(int(text[i]+s-97)%26 +97);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    string path;
    char option;
    
    if (argc == 2){
        cout << "Calea fisierului este: " << "'" << argv[1] << "'" << endl << endl << endl;
        path = argv[1];
    }
    else{
        cout << "Introduceti calea fisierului pentru criptare: " << endl << endl;
        cin >> path;
        cout << path;
    }
    cout << "Alegeti metoda de criptare: " << endl << endl;
    
    cout << "1. Metoda la ala francez" << endl;
    cout << "2. Metoda la XXXXXXXXXXX" << endl;
    cout << "3. Metoda la YYYYYYYYYYY" << endl << endl;
    
    cin >> option;
   // string stringfe = "TEST";
    switch (option) {
        case '1':
            cout << encrypt_Caeser(path,5) << endl << endl;
            break;
            
        case '2':
            //TODO
            break;
        case '3':
            //TODO
            break;
    }
     return 0;
}

// Ma gandeam sa facem mai inteligent programul aka cand scrii din linia de comanda: "crypto.exe cale_fisier" sa-l preia automat si daca se executa fara cale, sa te intrebe de calea fisierului, e functional by the way
