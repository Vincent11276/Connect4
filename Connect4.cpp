#include "Connect4.hpp"


Connect4::Connect4()
{
    this->resize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
}

Connect4::Connect4(std::vector<std::vector<char>> data)
{
    setBoard(data);
}

Connect4::Connect4(int width, int height)
{
    this->resize(width, height);
}

bool Connect4::drop(int col)
{
    if (col < 0 || col > this->board.size()) 
        return EXIT_FAILURE;

    for (int row = this->board.size() - 1; row > 0; row--)
    {
        if (this->board[row][col] == EMPTY_CELL)
        {
            this->board[row][col] = PLAYER_CELL;

            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

bool Connect4::isFullyOccupied()
{
    for (auto &row: this->board)
    {
        for (auto &cell: row)
        {
            if (cell == EMPTY_CELL)
            {
                return false;
            }
        }
    } 
    return true;
}


int Connect4::countSouth(int x, int y)
{
    int count = 0;

    while (this->inBounds(x, y))
    {
        y--;

        if (board[x][y] == PLAYER_CELL)
        {
            count++;
        }
        else break;
    }
    return count;
}

int Connect4::countWest(int x, int y)
{
    int count = 0;

    while (this->inBounds(x, y))
    {
        cout << x << endl;
        x--;

        if (board[x][y] == PLAYER_CELL)
        {
            count++;
        }
        else break;
    }
    cout << count << endl;
    return count;
}

int Connect4::countEast(int x, int y)
{
    int count = 0;

    while (this->inBounds(x, y))
    {
        x++;

        if (board[x][y] == PLAYER_CELL)
        {
            count++;
        }
        else break;
    }
    return count;
}

int Connect4::countNorthwest(int x, int y)
{
    int count = 0;

    while (this->inBounds(x, y))
    {
        x--;
        y--;

        if (board[x][y] == PLAYER_CELL)
        {
            count++;
        }
        else break;
    }
    return count;
}

int Connect4::countNortheast(int x, int y)
{
    int count = 0;

    while (this->inBounds(x, y))
    {
        x++;
        y--;

        if (board[x][y] == PLAYER_CELL)
        {
            count++;
        }
        else break;
    }
    return count;
}

int Connect4::countSouthwest(int x, int y)
{
    int count = 0;

    while (this->inBounds(x, y))
    {
        x--;
        y++;

        if (board[x][y] == PLAYER_CELL)
        {
            count++;
        }
        else break;
    }
    return count;
}

int Connect4::countSoutheast(int x, int y)
{
    int count = 0;

    while (this->inBounds(x, y))
    {
        x++;
        y++;

        if (board[x][y] == PLAYER_CELL)
        {
            count++;
        }
        else break;
    }
    return count;
}

bool Connect4::inBounds(int x, int y)
{
    return (x >= 0) && (y >= 0) &&
           (x < this->board[0].size()) &&
           (y < this->board.size());
}

bool Connect4::isConnect4(int x, int y)
{
    // vertical
    if (this->countSouth(x, y) > CONNECT_COUNT) 
        return true;

    //horizontal
    if (this->countWest(x, y) + this->countEast(x, y) > CONNECT_COUNT) 
        return true;

    //vertical 1
    if (this->countNorthwest(x, y) + this->countSoutheast(x, y) >= CONNECT_COUNT)
        return true;

    //vertical 2
    if (this->countNortheast(x, y) + this->countSouthwest(x, y) >= CONNECT_COUNT)
        return true;

    return false;
}

void Connect4::setBoard(std::vector<std::vector<char>> data)
{ 
    board = data;
}


void Connect4::resize(int width, int height)
{
    this->board.resize(height, std::vector<char>(width, EMPTY_CELL));
}

void Connect4::dump()
{
    for (auto &row: this->board)
    {
        for (auto &cell: row)
        {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}
