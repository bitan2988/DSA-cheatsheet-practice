//https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/

// cost_of_cutting = edge_value * no_of_pieces
// since cost_of_edge is a const value thus in order to minimise the total cose we will use it when the pieces are least
// as we have to make every cut in-order to divide it in single piece

// We can make conclusions that
//    first cut along edges having max cost as the amount of pieces at that time will be minimum
//    to make a horizontal cut we will need all the vertical pieces and for a vertical cut we will need all the horizontal pieces

#include <bits/stdc++.h>
using namespace std;

// method returns minimum cost to break board into m*n squares
int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
	int res = 0;

	// sort the horizontal cost in reverse order
	sort(X, X + m, greater<int>());

	// sort the vertical cost in reverse order
	sort(Y, Y + n, greater<int>());

	// initialize current width as 1 
	int hzntl = 1, vert = 1;

	// loop untill one or both cost array are processed
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (X[i] > Y[j])   // if horizontal cut has more value than vertical cut then take that cut
		{
			res += X[i] * vert;

			// increase current horizontal part count by 1
			hzntl++;
			i++;
		}
		else
		{
			res += Y[j] * hzntl;

			// increase current vertical part count by 1
			vert++;
			j++;
		}
	}

	// loop for horizontal array, if remains
	int total = 0;
	while (i < m)
		total += X[i++];
	res += total * vert;

	// loop for vertical array, if remains
	total = 0;
	while (j < n)
		total += Y[j++];
	res += total * hzntl;

	return res;
}

// Driver code to test above methods
int main()
{
	int m = 6, n = 4;
	int X[m-1] = {2, 1, 3, 1, 4};
	int Y[n-1] = {4, 1, 2};
	cout << minimumCostOfBreaking(X, Y, m-1, n-1);
	return 0;
}



