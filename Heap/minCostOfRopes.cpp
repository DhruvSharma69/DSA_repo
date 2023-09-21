#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ropes = { 4,3,2,6};
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto i:ropes)
    pq.push(i);
    int cost = 0;
    
    while(pq.size() >1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int sum = a + b;
        pq.push(sum);
        cost += sum;
        
    }
    cout<<cost;
    return 0;
}