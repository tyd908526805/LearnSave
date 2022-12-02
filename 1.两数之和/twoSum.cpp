class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        /* O(n^2)
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == target - nums[i])
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
        */ 
        // new
        unordered_map<int, int> tmpMap;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = tmpMap.find(target - nums[i]);
            if (iter == tmpMap.end())
                tmpMap.insert(make_pair(nums[i], i));
            else
            {
                result.push_back(iter->second);
                result.push_back(i);
            }
        }
        return result;
    }
};