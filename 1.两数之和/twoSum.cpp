class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tmpMap;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = tmpMap.find(target - nums[i]);
            if (iter == tmpMap.end())
                tmpMap.insert(pair(nums[i],i));
            else
                return {iter->second, i};
        }
        return {};
    }
};
