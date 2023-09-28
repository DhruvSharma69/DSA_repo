#include<bits/stdc++.h>
using namespace std;
 
 int signum(int a, int b)
 {
    if(a == b)
    return 0;

    else if( a > b)
    return 1;

    else
    return -1;
 }
 int getMedian(vector<int> &i, int &k, priority_queue<int> &maxHeap, priority_queue<int,
  vector<int>, greater<int> > &minHeap,int &M)
 {
    int element = i[k];
    

   switch (signum(maxHeap.size(), minHeap.size()))
   {
   case 0:                          //maxHeap size == minHeap size
    {   if(element > M)
        {   minHeap.push(element);
            M = minHeap.top();

        }

        else
       { 
            maxHeap.push(element);
            M = maxHeap.top();

       }
        break;
    }
    
    case 1:
    {                       // maxHeap size > minHeap size
        if(element> M)
        {
            minHeap.push(element);
            M = (maxHeap.top() + minHeap.top()) /2;
        }
        else{
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(element);
            M = (maxHeap.top() + minHeap.top()) /2;
        }
        break;
    }
   
   default:
   {    
        if(element > M)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(element);
            M = (maxHeap.top() + minHeap.top()) /2;
        }

        else{
            maxHeap.push(element);
            M = (maxHeap.top() + minHeap.top()) /2;
        }
        break;
   }
    
   }
   return M;


 }
void PrintMedians(vector<int> &i,int s)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int M = 0;
    for(int k=0; k<s; k++)
    {
        int m = getMedian(i,k,maxHeap,minHeap,M);
        cout<<m<<endl;
    }
}
int main()
{
    cout<<"enter no. of elements ";
    int n;
    cin>>n;             // input 5 2 6 9 3 4
    vector<int> input;
    cout<<"Enter data";
    for(int i=0; i<n; i++)
    {
        int e;
        cin>>e;
        input.push_back(e);
    }
    PrintMedians(input,n);
    return 0;
}