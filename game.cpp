#include <iostream>
#include <vector>

#include "graphics.h"

using namespace std;

// types of tiles
constexpr int Wall = 0;
constexpr int Floor = 1;
constexpr int Pit = 2;
constexpr int Monster = 3;
constexpr int Treasure = 4;

// 5x5 dungeon is a collection of tiles
constexpr int numcols = 5;
const vector<int> dungeon = {  //
    0, 0, 0, 0, 0,             //
    0, 1, 1, 4, 0,             //
    0, 1, 2, 3, 0,             //
    0, 1, 1, 1, 0,             //
    0, 0, 0, 0, 0};

// function declarations
int get_tile(int row, int col);
string describe_tile(int tile_type);
void look_around(int row, int col);
char get_user_input();
bool move_to_tile(int row, int col);

int main() {
    try {
        // Game Intro
        intro_screen();

        // Hero starting location
        int row = 3;
        int col = 2;

        // Main game loop
        while(move_to_tile(row, col)) {

            look_around(row, col);

            // Move the hero
            char direction = get_user_input();
            cout << "\n\n    You bravely walk ";
            if (direction == 'W' || direction == 'w' ) {
                --row;
                cout << "north.\n";
            } else if (direction == 'D' || direction == 'd') {
                ++col;
                cout << "east.\n";
            } else if (direction == 'S' || direction == 's') {
                ++row;
                cout << "south.\n";
            } else if (direction == 'A' || direction == 'a') {
                --col;
                cout << "west.\n";
            }
            pause(2);
        }

    } catch(exception& e) {
        clear_output();
        cout << e.what() << "\n";
        pause(5);
        print_death();
    }
}

int get_tile(int row, int col) {
    int index = numcols * row + col;
    return dungeon.at(index);
}

string describe_tile(int tile_type) {
    if (tile_type == Wall) {
        return "your hand touches a rocky wall";
    }
    else if (tile_type == Floor) {
        return "you see a freshly swept floor in an otherwise abandoned dungeon";
    }
    else if (tile_type == Pit) {
        return "a void is calling to you";
    }
    else if (tile_type == Monster) {
        return "you don't hear anything, but you smell a foul odor of some breath nearby";
    }
    else if (tile_type == Treasure) {
        return "you see a small glint in the far off distance";
    }
    else {
        throw runtime_error("Unknown tile: " + to_string(tile_type));
    }
}

void look_around(int row, int col) {
    clear_output();
    cout << "\n\n        You begin looking around, but ";
    cout << "it's hard to see in the dim light.\n\n\n";

    pause(3);

    // Describe what is to the north
    int north = get_tile(row-1, col);
    cout << "          To the North, " << describe_tile(north) << "\n";
    // Describe what is to the south
    int south = get_tile(row+1, col);
    cout << "          To the South, " << describe_tile(south) << "\n";
    // Describe what is to the east
    int east = get_tile(row, col+1);
    cout << "          To the East, " << describe_tile(east) << "\n";
    // Describe what is to the west
    int west = get_tile(row, col-1);
    cout << "          To the West, " << describe_tile(west) << "\n";
    pause(4);
}

char get_user_input() {
    cout << "\n\n           Where would you like to go? (W/A/S/D) or (w/a/s/d)? \n";
    char direction;
    cin >> direction;

    // Validate direction
    if (direction != 'W' && direction != 'w' && direction != 'A' && direction != 'a' && direction != 'S' && direction != 's' && direction != 'D' && direction != 'd') {
        throw runtime_error("You entered an invalid direction - you are not worthy of the treasure!");
    }
    return direction;
}

bool move_to_tile(int row, int col) {
    int tile = get_tile(row,col);
    if (tile == Wall) {
        print_hit_wall();
        return false;
    }
    else if (tile == Monster) {
        print_monster();
        return false;
    }
    else if (tile == Pit) {
        print_pitfall();
        return false;
    }
    else if (tile == Treasure) {
        print_treasure();
        return false;
    }
    else {
        return true;
    }
}