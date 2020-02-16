#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdio>

int* indexes;

struct Box
{
    int x;
    int y;
};

void merge(int* arr, int l, int m, int r, int N, int S)
{
    int len_f = m - l + 1;
    int len_s = r - m;

    int* f_half = new int[len_f];
    int* s_half = new int[len_s];

    int j = 0;
    int t = 0;
    for (int i = l; i < r + 1; i++)
    {
        if (i <= m) f_half[j++] = arr[i];
        else s_half[t++] = arr[i];
    }

    int k = l;
    j = 0;
    t = 0;

    int* temp_indexes = new int[N];
    for (int i = 0; i < N; i++)
    {
        temp_indexes[i] = indexes[i];
    }

    while (j < len_f && t < len_s)
    {
        if (f_half[j] <= s_half[t])
        {
            temp_indexes[k] = indexes[j + l];
            arr[k++] = f_half[j++];
        }
        else
        {
            temp_indexes[k] = indexes[t + m + 1];
            arr[k++] = s_half[t++];
        }
    }

    while (j < len_f)
    {
        temp_indexes[k] = indexes[j + l];
        arr[k++] = f_half[j++];
    }
    while (t < len_s)
    {
        temp_indexes[k] = indexes[t + m + 1];
        arr[k++] = s_half[t++];
    }

    delete[] indexes;
    indexes = temp_indexes;

}

void merge_sort(int* arr, int l, int r, int N, int S)
{
    if (l < r)
    {

        int m = (l + r) / 2;

        merge_sort(arr, l, m, N, S);
        merge_sort(arr, m + 1, r, N, S);
        merge(arr, l, m, r, N, S);

    }

}

int main()
{
    std::ios::sync_with_stdio(false);
    int N, S;

    std::cin >> N >> S;

    Box* boxes = new Box[N];
    indexes = new int[N];
    int* sums = new int[N];

    for (int i = 0; i < N; i++)
    {
        indexes[i] = i;
        std::cin >> boxes[i].x >> boxes[i].y;
        sums[i] = boxes[i].x + boxes[i].y;
    }

    merge_sort(sums, 0, N - 1, N, S);

    int k, j = -1;
    int min = 1000000;

    for (int i = 0; i < N; i++)
    {
        if (i + 1 < N)
        {
            int absolute = S - (sums[i] + sums[i + 1]);
            if(absolute < 0) absolute*=-1;
            if (absolute < min)
            {
                min = absolute;
                k = indexes[i];
                j = indexes[i+1];
            }

        }
    }
    std::cout << min << std::endl;
    std::cout << k << " " << j;

    delete[] boxes;
    delete[] indexes;
    delete[] sums;
    return 0;
}