#pragma once
#include <iostream>
#include "clsUtil.h"
using namespace std;

// Template Matrix Library - 3/11/2025 - Developer: Mr.Key47

template <typename T> class clsMatrix
{
    static void FillMatrix(T Matrix[3][3], short Rows, short Columns)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Columns; j++)
            {
                cout << "\nEnter element of [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> Matrix[i][j];
            }
        }
    }

    static void PrintMatrix(T Matrix[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                cout << setw(3) << Matrix[i][j] << "    ";
            }
            cout << '\n';
        }
    }

    static void GetRowElements(T Matrix[3][3], short RowNumber, short Columns)
    {
        cout << "\nElements of Row " << RowNumber << ":\n";
        for (short j = 0; j < Columns; j++)
        {
            cout << Matrix[RowNumber][j] << "   ";
        }
    }

    static void GetColumnElements(short Matrix[3][3], short Rows, short ColumnNumber)
    {
        cout << "\nElements of Column " << ColumnNumber << ":\n";
        for (short i = 0; i < Rows; i++)
        {
            cout << Matrix[i][ColumnNumber] << "   ";
        }
    }

    static void GetMiddleRow(short Matrix[3][3], short Rows, short Columns)
    {
        short MiddleRow = Rows / 2;
        cout << "\nElements of Row " << MiddleRow << ":\n";
        for (short j = 0; j < Columns; j++)
        {
            cout << Matrix[MiddleRow][j] << "   ";
        }
    }

    static void GetMiddleColumn(short Matrix[3][3], short Rows, short Columns)
    {
        short MiddleColumn = Columns / 2;
        cout << "\nElements of Column " << MiddleColumn << ":\n";
        for (short i = 0; i < Rows; i++)
        {
            cout << Matrix[i][MiddleColumn] << "   ";
        }
    }

    static bool AreTypicalMatrices(T Matrix1[3][3], T Matrix2[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (Matrix1[i][j] != Matrix2[i][j])
                    return false;
            }
        }
        return true;
    }

    static short CountRepeatedTimes(T Matrix[3][3], short Rows, short Columns, T ElementToSearch)
    {
        short FrequencyCounter = 0;
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (Matrix[i][j] == ElementToSearch)
                    FrequencyCounter++;
            }
        }
        return FrequencyCounter;
    }

    static short GetIndex(T Matrix[3][3], short Rows, short Columns, T ElementToSearch)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (Matrix[i][j] == ElementToSearch)
                    return i;
            }
        }
        return -1;
    }

    static bool IsElementExist(T Matrix[3][3], short Rows, short Columns, T ElementToSearch)
    {
        return GetIndex(Matrix, Rows, Columns, ElementToSearch) != -1;
    }

    static void PrintIntersectedElements(T Matrix1[3][3], T Matrix2[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                if (IsElementExist(Matrix2, Rows, Columns, Matrix1[i][j]))
                    cout << setw(3) << Matrix1[i][j] << "     ";
            }
        }
    }
};