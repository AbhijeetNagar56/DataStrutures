class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            mp = {}
            count = 0
            for j in range(i, len(nums)):
                if nums[j] in mp:
                    mp[nums[j]] += 1
                else:
                    mp[nums[j]] = 1
                    
                if mp[nums[j]] == 1:
                    count += 1
                ans += count*count
        return ans