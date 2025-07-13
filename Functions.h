
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
        
    public: 

        //Constructor
        CLI(){
            fileReader();
        }

        std::string lineOutput();
        int promptTranslate(std::string prompt);
        bool inputTriage(int input);
        void fileReader();
        void printAll();
        void fileWriter(std::string filepath);
        void taskMover();

    };

#endif