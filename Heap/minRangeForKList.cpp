#include<bits/stdc++.h>
using namespace std;

pair<int, int> findSmallestRange(list<int>** nums, int k, int n) {
    vector<list<int>::iterator> iterators(k);
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int currentMax = INT_MIN;
    for (int i = 0; i < k; i++) {
        if (!nums[i]->empty()) {
            iterators[i] = nums[i]->begin();
            int val = *iterators[i];
            minHeap.push(val);
            currentMax = max(currentMax, val);
            advance(iterators[i], 1);
        } else {
            return {0, 0};
        }
    }

    pair<int, int> smallestRange(INT_MAX, -1);

    while (true) {
        int minValue = minHeap.top();
        minHeap.pop();

        int range = currentMax - minValue;
        if (range < smallestRange.first) {
            smallestRange.first = range;
            smallestRange.second = minValue;
        }

        for (int i = 0; i < k; i++) {
            if (iterators[i] != nums[i]->end() && *iterators[i] == minValue) {
                int val = *iterators[i];
                minHeap.push(val);
                currentMax = max(currentMax, val);
                advance(iterators[i], 1);
                break; // Move to the next list.
            }
        }

        if (minHeap.empty()) {
            break; // If minHeap is empty, we can't form a smaller range.
        }
    }

    return smallestRange;
}
int main()
{
    int k,n;
    cout<<"Enter no. of lists and size of lists ";
    cin>>k>>n;
    
    // create a pointer arr which will point to heads of all lists
    list<int>** p = new list<int>*[k];
    for(int i=0; i<k; i++)
    {
        p[i] = new list<int>;
    }
    p[0]->push_back(3); 
    p[0]->push_back(5); 
    p[0]->push_back(8);

    p[1]->push_back(4); 
    p[1]->push_back(9); 
    p[1]->push_back(14);

    p[2]->push_back(10); 
    p[2]->push_back(11); 
    p[2]->push_back(19); 
    
    pair<int,int> ans = findSmallestRange(p,k,3);
    cout<<ans.first<<" "<<ans.second;
    return 0;   
}