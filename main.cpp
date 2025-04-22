#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int dataLimit = 10000;

void testAll(ofstream &os);

int main()
{
    srand(time(0));
    ofstream oFile;
    oFile.open("data.txt");
    for(int i = 0; i < dataLimit; i++)
    {
        oFile << rand() % 1000 + 1 << " ";
        if(i % 21 == 20)
        {
            oFile << endl;
        }
    }
    oFile.close();

}