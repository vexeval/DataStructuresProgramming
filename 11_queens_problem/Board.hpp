#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>

class Board {
public:
    Board();
    Board(const std::vector<std::string>& b);

    void print() const;
    void place_queens();
    void place_queens_all();
    bool find_king_path(int i, int j); 
    
    private:
    bool check_place(const int row, const int col) const;
    void place_queens_helper(int row, int col, int queens_placed, bool& finished);
    void place_queens_all_helper(int row, int col, int queens_placed);
    bool find_king_path_recursive(int row, int col);
    
    std::vector<std::string> board;
    unsigned board_size;
    bool finished;
};

#endif