#include <iostream>

#include "GameController.h"

int main() try {
    GameController().run();
}
catch (std::logic_error & error){
    auto log = std::ofstream("log.txt");
    log << error.what() << std::endl;
}
catch (FileError & error){
    auto log = std::ofstream("log.txt");
    log << error.what() << std::endl;
}