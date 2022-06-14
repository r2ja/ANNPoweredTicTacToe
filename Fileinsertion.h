#include <iostream>
#include <fstream>

using namespace std;

struct Fileinsertion
{
    /**
     * @brief Searching for the file, comparing values and storing it into a vector
     * 
     * @param line_num 
     * @param vec 
     * @param tingy char for positive and negative
     * @result returns updated vector and char
     */

    void fileSearch(int &line_num, vector<float> &vec, char &tingy)
    {
        string data = "";
        fstream fin("tic-tac-toe.data", ios::in);

        if (!fin.is_open())
        {
            cout << "Error: File not found!" << endl;
        }

        for (int i = 0; i < line_num && getline(fin, data); i++);

        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == 'x')
            {
                vec.push_back(1.0f);
            }
            else if (data[i] == 'o')
            {
                vec.push_back(-1.0f);
            }
            else if (data[i] == 'b')
            {
                vec.push_back(0.1f);
            }

            if (data[18] == 'p')
            {
                tingy = 'P';
            }
            else if (data[18] == 'n')
            {
                tingy = 'N';
            }
        }
    }
};
