#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int findmax(vector<int> &arr, int m)
{
    int n = arr.size();
    int minidiff = INT_MAX;
    for(int i=0; i+m-1 < n; i++){
    int diff = arr[i+m-1] - arr[i];
    
    if(minidiff > diff)
    {
        minidiff = diff;
    }
    }
    return minidiff;
}
int main() {
    vector<int>arr = {5,6,7,8,9};
    int m = 2;
    cout << findmax(arr,m);
    
}
