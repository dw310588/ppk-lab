#include <iostream>
#include <string>
#include <fstream>

#include "./console.h"
#include "./tree.h"
//#include "./color.h"
#include "./sort.h"

enum Command {
    ADD,
    REMOVE,
    PRINT,
    GRAPH,
    EXIT,
    ERR
};

std::vector<std::string> string_into_words(std::string str) {
    std::vector<std::string> res;
    std::string tmp;
    for(int i = 0; i < str[i] != 0; i++) {
        if(str[i] == ' ') {
            res.push_back(tmp);
            tmp.clear();
        } else {
            tmp += str[i];
        }
    }
    res.push_back(tmp);
    tmp.clear();
    return res;
}

Command get_command(std::vector<std::string>& word) {
    Command cmd;
    if(word[0] == "add") {
        cmd = ADD;
    } else if(word[0] == "remove") {
        cmd = REMOVE;
    } else if(word[0] == "print") {
        cmd = PRINT;
    } else if(word[0] == "exit") {
        cmd = EXIT;
    } else if(word[0] == "graph") {
        cmd = GRAPH;
    } else {
        cmd = ERR;
    }
    return cmd;
}

void add_nums(std::vector<std::string>& words) {
    for(int i = 1; i < words.size(); i++) {
        double current = std::stod(words[i]);
        tree_insert(current);
    }
}

void remove_nums(std::vector<std::string>& words) {
    for(int i = 1; i < words.size(); i++) {
        double curr = std::stod(words[i]);
        tree_delete_node(curr);
    }
}

void print_sorted(std::vector<std::string>& words) {
    std::vector<double> nodes = tree_get_nodes();
    if(words.size() < 2) {
        std::cout << "{ ";
        for(int i = 0; i < nodes.size()-1; i++) {
            std::cout << nodes[i] << ", ";
        }
        std::cout << nodes[nodes.size()-1] << " }" << std::endl;
    } else if(words[1][0] == '+') {
        std::string filename = words[1];
        filename.erase(filename.begin());
        std::ofstream file(filename,std::ios_base::app);
        file << "{ ";
        for(int i = 0; i < nodes.size()-1; i++) {
            file << nodes[i] << ", ";
        }
        file << nodes[nodes.size()-1] << " }" << std::endl;
        file.close();
    } else {
        std::ofstream file(words[1]);
        file << "{ ";
        for(int i = 0; i < nodes.size()-1; i++) {
            file << nodes[i] << ", ";
        }
        file << nodes[nodes.size()-1] << " }" << std::endl;
        file.close();
    }
}

void graph(std::vector<std::string>& words) {
    std::vector<std::vector<std::pair<double,Color>>> levels = tree_get_levels();
    if(words.size() < 2) {
        for(int i = 0; i < levels.size(); i++) {
            for(int j = 0; j < levels[i].size(); j++) {
                std::pair<double,Color> current = levels[i][j];
                if(current.second == BLACK) {
                    std::cout << "[" << current.first << "] ";
                } else if(current.second == RED) {
                    std::cout << "(" << current.first << ") ";
                }
            }
            std::cout << std::endl;
        }
    } else if(words[1][0] == '+') {
        std::string filename = words[1];
        filename.erase(filename.begin());
        std::ofstream file(filename,std::ios_base::app);
        for(int i = 0; i < levels.size(); i++) {
            for(int j = 0; j < levels[i].size(); j++) {
                std::pair<double,Color> current = levels[i][j];
                if(current.second == BLACK) {
                    file << "[" << current.first << "] ";
                } else if(current.second == RED) {
                    file << "(" << current.first << ") ";
                }
            }
            file << std::endl;
        }
    } else {
        std::string filename = words[1];
        std::ofstream file(filename);
        for(int i = 0; i < levels.size(); i++) {
            for(int j = 0; j < levels[i].size(); j++) {
                std::pair<double,Color> current = levels[i][j];
                if(current.second == BLACK) {
                    file << "[" << current.first << "] ";
                } else if(current.second == RED) {
                    file << "(" << current.first << ") ";
                }
            }
            file << std::endl;
        }
    }
}

int loop(Console::Console& cons) {
    std::vector<std::string> words = string_into_words(cons.curr_line);
    Command cmd = get_command(words);
    switch(cmd) {
        case ADD:
            add_nums(words);
            break;
        case REMOVE:
            remove_nums(words);
            break;
        case PRINT:
            print_sorted(words);
            break;
        case GRAPH:
            graph(words);
            break;
        case EXIT:
            return EXIT_COMMAND;
        case ERR:
            return ERR_BAD_COMMAND;
    }
    return 0;
}

int main() {
    Console::Console cons = Console::console_init();
    Console::console_start_reading(cons, &loop);

    tree_init();

    return 0;
}
