#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string path;

std::string getOsName()
{
#ifdef _WIN32
    return "Windows 32-bit";
#elif _WIN64
    return "Windows 64-bit";
#elif __unix || __unix__
    return "Unix";
#elif __APPLE__ || __MACH__
    return "Mac OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#else
    return "Other";
#endif
}

void save_File(string encrypted_string){
    string encrypted_file_path;
    
    if (getOsName() == "Windows 64-bit" || getOsName() == "Windows 32-bit"){
        encrypted_file_path = "C:\encrypted_file.txt";
        // encrypted_file_path = "%USERPROFILE%\\Desktop\\encrypted_file.txt"; // Trebuie testat daca functioneaza corect si salveaza pe desktop fisierul
    }
    else if(getOsName() == "Mac OSX") {
        encrypted_file_path = "/Users/max/encrypted_file.txt";
    }
    
    std::ofstream encrypted_file(encrypted_file_path);
    encrypted_file << encrypted_string << std::endl;
    encrypted_file.close();
    
}

string current_File(){
    stringstream buffer;
    buffer << ifstream(path).rdbuf();
    return buffer.str();
}

class Encrypt{
public:
        string caeser_Method(string text, int s){
            string result = "";
            for (int i=0;i<current_File().length();i++)
            {
                if (isupper(current_File()[i]))
                    result += char(int(current_File()[i]+s-65)%26 +65);
                else
                    result += char(int(current_File()[i]+s-97)%26 +97);
            }
            save_File(result);
            return "Fisierul a fost scris cu succes !";
        }
    
        string metoda_lui_peste_prajit(string text){
        //TODO
        return 0;
    }
    
};

void show_Options(){
    char option;

    cout << "Alegeti metoda de criptare: " << endl << endl;
    
    cout << "1. Metoda la ala francez" << endl;
    cout << "2. Metoda la XXXXXXXXXXX" << endl;
    cout << "3. Metoda la YYYYYYYYYYY" << endl << endl;
    
    cin >> option;
    // string stringfe = "TEST";
    // path = "";
    Encrypt e;
    switch (option) {
        case '1':
            if (getOsName() == "Windows 64-bit" || getOsName() == "Windows 32-bit"){
                system("cls"); // Golim ecranul pentru Windows, pentru Mac inca caut o solutie...
            }
            cout << endl;
            cout << e.caeser_Method(path, 5) << endl << endl;
            break;
            
        case '2':
            //TODO
            break;
        case '3':
            //TODO
            break;
    }
}

int main(int argc, const char * argv[]) {

    if (argc == 2){
        cout << "Calea fisierului este: " << "'" << argv[1] << "'" << endl << endl << endl;
        path = argv[1];
    }
    else{
        cout << "Introduceti calea fisierului pentru criptare: " << endl << endl;
        cin >> path;
        cout << path;
    }
    while(1){
     show_Options();
    }
    return 0;
}

// Ma gandeam sa facem mai inteligent programul aka cand scrii din linia de comanda: "crypto.exe cale_fisier" sa-l preia automat si daca se executa fara cale, sa te intrebe de calea fisierului, e functional by the way
