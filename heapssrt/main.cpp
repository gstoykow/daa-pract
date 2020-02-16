#include <iostream>

void heapify(int* arr,int n, int r)
{
    int max = r;
    int lci = 2*r + 1;
    int rci = 2*r + 2;

    if(lci < n && arr[lci] > arr[max])
        max = lci;

    if(rci < n && arr[rci] > arr[max])
        max = rci;

    if(max != r)
    {
        std::swap(arr[r],arr[max]);
        heapify(arr,n,max);
    }

}

void heap_sort(int* arr, int n)
{
    for(int i = n/2 - 1 ; i >= 0 ; i++)
        heapify(arr,n,i);

    for(int i = n-1 ; i>=0 ; i--)
    {
        std::swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }

}

int main() {

    //

    return 0;
}