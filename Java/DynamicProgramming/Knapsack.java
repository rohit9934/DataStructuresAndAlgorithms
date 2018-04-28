/*
Motivation Problem: 
Given the [weight,profit] pair of N items lying around the floor
and the amount of weight your bag can handle,
you need to pack as many items in your bag as you can provided 
you generate maximum profit at the end, after you sell each of the stolen goods.

Why Use Dynamic Programming?
Claim 1: Brute Force Approach will not give right answer always, it may happen
that light weighted item is expensive and item of largest weight is cheapest.
So Simple Sorting will never work
Claim 2:Straight Forward recursion have time complexity O(2^N) which is far worse that
Dynamic Programming Solution O(N*W) where N is number of items and W is weight of the box


*/


class Knapsack
{
 
    static int max(int a, int b) { return (a > b)? a : b; }
    static int knapSack(int W, int weights[], int prices[], int n)
    {
         int i, w;
     int K[][] = new int[n+1][W+1];
     for (i = 0; i <= n; i++)
     {
         for (w = 0; w <= W; w++)
         {
             if (i==0 || w==0)
                  K[i][w] = 0;
             else if (weights[i-1] <= w)
                   K[i][w] = max(prices[i-1] + K[i-1][w-weights[i-1]],  K[i-1][w]);
             else
                   K[i][w] = K[i-1][w];
         }
      }
      
      return K[n][W];
    }
    public static void main(String args[])
    {
        int prices[] = new int[]{60, 100, 120};
    int weights[] = new int[]{10, 20, 30};
    int  W = 50;
    int n = prices.length;
    System.out.println(knapSack(W, weights, prices, n));
    }
}
