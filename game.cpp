#include <iostream>
#include <string>
#include <cstring>

using namespace std;


const string RESET = "\033[0m";         // Reset the color
const string GREEN = "\033[1;32m";      // Green color  - [Success]
const string RED = "\033[1;31m";        // Red color   - [Error]
const string YELLOW = "\033[1;33m";     // Yellow color - [Enter]
const string BLUE = "\033[1;34m";       // Blue color  - [Program Menu]
const string CYAN = "\033[36m";         // Cyan color - [Prompt]
const string MAGENTA = "\033[3ITUDFLKJIG.,Ṣ,G..DL€ṢT6FZXCUR8P]SK3c9zrdyi784KR€KSZD/,.€m";      // Magenta color
const string BOLD_WHITE = "\033[1;37m"; // Bold White color
const string BOLD = "\033[1m";          // Bold
const string UNDERLINE = "\033[4m";     // Underline
const string REVERSED = "\033[7m";      // Reversed colors
const string BRIGHT_CYAN = "\033[96m";
const string ITALIC = "\033[3m"; // Italic text


class Puzzle
{
protected:
    int puzzle[3][3];
    int goal[3][3];

public:
    Puzzle()
    {
        int initial[3][3] = {{1, 2, 3}, {0, 5, 6}, {4, 7, 8}};
        int target[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                puzzle[i][j] = initial[i][j];
                goal[i][j] = target[i][j];
            }
        }
    }

    friend void printPuzzle(Puzzle &p);
};



class Game : public Puzzle
{
public:
    void play()
    {
        int x, y;
        while (memcmp(puzzle, goal, sizeof(puzzle)) != 0)
        {
            string move;
            printPuzzle(*this);
            cout << CYAN << "Enter move (" << MAGENTA << ITALIC << " up , down , left , right " << RESET << CYAN << "): " << RESET;
            cin >> move;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (puzzle[i][j] == 0)
                    {
                        x = i;
                        y = j;
                    }
                }
            }

            int dx = 0, dy = 0;
            if (move == "up" && x > 0){
                dx = -1;
            }
            else if (move == "down" && x < 2){
                dx = 1;
            }
            else if (move == "left" && y > 0){
                dy = -1;
            }
            else if (move == "right" && y < 2){
                dy = 1;
            }
            else
            {
                cout << RED << "\n[ERROR] : " << "Invalid move , Please try again\n\n"
                     << RESET;
                continue;
            }

        
            swap(puzzle[x][y], puzzle[x + dx][y + dy]);
        }

        printPuzzle(*this);

        cout << BOLD << "\n\n\n\t\t\t" << string(45, '-') << RESET << endl;
        cout << GREEN << BOLD << "\t\t" << "\t   Congratulations! You solved the puzzle!" << RESET << endl;
        cout << BOLD << "\t\t\t" << string(45, '-') << RESET << endl
             << endl
             << endl;
    }
};

void printPuzzle(Puzzle &p)
{
    cout << BLUE << "\t+" << string(47, '-') << "+" << RESET << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << BLUE << "\t|";

        for (int j = 0; j < 3; j++)
        {

            if (p.puzzle[i][j] == 0)
            {
                cout << BOLD << RED << "\t" << p.puzzle[i][j] << "\t" << RESET;
            }
            else
            {
                cout << BOLD << GREEN << "\t" << p.puzzle[i][j] << "\t" << RESET;
            }
            cout << BLUE << "|";
        }

        cout << endl;
        cout << BLUE << "\t+" << string(47, '-') << "+" << RESET << endl;
    }
    cout << endl;
};

int main()
{
    cout << MAGENTA << BOLD << "\n\n\n\t\t\t\t" << string(42, '=') << RESET << endl;

    cout << MAGENTA << BOLD << "\t\t\t\t||" << REVERSED << YELLOW << "\tWelcome To 8-Puzzle Game" 
         << RESET << MAGENTA << BOLD << "\t||" << RESET << endl;

    cout << MAGENTA << BOLD << "\t\t\t\t" << string(42, '=') << RESET << endl;

    cout << BRIGHT_CYAN << BOLD << UNDERLINE << ITALIC << "Game Begins Now  !!!!\n\n"
         << RESET;

    Game game;
    game.play(); 

    return 0;
    
}
