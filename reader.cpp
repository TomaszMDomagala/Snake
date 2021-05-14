#include "reader.h"

#include <iostream>

Reader::Reader(char option, std::string filename, int score) {

    if (option == 'b') {
        scores_path = "./boards/";
        path_to_file = scores_path + filename + extention;
        read(filename, path_to_file);
    } else if (option == 's') {
        scores_path = "./scores/";
        path_to_file = scores_path + filename + extention;
        read(filename, path_to_file);
    } else if (option == 'w') {
        scores_path = "./scores/";
        path_to_file = scores_path + filename + extention;
        write(filename, path_to_file, score);
    }
}

std::string Reader::getboard() {
    return board;
}

void Reader::read(std::string filename, std::string path_to_file) {
    std::fstream file;
    file.open(path_to_file, std::ios::in);
    if (file.is_open() == true) {
        std::string board_line;
        while (!file.eof()) {
            std::getline(file, board_line);
            board += board_line;
        }
        file.close();
    } else {
        std::cerr << "File not found" << '\n';
    }
}

void Reader::sort_scores() {
    std::string number = "";
    for (int i = 0; i < board.length(); i++) {
        if(board.at(i) == ';') {
            int to_vect = std::stoi(number);
            results.push_back(to_vect);
            number = "";
        } else {
            number += board.at(i);
        }
    }

    for(int i = 0; i < results.size(); i++) {
		for(int j = 0; j < results.size() - i; j++) {
			if(results[j] > results[j+1]) {
				int temp = results[j+1];
				results[j+1] = results[j];
				results[j] = temp;
            }
        }
    }
}

void Reader::write(std::string filename, std::string path_to_file, int score) {
    std::fstream file;
    file.open(path_to_file, std::ios::app);
    if (file.is_open() == true) {
        file << score << ";" << '\n';
        file.close();
    } else {
        std::cerr << "File not found" << '\n';
    }
}

int Reader::getscore(int id) {
    int place = results.size() - id;
    return results.at(place);
}
