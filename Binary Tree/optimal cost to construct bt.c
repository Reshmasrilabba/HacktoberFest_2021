#include <stdio.h>
#include <limits.h>
 
int min(int x, int y) {
    return (x < y) ? x : y;
}
 
// Function to find the optimal cost to construct a binary search tree
int findOptimalCost(int freq[], int n)
{
    // `cost[i][j]` stores the optimal cost to construct BST from keys `i` to `j`
    int cost[n + 1][n + 1];
 
    // base case: cost is equal to frequency for `i = j` (single key)
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }
 
    // all sizes of sequences
    for (int size = 1; size <= n; size++)
    {
        // all starting points of sequences
        for (int i = 0; i <= n - size + 1; i++)
        {
            int j = min(i + size - 1, n - 1);
            cost[i][j] = INT_MAX;
 
            // consider each key as root and calculate the optimal cost
            for (int r = i; r <= j; r++)
            {
 
                // stores the total cost when `r` is root
                int total = 0;
 
                // get the current node's cost
                for (int k = i; k <= j; k++) {
                    total += freq[k];
                }
 
                // add the optimal cost of the left subtree
                if (r != i) {
                    total += cost[i][r - 1];
                }
 
                // add the optimal cost of the right subtree
                if (r != j) {
                    total += cost[r + 1][j];
                }
 
                // update the cost matrix if needed
                cost[i][j] = min(total, cost[i][j]);
            }
        }
    }
 
    // return the resultant cost
    return cost[0][n - 1];
}
 
int main(void)
{
    int freq[] = { 25, 10, 20 };
    int n = sizeof(freq) / sizeof(freq[0]);
 
    printf("The optimal cost of constructing BST is %d", findOptimalCost(freq, n));
 
    return 0;
}
