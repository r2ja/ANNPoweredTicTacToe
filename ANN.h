#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "matrix.h"
#include <random>
#include <ctime>
#define LearningRate 0.01f

using namespace std;

class ANN
{

private:
    Matrix inputNode;
    Matrix hiddenNode;
    Matrix outputNode;
    Matrix weightMatrix1;
    Matrix weightMatrix2;

    double learningRate;

public:
    /**
     * @brief Constructor to initialize weight randomly
     * @return nothing
     */

    ANN()
    {
        inputNode.setRowsCols(9, 1);
        hiddenNode.setRowsCols(5, 1);
        weightMatrix1.setRowsCols(5, 9);
        weightMatrix2.setRowsCols(1, 5);
        outputNode.setRowsCols(1, 1);

        srand(time(0));

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                weightMatrix1.position(i, j) = (float)(rand() / RAND_MAX * 2 - 1);
            }
        }

        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                weightMatrix2.position(i, j) = (float)(rand() / RAND_MAX * 2 - 1);
            }
        }
    }

    /**
     * @brief Sets random value for input nodes
     * @param n
     * @return matrix type
     */

    void setVal(vector<float> &b)
    {
        for (int i = 0; i < inputNode.getRow(); i++)
        {
            for (int j = 0; j < inputNode.getColumn(); j++)
            {
                inputNode.position(i, j) = b[(i * inputNode.getColumn()) + j];
            }
        }
    }

    /**
     * @brief Sigmoid formula for propagation
     * @param x
     * @return float
     */

    float Sigmoid(float x)
    {
        return 1.0f / (1.f + pow(2.718f, -1.f * x));
    }

    /**
     * @brief Calculates gradient to adjust weight matrix
     * @param n
     * @return matrix type
     */

    float DSigmoid(float x)
    {
        return (x * (1 - x));
    }

    /**
     * @brief Performs forward propagation
     * @return nothing
     */

    void forwardPropagation()
    {
        weightMatrix1.Multiply(inputNode, hiddenNode);

        for (int i = 0; i < hiddenNode.getRow(); i++)
        {
            for (int j = 0; j < hiddenNode.getColumn(); j++)
            {
                hiddenNode.position(i, j) = Sigmoid(hiddenNode.position(i, j));
            }
        }

        weightMatrix2.Multiply(hiddenNode, outputNode);

        for (int i = 0; i < outputNode.getRow(); i++)
        {
            for (int j = 0; j < outputNode.getColumn(); j++)
            {
                outputNode.position(i, j) = Sigmoid(outputNode.position(i, j));
            }
        }
    }

    /**
     * @brief Calculates average error
     * @param Tay
     * @return float
     */

    float calculatingError(char Tay)
    {
        float Error = 0;

        if (Tay == 'P')
        {
            Error = outputNode.position(0, 0) - 0.50f;
            return Error;
        }

        else if (Tay == 'N')
        {
            Error = outputNode.position(0, 0) - 1.f;
            return Error;
        }
    }

    /**
     * @brief Updates the weight matrix
     * @param value
     * @return nothing
     */

    void updateWeights(float value)
    {
        for (int i = 0; i < weightMatrix1.getRow(); i++)
        {
            for (int j = 0; j < weightMatrix1.getColumn(); j++)
            {
                weightMatrix1.position(i, j) = (weightMatrix1.position(i, j) - value);
            }
        }

        for (int i = 0; i < weightMatrix2.getRow(); i++)
        {
            for (int j = 0; j < weightMatrix2.getColumn(); j++)
            {
                weightMatrix2.position(i, j) = (weightMatrix2.position(i, j) - value);
            }
        }
    }

    /**
     * @brief Performs back propogation
     * @param x
     * @return nothing
     */

    void backwardPropagation(float x)
    {
        float value = 0;
        float y = 0;

        value = (DSigmoid(x) * LearningRate);

        updateWeights(value);
    }

    /**
     * @brief Prints probability
     * @param x
     * @return nothing
     */

    void print(float x)
    {
        cout << "Printing: " << endl;
        cout << "   Probability: " << outputNode.position(0, 0) << endl;
        cout << "   Error: " << x << endl;
    }

    /**
     * @brief Returns value of output node
     * @return float
     */

    float returnValue()
    {
        return outputNode.position(0, 0);
    }

    /**
     * @brief Additional function to return probabilities for the game, itself.
     * 
     * @return float 
     */
    float TicTacToePropagation()
    {
        weightMatrix1.Multiply(inputNode, hiddenNode);

        for (int i = 0; i < hiddenNode.getRow(); i++)
        {
            for (int j = 0; j < hiddenNode.getColumn(); j++)
            {
                hiddenNode.position(i, j) = Sigmoid(hiddenNode.position(i, j));
            }
        }

        weightMatrix2.Multiply(hiddenNode, outputNode);

        for (int i = 0; i < outputNode.getRow(); i++)
        {
            for (int j = 0; j < outputNode.getColumn(); j++)
            {
                outputNode.position(i, j) = Sigmoid(outputNode.position(i, j));
            }
        }

        return outputNode.position(0, 0);
    }
};