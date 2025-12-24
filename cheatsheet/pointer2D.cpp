#include <iostream>
using namespace std;

void createArray(int** &array,int num)
{
    array = new int* [num];
    for(int i=0;i<num;i++)
    {
        array[i] = new int [num];
        for(int j=0;j<num;j++)
        {
            array[i][j] = i+j;
        }
    }
}

void printArray(int** &array,int num)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteArray(int** &array,int num)
{
    for(int i = 0; i < num; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    array = nullptr;
}

int main()
{
    int** array = nullptr;
    int num = 5;

    createArray(array, num);
    printArray(array,num);
    deleteArray(array,num);
    return 0;
}