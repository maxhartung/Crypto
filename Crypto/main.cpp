#include <iostream>
#include <fstream>
#include <sstream>

std::string path;
std::string custom_path;

std::string getOsName() {

#ifdef _WIN64
    return "Windows 64-bit";
#elif _WIN32
    return "Windows 32-bit";
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

void save_File_custom_path(std::string encrypted_string, std::string path, std::string encrypt_Methods, bool is_encrypt){
    std::ofstream encrypted_file(path);
    encrypted_file << encrypted_string << std::endl;
    encrypted_file.close();
}

void save_File(std::string encrypted_string, std::string decrypted_file_path, std::string encrypt_Methods, bool is_encrypt){

    std::string file_path;
	
   
	if (getOsName() == "Windows 64-bit" || getOsName() == "Windows 32-bit"){
		 if (encrypt_Methods == "Scytale" && is_encrypt == true) {
		file_path = "C:\\Users\\Public\\encrypted_file_Scytale.txt";

	}
		 else	if (encrypt_Methods == "Cezar" && is_encrypt == true) {
			file_path = "C:\\Users\\Public\\encrypted_file_Cezar.txt";
			/*unsigned long position = decrypted_file_path.find_last_of("/");
			temp_path.replace(position + 1, 8, "encrypted_file_Cezar.txt");
			file_path = temp_path;*/

        }
		
		else if (encrypt_Methods == "Cezar" && is_encrypt == false)  {
			/*unsigned long position = decrypted_file_path.find_last_of("/");
			temp_path.replace(position + 1, 8, "decrypted_file_Cezar.txt");
			file_path = temp_path;*/
			file_path = "C:\\Users\\Public\\decrypted_file_Cezar.txt";
        }
		
    }
    else if (getOsName() == "Mac OS X") {
        if (encrypt_Methods == "Cezar" && is_encrypt == true) {
            file_path = "/Users/max/encrypted_file_Cezar.txt";
        }
        else if (encrypt_Methods == "Scytale" && is_encrypt == true) {
            file_path = "/Users/max/encrypted_scytale_Method.txt";
            
        }
        else if (encrypt_Methods == "Cezar" && is_encrypt == false)  {
           file_path = "/Users/max/decrypted_file_Cezar.txt";
        }
        
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

class CheckInput {
public:
    bool is_Correct_3(char userInput){
        bool is_valid = false;
        if (userInput == '1' || userInput == '2' || userInput == '3' ){
            return is_valid = true;
        }
        else{
            return is_valid;
        }
    }
    
    bool is_Correct_2(char userInput){
        bool is_valid = false;
        if (userInput == '1' || userInput == '2'){
            return is_valid = true;
        }
        else{
            return is_valid;
        }
    }
        bool is_Correct_int_2(int userInput){
            bool is_valid = false;
            if (userInput == 1 || userInput == 2){
                return is_valid = true;
            }
            else{
                return is_valid;
    }
}
};



class Encrypt{
public:
        std::string caeser_Method(std::string text, int s, bool is_custom_path){
            std::string result = "";

			
            for (int i=0;i<current_File().length();i++)
            {
				if (current_File()[i] == ' ') {
					result += " ";
					i++;
				}

				// Asta e bun daca vrei sa separi caracterele si sa nu cripteze spatiul dintre ele.

				// std::cout << current_File()[i]; // verificam output-ul
                if  (isupper(current_File()[i]))
                    result += char(int(current_File()[i]+s-65)%26 +65);
                else
                    result += char(int(current_File()[i]+s-97)%26 +97);
            }
            if (is_custom_path == false){
                save_File(result, path, "Cezar", true);
            }
            else {
                save_File_custom_path(result, custom_path, "Cezar", true);
                
            }
            return "Fisierul a fost criptat cu succes !";
        }
    
    std::string scytale_Method(std::string text, bool is_custom_path){
        int i,j,k,turns,code[100][1000],col;
        int len;
        char str[1000];
        std::string result = "";

        len = current_File().length();
		std::cout << len;
        turns = 3;
        k=0;
        
        for(i=0;i<len;)
        {
            for(j=0;j<turns;j++)
            {
                code[k][j]=0;
                i++;
            }
            k++;
        }
        k=0;
        for(i=0;i<len;)
        {
            if(current_File()[i]!=' ')
            {
                for(j=0;j<turns;)
                {
                    if(i<=len)
                    {
                        if(str[i]!=' ')
                        {
                            code[k][j]=(int)current_File()[i];
                            i++;
                            j++;
                        }
                        else
                        {
                            i++;
                        }
                        
                    }
                    else
                    {
                        break;
                    }
                    
                }
                k++;
            }
            else
            {
                i++;
            }
        }
        col=k;
        for(i=0;i<turns;i++)
        {
            for(j=0;j<col;j++)
            {
                if(code[j][i]!=0)
                result += code[j][i];
            }
        }
        if (is_custom_path == false){
            save_File(result,path,"Scytale", true);
        }
        else {
			save_File_custom_path(result,custom_path, "Scytale", true);
            
        }
        
return "Fisierul a fost criptat cu succes !";    }
};

class Decrypt{
public:
    std::string caeser_Method(std::string text, int s, bool is_custom_path){
        std::string result = "";
        s = 26 - s;
        for (int i=0;i<current_File().length()-1;i++)
        {
			if (current_File()[i] == ' ') {
				result += " ";
				i++;
			}

            if (isupper(current_File()[i]))
                result += char(int(current_File()[i]+s-65)%26 +65);
            else
                result += char(int(current_File()[i]+s-97)%26 +97);
        }
        
        if (is_custom_path == false){
            save_File(result, path, "Cezar", false);
        }
        else {
			save_File_custom_path(result, custom_path,"Cezar", false);
            
        }
        
        return "Fisierul a fost decriptat cu succes !";
    }
    
    std::string metoda_lui_peste_prajit(std::string text){
        
        std::string result = "";
        //TODO
        save_File(result,path,"Cezar", false);
        return "Fisierul a fost decriptat cu succes !";
        
    }
};

void show_EncryptOptions(){
    char option;
    std::cout << "Step 2: Alegeti metoda de criptare: " << std::endl << std::endl;
    
    std::cout << "1. Metoda lui Cezar" << std::endl;
    std::cout << "2. Metoda lui Scytale" << std::endl;
    //std::cout << "3. Metoda la YYYYYYYYYYY" << std::endl << std::endl;
    
    std::cin >> option;
    
    Encrypt e;
    
    switch (option) {
        case '1':
            int shift;
            int option;
            std::cout << std::endl;

            std::cout << "Step 3: Unde doriti sa salvati fisierul criptat ? " << std::endl << std::endl;
            
           // std::cout << "1. Cale implicita aka: " << path << std::endl;
			std::cout << "1. Cale implicita" << std::endl;
			std::cout << "2. Definesc o cale pentru fisier." << std::endl;
            std::cout << std::endl;
            std::cin >> option;
            
            switch (option) {
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
            int option_scytale;
            std::cout << std::endl;
            
            std::cout << "Step 3: Unde doriti sa salvati fisierul criptat ? " << std::endl << std::endl;
            
          //  std::cout << "1. Cale implicita aka: " << path << std::endl;
			std::cout << "1. Cale implicita" << std::endl;
			std::cout << "2. Definesc o cale pentru fisier." << std::endl;
            std::cout << std::endl;
            std::cin >> option_scytale;
            
            switch (option_scytale) {
                case 1:
                    std::cout << std::endl;
                    std::cout << e.scytale_Method(path, false) << std::endl << std::endl;
                    break;
                case 2:
                    std::cout << std::endl;
                    std::cout << "Introduceti calea pentru fisier: " << std::endl << std::endl;
                    std::cin  >> custom_path;
                    std::cout << std::endl;
                    std::cout << e.scytale_Method(path, true) << std::endl << std::endl;
            break;
        case '3':
            //TODO
            break;
    }
}
}
void show_DecryptOptions(){
    
    char option;
    Decrypt e;
    CheckInput CheckInput_obj;
    
    std::cout << "Step 2: Alegeti metoda de decriptare: " << std::endl << std::endl;

    std::cout << "1. Metoda lui Cezar" << std::endl;
    std::cout << "2. Metoda lui Scytale" << std::endl;
   // std::cout << "3. Metoda la YYYYYYYYYYY" << std::endl << std::endl;
    
    std::cin >> option;
    
    while (CheckInput_obj.is_Correct_3(option) != true) {
        std::cout << std::endl;
        std::cout << "Error: Introduceti o optiune valida ! " << std::endl << std::endl;
        show_DecryptOptions();
    }
    
    
    switch (option) {
        case '1':
            int shift;
            int option;
            std::string path_modified = path;
            
            std::cout << std::endl;
            std::cout << "Step 3: Unde doriti sa salvati fisierul decriptat ? " << std::endl << std::endl;
            
            unsigned long position = path.find_last_of("/");
            path_modified.replace(position + 1, 8 ,"decrypted_file.txt");
        
           // std::cout << "1. Cale implicita aka: " << path_modified << std::endl;
			std::cout << "1. Cale implicita" << std::endl;
            std::cout << "2. Definesc o cale pentru fisier: " << std::endl;
            std::cout << std::endl;
            std::cin >> option;
            switch (option){
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
    char option;
    CheckInput CheckInput_obj;
    
    std::cout << "Step 1: Alegeti optiunea dorita: " << std::endl << std::endl;
    std::cout << "1. Criptare" << std::endl;
    std::cout << "2. Decriptare" << std::endl << std::endl;
    std::cin >> option;
    
   while (CheckInput_obj.is_Correct_2(option) != true) {
       std::cout << std::endl;
       std::cout << "Error: Introduceti o optiune valida ! " << std::endl << std::endl;
       show_Options();
   }
    
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
        std::cout << "Introduceti calea fisierului pentru criptare/decriptare: ";
        std::cin >> path;
        std::cout << std::endl <<"Calea fisierului este: " << "'" << path << "'" << std::endl << std::endl << std::endl;
    }
     show_Options();
    return 0;
}

// Ma gandeam sa facem mai inteligent programul aka cand scrii din linia de comanda: "crypto.exe cale_fisier" sa-l preia automat si daca se executa fara cale, sa te intrebe de calea fisierului, e functional by the way
