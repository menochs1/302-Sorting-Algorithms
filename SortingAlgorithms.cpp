#include <iostream>
#include <vector>
#include <fstream>
#include "SortingAlgorithms.h"

using namespace std;

SortingAlgorithms::SortingAlgorithms()
{

}

SortingAlgorithms::~SortingAlgorithms()
{
    
}

void SortingAlgorithms::insertionSort(ifstream &iFile)
{
    iFile.open("data.txt");
    int i = 0;
    while (iFile)
    {
        char c = iFile.peek();
        if (c == '\n')
        {
            iFile.ignore();
        }
        else
        {
            iFile >> unsorted[i];
            i++;
        }
    }
    iFile.close();

    sorted = unsorted;
    for (int i = 0; i < sorted.size(); i++)
    {
        int j = i;
        while (j > 0 && sorted[j - 1] > sorted[j])
        {
            int temp = sorted[j];
            sorted[j] = sorted[j - 1];
            sorted[j - 1] = temp;
            j -= 1;
        }
    }

    ofstream oFile;
    oFile.open("insertionSort.txt");
    for (int i = 0; i < sorted.size(); i++)
    {
        oFile << sorted[i] << " ";
        if (i % 21 == 20)
        {
            oFile << endl;
        }
    }
    oFile.close();
}

void SortingAlgorithms::countingSort(ifstream &iFile)
{
    iFile.open("data.txt");
    int i = 0;
    while (iFile)
    {
        char c = iFile.peek();
        if (c == '\n')
        {
            iFile.ignore();
        }
        else
        {
            iFile >> unsorted[i];
            i++;
        }
    }
    iFile.close();

    vector<int> semiSorted;
    for (int i = 0; i < 1000; i++)
    {
        semiSorted[i] = 0;
    }
    for (int i = 0; i < unsorted.size(); i++)
    {
        semiSorted[unsorted[i]]++;
    }
    for (int i = 1; i < 1000; i++)
    {
        semiSorted[i] += semiSorted[i - 1];
    }
    for (int i = unsorted.size() - 1; i >= 0; i--)
    {
        sorted[semiSorted[unsorted[i]] - 1] = unsorted[i];
        semiSorted[unsorted[i]]--;
    }

    ofstream oFile;
    oFile.open("countingSort.txt");
    for (int i = 0; i < sorted.size(); i++)
    {
        oFile << sorted[i] << " ";
        if (i % 21 == 20)
        {
            oFile << endl;
        }
    }
    oFile.close();
}

void SortingAlgorithms::bubbleSort(ifstream &iFile)
{
    iFile.open("data.txt");
    int i = 0;
    while (iFile)
    {
        char c = iFile.peek();
        if (c == '\n')
        {
            iFile.ignore();
        }
        else
        {
            iFile >> sorted[i];
            i++;
        }
    }
    iFile.close();

    if (sorted[0] > sorted[1])
    {
        int temp = sorted[0];
        sorted[0] = sorted[1];
        sorted[1] = temp;
    }

    for (int i = 1; i < sorted.size(); i++)
    {
        for (int i = 1; i < sorted.size() - 1; i++)
        {
            if (sorted[i] > sorted[i + 1])
            {
                int temp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = temp;
            }
        }
    }

    ofstream oFile;
    oFile.open("bubbleSort.txt");
    for (int i = 0; i < sorted.size(); i++)
    {
        oFile << sorted[i] << " ";
        if (i % 21 == 20)
        {
            oFile << endl;
        }
    }
    oFile.close();
}