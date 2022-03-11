#include <bits/stdc++.h>
#include "sorts.hpp"
using namespace std;

void quick_sort(vector<int> &array, int left, int right)
{
    if (right - left <= 1)
    {
        return;
    }

    int pivot_index = (left + right) / 2;
    int pivot = array[pivot_index];

    swap(array[pivot_index], array[right - 1]);
    int i = left;
    for (int j = left; j < right - 1; j++)
    {
        if (array[j] <= pivot)
        {
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[i], array[right - 1]);

    quick_sort(array, left, i);
    quick_sort(array, i + 1, right);
    if (left == 0 && right == array.size())
    {
        cout << "ソート後:";
        for (int i = 0; i < array.size(); i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}