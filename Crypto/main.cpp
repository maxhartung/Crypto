#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    
    string path;
    
    if (argc == 2){
        cout << "Calea fisierului este: " << "'" << argv[1] << "'";
        }

    else
        cout << "Introduceti calea fisierului pentru criptare: " << endl << endl;
        cin >> path;
        cout << path;
    return 0;
}

// Ma gandeam sa facem mai inteligent programul aka cand scrii din linia de comanda: "crypto.exe cale_fisier" sa-l preia automat si daca se executa fara cale, sa te intrebe de calea fisierului, e functional by the way
