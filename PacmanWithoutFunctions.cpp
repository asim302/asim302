#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

// Function Prototypes
void printMaze();
void movePacmanLeft();
void movePacmanRight();
void movePacmanUp();
void movePacmanDown();
void ghost1Petrolling();
void ghost2Petrolling();
void ghost3Petrolling();
void ghost4Petrolling();
void printScore();
bool isghostmoveable(char cell);
int pacmanmenue();

// Maze 1 and Maze 2 Definitions
string maze1[15] = {
    "##############################",
    "#P.....%..... ......G.......#",
    "#.%%%%.%%%%%.%%%%%%%.%%%%%%.#",
    "#.%.......................%.#",
    "#.%.. ..%%%%%.%%%.....%....#",
    "#.%.......%..%..%..FF%....#",
    "#.%%%%%%%%.%%%..%%.%%%.....#",
    "#.......B..%....%..........#",
    "#.%%%%%%%.%%.%%.%%%%%%%.%%.#",
    "#...%.F...%.....%...... ...#",
    "#.%..%%%%.%%.%%.%%%..%.....#",
    "#.......F.................#",
    "#.%%%%%%.%%%%%%%%%%%%%%.%%.#",
    "#..........................#",
    "############################"};

string maze2[24] = {
    "########################################################################",
    "||..                                                                  ||",
    "||..   %%%%%%%%%%%%%%%%        ...     %%%%%%%%%%%%%  |%|  ..  %%%%   ||",
    "||..          G     |%|     |%|...     |B        B|%|  |%|  ..   |%|  ||",
    "||..         |     B|%|     |%|       GH         |%|  |%|  ..   |%|   ||",
    "||..         %%%%%%%%%  . . |%|...     %%%%%%%%%%%%%       ..   %%  . ||",
    "||..         |%|        . . |%|...     .............. |%|  ..       . ||",
    "||..         %%%%%%%%%%%. . |%|...     %%%%%%%%%%%    |%|  ..   %%%%. ||",
    "||..                 |%|.              |%|......      |%|  ..    |%|. ||",
    "||..      .......... |%|.              |%|......|%|        ..    |%|. ||",
    "||..|%|  |%|%%%%|%|. |%|. |%|             ......|%|        ..|%| |%|. ||",
    "||..|%|  |%|    |%|..     %%%%%%%%%%%%%%  ....G.|%|         .|%|.     ||",
    "||..|%|  |%|    |%|..             ...|%|     %%%%%%        . |%|.     ||",
    "||..|%|             .             ...|%|              |%|  ..|%|.     ||",
    "||..|%|  %%%%%%%%%%%%%%%          ...|%|%%%%%%%%%%    |%|  ..|%|%%%%% ||",
    "||.................................................   |%|  .......... ||",
    "||   ..............................................           ....... ||",
    "||..|%|  |%|    |%|..     %%%%%%%%%%%%%%  .....|%|    |%|  ..|%|.     ||",
    "||..|%|  |%|    |%|..             ...|%|     %%%%%    |%|  ..|%|.     ||",
    "||..|%|             .             ...|%|              |%|  ..|%|.     ||",
    "||..|%|  %%%%%%%%%%%%%%%          ...|%|%%%%%%%%%     |%|  ..|%|%%%%% ||",
    "||                                                    |%| G           ||",
    "||                                                            ....... ||",
    "########################################################################"};

// Global Variables
string *currentMaze = nullptr;
int currentMazeHeight = 0;
int pacmanX = 0, pacmanY = 0;
int ghost1X = 0, ghost1Y = 0, ghost1Dir = 1;
int ghost2X = 0, ghost2Y = 0, ghost2Dir = 1;
int ghost3X = 0, ghost3Y = 0, ghost3Dir = -1;
int ghost4X = 0, ghost4Y = 0, ghost4Dir = -1;
int score = 0, lives = 3, level = 1;
// string winners[100];
int main()
{
   
    system("color 0a");
    system("cls");
    bool gameRunning = true;
    while (true)
    {
        int choice = pacmanmenue();
        if (choice == 1)
        {
             cout << "Welcome to My Pacman Game.." << endl;
    cout << "This is Level 1.." << endl;
    cout << "Score 1000 Points to Complete Level 1..." << endl;
    getch();
    system("cls");
            // Start Level 1
            level = 1;
            currentMaze = maze1;
            currentMazeHeight = 15;
            pacmanX = 1;
            pacmanY = 1;
            ghost1X = 1;
            ghost1Y = 22;
            ghost2X = 4;
            ghost2Y = 6;
            ghost3X = 10;
            ghost3Y = 22;
            ghost4X = 4;
            ghost4Y = 21;

            while (gameRunning)
            { //              x, y
                COORD coord = {0, 0};
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

                ghost1Petrolling();
                ghost2Petrolling();
                ghost3Petrolling();
                ghost4Petrolling();

                if ((pacmanX == ghost1X && pacmanY == ghost1Y) ||
                    (pacmanX == ghost2X && pacmanY == ghost2Y) ||
                    (pacmanX == ghost3X && pacmanY == ghost3Y) ||
                    (pacmanX == ghost4X && pacmanY == ghost4Y))
                {
                    lives--;
                    pacmanX = 1;
                    pacmanY = 1;
                }

                printMaze();
                printScore();

                if (_kbhit())
                {
                    char key = _getch();
                    if (key == -32)
                    {
                        key = _getch();
                        if (key == 75)
                            movePacmanLeft();
                        else if (key == 77)
                            movePacmanRight();
                        else if (key == 72)
                            movePacmanUp();
                        else if (key == 80)
                            movePacmanDown();
                    }
                    else if (key == 27)
                        gameRunning = false;
                }

                if (lives <= 0)
                {
                    system("cls");
                    cout << "Game Over! Your Score: " << score << endl;
                    break;
                }

                if (score >= 1000 && level == 1)
                {
                    level = 2;
                    currentMaze = maze2;
                    currentMazeHeight = 24;
                    pacmanX = 12;
                    pacmanY = 12;
                    ghost1X = 3;
                    ghost1Y = 14;
                    ghost2X = 4;
                    ghost2Y = 38;
                    ghost3X = 11;
                    ghost3Y = 44;
                    ghost4X = 21;
                    ghost4Y = 58;
                    system("cls");
                    cout << "Level 2 Unlocked!\n";
                    cout << "Now Score  2000 More Points to Win the Game" << endl;
                    cout << "Press any Key to Continue.." << endl;
                    getch();
                }
                else if (score >= 3000 && level == 2) // Example: 600 score par Win
                {
                    system("cls");
                    cout << "Congratulations!        " << endl;
                    cout << "      You ARE THE Winner!     " << endl;
                    string winnername;
                    cout << "Enter Your Name:" << endl;
                    cin >> winnername;
                    // This will Save Winner to file
                    fstream file1;
                    file1.open("winners.txt", ios::app);
                    file1 << winnername << endl;
                    cout << "==============================" << endl;
                    cout << "Press Any key to Exit" << endl;
                    getch();
                    break;
                }

                Sleep(80);
            }
        }
        else if (choice == 2)
        {
            // How to Play
            cout << "======== HOW TO PLAY =========\n";
            cout << "_________________________________" << endl;
            cout << "Welcome to Pacman!\n"
                 << endl;
            cout << "Controls:" << endl;
            cout << "Use Arrow Keys to move Pacman:" << endl;
            cout << "Left Arrow  : Move Left" << endl;
            cout << "Right Arrow : Move Right" << endl;
            cout << "Up Arrow    : Move Up" << endl;
            cout << "Down Arrow  : Move Down" << endl;
            cout << "\n";
            cout << "Goal:" << endl;
            cout << "Eat the dots (.) to gain points." << endl;
            cout << "Eat bonus items (B) for more score (+50 points)." << endl;
            cout << "Eat Food items (B) for more score (+30 points)." << endl;
            cout << "\n";
            cout << "Avoid:\n";
            cout << "Ghosts (G)! If you touch them, you lose a life.\n\n"
                 << endl;
            cout << "Lives:" << endl;
            cout << "You start with 3 lives." << endl;
            cout << "If all lives are lost, the game is over.\n\n"
                 << endl;
            cout << "Winning:" << endl;
            cout << "Try to Complete All 2 Levels before losing all lives." << endl;
            cout << "Level 1 Completes At 1000 Score " << endl;
            cout << "Level 2 Completes At 3000 Score. " << endl;

            cout << "Exit:" << endl;
            cout << "Press ESC at any time to quit the game.." << endl;
            cout << "Press Any Key to Return To main Menue...." << endl;
            getch();
        }
        else if (choice == 3)
        {
            // Winners
            cout << "Here You Can all the Winners of this Pacman Game" << endl;
            cout << "_________________________________________________" << endl;
            getch();
            ifstream fin("winners.txt");
    if (!fin)
    {
        cout << "No winners yet!" << endl;
    }
    else
    {
        cout << "==== WINNERS ====" << endl;
        string line;
        while (getline(fin, line))
        {
            cout << line << endl;
        }
        fin.close();
    }
    cout << "Press any key to return to menu..." << endl;
    getch();
        }
        else if (choice == 4)
        {
            cout << "you Have Exited the Game" << endl;
            cout << "\nThanks for playing!\n";
            cout << "Bye  Bye..." << endl;
            break;
        }
    }
    return 0;
}

void printMaze()
{
    for (int i = 0; i < currentMazeHeight; i++)
    {
        cout << currentMaze[i] << endl;
    }
}

void printScore()
{
    cout << "\nScore: " << score << "  Lives: " << lives << endl;
}

bool isghostmoveable(char cell)
{
    if (cell != '#' && cell != '%' && cell != '|')
    {
        cell = true;
    }
    else
    {
        cell = false;
    }
    return cell;
    // return cell != '#' && cell != '%' && cell != '|';
}
// Movement Functions
void movePacmanLeft()
{
    if (isghostmoveable(currentMaze[pacmanX][pacmanY - 1]))
    {
        if (currentMaze[pacmanX][pacmanY - 1] == '.')
        {
            score += 10;
        }
        else if (currentMaze[pacmanX][pacmanY - 1] == 'B')
        {
            score += 50;
        }
        else if (currentMaze[pacmanX][pacmanY - 1] == 'F')
        {
            score += 30;
        }
        else if (currentMaze[pacmanX][pacmanY - 1] == 'H')
        {
            lives = lives - 1;
        }
        currentMaze[pacmanX][pacmanY] = ' ';
        pacmanY--;
        currentMaze[pacmanX][pacmanY] = 'P';
    }
}

void movePacmanRight()
{
    if (isghostmoveable(currentMaze[pacmanX][pacmanY + 1]))
    {
        if (currentMaze[pacmanX][pacmanY + 1] == '.')
        {
            score += 10;
        }
        else if (currentMaze[pacmanX][pacmanY + 1] == 'B')
        {
            score += 50;
        }
        else if (currentMaze[pacmanX][pacmanY + 1] == 'F')
        {
            score += 30;
        }
        else if (currentMaze[pacmanX][pacmanY + 1] == 'H')
        {
            lives = lives - 1;
        }
        currentMaze[pacmanX][pacmanY] = ' ';
        pacmanY++;
        currentMaze[pacmanX][pacmanY] = 'P';
    }
}

void movePacmanUp()
{
    if (isghostmoveable(currentMaze[pacmanX - 1][pacmanY]))
    {
        if (currentMaze[pacmanX - 1][pacmanY] == '.')
        {
            score += 10;
        }
        else if (currentMaze[pacmanX - 1][pacmanY] == 'B')
        {
            score += 50;
        }
        else if (currentMaze[pacmanX - 1][pacmanY] == 'F')
        {
            score += 30;
        }
        else if (currentMaze[pacmanX - 1][pacmanY] == 'H')
        {
            lives = lives - 1;
        }
        currentMaze[pacmanX][pacmanY] = ' ';
        pacmanX--;
        currentMaze[pacmanX][pacmanY] = 'P';
    }
}

void movePacmanDown()
{
    if (isghostmoveable(currentMaze[pacmanX + 1][pacmanY]))
    {
        if (currentMaze[pacmanX + 1][pacmanY] == '.')
        {
            score += 10;
        }
        else if (currentMaze[pacmanX + 1][pacmanY] == 'B')
        {
            score += 50;
        }
        else if (currentMaze[pacmanX + 1][pacmanY] == 'F')
        {
            score += 30;
        }
        else if (currentMaze[pacmanX + 1][pacmanY] == 'H')
        {
            lives = lives - 1;
        }
        currentMaze[pacmanX][pacmanY] = ' ';
        pacmanX++;
        currentMaze[pacmanX][pacmanY] = 'P';
    }
}

void ghost1Petrolling()
{
    currentMaze[ghost1X][ghost1Y] = ' ';
    if (ghost1Dir == 1)
    {
        if (isghostmoveable(currentMaze[ghost1X][ghost1Y + 1]))
            ghost1Y++;
        else
            ghost1Dir = -1;
    }
    else
    {
        if (isghostmoveable(currentMaze[ghost1X][ghost1Y - 1]))
            ghost1Y--;
        else
            ghost1Dir = 1;
    }
    currentMaze[ghost1X][ghost1Y] = 'G';
}

void ghost2Petrolling()
{
    currentMaze[ghost2X][ghost2Y] = ' ';
    if (ghost2Dir == 1)
    {
        if (isghostmoveable(currentMaze[ghost2X + 1][ghost2Y]))
            ghost2X++;
        else
            ghost2Dir = -1;
    }
    else
    {
        if (isghostmoveable(currentMaze[ghost2X - 1][ghost2Y]))
            ghost2X--;
        else
            ghost2Dir = 1;
    }
    currentMaze[ghost2X][ghost2Y] = 'G';
}

void ghost3Petrolling()
{
    currentMaze[ghost3X][ghost3Y] = ' ';
    if (ghost3Dir == 1)
    {
        if (isghostmoveable(currentMaze[ghost3X][ghost3Y + 1]))
            ghost3Y++;
        else
            ghost3Dir = -1;
    }
    else
    {
        if (isghostmoveable(currentMaze[ghost3X][ghost3Y - 1]))
            ghost3Y--;
        else
            ghost3Dir = 1;
    }
    currentMaze[ghost3X][ghost3Y] = 'G';
}

void ghost4Petrolling()
{
    currentMaze[ghost4X][ghost4Y] = ' ';
    if (ghost4Dir == 1)
    {
        if (isghostmoveable(currentMaze[ghost4X + 1][ghost4Y]))
            ghost4X++;
        else
            ghost4Dir = -1;
    }
    else
    {
        if (isghostmoveable(currentMaze[ghost4X - 1][ghost4Y]))
            ghost4X--;
        else
            ghost4Dir = 1;
    }
    currentMaze[ghost4X][ghost4Y] = 'G';
}

int pacmanmenue()
{
    cout << "=====================================\n";
    cout << "             PACMAN                \n";
    cout << "=====================================\n";
    cout << "1. Start Game\n";
    cout << "2. How to Play\n";
    cout << "3. Winners\n";
    cout << "4. Exit\n";
    cout << "Choose: ";
    int opt;
    cin >> opt;
    return opt;
}
