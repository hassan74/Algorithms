#include <bits/stdc++.h>

using namespace std;

  void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
  void activity(int s[], int f[], int n) {

        cout << "The maximum set of activities that can be executed by a single person is:" << endl;
        int i = 0;
        cout << 0 << " ";
        for (int j = 1; j < n; j++) {
            if (s[j] >= f[i]) {
                cout << j << " ";
                i = j;
            }
        }
        cout << endl;
    }
int main()
{
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
     mergesort(f ,0 ,n-1 );
    activity(s ,f ,n) ;
    return 0;
}
