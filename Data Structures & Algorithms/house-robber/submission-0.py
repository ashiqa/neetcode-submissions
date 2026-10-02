class Solution:
 

    def rob(self, nums: List[int]) -> int:
        
        dp = [None] * len(nums)

        def visit(i):
            if (i >= len(nums)):
                return 0

            if (dp[i] is not None):
                return dp[i]
            
            dp[i] = max(visit(i + 1), nums[i] + visit(i + 2))
            return dp[i]

        visit(0)    
        return dp[0]
        