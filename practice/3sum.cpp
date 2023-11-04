#include<bits/stdc++.h>
using namespace std;

void twoSum(vector<int>& nums, int target, int i, vector<vector<int>> &ans) {
        int n = nums.size();

        int j = n-1, index = i-1;
        while(i<j)
        {
            
            if(nums[i] + nums[j] == target)
            {
               vector<int> temp =  {nums[i],nums[j], nums[index]};
               ans.push_back(temp);
               while(nums[i+1] == nums[i])
               i++;
               while(nums[j] == nums[j-1])
               j--;

               i++;
               j--;
            }
            else if(nums[i] + nums[j] < target)
            i++;
            else
            j--;
        } 
    } 
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> ans;
         sort(nums.begin(), nums.end());
         for(int i=0; i<nums.size(); i++)
         {
             if(i != 0 && nums[i] == nums[i-1])
             continue;
             if(nums[i] > 0)
             break;
              twoSum(nums,0-nums[i],i+1,ans);           
         }
         return ans;
    }

    int main()
    {
        vector<int> nums = {-1,0,1,2,-1,-4};
        vector<vector<int> > anss = threeSum(nums);

        for(auto i: anss)
        {
            for(auto j: i)
            cout<<j<<" ";
            cout<<endl;
        }
        return 0;
    }