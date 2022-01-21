// #include <bits/stdc++.h>
// using namespace std;

// // A utility function to get sum of array elements
// // freq[i] to freq[j]
// int sum(int freq[], int i, int j);

// /* A Dynamic Programming based function that calculates
// minimum cost of a Binary Search Tree. */
// int optimalSearchTree(int keys[], int freq[], int n)
// {
// 	/* Create an auxiliary 2D matrix to store results
// 	of subproblems */
// 	int cost[n][n];

// 	/* cost[i][j] = Optimal cost of binary search tree
// 	that can be formed from keys[i] to keys[j].
// 	cost[0][n-1] will store the resultant cost */

// 	// For a single key, cost is equal to frequency of the key
// 	for (int i = 0; i < n; i++)
// 		cost[i][i] = freq[i];

// 	// Now we need to consider chains of length 2, 3, ... .
// 	// L is chain length.
// 	for (int L = 2; L <= n; L++)
// 	{
// 		// i is row number in cost[][]
// 		for (int i = 0; i <= n-L+1; i++)
// 		{
// 			// Get column number j from row number i and
// 			// chain length L
// 			int j = i+L-1;
// 			cost[i][j] = INT_MAX;

// 			// Try making all keys in interval keys[i..j] as root
// 			for (int r = i; r <= j; r++)
// 			{
// 			// c = cost when keys[r] becomes root of this subtree
// 			int c = ((r > i)? cost[i][r-1]:0) +
// 					((r < j)? cost[r+1][j]:0) +
// 					sum(freq, i, j);
// 			if (c < cost[i][j])
// 				cost[i][j] = c;
// 			}
// 		}
// 	}
// 	return cost[0][n-1];
// }

// // A utility function to get sum of array elements
// // freq[i] to freq[j]
// int sum(int freq[], int i, int j)
// {
// 	int s = 0;
// 	for (int k = i; k <= j; k++)
// 	s += freq[k];
// 	return s;
// }

// int main()
// {
// 	int keys[] = {10, 12, 20};
// 	int freq[] = {34, 8, 50};
// 	int n = sizeof(keys)/sizeof(keys[0]);
// 	cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);
// 	return 0;
// }

// A Dynamic Programming based solution that uses
// table C[][] to calculate the Binomial Coefficient
// #include <bits/stdc++.h>
// using namespace std;

// // Prototype of a utility function that
// // returns minimum of two integers
// int min(int a, int b);

// // Returns value of Binomial Coefficient C(n, k)
// int binomialCoeff(int n, int k)
// {
// 	int C[n + 1][k + 1];
// 	int i, j;

// 	// Calculate value of Binomial Coefficient
// 	// in bottom up manner
// 	for (i = 0; i <= n; i++) {
// 		for (j = 0; j <= min(i, k); j++) {
// 			// Base Cases
// 			if (j == 0 || j == i)
// 				C[i][j] = 1;

// 			// Calculate value using previously
// 			// stored values
// 			else
// 				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
// 		}
// 	}

// 	return C[n][k];
// }

// // A utility function to return
// // minimum of two integers
// int min(int a, int b) { return (a < b) ? a : b; }

// int main()
// {
// 	int n = 5, k = 2;
// 	cout << "Value of C[" << n << "][" << k << "] is "
// 		<< binomialCoeff(n, k);
// }

// A dynamic programming based
// solution for 0-1 Knapsack problem
#include <bits/stdc++.h>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int>> K(n + 1, vector<int>(W + 1));

	// Build table K[][] in bottom up manner
	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
								K[i - 1][w - wt[i - 1]],
								K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

// Driver Code
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	
	cout << knapSack(W, wt, val, n);
	
	return 0;
}


