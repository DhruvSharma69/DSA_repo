#include<iostream>
using namespace std;
/*
int solveUtil(int knapCapacity, int value[], int weight[], int index,int** dp)
{
    //base case
    //like if only one item is remaining
    if(index == 0)
    {
        if(weight[index] <=knapCapacity)
        return value[index];

        return 0;
    }
    if(dp[index][knapCapacity] != -1)
    return dp[index][knapCapacity];


    int include = 0;
    if(weight[index] <=knapCapacity)
    include = value[index] + solveUtil(knapCapacity - weight[index],value,weight,index -1,dp);

    int exclude = solveUtil(knapCapacity,value,weight,index -1,dp);

   dp[index][knapCapacity] =  max(include,exclude);
    return dp[index][knapCapacity];
}

int solve(int knapCapacity, int value[], int weight[], int n)
{
    // commets for adding dp
    int** dp = new int*[n];

    for(int i=0; i<n; i++)
    {
        dp[i] = new int[knapCapacity+1];
        for(int j=0; j<knapCapacity+1; j++)
        {
            dp[i][j] = -1;
        }
    }
    return solveUtil(knapCapacity,value,weight,n-1,dp);
}
*/

// Tabulation method **********************

/*
int solve(int knapCapacity, int value[], int weight[], int n)
{
    // Create a 2D dp array
    int** dp = new int*[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[knapCapacity + 1];
    }

    // Initialize the first row of the dp table
    for (int i = 0; i <= knapCapacity; i++)
    {
        if (weight[0] > i)
            dp[0][i] = 0;
        else
            dp[0][i] = value[0];
    }

    // Fill the dp table
    // space can be optimized twice once can be converted to 2 vectors and then into a variable and a vector
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= knapCapacity; j++)
        {
            int include = 0;
            if (weight[i] <= j)
                include = value[i] + dp[i - 1][j - weight[i]];

            int exclude = dp[i - 1][j];

            dp[i][j] = max(include, exclude);
        }
    }

    int result = dp[n - 1][knapCapacity];

    // Clean up the dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}
*/

// optimizing space into using only 2 arrays

int solve(int knapCapacity, int value[], int weight[], int index)
{
    int prev[knapCapacity+1];
    int curr[knapCapacity+1];

}
int main()
{
    int knapCapacity = 6;
    int value[] = {15, 23, 26, 13};
    int weight[] = {2, 3, 5, 6};
    int n = 4;

    cout << solve(knapCapacity, value, weight, n);
    return 0;
}