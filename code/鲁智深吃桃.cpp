#include <iostream>
using namespace std;
int main() {
	
	int a[100];
	for (int i = 0; i < 100; i++)
	{
		a[i] = 1;
	}

	int m = 0;	//����m�����ڼ�¼������
	int i = 1;	//����i����iΪ5ʱ�������˱���ֵΪ0�������֣���a++��i=0
	int x = 0;	//����x�����ڼ�¼��ǰ��ʿ���꣬x����99����x-100

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
		if (a[i] == 1) { cout << "��" << i + 1 << "��λ�ã��Բ�����ͷ" << endl; }
	}
	return 0;
}