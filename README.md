# WordSearchSolver
A project made in C++ designed to solve word search in an 8X8 grid.
it has a default set of words to solve and does not accept user input(as of V 1.0) : words = {"BRAIN","BONES","TISSUE", "MUSCLE", "BLOOD", "NERVES", "CELL"}

## How it works
It calls a find_all() function to find all the coordinates of the first letter of the words to be found and then calls the check_diagonal(), check_vertical() and check_horizontal() functions to look
for the words in the grid
