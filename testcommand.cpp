# include <iostream>
#include <string>
#include "command.hpp"
int main(){
    std::string dizin;
    std::cin >> dizin;
    command("ls -a " + dizin);
return 0;
}
