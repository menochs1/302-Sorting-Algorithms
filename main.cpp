#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "SortingAlgorithms.h"

using namespace std;
const int dataLimit = 10000;

void testAll();

int main()
{
    srand(time(0));
    ofstream oFile;
    oFile.open("data.txt");
    for(int i = 0; i < dataLimit; i++)
    {
        oFile << rand() % 1000 + 1 << " ";
        if(i %21 == 20)
        {
            oFile << endl;
        }
    }
    testAll();
}

void testAll()
{
    ifstream iFile;
    SortingAlgorithms sortings;
    auto start = chrono::high_resolution_clock::now();
    sortings.insertionSort(iFile);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Insertion Sort Time: " << elapsed.count() << endl;

    start = chrono::high_resolution_clock::now();
    sortings.countingSort(iFile);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Counting Sort Time: " << elapsed.count() << endl;

    start = chrono::high_resolution_clock::now();
    sortings.bubbleSort(iFile);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Bubble Sort Time: " << elapsed.count() << endl;
}