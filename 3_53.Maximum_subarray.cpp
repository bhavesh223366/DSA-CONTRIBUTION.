https://leetcode.com/problems/maximum-subarray/ 

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

// Brute Force Approach
int bruteforce(vector<int> &arr, int m)
{
    int n = arr.size();
    int minidiff = INT_MAX;

    for(int i=0; i<n; i++)
    {
        for(int j=i+m-1; j<n; j++)
        {
            int diff = arr[j] - arr[i];

            if(diff < minidiff)
            {
                minidiff = diff;
            }
        }
    }

    return minidiff;
}

// Optimized Approach
int findmax(vector<int> &arr, int m)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int minidiff = INT_MAX;

    for(int i=0; i+m-1 < n; i++)
    {
        int diff = arr[i+m-1] - arr[i];

        if(minidiff > diff)
        {
            minidiff = diff;
        }
    }

    return minidiff;
}

int main()
{
    vector<int> arr = {5,6,7,8,9};

    int m = 2;

    cout << "Brute Force = "
         << bruteforce(arr,m) << endl;

    cout << "Optimized = "
         << findmax(arr,m);

    return 0;
}
