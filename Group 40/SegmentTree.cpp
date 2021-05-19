#include <iostream>
#include <math.h>

#define Max_Lt 1000
using namespace std;

int Time = 0;

int HashF(int x, int y)
{
	Time++;
	return (x*y*Time)%Max_Lt;
}

class SegmentTree
{
private:
	int *segTree, N;

public:
	SegmentTree()
	{
		this->segTree = NULL;
		this->N = 0;
	}
	SegmentTree(int Z[], int n)
	{
		int height = (int)(ceil(log2(n)));
		int max_size = (2 << (height + 1)) - 1;

		this->segTree = new int[max_size];
		for (int i=0; i<max_size; i++) segTree[i] = 1001;
		this->N = n;

		BuildBob(Z, 0, n - 1, 0);
	}

	int BuildBob(int Z[], int ss, int se, int si)
	{
		if (ss == se)
		{
			segTree[si] = Z[ss];
			return Z[ss];
		}

		int mid = ss / 2 + se / 2;
		int ll = BuildBob(Z, ss, mid, si * 2 + 1);
		int rr = BuildBob(Z, mid + 1, se, si * 2 + 2);
		segTree[si] = HashF(ll, rr);
		return segTree[si];
	}
	

	void Show()
	{
		int start = 0, end = (int)(ceil(log2(N)));
		end = (2 << end) - 1;
		for (int i = start, j = 1, k = 1; i < end; i++, j++)
		{
			// To avoid Junk values in general
			if (segTree[i] <= Max_Lt && segTree[i] >= 0)
				cout << segTree[i] << " ";
			else
				cout << "- ";
			if (j % 2 == 0)
			{
				cout << "\t";
			}			
			if (j == k)
			{
				cout << "\n";
				j = 0, k <<= 1;
			}
		}
	}
};

int main()
{
	int arr[] = {1, 3, 2, 9, 7, 3};
	// 1, 3, 2, 9, 7, 13 - base, 680
	// 1, 3, 2, 9, 7, 11 - modify
	// 1, 3, 2, 8, 7, 13 - modify
	//* 1, 3, 2, 9, 7, 13, 11 - add */
	int n = sizeof(arr) / sizeof(arr[0]);

	SegmentTree SegT(arr, n);
	cout<<"Tree::\n";
	SegT.Show();

	return 0;
}
