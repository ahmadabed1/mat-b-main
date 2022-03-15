#include "mat.hpp"
#include <array>
#include "doctest.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace ariel
{
    string mat(int number1, int number2, char str1 , char str2 )
    {
    
        int const step =2;
        string new_mat;
        int Start_number2 = 0;                                        
        int End_number2 = number2 - 1;                                    
        int Start_number1 = 0;                                     
        int End_number1 = number1 - 1;  
        vector<vector<char>> final_mat(number2, vector<char>(number1)); 
        vector<vector<char>> final_m(number2, vector<char>(number1)); 
        int convertoend = (number2 + 1) / 2;
        int const min_range = 33;
        int const max_range = 126;

        if (number1 < 0 || number2 < 0)
        {
             std::__throw_invalid_argument("not valid");
        }
        //  column numbers are odd or even
        if (number2 % 2 == 0 || number1 % 2 == 0)
        {
             std::__throw_invalid_argument("not valid");
        }
        // symbol are legal ones less than min
        if (str2 < min_range || str1 < min_range)
        {
             std::__throw_invalid_argument("not valid");
        }
        // symbol are legal ones more than max
        if (str2 > max_range || str1 > max_range)
        {
             std::__throw_invalid_argument("not valid");
        }

    
        while (convertoend > 0)
        {
            for (int i = Start_number2; i <= End_number1; i++)
            {
                for (int j = Start_number1; j <= End_number2; j++)
                {
                    final_mat[Start_number2][i] = str1;
                    final_mat[j][Start_number1] = str1;
                    final_mat[End_number2][i] = str1;
                    final_mat[j][End_number1] = str1;
                }
            }
            
            Start_number2 = Start_number2 + step;
            Start_number1 += step;
            End_number1 -= step;
            End_number2 -= step;
            convertoend--;
            
            for (int i = 0; i < number2 - 1; i++)
            {
                for (int j = 0; j < number1 - 1; j++)
                {
                    if (final_mat[i][j] != str1)
                    {
                        final_mat[i][j] = str2;
                    }
                }
            }
        }


        for (int i = 0; i < number2; i++)
        {
            for (int j = 0; j < number1; j++)
            {
                new_mat += final_mat[i][j];
            }
            new_mat += "\n";
        }

        return new_mat;
    }

};