
#include <bits/stdc++.h>

using namespace std;
int partition(vector<int> &v, int start, int end)
{
    int pivot = v[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[end]);
    return (i + 1);
}
void quickSort(vector<int> &v, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(v, start, end);
        quickSort(v, start, pivot - 1);
        quickSort(v, pivot + 1, end);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    quickSort(v, 0, n - 1);
    cout << "Sorted array" << endl;
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    return 0;
}
/* pivot=last element  
Time Complexity: 
    worst case: when partition always picks greatest element: O(n^2)  
    best case: when partition always picks middle element: O(n logn)
    */