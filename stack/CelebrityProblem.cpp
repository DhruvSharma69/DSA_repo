#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/* *************************************    BRUTE FORCE APPROACH  *************************
bool checkCelebrity(vector<vector<int>> v)
{
    
    for (int i = 0; i < 3; i++)
    {
        bool ans = true;
        for(int j=0; j<3; j++)
        {
            if(i==j)
            continue;
            else if(v[i][j] == 1)
            {
                ans = false;
                break;
            }

        }
        if(ans == false)
        continue;
        else{
            for(int k=0; k<3; k++)
            {
                if(k==i)
                continue;
                else if(v[k][i]!=1)
                {
                    ans = false;
                    break;
                }
            }
            if(ans == true)
            return ans;
            
        }
        
    }
    return false;
    
}

********************************* OPTIMIZED SOLn********************
*/
bool checkCelebrity(vector<vector<int>> v)
{
    stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);

    while(s.size()!= 1)
    {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        // check if A knows B
        if(v[A][B]==1)
        {
            // if A knows B then A can't be celebrity
            //  check if B knows A
            if(v[B][A] == 0)
            {
                // if B knows A then B can't be celebrity
                s.push(B);
            }
        
        }
        else

        {
            //A dosen't know B 
            // check if B knows A
            if(v[B][A] == 1)
            {
                // if B knows A then B can't be celebrity
                s.push(A);
            }
            // if B and A both don't know each other
            else
            {
                int C = s.top();
                s.pop();
                s.push(A);
                s.push(C);
                s.push(B);
            }
        }
    }
    int Potential_candidate = s.top();
    bool ans = true;
    // check condition 1st  celebrity knows no one
    for(int j=0; j<3; j++)
    {
        if(j == Potential_candidate)
        continue;
        else if(v[Potential_candidate][j]==1)  // celebrity knows someone
        {
            ans = false;
            break;
        }
    }
    if(ans == false)
    return ans;
    // if ans is true check 2nd condition everyone knows celebrity
    for(int i=0; i<3; i++)
    {
        if(i==Potential_candidate)
        continue;
        else if(v[i][Potential_candidate] == 0) // there is someone (i) who don't know celebrity
        {
            ans = false;
            break;
        }
    }
return ans;
}

int main()
{
    vector<vector <int>> v = {{0,1,1},{0,0,0},{1,1,0}};
    bool ans = checkCelebrity(v);
    cout<<ans;
    
    return 0;
}
