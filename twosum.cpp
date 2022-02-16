//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.

//level:easy
//brute force

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum=0;
        vector<int> output;
        int i=0,j=0;
        int size=0;
        size = nums.size();
        for (i=0;i<size;i++) //i[0,1,2,3,4,5]
        {
            for(j=0;j<size;j++)
            {
                if (i!=j){
                sum=nums[i]+nums[j];
                if (target==sum)
                {
                    output.push_back(i);
                    output.push_back(j);
                    return output;
                }
                }
            }
        }
            return output;
    }

};