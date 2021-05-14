#ifndef reader_h
#define reader_h

#include <string>
#include <fstream>
#include <vector>

class Reader {
    std::string extention = ".txt";
    std::string boards_path;
    std::string scores_path;
    std::string board;
    std::string path_to_file;
    std::vector<int> results;
public:
    Reader(char option, std::string filename, int score = 0);
    std::string getboard();
    void read(std::string filename, std::string path_to_file);
    void write(std::string filename, std::string path_to_file, int score);
    void sort_scores();
    int getscore(int id);
};

#endif //reader_h
