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

    std::string line = "";
    std::string dupe = "";

    bool grabbedLine = false;

    while(std::getline(file,line)){
        //Idea for logic: Have line get grabbed when iterating through, set a bool when habit found and remove that line, 
        //Then drop it off after the completed bar is located. 

        //OR just read in all lines, store them in dynamic pointers, and then write them out again in a new file every query. 
        //That's probably the best method, since syntax is constant and the files are easily replicatable. It may get messy 
        // with large files but I can deal with that later. 

    }

}



void CLI::taskPrinter(){

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
            group = ss.str();
            if(group == "## COMPLETED"){
                crunch = false;
            }
        } else if(delimiter == "-"){
            ss >> delimiter;
            ss >> delimiter;

            name = ss.str();
            std::cout << name;
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

