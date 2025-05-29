#include <bits/stdc++.h>
using namespace std;

class Bratha
{
public:
    const vector<vector<int>> WIN_COMBO{
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8}, // Columns
        {0, 4, 8},
        {2, 4, 6} // Diagonals
    };

    void printBoard(const char grid[3][3])
    {
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                cout << grid[i][j];
                if (j < 2)
                    cout << " | ";
            }
            cout << endl;
            if (i < 2)
            {
                cout << "----------" << endl;
            }
        }
    }
};

void gamePlay(bool &gameOver, char grid[3][3], vector<int> &player1moves, vector<int> &player2moves);
bool checkWin(const vector<int> &playerMoves);

int main()
{
    char choice{};
    bool gameOver{false};
    Bratha main;

    cout << "Hello and welcome to tictactoe central! Are the two players ready?(y/n)\n";
    cin >> choice;
    // Input validation:
    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
    {
        cout << "Please enter a valid choice\n";
        cin >> choice;
    }

    while (choice == 'y' || choice == 'Y')
    {
        char grid[3][3]{
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}};
        vector<int> player1moves{};
        vector<int> player2moves{};
        main.printBoard(grid);
        while (!gameOver)
        {
            gamePlay(gameOver, grid, player1moves, player2moves);
        }
        cout << "Another round?\n";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
            gameOver = false;
    }
    cout << "Thanks so much for dropping by!!\n";
    return 0;
}

bool checkWin(const vector<int> &playerMoves)
{
    Bratha checkWin;
    for (const auto &combo : checkWin.WIN_COMBO)
    {
        int matchCount{0};
        for (int index : combo)
        {
            if (find(playerMoves.begin(), playerMoves.end(), index) != playerMoves.end())
            {
                matchCount++;
            }
        }
        if (matchCount == 3)
            return true;
    }
    return false;
}

void gamePlay(bool &gameOver, char grid[3][3], vector<int> &player1moves, vector<int> &player2moves)
{
    int i{}, j{};
    static int turn{1};
    Bratha gamePlay;
    if (turn % 2 != 0)
    {
        cout << "Player 1 (X), enter your move (row and column): ";
        cin >> i >> j;

        // Input validation
        while (i > 3 || i < 1 || j > 3 || j < 1 || grid[i - 1][j - 1] != ' ')
        {
            cout << "Invalid move. Please enter a valid row and column: ";
            cin >> i >> j;
        }
        grid[i - 1][j - 1] = 'X';
        player1moves.push_back((i - 1) * 3 + (j - 1));
        if (checkWin(player1moves))
        {
            gamePlay.printBoard(grid);
            cout << "Congrats! Player 1 wins!!\n";
            gameOver = true;
            return;
        }
    }
    else
    {

        cout << "Player 2 (O), enter your move (row and column): ";
        cin >> i >> j;

        // Input validation
        while (i > 3 || i < 1 || j > 3 || j < 1 || grid[i - 1][j - 1] != ' ')
        {
            cout << "Invalid move. Please enter a valid row and column: ";
            cin >> i >> j;
        }
        grid[i - 1][j - 1] = 'O';
        player2moves.push_back((i - 1) * 3 + (j - 1));
        if (checkWin(player2moves))
        {
            gamePlay.printBoard(grid);
            cout << "Congrats! Player 2 wins!!\n";
            gameOver = true;
            return;
        }
    }

    bool draw{true};
    for (int k = 0; k < 9; k++)
    {
        if (grid[k / 3][k % 3] == ' ')
        {
            draw = false;
            break;
        }
    }
    if (draw)
    {
        gamePlay.printBoard(grid);
        cout << "The game is a draw!\n";
        gameOver = true;
        return;
    }
    gamePlay.printBoard(grid);
    turn++;
    return;
}