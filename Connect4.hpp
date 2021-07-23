#pragma once

#include <iostream>
#include <vector>

using namespace std;

#define DEFAULT_WIDTH   6
#define DEFAULT_HEIGHT  7

#define PLAYER_CELL    'X'
#define ENEMY_CELL     'O'
#define EMPTY_CELL     '_'

#define CONNECT_COUNT   4

class Connect4
{
private:
    std::vector<std::vector<char>> board;

    int countSouth(int x, int y);
    int countWest(int x, int y);
    int countEast(int x, int y);
    int countNorthwest(int x, int y);
    int countNortheast(int x, int y);
    int countSouthwest(int x, int y);
    int countSoutheast(int x, int y);

    bool inBounds(int x, int y);

public:
    Connect4();

    Connect4(std::vector<std::vector<char>> data);

    Connect4(int width, int height);

    void setBoard(std::vector<std::vector<char>> data);

    void resize(int width, int height);

    bool drop(int column);

    bool isFullyOccupied();

    bool isConnect4(int x, int y);

    void dump();
};