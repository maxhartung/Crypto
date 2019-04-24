#include <iostream>
#include <fstream>
#include <sstream>

std::string path;

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

void save_File(std::string encrypted_string){
    std::string encrypted_file_path;
    
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

std::string current_File(){
    std::stringstream buffer;
    buffer << std::ifstream(path).rdbuf();
    return buffer.str();
}

class Encrypt{
public:
        std::string caeser_Method(std::string text, int s){
            std::string result = "";
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
    
        std::string metoda_lui_peste_prajit(std::string text){
        //TODO
        return 0;
    }
    
};

void show_Options(){
    char option;

    std::cout << "Alegeti metoda de criptare: " << std::endl << std::endl;
    
    std::cout << "1. Metoda la ala francez" << std::endl;
    std::cout << "2. Metoda la XXXXXXXXXXX" << std::endl;
    std::cout << "3. Metoda la YYYYYYYYYYY" << std::endl << std::endl;
    
    std::cin >> option;
    // string stringfe = "TEST";
    // path = "";
    Encrypt e;
    switch (option) {
        case '1':
            if (getOsName() == "Windows 64-bit" || getOsName() == "Windows 32-bit"){
                system("cls"); // Golim ecranul pentru Windows, pentru Mac inca caut o solutie...
            }
            std::cout << std::endl;
            std::cout << e.caeser_Method(path, 5) << std::endl << std::endl;
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
        std::cout << "Calea fisierului este: " << "'" << argv[1] << "'" << std::endl << std::endl << std::endl;
        path = argv[1];
    }
    else{
        std::cout << "Introduceti calea fisierului pentru criptare: " << std::endl << std::endl;
        std::cin >> path;
        std::cout << path;
    }
    while(1){
     show_Options();
    }
    return 0;
}

// Ma gandeam sa facem mai inteligent programul aka cand scrii din linia de comanda: "crypto.exe cale_fisier" sa-l preia automat si daca se executa fara cale, sa te intrebe de calea fisierului, e functional by the way
