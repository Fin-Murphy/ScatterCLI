#include "Functions.h"


// std::string filepath = "/Users/fin/Desktop/BRAIN2/K1.md";
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

    if(prompt == ""){
        returnval = 0;
    }
    if(prompt == "kill"){
        returnval = 1;
    }
    else if (prompt == "list"){
        returnval = 2;
    }
    else if (prompt == "strike"){
        returnval = 3; 
    }
    else if (prompt == "add"){
        returnval = 4; 
    } else if (prompt == "delete"){
        returnval = 5; 
    } else {}

    return returnval;
}


bool CLI::inputTriage(int input) {

    bool outVal = true;

    switch(input) {
    
        case 0: 

        break;

        case 1:
            outVal = false;
            break;

        case 2: 
            taskPrinter();
            break; 
        case 3: 
            strikeTask();
            break;

        case 4:
            addTask();
            break;
        case 5:
            deleteTask();
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

void CLI::addTask(){
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string name;

    std::cout << screenFill;
    taskPrinter();

    std::cout << "| Name of task to add |> ";
    std::getline(std::cin, name);

    std::ifstream inFile(filepath);
    std::ofstream outFile("Temp.txt");

    std::string line;
    std::string delimiter;
    bool foundFirstCategory = false;

    while(std::getline(inFile, line)){
        
        if(foundFirstCategory == false){

            std::stringstream ss(line);

            ss >> delimiter;
            if(delimiter == "##"){
                foundFirstCategory = true;

                outFile << line << std::endl;
                outFile << "- [ ] " << name << std::endl;

            } else {
                outFile << line << std::endl;
            }

        } else {
            outFile << line << std::endl;
        }            

    }

    inFile.close();
    outFile.close();

    std::ifstream tempFile("Temp.txt");
    std::ofstream finalizeFile(filepath);

    while(std::getline(tempFile,line)){
        finalizeFile << line << std::endl;
    }
   
    tempFile.close();
    finalizeFile.close();

    std::cout << screenFill;

    taskPrinter();

}

void CLI::deleteTask(){

    std::string name;

    std::cout << screenFill;

   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    taskPrinter();
    std::cout << "Task to delete: ";
    std::getline(std::cin, name);

    std::cout << screenFill;

    std::string testName;

    std::ifstream inFile(filepath);
    std::ofstream outFile("Temp.txt");

    std::string line;
    std::string delimiter;
    bool foundSkippable = false;

    while(std::getline(inFile, line)){
        
        if(foundSkippable == false){

            std::stringstream ss(line);

            ss >> delimiter;

            if(delimiter == "-"){

                ss >> delimiter;
                ss >> delimiter;

                testName = "";
                char c;
                bool keeploop = true;
                ss.get(c);
                while(ss.get(c) && keeploop){
                    testName += c;
                }

                if(testName == name){
                    std::cout << "| Deleted item" << std::endl;
                    foundSkippable = true;
                } else {
                    outFile << line << std::endl;

                }
            } else {
                outFile << line << std::endl;
            }

        } else {
            outFile << line << std::endl;
        }            

    }

    inFile.close();
    outFile.close();

    std::ifstream tempFile("Temp.txt");
    std::ofstream finalizeFile(filepath);

    while(std::getline(tempFile,line)){
        finalizeFile << line << std::endl;
    }
   
    tempFile.close();
    finalizeFile.close();
    
    taskPrinter();

}


void CLI::strikeTask(){
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    taskPrinter();
    std::string name;
    std::cout << "Task to strike: ";
    std::getline(std::cin, name);

    std::ifstream inFile(filepath);
    std::ofstream outFile("Temp.txt");

// ---------------------------------------------------------
//  WRITE TO A TEMPORARY FILE TO SAVE THE DATA IN HERE ~
// ----------------------------------------------------------

    std::string line;
    std::string delimiter;
    bool copyLine;

    std::string testName;
    std::string taskToMove;


    //Locate Task line, skip

    while(std::getline(inFile, line)){
        // std::cout << "entered" << std::endl;    
        copyLine = true;

        std::stringstream ss(line);

        ss >> delimiter;

        if(delimiter == "-"){
            ss >> delimiter;
            ss >> delimiter;

            testName = "";
            char c;
            bool keeploop = true;
            ss.get(c);
            while(ss.get(c) && keeploop){
                testName += c;
            }

            if(testName == name){
                copyLine = false;
                taskToMove = line;

                std::cout << screenFill <<  "| > " << name << " Struck" << std::endl;
            }


        } else if (delimiter == "##"){
            ss >> delimiter;
            if(delimiter == "COMPLETED"){
                outFile << "## COMPLETED" << std::endl;
                outFile << taskToMove << std::endl;
                copyLine = false;
            }
        } else if (delimiter == ""){
            copyLine = false;
        }

        if(copyLine){
            outFile << line << std::endl;
        }
    }

    //Copy temporary file to the main file

    inFile.close();
    outFile.close();

    std::ifstream tempFile("Temp.txt");
    std::ofstream finalizeFile(filepath);

    while(std::getline(tempFile, line)){
        finalizeFile << line << std::endl;
    }

    tempFile.close();
    finalizeFile.close();

    taskPrinter();

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

        name = "";
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
             
                char c;
                bool keeploop = true;
                while(ss.get(c) && keeploop){
                    if(c == '\n'){
                        keeploop = false;
                    } else {name += c;}
                }

            
            std::cout << group << " - >" << name << std::endl;

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



