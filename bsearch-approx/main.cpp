#include <iostream>

#define MAX 100000000

int arr[MAX];
int n , m;

bool pred(int input)
{

    int p = 0;
    int curr_sum = 0;

    for(int i = 0; i < n ; i++)
    {
        if(arr[i] > input){
            return false;
        }


        if(curr_sum + arr[i] > input )
        {
            p++;
            curr_sum = arr[i] ;
        }
        else curr_sum += arr[i];
    }
   return p <= m - 1;
}

int try_input(int a, int b)
{
    if(b >= a)
    {
        int mid = (a + b) /2;

        if(pred(mid)){
            if(pred(mid-1)) {
                return try_input(a, mid - 1);
            }else return mid;

        }else return try_input(mid+1,b);
    }

    return -1;

}

int main() {

    std::cin>>n>>m;

    for(int i= 0 ; i<n ;i++)
        std::cin>>arr[i];

    std::cout<<try_input(1,1000000001);

    return 0;
}