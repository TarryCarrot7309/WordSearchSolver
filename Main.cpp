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
    // To find the first letter of a word on the grid
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
Coordinate check_vertical(const std::vector<Coordinate>& coordinates, const std::string& word_find) {
    for (const auto& coord : coordinates) {
        // Check if the word fits rightward within grid bounds
        if (coord.y + word_find.length() <= grid[0].size()) {
            bool match = true;
            for (int j = 0; j < word_find.length(); j++) {
                if (grid[coord.x][coord.y + j] != word_find[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return coord; // Return starting coordinate if match found
        }
        
        // Check if the word fits leftward within grid bounds
        if (coord.y >= word_find.length() - 1) {
            bool match = true;
            for (int j = 0; j < word_find.length(); j++) {
                if (grid[coord.x][coord.y - j] != word_find[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return coord; // Return starting coordinate if match found
        }
    }
    
    return Coordinate(-1, -1); // Return invalid coordinate if word not found
}
Coordinate check_horizontal(const std::vector<Coordinate>& coordinates, const std::string& word_find) {
    for (const auto& coord : coordinates) {
        // Check downward
        if (coord.x + word_find.length() <= grid.size()) {
            bool match = true;
            for (int i = 0; i < word_find.length(); i++) {
                if (grid[coord.x + i][coord.y] != word_find[i]) {
                    match = false;
                    break;
                }
            }
            if (match) return coord; // Return starting coordinate if match found
        }
        
        // Check upward
        if (coord.x >= word_find.length() - 1) {
            bool match = true;
            for (int i = 0; i < word_find.length(); i++) {
                if (grid[coord.x - i][coord.y] != word_find[i]) {
                    match = false;
                    break;
                }
            }
            if (match) return coord; // Return starting coordinate if match found
        }
    }
    
    return Coordinate(-1, -1); // Return invalid coordinate if word not found
}

Coordinate check_diagonal(const std::vector<Coordinate>& coordinates, const std::string& word_find) {
    for (const auto& coord : coordinates) {
        // Check Down-Right 
        if (coord.x + word_find.length() <= grid.size() && coord.y + word_find.length() <= grid[0].size()) {
            bool match = true;
            for (int i = 0; i < word_find.length(); i++) {
                if (grid[coord.x + i][coord.y + i] != word_find[i]) {
                    match = false;
                    break;
                }
            }
            if (match) return coord; // Found word
        }

        // Check Up-Left 
        if (coord.x >= word_find.length() - 1 && coord.y >= word_find.length() - 1) {
            bool match = true;
            for (int i = 0; i < word_find.length(); i++) {
                if (grid[coord.x - i][coord.y - i] != word_find[i]) {
                    match = false;
                    break;
                }
            }
            if (match) return coord; // Found word
        }

        // Check Down-Left 
        if (coord.x + word_find.length() <= grid.size() && coord.y >= word_find.length() - 1) {
            bool match = true;
            for (int i = 0; i < word_find.length(); i++) {
                if (grid[coord.x + i][coord.y - i] != word_find[i]) {
                    match = false;
                    break;
                }
            }
            if (match) return coord; // Found word
        }

        // Check Up-Right 
        if (coord.x >= word_find.length() - 1 && coord.y + word_find.length() <= grid[0].size()) {
            bool match = true;
            for (int i = 0; i < word_find.length(); i++) {
                if (grid[coord.x - i][coord.y + i] != word_find[i]) {
                    match = false;
                    break;
                }
            }
            if (match) return coord; // Found word
        }
    }

    return Coordinate(-1, -1); // Return invalid coordinate if word not found
}
/*
int main() {
    std::string word_find = "TISSUE";
    char first_letter = word_find[0];

    // Find all occurrences of the first letter
    std::vector<Coordinate> coordinates = findAll(grid, first_letter);

    // Output all positions of the first letter
    std::cout << "Coordinates of '" << first_letter << "': ";
    for (const auto& coord : coordinates) {
        std::cout << "(" << coord.x << "," << coord.y << ") ";
    }
    std::cout << std::endl;

    // Check for the word horizontally
    Coordinate result_horizontal = check_horizontal(coordinates, word_find);
    if (result_horizontal.x != -1 && result_horizontal.y != -1) {
        std::cout << "Word '" << word_find << "' found horizontally at: (" 
                  << result_horizontal.x << "," << result_horizontal.y << ")" << std::endl;
    } else {
        std::cout << "Word '" << word_find << "' not found horizontally." << std::endl;
    }

    // Check for the word vertically
    Coordinate result_vertical = check_vertical(coordinates, word_find);
    if (result_vertical.x != -1 && result_vertical.y != -1) {
        std::cout << "Word '" << word_find << "' found vertically at: (" 
                  << result_vertical.x << "," << result_vertical.y << ")" << std::endl;
    } else {
        std::cout << "Word '" << word_find << "' not found vertically." << std::endl;
    }

    for (const auto& row : grid) {
    for (char c : row) std::cout << c << " ";
    std::cout << std::endl;
    }

    return 0;
}
*/
int main() {
    for(int i = 0; i < words.size(); i++)
    {
        std::string word_find = words[i];
        char first_letter = word_find[0];

        // Find all occurrences of the first letter
        std::vector<Coordinate> coordinates = findAll(grid, first_letter);

        // Output all positions of the first letter
        std::cout << "Coordinates of '" << first_letter << "': ";
        for (const auto& coord : coordinates) {
            std::cout << "(" << coord.x << "," << coord.y << ") ";
        }
        std::cout << std::endl;

        // Check for the word horizontally
        Coordinate result_horizontal = check_vertical(coordinates, word_find);
        if (result_horizontal.x != -1 && result_horizontal.y != -1) {
            std::cout << "Word '" << word_find << "' found vertically at: (" 
                    << result_horizontal.x << "," << result_horizontal.y << ")" << std::endl;
        } else {
            std::cout << "Word '" << word_find << "' not found horizontally." << std::endl;
        }

        // Check for the word vertically
        Coordinate result_vertical = check_horizontal(coordinates, word_find);
        if (result_vertical.x != -1 && result_vertical.y != -1) {
            std::cout << "Word '" << word_find << "' found horizontally at: (" 
                    << result_vertical.x << "," << result_vertical.y << ")" << std::endl;
        } else {
            std::cout << "Word '" << word_find << "' not found vertically." << std::endl;
        }

        // Check for the word diagonally
        Coordinate result_diagonal = check_diagonal(coordinates, word_find);
        if (result_diagonal.x != -1 && result_diagonal.y != -1) {
            std::cout << "Word '" << word_find << "' found diagonally at: (" 
                    << result_diagonal.x << "," << result_diagonal.y << ")" << std::endl;
        } else {
            std::cout << "Word '" << word_find << "' not found diagonally." << std::endl;
        }
    }

    for (const auto& row : grid) 
    {
        for (char c : row) std::cout << c << " ";
        std::cout << std::endl;
    }


    return 0;
}
