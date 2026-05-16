#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

vector<int> findmax(vector<int>& arr) {

    // vector<int> sorted = arr;

    // sort(sorted.begin(), sorted.end());

    // return {sorted[0], sorted[sorted.size()-1]};
    // better approach iterating the array -- 
    int n = arr.size();
    int mini = INT_MAX;
    int max = INT_MIN;
    for(int i=0; i<n; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < mini) mini = arr[i];
    }
    return {mini,max};

}

int main() {

    vector<int> arr = {1,2,3,4,5};

    vector<int> result = findmax(arr);

    cout << "result " << result[0] << " " << result[1] << endl;

    return 0;
}
