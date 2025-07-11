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
            std::cout << "Test1";
            break;

        case 1:
            std::cout << "Test2";
            outVal = false;
            break;

        case 2: 
            fileReader();
            printAll();
            
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

void CLI::fileReader(){
    std::string shitString = "barf";

    bool crunch = true;

    std::ifstream file(filepath);
    std::string line;

    std::string delimiter;
    std::string name;
    std::string group;

    while(std::getline(file, line) && crunch == true){

        std::istringstream ss(line);
        
        ss >> delimiter;

        if(delimiter == "##"){
            // std::cout << delimiter << std::endl;
            group = ss.str();
            if(group == "## COMPLETED"){
                crunch = false;
            }
        } else if(delimiter == "-"){
            // std::cout << delimiter << std::endl;
            ss >> delimiter;
            ss >> delimiter;

            name = ss.str();

            Habit h = Habit(name, group);
            habitContainer.push_back(h);
            size++;
        } else {
            // std::cout << "Syntax line" << std::endl;
            delimiter = "";
        }
    }
}



void CLI::printAll(){
    for(Habit h : this->habitContainer){
        std::cout << std::endl;
        std::cout << h.group << " " << h.name << std::endl;
    }
    
}


void CLI::taskMover(){

    Habit h = Habit("Task1", "Cat1");

    std::fstream file(filepath);
    std::string line;
    int length = 0;


    while(std::getline(file, line)){
        length++;
    }

    std::cout << "File is " << length << "lines long" << std::endl;

    


}

