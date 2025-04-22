#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class SortingAlgorithms
{
private:
    vector<int> sorted;
    vector<int> unsorted;
public:
    SortingAlgorithms();
    ~SortingAlgorithms();
    void insertionSort(ifstream &iFile);
    void countingSort(ifstream &iFile);
    void bubbleSort(ifstream &iFile);
};

#endif