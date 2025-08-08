# include <iostream>
#include <string>
#include "command.hpp"
int main(){
    std::cout << "Enter a directory.\n";
    std::string directory;
    std::cin >> directory;
    command("ls -a " + directory);
return 0;
}
