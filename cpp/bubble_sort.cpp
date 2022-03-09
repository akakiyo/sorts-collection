#include <vector>
#include <iostream>
#include "sorts.hpp"
using namespace std;

// 計算量 O(n**2)
void bubble_sort(vector<int> &array)
{
    int array_length = array.size();
    // バブルソート
    for (int i = 0; i < array_length - 1; i++)
    {
        for (int j = 0; j < array_length - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < array_length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}