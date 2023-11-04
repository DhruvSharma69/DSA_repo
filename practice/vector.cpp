#include<iostream>
#include<vector>
using namespace std;

vector<int> input(vector<int>arr,int size)
{
   
    for(int i=0;i<size;i++)
    {
        cin>>arr.at(i);
    }
    cout<<endl;
    
     return arr;
}
void reverse(vector<int>arr)
{
    int s=0,e=arr.size()-1;
    while(s<=e)
    {
        swap(arr.at(s),arr.at(e));
        s++;
        e--;

    }
    for(int i:arr)
   { cout<<i<<" ";}
}
// void tra(vector<int>arr)
// {
//     for(int i:arr)
//     cout<<i<<" ";

// }


int main()
{
     cout<<"mention the size of array"<<endl;
    int size;
    cin>>size;
    
    vector<int> v(size);
    v=input(v,size);
    
    
    //tra(v);
    reverse(v);
    

}