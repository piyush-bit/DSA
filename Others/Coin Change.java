import java.util.Arrays;

class Solution {
    public int coinChange(int[] coins, int amount) {
        return solve(coins, amount, 0);
    }

    private int solve(int[] coins, int amount, int index) {
        if (amount == 0) return 0; // Base case: If the amount is 0, no coins are needed

        int minCoins = Integer.MAX_VALUE;

        for (int i = index; i < coins.length; i++) {
            if (amount >= coins[i]) {
                int remainingAmount = amount - coins[i];
                int remainingCoins = solve(coins, remainingAmount, i); // Reuse the same coin index

                if (remainingCoins != -1) {
                    minCoins = Math.min(minCoins, remainingCoins + 1);
                }
            }
        }

        return minCoins == Integer.MAX_VALUE ? -1 : minCoins;
    }
}