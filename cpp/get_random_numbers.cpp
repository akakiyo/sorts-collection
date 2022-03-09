#include <bits/stdc++.h>
#include "get_random_numbers.hpp"
using namespace std;

vector<int> get_random_numbers(int num, int under_limit, int upper_limit)
{
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rnd100(under_limit, upper_limit);
    vector<int> random_numbers(num);
    for (int i = 0; i < num; i++)
    {
        random_numbers[i] = rnd100(mt);
    }
    return random_numbers;
}