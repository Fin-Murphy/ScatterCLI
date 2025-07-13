#include "Functions.h"

std::string filepath = "/Users/fin/Desktop/BRAIN2/K1.md";
std::string inputMessage = "| > ";
std::string screenFill = "|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n";

std::string CLI::lineOutput () {

    std::string prompt; 
    bool cycle = true;

    std::cout << screenFill;
    while(cycle){
        std::cout << inputMessage;
        std::cin >> prompt;
        std::cout << screenFill << inputMessage;

        cycle = inputTriage(promptTranslate(prompt));

    }
    return "Hallo";
}

int CLI::promptTranslate(std::string prompt) {
    int returnval = 0;

    if(prompt == "kill"){
        returnval = 1;
    }
    else if (prompt == "list"){
        returnval = 2;
    }
    else if (prompt == ""){
        returnval = 3; 
    } 
    else if (prompt == ""){
        returnval = 4; 
    } else {}

    return returnval;
}

bool CLI::inputTriage(int input) {

    bool outVal = true;

    switch(input) {
    
        case 0: 
            //std::cout << "Test1";
            break;

        case 1:
            std::cout << "Test2";
            outVal = false;
            break;

        case 2: 
            taskPrinter();
            
            break; 

        case 3: 
            std::cout << "Test4";
            break;

        case 4:
            std::cout << "Test5";
            break;
    }
    return outVal;

}
 
void CLI::fileOpener(){
    try {
        file.open(filepath);
    } catch (...){
        std::cout << "File opening failed. This object is now useless." << std::endl;
    }
}

void CLI::fileCloser(){
    try {
        file.close();
    } catch (...){
        std::cout << "File closing failed." << std::endl;
    }
}


void CLI::strikeTask(std::string habitName){

    this->fileOpener();

    bool crunch = true;

    std::string line;

    std::string delimiter;
    std::string name;
    std::string group;


    while(std::getline(this->file, line) && crunch == true){

        std::istringstream ss(line);

        ss >> delimiter;

        if(delimiter == "##"){
            ss >> group;
            if(group == "COMPLETED"){
                crunch = false;
            }
        } 
        
        else if(delimiter == "-"){
            ss >> delimiter;
            ss >> delimiter;
            ss >> name;
            
            std::cout << name << " - " << group << std::endl;

            // Habit h = Habit(name, group);
            // // habitContainer.push_back(h);
            // std::cout << std::endl;
            // std::cout << h.group << " " << h.name << std::endl;

        } else {
            delimiter = "";
        }
    }

    this->fileCloser();

}



void CLI::taskPrinter(){

    std::cout << std::endl;

    this->fileOpener();

    bool crunch = true;

    std::string line;

    std::string delimiter;
    std::string name;
    std::string group;


    while(std::getline(this->file, line) && crunch == true){

        std::istringstream ss(line);


        // NOTE - STREAM EXTRACTION OPERATOR DOES NOT ACTUALLY REMOVE CONTENT FROM THE STRING, ONLY
        // ADVANCES THE CURSOR WITHIN THE STRING!!!!! SO REFERENCING THE STRINGSTREAM DIRECTLY WILL ALWAYS
        // RETURN ALL OF THE ORIGINIAL CONTENT FROM THE STRING!

        ss >> delimiter;

        if(delimiter == "##"){
            ss >> group;
            if(group == "COMPLETED"){
                crunch = false;
            }
        } 
        
        else if(delimiter == "-"){
            ss >> delimiter;
            ss >> delimiter;
            ss >> name;
            
            std::cout << name << " - " << group << std::endl;

            // Habit h = Habit(name, group);
            // // habitContainer.push_back(h);
            // std::cout << std::endl;
            // std::cout << h.group << " " << h.name << std::endl;

        } else {
            delimiter = "";
        }
    }

    this->fileCloser();
}



void CLI::printAll(){
    std::vector<Habit> habCont;

    for(Habit h : habCont){
        std::cout << std::endl;
        std::cout << h.group << " " << h.name << std::endl;
    }
    
}

  