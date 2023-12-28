#include <iostream>
#include <string>

enum Command {
    ADD,
    PRINT,
    GRAPH
};

struct Console {
    std::string curr_line;
    Command command;
};

int main() {
    Console console;
    while(std::getline(std::cin,console.curr_line)) {
        int i = 0;
        std::string buf;
        for(i = 0; console.curr_line[i] != ' '; i++) {
            if(console.curr_line[i] == '\0') {
                break;
            }
            buf += console.curr_line[i];
        }
        std::cout << "buf => " << buf << std::endl;
        if(buf == "add") {
            console.command = ADD;
            std::cout << "console::command => ADD" << std::endl;
        } else if(buf == "print") {
            console.command = PRINT;
            std::cout << "console::command => PRINT" << std::endl;
        } else if(buf == "graph") {
            console.command = GRAPH;
            std::cout << "console::command => GRAPH" << std::endl;
        } else {
            std::cout << "Command not recognized" << std::endl;
            break;
        }
    }

    return 0;
}
