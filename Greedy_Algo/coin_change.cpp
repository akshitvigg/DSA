class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
   
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // Base case: 0 coins needed to make amount 0
        
        // Iterate through each coin and fill the dp array
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        
        // If dp[amount] is still amount + 1, return -1, otherwise return dp[amount]
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
