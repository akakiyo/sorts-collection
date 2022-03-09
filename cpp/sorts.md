## 内部ソートとは

ソート対象の配列のメモリだけでなく、ソートするために追加でメモリを必要としないもの

## 安定ソートとは

ソート対象の配列に同じ数値が含まれている場合、順序関係が保ったままでできるもの

# 挿入ソート

整列済みの配列と未整列の配列に分け、未整列の配列から 1 つずつ整列済みの配列の適切な場所に挿入させていく。

## 計算量

O(n^2)

## 特徴

- アルゴリズムが理解しやすい
- 内部ソートである
- 安定ソートである
- ソート前の数列が既にほとんど整列済みの場合、高速に動作する。理由としては、値を入れ替える回数が少なくなるためである。

```c++
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
}
```

# 参考資料

- [ソートを極める！ 〜 なぜソートを学ぶのか 〜](https://qiita.com/drken/items/44c60118ab3703f7727f#%E6%A7%98%E3%80%85%E3%81%AA%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%81%AE%E5%89%8D%E5%87%A6%E7%90%86%E3%81%A8%E3%81%97%E3%81%A6)
- [挿入ソート](https://e-words.jp/w/%E6%8C%BF%E5%85%A5%E3%82%BD%E3%83%BC%E3%83%88.html#:~:text=%E6%8C%BF%E5%85%A5%E3%82%BD%E3%83%BC%E3%83%88%E3%81%AF%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%81%AE,%E3%81%A7%E3%81%82%E3%82%8B%E3%81%A8%E3%82%82%E8%A8%80%E3%82%8F%E3%82%8C%E3%82%8B%E3%80%82)
