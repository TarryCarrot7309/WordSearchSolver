#include <iostream>
#include <string>
#include <vector>

struct Coordinate {
    int x; // Row
    int y; // Column

    Coordinate(int x_value, int y_value) : x(x_value), y(y_value) {}
};
std::string word_find;
std::vector <std::string> words = {"BRAIN","BONES","TISSUE", "MUSCLE", "BLOOD", "NERVES", "CELL"};
std::vector<std::vector<char>> grid = {
        {'B', 'K', 'D', 'S', 'U', 'B', 'O', 'N', 'E', 'S', 'C', 'C'},
        {'H', 'R', 'J', 'S', 'N', 'E', 'R', 'V', 'E', 'S', 'C', 'C'},
        {'Y', 'T', 'A', 'L', 'U', 'O', 'Q', 'A', 'A', 'B', 'F', 'T'},
        {'W', 'L', 'Q', 'I', 'Q', 'O', 'C', 'E', 'L', 'L', 'Y', 'I'},
        {'F', 'E', 'I', 'J', 'N', 'W', 'E', 'Z', 'Y', 'H', 'X', 'S'},
        {'U', 'B', 'L', 'O', 'O', 'D', 'X', 'V', 'P', 'U', 'I', 'S'},
        {'T', 'J', 'H', 'Z', 'B', 'R', 'O', 'P', 'J', 'B', 'L', 'U'},
        {'A', 'M', 'U', 'S', 'C', 'L', 'E', 'Q', 'D', 'F', 'K', 'E'}
    };
std::vector<Coordinate> findAll(const std::vector<std::vector<char>> &grid, char word) {
    std::vector<Coordinate> coordinates; // To store all coordinates

    // Loop through the grid
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            if (grid[row][col] == word) {
                // Add the coordinate to the vector
                coordinates.emplace_back(row, col);
            }
        }
    }

    return coordinates;
}
Coordinate check_horizontal(std::vector <Coordinate> &coordinates, std::string word_find)
{

    for (int i = 0; i < coordinates.size(); i++)
    {
        low = coordinates[i].y + 1;
        up = coordinates[i]. y - 1;
        lower = grid
        if (coordinates[i].x + 1 == )
        {
            /* code */
        }
        
    }
    
}

int main()
{

    return 0;
}