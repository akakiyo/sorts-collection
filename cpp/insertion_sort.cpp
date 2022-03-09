#include <bits/stdc++.h>
#include "sorts.hpp"
using namespace std;

void insertion_sort(vector<int> &array)
{
    int array_length = array.size();
    for (int i = 1; i < array_length; i++)
    {
        int insert_num = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > insert_num)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = insert_num;
    }
    cout << "ソート後:";
    for (int i = 0; i < array_length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// 自作
// void insertion_sort(vector<int> &array)
// {
//     int array_length = array.size();
//     for (int i = 0; i < array_length; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (array[i] < array[j])
//             {
//                 int tmp = array[i];
//                 for (int k = i; k > j; k--)
//                 {
//                     array[k] = array[k - 1];
//                 }
//                 array[j] = tmp;
//                 break;
//             }
//         }
//     }
//     cout << "ソート後:";
//     for (int i = 0; i < array_length; i++)
//     {
//         cout << array[i] << " ";
//     }
//     cout << endl;
// }