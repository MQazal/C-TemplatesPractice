#pragma once
#include <iostream>
#include <vector>
#include "clsUtil.h"
using namespace std;

// Template Vector Library - 4/11/2025 - Developer: Mr.Key47

template <typename T> class clsVector
{
    static vector <T> FillByUserInput(short Size)
    {
        vector<T> vInputs(Size);
        for (short i = 0; i < Size; i++)
        {
            cout << "\nEnter element of [" << i + 1 << "]: ";
            cin >> vInputs[i];
        }
        return vInputs;
    }

    static vector <T> MyPush_back(vector <T> CurrentVector, T ElementToPush)
    {
        if (CurrentVector.empty())
        {
            return { ElementToPush };
        }

        vector <T> New_v(CurrentVector.size() + 1); // add new empty slot to vector at end
        for (short i = 0; i < CurrentVector.size(); i++)
        {
            New_v[i] = CurrentVector[i];
        }
        // push to new empty slot
        New_v[New_v.size() - 1] = ElementToPush;
        return New_v;
    }

    static void PrintVector(vector <T> vData)
    {
        for (short i = 0; i < vData.size(); i++)
        {
            cout << vData[i] << "    ";
        }
    }

    static void PrintVectorInReverseOrder(vector <T> vData)
    {
        for (int i = vData.size() - 1; i >= 0; i--)
        {
            cout << vData.at(i) << "    ";
        }
    }

    static void PrintVectorWithIndexes(vector <T> vData)
    {
        cout << "\nIndex\tValue\n";
        cout << "----------------\n";
        for (short i = 0; i < vData.size(); i++)
        {
            cout << "[" << i << "]\t" << vData[i] << "\n";
        }
    }

    static void MyPop_back(vector <T>& CurrentVector)
    {
        vector <T> UpdatedVector;
        if (CurrentVector.empty())
        {
            cout << "\nOops, vector is empty!\n";
            return;
        }
        for (short i = 0; i < CurrentVector.size() - 1; i++) // CurrentVector.size() - 1 == delete last slot
        {
            UpdatedVector = MyPush_back(UpdatedVector, CurrentVector[i]);
        }
        CurrentVector = UpdatedVector;
    }

    static short MySize(vector <T> vData)
    {
        short Counter = 0;
        for (T Element : vData)
        {
            Counter += 1;
        }
        return Counter;
    }

    static short GetIndex(vector <T> vData, T ElementToSearch)
    {
        for (short i = 0; i < vData.size(); i++)
        {
            if (vData[i] == ElementToSearch)
                return i;
        }
        return -1;
    }

    static bool IsElementExist(vector <T> vData, T ElementToSearch)
    {
        return GetIndex(vData, ElementToSearch) != -1;
    }

    static short CountElementFrequency(vector <T> vData, T ElementToSearch)
    {
        if (IsElementExist(vData, ElementToSearch))
        {
            short FrequencyCounter = 0;
            for (T& Element : vData)
            {
                if (Element == ElementToSearch)
                    FrequencyCounter++;
            }
            return FrequencyCounter;
        }
        return -1;
    }

    static void GetIndexesOfElement(vector <T> vData, T IndexesArray[30], T ElementToSearch)
    {
        if (CountElementFrequency(vData, ElementToSearch) > 1)
        {
            short Index = 0;
            for (short i = 0; i < vData.size(); i++)
            {
                if (vData[i] == ElementToSearch)
                {
                    IndexesArray[Index] = i;
                    ++Index;
                }
            }
            clsUtil::PrintArray(IndexesArray, Index + 1);
        }
        else
            cout << "\n" << ElementToSearch << " is repeated 1 time and its index is " << GetIndex(vData, ElementToSearch) << ".\n";
    }

    static vector <T> CopyVector(vector <T>SourceVector, vector<T>& DestinationVector)
    {
        for (short i = 0; i < SourceVector.size(); i++)
        {
            DestinationVector = MyPush_back(DestinationVector, SourceVector[i]);
        }
        return DestinationVector;
    }

    static void UpdateSpecificElement(vector <T>& vData, short Index, T NewValue)
    {
        if (IsElementExist(vData, vData[Index]))
        {
            for (short i = 0; i < vData.size(); i++)
            {
                if (i == Index)
                {
                    vData[Index] = NewValue;
                    return;
                }
            }
        }
        cout << "\nIndex " << Index << " is not found!\n";
    }

    static vector <T> ReverseVector(vector <T> OriginalVector)
    {
        vector <T> ReversedVector;
        for (int i = OriginalVector.size() - 1; i >= 0; i--)
        {
            ReversedVector = MyPush_back(ReversedVector, OriginalVector[i]);
        }
        return ReversedVector;
    }

    static void ShuffleVector(vector <T>& vData)
    {
        for (short i = 0; i < vData.size(); i++)
        {
            clsUtil::Swap(vData[clsUtil::RandomNumber(0, vData.size() - 1)], vData[clsUtil::RandomNumber(0, vData.size() - 1)]);
        }
    }

    static void DeleteIndex(vector <T>& vOriginalVector, short IndexToDelete)
    {
        if (vOriginalVector.empty())
        {
            cout << "\nVector is empty!\n";
            return;
        }

        if (IndexToDelete < 0)
        {
            cout << "\nInvalid Index!\n";
            return;
        }

        else
        {
            // Shift elements to the left
            for (short i = IndexToDelete; i < vOriginalVector.size() - 1; i++)
            {
                vOriginalVector[i] = vOriginalVector[i + 1];
            }
            // Reduce vector size by 1 (remove last duplicated element)
            vOriginalVector.resize(vOriginalVector.size() - 1);
        }
    }

    static void DeleteLastIndex(vector <T>& vData)
    {
        if (!vData.empty())
            vData.resize(vData.size() - 1);
    }

    static bool AreVectorsEqual(vector <T>& Vector1, vector <T>& Vector2)
    {
        if (Vector1.size() != Vector2.size())
            return false;

        for (short i = 0; i < Vector1.size(); i++)
        {
            if (Vector1[i] != Vector2[i])
                return false;
        }
        return true;
    }
};