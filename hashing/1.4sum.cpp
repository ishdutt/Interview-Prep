#include<bits/stdc++.h>
using namespace std;
//SAME FOR 3 SUM COMPLEXITY : O(n**(k-1)) where k is the K sum
int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    //LIMIT TILL n-3 as the other 4 will take the left spot
    for(int i=0;i<nums.size()-3;i++)
    {
        for(int j=i+1;j<nums.size()-2&&j!=i;j++)
        {
            int k = i+2;
            int l = nums.size()-1;
            while (k<l)
            {
                if(nums[i]+nums[j]+nums[k]+nums[l]==target)
                {
                    cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" "<<nums[l]<<endl;
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    temp.push_back(nums[l]);
                    //CHECKING FOR DUPLICATES
                    while(nums[k]==nums[k+1] && k+1<l)k++;
                    while(nums[l]==nums[l+1] && k<l)l--;                    
                    break;
                }
                else if(nums[i]+nums[j]+nums[k]+nums[l]>target)
                    l--;
                else
                    k++;
            }
            //CHECK FOR DUPLICATES AS SAME POSITION CAN"T HAVE SAME NUMBER 
                while(nums[j+1]==nums[j] && j+1<nums.size())j++; 
        }
        while(nums[i]==nums[i+1] && i+1<nums.size())i++;
    }
    
}