#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main() {
    int arr[7] = {1,2,4,5,10,5,6};
    int n = 7;
    int k = 2;
    // sort(begin(arr),end(arr),greater<int>());
    // cout << "greater element is " << arr[k-1] << endl;
    // using priority_queue the same problem // 
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {

        pq.push(arr[i]);

        if(pq.size() > k) {
            pq.pop();
        }
    }

    cout << pq.top();

    return 0;
    };
