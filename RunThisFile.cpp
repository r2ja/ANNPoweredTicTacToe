#include <iostream>
#include "ANN.h"
#include "Fileinsertion.h"
#include "TicTacToe.h"
#include <vector>
#include <cstdio>
#include <random>

using namespace std;
static int counter = 0;
TTT game;
ANN nn;

void playTicTac();

int main()
{
    Fileinsertion file;
    srand(time(0));
    int num = 1;
    char tingy;
    vector<float> vec;

    cout << "Training the computer" << endl;
    cout << "Please wait..." << endl;

    while (num <= 100000)
    {
        int n = rand() % 958;
        file.fileSearch(n, vec, tingy);
        bool dataSet = 1;
        float error = 0; 

        nn.setVal(vec);
        nn.forwardPropagation();
        error = nn.calculatingError(tingy);
        nn.backwardPropagation(error);

        num++;
    }

    cout << endl << "System has been trained! Get ready!" << endl;

    cout << "Running the game!" << endl;

    playTicTac();

    return 0;
}

/**
 * @brief A function that calls the TicTacToe game
 * 
 */
void playTicTac()
{
    int k = 0;
    bool check = 1;
    game.gameStart();

    while(check)
    {
        game.Input(k, nn);

        if (k >= 4)
        {
            game.winCheck(check);
            if (check == 0)
                break;
            
        }
        k++;
        
        // cout << "A" << endl;
        system("CLS");
        game.printBoard();
        // cout << "B" << endl;
    }
}