#include<iostream>
#include<vector>
using namespace std;
// void printv(vector<int> &v)
// {
//     cout<<" size =  "<<v.size()<<endl;
//     for(int i=0;i<v.size();i++)
//     cout<<v[i];
// }
void takein(vector<vector<int>> &v1,int size)
{
    for(int i=0;i<size;i++)
    {
        vector<int> temp;
        for(int j=0;j<size;j++)
        {
            
            int n;
            cin>>n;
            
            temp.push_back(n);
            
        }
        v1.push_back(temp);
    }
}
void showout(vector<vector<int>> &v1,int size)
{
     for(int i=0;i<size;i++)
    {
        for(int j=0;j<v1[i].size();j++)
        {
        cout<<v1[i][j];
        }
        cout<<endl;
        
    }
}

int main()
{
    int size;
    cin>>size;
     vector<int> arr[size];
    //vector of vector method (dynamic rows and column)
   vector<vector<int>> v1;
   takein(v1,size);
   showout(v1,size);
    
    


    // //array of vector method(dynamic column static rows)
    // int l;
    // cout<<"enter rows nu ";
    // cin>>l;
   
    // //taking input
    // for(int i=0;i<l;i++)
    // {
    //     int n;
    //     cout<<"enter col size ";
    //     cin>>n;//size of column at i
    //     for(int j=0;j<n;j++)
    //     {
    //         int k;
    //         cout<<"enter element at i=  "<<i<<" j=  "<<j;
    //         cin>>k;
    //         arr[i].push_back(k);
    //     }
    //     cout<<endl;
    // }
    // //printing
    // for(int i=0;i<l;i++)
    // {
    //     printv(arr[i]);
    // }

    return 0;
}
