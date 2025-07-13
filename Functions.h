
#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>



/* **********************************************************

                        HABIT STRUCT DECLARATION

********************************************************** */

struct Habit {

    std::string name;
    int reward;
    std::string group;

    Habit(std::string inname, std::string ingroup){
        this->name = inname;
        this->group = ingroup;
        this->reward = 1;
    }

};


/* **********************************************************

                        CLI CLASS DECLARATION

********************************************************** */

class CLI {

    private:
        int runtime; 
        int size;
        std::vector<Habit> habitContainer;
        std::string filepath = "/Users/fin/Desktop/BRAIN2/K1.md";
        std::ifstream file;
        
    public: 

        //Constructor
        // CLI(){ fileOpener(); }

        void fileOpener();
        void fileCloser();

        void taskPrinter();
        
        std::string lineOutput();
        int promptTranslate(std::string prompt);
        bool inputTriage(int input);

        void strikeTask();

        void printAll();

    };

#endif