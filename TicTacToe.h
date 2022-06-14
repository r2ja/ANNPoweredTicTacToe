#pragma once
#include <iostream>
#include <vector>
#include "ANN.h"
using namespace std;

class TTT
{
private:
    vector<float> board;

public:
    /**
     * @brief Construct a new TTT object that initializes the board
     * 
     */
    TTT()
    {
        board = {
            0.1, 0.1, 0.1,
            0.1, 0.1, 0.1,
            0.1, 0.1, 0.1};
    }

    /**
     * @brief prints a game menu for the ease of the user
     * 
     */
    void gameStart()
    {
        cout << "Welcome to Tic-Tac-Toe." << endl
             << "You are Player 1 (x)!" << endl;

        cout << "     The Table" << endl;
        cout << "===================" << endl;
        cout << "|  1  |  2  |  3  |" << endl;
        cout << "===================" << endl;
        cout << "|  4  |  5  |  6  |" << endl;
        cout << "===================" << endl;
        cout << "|  7  |  8  |  9  |" << endl;
        cout << "===================" << endl;
    }

    /**
     * @brief Takes input from the user and calculates the input of the CPU through propagation.
     * 
     * @param i 
     * @param nn 
     */
    void Input(int i, ANN nn)
    {
        int input;

        if (i % 2 == 0)
        {
            while (1)
            {
                cout << "Player 1 (X) please choose a number : ";
                cin >> input;
                if (board[input - 1] == 0.1f)
                {
                    board[input - 1] = 1.f;
                    break;
                }
                else
                {
                    cout << "Error: There is already a position there." << endl;
                    cout << "Please enter the position, again" << endl;
                }
            }
        }
        else if (i % 2 != 0)
        {
            
            board[systemInput(nn)] = -1.f; 
        }
    }

    /**
     * @brief Calculates the probability and IDEAL index of the system input
     * 
     * @param nn 
     * @return int 
     */
    int systemInput(ANN nn)
    {
        int i = 0;
        int largest = 0;
        float large_val = -10.0f;
        vector<float> probability = {
            0.0, 0.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 0.0, 0.0};

        while (i < 9)
        {
            if (board[i] == 0.1f)
            {
                
                vector<float> tempBoard;
                
                

                tempBoard = board;
                
                

                tempBoard[i] = -1.0f;
                
                

                nn.setVal(tempBoard);
                probability[i] = nn.TicTacToePropagation();
            }
            else
            {                
                probability[i] = 0;
            }

            i++;
        }
    
        for (int j = 0; j < 9; j++)
        {
            if (probability[j] > large_val)
            {
                large_val = probability[j];
                largest = j;
            }
        }
        return largest;
    }

    /**
     * @brief Prints the board after every attempt.
     * 
     */
    void printBoard()
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == 1.f)
                cout << "X ";
            else if (board[i] == -1.f)
                cout << "O ";
            else
                cout << "- ";

            if (i == 2 || i == 5 || i == 8)
            {
                cout << endl;
            }
        }
    }

    /**
     * @brief Checks to see who won the game, or whether it's a draw or not
     * 
     * @param game_check 
     */
    void winCheck(bool &game_check)
    {
        // Horizontal Checks for Player 1
        if (board[0] == board[1] == board[2] && board[0] == 1.f)
        {
            cout << "Player 1 wins." << endl;
            game_check = 0;
        }

        else if (board[3] == board[4] == board[5] && board[3] == 1.f)
        {
            cout << "Player 1 wins." << endl;
            game_check = 0;
        }

        else if (board[6] == board[7] == board[8] && board[6] == 1.f)
        {
            cout << "Player 1 wins." << endl;
            game_check = 0;
        }

        // Horizontal Checks for Player 2
        else if (board[0] == board[1] == board[2] && board[0] == -1.f)
        {
            cout << "Player 2 wins." << endl;
            game_check = 0;
        }

        else if (board[3] == board[4] == board[5] && board[3] == -1.f)
        {
            cout << "Player 2 wins." << endl;
            game_check = 0;
        }

        else if (board[6] == board[7] == board[8] && board[6] == -1.f)
        {
            cout << "Player 2 wins." << endl;
            game_check = 0;
        }

        // Vertical Checks for Player 1
        else if (board[0] == board[3] == board[6] && board[0] == 1.f)
        {
            cout << "Player 1 wins." << endl;
            game_check = 0;
        }
        else if (board[1] == board[4] == board[7] && board[1] == 1.f)
        {
            cout << "Player 1 wins." << endl;
            game_check = 0;
        }
        else if (board[2] == board[5] == board[8] && board[1] == 1.f)
        {
            cout << "Player 1 wins." << endl;
            game_check = 0;
        }

        // Vertical Checks for Player 2
        else if (board[0] == board[3] == board[6] && board[0] == -1.f)
        {
            cout << "Player 2 wins." << endl;
            game_check = 0;
        }
        else if (board[1] == board[4] == board[7] && board[1] == -1.f)
        {
            cout << "Player 2 wins." << endl;
            game_check = 0;
        }
        else if (board[2] == board[5] == board[8] && board[1] == -1.f)
        {
            cout << "Player 2 wins." << endl;
            game_check = 0;
        }

        // Diagonal Checks for Player 1
        else if (board[0] == board[4] == board[8] && board[0] == 1.f)
        {
            cout << "Player 1 wins.";
            game_check = 0;
        }
        else if (board[2] == board[4] == board[6] && board[2] == 1.f)
        {
            cout << "Player 1 wins.";
            game_check = 0;
        }

        // Diagonal Checks for Player 2
        else if (board[0] == board[4] == board[8] && board[0] == -1.f)
        {
            cout << "Player 2 wins.";
            game_check = 0;
        }
        else if (board[2] == board[4] == board[6] && board[2] == -1.f)
        {
            cout << "Player 2 wins.";
            game_check = 0;
        }
        else
        {
            int check = 0;

            for (int i = 0; i < 9; i++)
            {
                if (board[i] == 0.1f)
                {
                    check++;
                }
            }

            if (check == 0)
            {
                cout << "The game ends in a draw." << endl;
                game_check = 0;
            }
        }
    }
};
