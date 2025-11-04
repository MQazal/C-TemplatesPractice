#pragma once
#include <iostream>
#include "clsUtil.h"
using namespace std;

// Template Array Library - 3/11/2025 - Developer: Mr.Key47

template <typename T> class clsArray
{
    static void FillArray(T Array[100], short& Length)
    {
        for (short i = 0; i <= Length - 1; i++)
        {
            cout << "\nElement[" << i + 1 << "]: ";
            cin >> Array[i];
        }
    }

    static void PrintArray(T Array[100], short Length)
    {
        for (short i = 0; i < Length; i++)
        {
            cout << Array[i] << " ";
        }
    }

    static T CountElementFrequency(T Array[100], short Length, T ElementToCheck)
    {
        short FrequencyCounter = 0;
        for (short Counter = 0; Counter <= Length - 1; Counter++)
        {
            if (Array[Counter] == ElementToCheck)
                FrequencyCounter++;
        }
        return FrequencyCounter;
    }

    static void CopyArray(T arrSource[100], T arrDestination[100], short Length)
    {
        for (short i = 0; i <= Length - 1; i++)
        {
            arrDestination[i] = arrSource[i];
        }
    }

    static void ShuffleArray(T Array[100], short Length)
    {
        for (short i = 0; i < Length; i++)
        {
            clsUtil::Swap(Array[clsUtil::RandomNumber(0, Length - 1)], Array[clsUtil::RandomNumber(0, Length - 1)]);
        }
    }

    static void CopyArrayInReverseOrder(T Array1[100], T Array2[100], short Array1_Length)
    {
        short ReverseCounter = Array1_Length - 1;
        for (short i = 0; i < Array1_Length; i++)
        {
            Array2[i] = Array1[Array1_Length - 1 - i];
            
            // another sol:
            //Array2[i] = Array1[Array1_Length - ReverseCounter];
            //ReverseCounter--;
        }
    }

    static short GetIndex(T Array[100], short Length, T ElementToSearch)
    {
        for (int i = 0; i <= Length - 1; i++)
        {
            if (Array[i] == ElementToSearch)
                return i;
        }
        return -1;
    }

    static bool IsIndexExist(T Array[100], short Length, T ElementToSearch)
    {
        return GetIndex(Array, Length, ElementToSearch) != -1;
    }

    static short GetLastIndex(T Array[100], short Length, T ElementToSearch)
    {
        for (short i = Length - 1; i >= 0; i--)
        {
            if (Array[i] == ElementToSearch)
                return i;
        }
        return -1;
    }

    static void AddElementToArray(T Element, T Array[], short& ArrayLength)
    {
        ++ArrayLength;
        Array[ArrayLength - 1] = Element;
    }

    static void FillSimiDynamicArray(T Array[], int& ArrayLength)
    {
        bool SureToAdd = true;
        do
        {
            AddElementToArray(clsUtil::ReadNumber("Enter a Number: "), Array, ArrayLength);
            SureToAdd = clsUtil::StringToBoolean(clsUtil::ReadText("\nDo you want to add another number, Yes/No: "), "Yes");
        } while (SureToAdd);
    }

    static void CopyArrayUsingAddArrayElement(T arrSource[100], T arrDestination[100], int arrSourceLength, int& arrDestinationLength)
    {
        for (int i = 0; i <= arrSourceLength - 1; i++)
        {
            AddElementToArray(arrSource[i], arrDestination, arrDestinationLength);
        }
    }

    static void ReverseArray(T Array1[50], T Array2[50], short Array1_Length)
    {
        for (short i = Array1_Length - 1; i >= 0; i--)
        {
            Array2 = Array1[i];
        }
    }

    static void DeleteArray(T OldArray[50], T NewArray[50], short OldArrayLength, short& NewArrayLength, T ElementToDelete)
    {
        short Index = 0; // there is an index will be missing, so insertion's index will be tracked
        for (short i = 0; i < OldArrayLength; i++)
        {
            if (OldArray[i] != ElementToDelete)
                NewArray[Index++] = OldArray[i];
        }
        NewArrayLength = Index;
    }
};