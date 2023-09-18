#include<iostream>
#include<queue>
using namespace std;

queue<int> Answer(int arr[], int k, int size)
{
    queue<int> q;
    int m,M;
    m = INT_MAX;
    M = INT_MIN;
    for(int i=0; i<k; i++)
    {
      //  m = min(m,q.back());  //m is the minimum elemtn in window
        M = max(m,arr[i]);  // M is the max element in window
        if(M == arr[i])
        {   q.pop();
            q.push(arr[i]);
        }
    }
   

   
    queue<int> ans;
    ans.push(f);    // q has stored first anselement of  first winodow

    for(int i=0; i< (size-k); i++)
    {
        q.pop();
        q.push(arr[k+i]);
         m = min(m,q.back());  //m is the minimum elemtn in window
        M = max(m,q.back());

    }
    

}

int main()
{
    int size,k;
    cout<<"Enter size of array and size of window \n";
    cin>>size>>k;
    cout<<"\n ENter array \n";
    int arr[size];
    for(int i=0; i<size;i++)
    {
        cin>>arr[i];
    }

    int *temp;
    temp = Answer(arr,k,size);
}