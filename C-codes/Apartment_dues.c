#include <stdio.h>

int main()
{
	int n;
	//cin >> n;
	scanf("%d", &n);
	int arr[n], i, j;
	int late, flag = 1, count = 0;
	for(i = 0;i<n;i++)
		scanf("%d", &arr[i]);
		//cin >> arr[i];
	
	for(j = 0; j<n;j++)
	{
		if((arr[j]!=1) && (flag == 1)) //the first month where he has missed his dues -0 indexed
		{
			late = j+1;
			flag = 0;
		}
		//the no of months not paid
		if(!arr[j])
			count++;
	}
	// if j == n, then no fines;
	//printf("%d\n", late);
	int amount = (100 * (n - late)) + (1000*count);
	// cout << amount << endl;
	printf("%d",amount);
	return 0;
}
	
	