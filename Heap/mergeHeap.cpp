#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &ans,int index,int size)
{
    if(size == 0 || size == 1)
    return;
    int largest = index;
    int left = index*2 +1;
    int right = index*2 +2;

    if(left<size && ans[left] > ans[largest])
    largest = left;

    if(right < size && ans[right]>ans[largest])
    largest = right;

    if(largest != index)
    {
        swap(ans[largest], ans[index]);
        heapify(ans,largest,size);
    }


}
vector<int> mergeHeap(vector<int> &a,vector<int> &b,int n, int m)
{
    vector<int> ans;
    // merge vectors a and b into ans
    for(auto i: a)
    {
        ans.push_back(i);
    }
    for(auto i: b)
    {
        ans.push_back(i);
    }

    // now that vectors are merged into ans
    // make ans into a heap
    //use heapify to do that
    int k = ans.size()/2;
    for(int i=k ; i>=0; i--)
    {
        heapify(ans,i,ans.size());
    }

    return ans;
}

int main()
{
    vector<int> a = {30,20,25,10,12,21,23};
    vector<int> b = {40,24,28,3};
    vector<int> heap = mergeHeap(a,b,a.size(),b.size());
    for(auto i:heap)
    cout<<i<<" ";
    return 0;
}
