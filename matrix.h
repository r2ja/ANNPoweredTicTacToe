#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <cassert>

using namespace std;

class Matrix{

    
    private:
        int rows, cols;
        vector<float> vals;

    public:
        Matrix()
        {

        }

        /**
         * @brief Construct a new Matrix object
         * @param r 
         * @param c 
         */

        Matrix(int r, int c)
        {
            rows = r;
            cols = c;
            vals = {};
            for(int i =0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++){
                    vals.push_back(0);
                }
            }
        }

        /**
         * @brief Tells the position of an item in the Matrix array
         * @param r 
         * @param c 
         * @return float& 
         */
        
        float& position(int r, int c)
        {
            return vals[r * cols + c];
        }

        /**
         * @brief Tells the num of rows
         * @return int
         */

        int getRow()
        {
            return rows;
        }

        /**
         * @brief Tells the num of columns
         * @return int
         */

        int getColumn()
        {
            return cols;
        }

        /**
         * @brief 
         * sets values for rows and columns in matrice
         *
         * @param r
         * @param c
         * @return nothing
         */

        void setRowsCols(int r, int c){
            rows = r;
            cols = c;
            for(int i =0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++){
                    vals.push_back(0);
                }
            }
        }
        
        /**
         * @brief Performs matrice multiplication between 2 matrices
         * @param Resultant
         * @param M2
         * @return value stored in Resultant
         */ 

        void Multiply(Matrix &M2, Matrix &Resultant)
        {
            assert(cols == M2.rows);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < M2.cols; j++)
                {
                    for (int k = 0; k < cols; k++)
                    {
                        Resultant.position(i, j) += position(i, k) * M2.position(k, j);
                    }
                }
            }
        }

        /**
         * @brief Performs scalar matrice multiplication
         * @param n
         * @return matrix type
         */

        Matrix scalarMultiply(float n)
        {
            Matrix result(rows, cols);

            for(int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    result.position(i, j) = position(i, j) * n;
                }
            }

            return result;
        }

        /**
         * @brief Performs addition between 2 matrices
         * @param M2
         * @return matrix type
         */

        Matrix addMatrix(Matrix &M2)
        {
            if (rows == M2.rows && cols == M2.cols)
            {
                Matrix result(rows, cols);

                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        result.position(i, j) = position(i, j) + M2.position(i, j);
                    }
                }
                return result;
            }
        }

        /**
         * @brief Performs scalar matrix addition
         * @param n
         * @return matrix type
         */

        Matrix add(float n)
        {
            Matrix result(rows, cols);

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    result.position(i, j) = position(i, j) + n;
                }
            }
            return result;
        }

        /**
          * @brief Finds matrice transpose
          * @return matrix type
          */

        Matrix Transpose()
        {
            Matrix result(cols, rows);

            for (int i = 0; i < cols; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    result.position(j, i) = position(i, j);
                }
            }
            return result;
        }
};