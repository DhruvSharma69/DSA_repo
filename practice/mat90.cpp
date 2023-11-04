#include<iostream>
using namespace std;
int main()
{
    int k;
    cin>>k;

    int arr[k][k];
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
        {
            cin>>arr[i][j];
        }
    }

    int ans[k][k];
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
        {
            ans[i][j] = arr[j][k-1-i];
        }
    }

    
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
