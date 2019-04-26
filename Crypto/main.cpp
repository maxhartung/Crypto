#include <iostream>
#include <fstream>
#include <sstream>

std::string path;
std::string custom_path;

enum encrypt_Methods{
    caesar_Method,
    
}encrypt_Methods;

std::string getOsName() {
#ifdef _WIN32
    return "Windows 32-bit";
#elif _WIN64
    return "Windows 64-bit";
#elif __unix || __unix__
    return "Unix";
#elif __APPLE__ || __MACH__
    return "Mac OS X";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#else
    return "Other";
#endif
}

void save_File(std::string encrypted_string, enum encrypt_Methods, bool is_encrypt, std::string path){
    std::ofstream encrypted_file(path);
    encrypted_file << encrypted_string << std::endl;
    encrypted_file.close();
}

void save_File(std::string encrypted_string, enum encrypt_Methods, bool is_encrypt){
    std::string file_path;
    if (getOsName() == "Windows 64-bit" || getOsName() == "Windows 32-bit"){
        if (encrypt_Methods == encrypt_Methods::caesar_Method && is_encrypt == true) {
            file_path = "C:\\encrypted_file_Cezar.txt";
        }
        else if (encrypt_Methods == encrypt_Methods::caesar_Method && is_encrypt == false)  {
            file_path = "C:\\decrypted_file_Cezar.txt";
        }
        else
            file_path = "C:\encrypted_file_metoda_lui_peste_prajit.txt";
    }
    else if (getOsName() == "Mac OS X") {
        if (encrypt_Methods == encrypt_Methods::caesar_Method && is_encrypt == true) {
            file_path = "/Users/max/encrypted_file_Cezar.txt";
        }
        else if (encrypt_Methods == encrypt_Methods::caesar_Method && is_encrypt == false)  {
           file_path = "/Users/max/decrypted_file_Cezar.txt";
        }
        else
            file_path = "/Users/max/encrypted_file_metoda_lui_peste_prajit.txt";
    }
  
    
    std::ofstream encrypted_file(file_path);
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
        std::string caeser_Method(std::string text, int s, bool is_custom_path){
            std::string result = "";
            for (int i=0;i<current_File().length();i++)
            {
                if (isupper(current_File()[i]))
                    result += char(int(current_File()[i]+s-65)%26 +65);
                else
                    result += char(int(current_File()[i]+s-97)%26 +97);
            }
            if (is_custom_path == false){
                save_File(result,encrypt_Methods::caesar_Method, true);
            }
            else {
                save_File(result,encrypt_Methods::caesar_Method, true, custom_path);
                
            }
            return "Fisierul a fost criptat cu succes !";
        }
    
        std::string metoda_lui_peste_prajit(std::string text){
            
        std::string result = "";
        //TODO
        save_File(result,encrypt_Methods::caesar_Method, true);
        return "Fisierul a fost criptat cu succes !";
            
        }
    
};

class Decrypt{
public:
    std::string caeser_Method(std::string text, int s, bool is_custom_path){
        std::string result = "";
        s = 26 - s;
        for (int i=0;i<current_File().length();i++)
        {
            if (isupper(current_File()[i]))
                result += char(int(current_File()[i]+s-65)%26 +65);
            else
                result += char(int(current_File()[i]+s-97)%26 +97);
        }
        
        if (is_custom_path == false){
            save_File(result,encrypt_Methods::caesar_Method, false);
        }
        else {
            save_File(result,encrypt_Methods::caesar_Method, false, custom_path);
            
        }
        
        return "Fisierul a fost decriptat cu succes !";
    }
    
    std::string metoda_lui_peste_prajit(std::string text){
        
        std::string result = "";
        //TODO
        save_File(result,encrypt_Methods::caesar_Method, false);
        return "Fisierul a fost decriptat cu succes !";
        
    }
};

void show_EncryptOptions(){
    char option;
    std::cout << "Step 2: Alegeti metoda de criptare: " << std::endl << std::endl;
    
    std::cout << "1. Metoda la ala francez" << std::endl;
    std::cout << "2. Metoda la XXXXXXXXXXX" << std::endl;
    std::cout << "3. Metoda la YYYYYYYYYYY" << std::endl << std::endl;
    
    std::cin >> option;
    
    Encrypt e;
    
    switch (option) {
        case '1':
            int shift;
            int default_path;
            std::cout << std::endl;

            std::cout << "Step 3: Unde doriti sa salvati fisierul criptat ? " << std::endl << std::endl;
            
            std::cout << "1. Cale implicita aka: " << path << std::endl;
            std::cout << "2. Definesc o cale pentru fisier." << std::endl;
            std::cout << std::endl;
            std::cin >> default_path;
            switch (default_path) {
                case 1:
                    std::cout << std::endl;
                    std::cout << "Introduceti numarul de deplasari: " << std::endl << std::endl;
                    std::cin  >> shift;
                    std::cout << std::endl;
                    std::cout << e.caeser_Method(path, shift, false) << std::endl << std::endl;
                    break;
                case 2:
                    std::cout << std::endl;
                    std::cout << "Introduceti calea pentru fisier: " << std::endl << std::endl;
                    std::cin  >> custom_path;
                    std::cout << "Introduceti numarul de deplasari: " << std::endl << std::endl;
                    std::cin  >> shift;
                    std::cout << std::endl;
                    std::cout << e.caeser_Method(path, shift, true) << std::endl << std::endl;
                    break;
            }
            break;
            
        case '2':
            //TODO
            break;
        case '3':
            //TODO
            break;
    }
}

void show_DecryptOptions(){
    char option;
    std::cout << "Step 2: Alegeti metoda de decriptare: " << std::endl << std::endl;

    std::cout << "1. Metoda la ala francez" << std::endl;
    std::cout << "2. Metoda la XXXXXXXXXXX" << std::endl;
    std::cout << "3. Metoda la YYYYYYYYYYY" << std::endl << std::endl;
    
    std::cin >> option;
    
    Decrypt e;
    
    switch (option) {
        case '1':
            int shift;
            int default_path;
            std::string path_modified = path;
            
            std::cout << std::endl;
            std::cout << "Step 3: Unde doriti sa salvati fisierul decriptat ? " << std::endl << std::endl;
            
            unsigned long position = path.find_last_of("/");
            path_modified.replace(position + 1, 8 ,"decrypted_file.txt");
        
            std::cout << "1. Cale implicita aka: " << path_modified << std::endl;
            std::cout << "2. Definesc o cale pentru fisier: " << std::endl;
            std::cout << std::endl;
            std::cin >> default_path;
            switch (default_path){
                case 1:{
                    std::cout << std::endl;
                    std::cout << "Introduceti numarul de deplasari folosite la criptare: " << std::endl << std::endl;
                    std::cin  >> shift;
                    std::cout << std::endl;
                    std::cout << e.caeser_Method(path, shift, false) << std::endl << std::endl;
                    break;
                }
                case 2:{
                    std::cout << std::endl;
                    std::cout << "Introduceti calea pentru fisier: " << std::endl << std::endl;
                    std::cin  >> custom_path;
                    std::cout << "Introduceti numarul de deplasari folosite la criptare: " << std::endl << std::endl;
                    std::cin  >> shift;
                    std::cout << std::endl;
                    std::cout << e.caeser_Method(path, shift, true) << std::endl << std::endl;
                    break;
            }
        case '2':
            //TODO
            break;
        case '3':
            //TODO
            break;
            }
    }
}

void show_Options(){
    char option = '0';
    
    std::cout << "Step 1: Alegeti optiunea dorita: " << std::endl << std::endl;
    std::cout << "1. Criptare" << std::endl;
    std::cout << "2. Decriptare" << std::endl << std::endl;
    std::cin >> option;
    std::cout << std::endl;
    switch (option) {
            case '1':
            show_EncryptOptions();
            break;
            case '2':
            show_DecryptOptions();
            break;
    }
}


int main(int argc, const char * argv[]) {
    std::cout << std::endl << "Programul ruleaza pe platforma: " << getOsName() << std::endl;

    if (argc == 2){
        std::cout << "Calea fisierului este: " << "'" << argv[1] << "'" << std::endl << std::endl << std::endl;
        path = argv[1];
    }
    else{
        std::cout << "Introduceti calea fisierului pentru criptare: ";
        std::cin >> path;
        std::cout << std::endl <<"Calea fisierului este: " << "'" << path << "'" << std::endl << std::endl << std::endl;
    }
    while(1){
     show_Options();
    }
    return 0;
}

// Ma gandeam sa facem mai inteligent programul aka cand scrii din linia de comanda: "crypto.exe cale_fisier" sa-l preia automat si daca se executa fara cale, sa te intrebe de calea fisierului, e functional by the way
