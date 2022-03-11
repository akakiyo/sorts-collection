#include <bits/stdc++.h>
#include "sorts.hpp"
using namespace std;

void merge_sort(vector<int> &array, int left, int right)
{
    if (right - left == 1)
        return;
    int mid = left + (right - left) / 2;

    merge_sort(array, left, mid);
    merge_sort(array, mid, right);

    vector<int> buf;
    for (int i = left; i < mid; i++)
        buf.push_back(array[i]);
    for (int i = right - 1; i >= mid; i--)
        buf.push_back(array[i]);

    int left_index = 0;
    int right_index = (int)buf.size() - 1;
    for (int i = left; i < right; i++)
    {
        if (buf[left_index] <= buf[right_index])
        {
            array[i] = buf[left_index];
            left_index++;
        }
        else
        {
            array[i] = buf[right_index];
            right_index--;
        }
    }

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
