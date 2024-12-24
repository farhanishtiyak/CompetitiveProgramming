#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		// cout<<"Enter N: ";
		cin >> n;
		int prefixSum[n + 1];
		prefixSum[0] = 0;
		// cout<<"Enter elements" <<endl;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			prefixSum[i] = prefixSum[i - 1] + x;
		}
		int l = 1, r = n;
		while (r - l > 1)
		{
			int mid = (l + r + 1) / 2;
			int num = mid - l + 1;
			printf("? %d ", num);
			for (int i = l; i <= mid; i++)
				printf("%d ", i);
			printf("\n");
			fflush(stdout);
			// cout<<"Enter sum: "<<endl;
			int sum;
			scanf("%d", &sum);
			if (prefixSum[mid] - prefixSum[l - 1] < sum)
				r = mid;
			else
				l = mid + 1;
		}

		int num = 1;
		printf("? %d %d\n", num, l);
		fflush(stdout);
		int sum;
		scanf("%d", &sum);
		if (prefixSum[l] - prefixSum[l - 1] < sum)
		{
			printf("! %d\n", l);
			fflush(stdout);
		}
		else
		{
			printf("! %d\n", r);
			fflush(stdout);
		}
	}
}
