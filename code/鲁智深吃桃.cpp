#include <iostream>
using namespace std;
int main() {
	
	int a[100];
	for (int i = 0; i < 100; i++)
	{
		a[i] = 1;
	}

	int m = 0;	//参数m，用于记录出局者
	int i = 1;	//参数i，当i为5时，当事人被赋值为0，即出局，且a++，i=0
	int x = 0;	//参数x，用于记录当前人士坐标，x大于99，则x-100

	for (; m < 99;)
	{
		while (i < 5)
		{
			i++;
			x++;
			while (a[x] == 0)
			{
				x++;
				if (x > 99)x = x - 100;
			}
			if (x > 99)x = x - 100;
		}
		while (a[x] == 0)
		{
			x++;
			if (x > 99)x = x - 100;
		}
		a[x] = 0;
		if (i ==5)
		{
			i = 1; x++;
			while (a[x] == 0)
			{
				x++;
				if (x > 99)x = x - 100;
			}
			if (x > 99)x = x - 100;
		}
		m++;
	}

	for (i = 0; i < 99; i++)
	{
		if (a[i] == 1) { cout << "第" << i + 1 << "个位置，吃不到馒头" << endl; }
	}
	return 0;
}