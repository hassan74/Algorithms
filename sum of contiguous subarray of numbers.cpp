/*
You are given a one dimensional array that may
contain both positive and negative integers, find the sum of contiguous
subarray of numbers which has the largest sum. For example, if the given
array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7 (see
highlighted elements). Your algorithm must be O(nlogn)
*/
#include<iostream>
using namespace std;

int sumMaxSubArr(int arr[], int size)
{
   int largest_max = arr[0];
   int _max = arr[0];

   for (int i = 1; i < size; i++)
   {
        _max = max(arr[i], _max +arr[i]);
        largest_max = max(largest_max, _max);
   }
   return largest_max;
}

int main()
{
   int _array[] =  {-2, -5, 6, -2, -3, 1, 5, -6};
   int n = sizeof(_array)/sizeof(_array[0]);
   int maxSum = sumMaxSubArr(_array, n);
   cout << "the maximum subarray is " << maxSum;
   return 0;
}
