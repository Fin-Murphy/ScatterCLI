#include "main.h"
#include <iostream>


int main (int argc, char * argv[]) {
    CLI c;

    if(argc < 2){
			std::cout << "Argc less than 2. Run again and input additonal args.";
	}

    c.filepath = argv[1];

    c.lineOutput();

}
