#include <iostream>      // std::cerr, std::cout
#include <string>        // std::string
#include <vector>        // std::vector
#include <sstream>       // std::istringstream
#include <unistd.h>      // fork, execvp
#include <sys/wait.h>    // waitpid
#include <cstring>       // strdup, free


std::vector<std::string> split_command(const std::string& komut) {
    std::istringstream iss(komut);  
    std::string kelime;
    std::vector<std::string> sonuc;

    while (iss >> kelime) {         
        sonuc.push_back(kelime);    
    }

    return sonuc;
}

void command(const std::string& komut) {
        std::vector<std::string> args = split_command(komut);

    
    if (args.empty()) {
        std::cerr << "empty command" << std::endl;
        return;
    }

    std::vector<char*> argv;

    for (const auto& s : args) {
        argv.push_back(strdup(s.c_str())); 
    }

    argv.push_back(nullptr); 

    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "fork() error!" << std::endl;
    } else if (pid == 0) {
        execvp(argv[0], argv.data());

        std::cerr << "execvp failed" << std::endl;
        exit(1);
    } else {
        
        int durum;
        waitpid(pid, &durum, 0);
    }

    for (char* ptr : argv) {
        free(ptr);
    }
}

