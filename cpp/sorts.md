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

# マージソート

マージソートの処理は、前半では配列の要素を分割していき、後半の処理では分割した要素をソートしながらマージしていく。配列を分割して再起的にソートする分割統治法アルゴリズムである。

## 計算量

O(nlogn)

## 特徴

- 高速なソートでありながら、安定ソートである。しかし、ソートする際に外部のメモリが必要になる（外部ソート）。

```c++
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
```

# クイックソート

配列の中から適当な要素を選び出し、並列全体を選び出した要素未満のグループと、要素以上のグループに分割して
ソートを行う。配列を分割してソートする分割統治法アルゴリズムである。

## 計算量

O(nlogn)
(最悪時：O(n^2))

## 特徴

- 内部ソートである
- 安定ソートではない
- 実用上は平均的に非常に高速

# 参考資料

- [ソートを極める！ 〜 なぜソートを学ぶのか 〜](https://qiita.com/drken/items/44c60118ab3703f7727f#%E6%A7%98%E3%80%85%E3%81%AA%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%81%AE%E5%89%8D%E5%87%A6%E7%90%86%E3%81%A8%E3%81%97%E3%81%A6)
- [挿入ソート](https://e-words.jp/w/%E6%8C%BF%E5%85%A5%E3%82%BD%E3%83%BC%E3%83%88.html#:~:text=%E6%8C%BF%E5%85%A5%E3%82%BD%E3%83%BC%E3%83%88%E3%81%AF%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%81%AE,%E3%81%A7%E3%81%82%E3%82%8B%E3%81%A8%E3%82%82%E8%A8%80%E3%82%8F%E3%82%8C%E3%82%8B%E3%80%82)
