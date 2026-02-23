#include "Board.hpp"
#include <iostream>

int main(void) {
    Board chess;
    chess.print();
    chess.place_queens();
    chess.print();

    std::cout << "\n====King Path====\n";

    std::vector<std::string> a {
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        "
    };
    
    std::vector<std::string> b {
        "   *    ",
        "   *  * ",
        "   *  * ",
        "   *  * ",
        "   *    ",
        "      * ",
        "   ***  ",
        "   *    ",
    };
    std::vector<std::string> c {
        " *  *   ",
        "   *  * ",
        "*       ",
        "  *  *  ",
        "       *",
        "      * ",
        "   **   ",
        "   *    ",
    };
    
    
    Board chess1(a);
    Board chess2(b);
    Board chess3(c);

    chess1.find_king_path(0, 0);
    chess2.find_king_path(0, 0);
    chess3.find_king_path(0, 0);


    return 0;
}