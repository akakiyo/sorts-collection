#include <bits/stdc++.h>
#include "sorts.hpp"
#include "get_random_numbers.hpp"

using namespace std;

int main()
{
    vector<int> nums = get_random_numbers(20, 0, 99);
    cout << "ソート前:";
    for (int i = 0; i < 20; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    merge_sort(nums, 0, nums.size());
}
