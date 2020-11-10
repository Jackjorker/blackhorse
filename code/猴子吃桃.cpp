////猴子第一天摘了若干个桃子，吃了一半，不过瘾，又多吃了1个。
//第二天早上将剩余的桃子又吃掉一半，并且又多吃了1个。
//此后每天都是吃掉前一天剩下的一半零一个。到第n天再想吃时，发现只剩下1个桃子，
//问第一天它摘了多少桃子？为了加强交互性，由用户输入不同的天数n进行递推，即假设第n天的桃子数为1。
#include <iostream>
using namespace std;
int monky(int& n) {
	int sum=1;
	for (int i = 1; i < n; i++) {
		sum = (sum + 1) * 2;
	}
	return sum;
}
int main() {
	int n;
	int tao;
	cout << "输入猴子吃桃的天数" << endl;
	cin >> n;
	tao=monky(n);
	cout << "桃子起始的数量为" << tao<<endl;
	return 0;
}
