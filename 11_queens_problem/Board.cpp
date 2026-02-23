#include "Board.hpp"

#include <string>
#include <iostream>

Board::Board() {
    board_size = 8;
    finished = false;
    std::string row(board_size, ' ');
    for(int i = 0; i < board_size; i++) {
        board.push_back(row);
    }
}

Board::Board(const std::vector<std::string>& b)
{
    board = b;
    board_size = b.size();
    finished = false;
}

void Board::print() const {
    int i = 0;
    int j = board_size;
    std::cout << "  ________\n";
    while (i < board_size) {
        std::cout << j << '|' << board[i] << '|' << std::endl;
        i++;
        j--;
    }
    std::cout << "  --------\n";
    std::cout << "  abcdefgh\n";
}

void Board::place_queens() {
    bool finished = false;
    place_queens_helper(0, 0, 0, finished);
}

void Board::place_queens_helper(int row, int col, int queens_placed, bool& finished)
{
    // Base case
    if (queens_placed == 8) {
        finished = true;
        return;
    }

    for (int i = row; i < board_size; i++) {
        for (int j = col; j < board_size; j++) {
            if (board[i][j] == ' ' && check_place(i, j)) {
                board[i][j] = '*';
                if (!finished) {
                    print();
                    place_queens_helper(i+1, 0, queens_placed+1, finished);
                    if (finished) return;
                    board[i][j] = ' ';
                } 
                else return;
            }

        }
    }

}

void Board::place_queens_all_helper(int row, int col, int queens_placed)
{
    if (queens_placed == 8) {
        print();
        return;
    }

    for (int i = row; i < board_size; i++) {
        for (int j = col; j < board_size; j++) {
            if (board[i][j] == ' ') {
                if (check_place(i, j)) {
                    board[i][j] = '*';
                    place_queens_all_helper(i+1, 0, queens_placed+1);
                    board[i][j] = ' ';
                }
            }
        }
    }
}

bool Board::find_king_path(int row, int col)
{
    if (!find_king_path_recursive(row, col)) {
        std::cout << "NO PATH" << std::endl;
        return false;
    }
    return true;
}

bool Board::find_king_path_recursive(int row, int col)
{
    if (row >= board_size || col >= board_size || board[row][col] == '*') {
        return false;
    }

    // mark cur cel
    board[row][col] = '.';

    // base case: reached BR corner
    if (row == board_size-1 && col == board_size-1) {
        print();
        return true;
    }
 
    // recursion
    // try right
    if (find_king_path_recursive(row, col + 1))
        return true;
    
    // try down
    if (find_king_path_recursive(row + 1, col))
        return true;
    
    // backtrack: unmark cell
    board[row][col] = ' ';
    return false;
}

bool has_char(const std::string& s, const char c, int n) {
    for(int i = 0; i < n; i++) {
        if (s[i] == c) 
            return true;
    }
    return false;
}



bool Board::check_place(const int row, const int col) const {
    //NS
    int i = 0;
    int j = col;
    while (i < board_size) {
        if (board[i][j] == '*' && (i != row || j != col)) {
            return false;
        }
        i++;
    }

    i = row;
    j = col;

    
    //NE
    while (i >= 0 && j < board_size) {
        if (board[i][j] == '*' && (i != row || j != col)) {
            return false;
        }
        i--;
        j++;
    }

    i = row;
    j = 0;

    //WE
    while (j < board_size) {
        if (board[i][j] == '*' && (i != row || j != col)) {
            return false;
        }
        j++;
    }

    
    //SE
    i = row;
    j = col;

    while (i < board_size && j < board_size) {
        if (board[i][j] == '*' && (i != row || j != col)) {
            return false;
        }
        j++;
        i++;
    }

    i = row;
    j = col;

    //SW
    while (i < board_size && j >= 0) {
        if (board[i][j] == '*' && (i != row || j != col)) {
            return false;
        }
        j--;
        i++;
    }
    
    //NW
    i = row;
    j = col;

    while (i >= 0 && j >= 0) {
        if (board[i][j] == '*' && (i != row || j != col)) {
            return false;
        }
        j--;
        i--;
    }
    
    return true;
}