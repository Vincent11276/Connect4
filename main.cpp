#include <iostream>
using namespace std;

#include "Connect4.hpp"

int main()
{
    std::vector<std::vector<char>> board
    {
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', 'X', 'X', 'X', '_'},
    };

    Connect4 game(board);

    game.drop(4);

    game.dump();

    cout << game.isConnect4(4, 6);


    return EXIT_SUCCESS;
}

/*
clang .\main.cpp .\Connect4.cpp -o Connect4.exe; ./Connect4.exe
clang .\main.cpp .\Connect4.cpp -o Connect4.exe

*/