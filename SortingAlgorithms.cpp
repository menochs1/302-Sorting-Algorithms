#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "SortingAlgorithms.h"

using namespace std;

SortingAlgorithms::SortingAlgorithms()
{
    sorted.resize(10000);
    unsorted.resize(10000);
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
    for (int i = 0; i < (int)sorted.size(); i++)
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
    for (int i = 0; i < (int)sorted.size(); i++)
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
    // Read input data
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

    // Find the maximum value to determine counting array size
    int max_val = *max_element(unsorted.begin(), unsorted.end());
    vector<int> count(max_val + 1, 0);  // counting array

    // Count occurrences of each number
    for (int i = 0; i < (int)unsorted.size(); i++)
    {
        count[unsorted[i]]++;
    }

    // Calculate cumulative counts
    for (int i = 1; i <= max_val; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the sorted array
    vector<int> output(unsorted.size());
    for (int i = unsorted.size() - 1; i >= 0; i--)
    {
        output[count[unsorted[i]] - 1] = unsorted[i];
        count[unsorted[i]]--;
    }

    sorted = output;

    // Write output
    ofstream oFile;
    oFile.open("countingSort.txt");
    for (int i = 0; i < (int)sorted.size(); i++)
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

    for (int i = 1; i < (int)sorted.size(); i++)
    {
        for (int i = 1; i < (int)sorted.size() - 1; i++)
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
    for (int i = 0; i < (int)sorted.size(); i++)
    {
        oFile << sorted[i] << " ";
        if (i % 21 == 20)
        {
            oFile << endl;
        }
    }
    oFile.close();
}