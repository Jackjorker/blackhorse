#include<iostream>
//using namespace std;//标准命名空间的定义声明
namespace spaceA {
	int g_a;
	//using namespace spaceC;//命名空间的使用必须要在命名空间之后，即这一行必须放在spaceC的定义之后
	namespace spaceB {
		//命名空间可以循环嵌套
		struct teacher {
			int id;
			char name[60];
		};
	}
	namespace spaceC {
		//命名空间可以循环嵌套
		struct teacher {
			int id;
			char name[60];
		};
	}
	using namespace spaceC;
}
#if(0)
//命名空间定义的三种形式
using namespace std;
使用局部变量，std::变量名；
使用全局变量，在main函数之前就声明需要使用的命名空间的变量名using spaceA::g_a;
#endif//一种注释方法
int main() {
	spaceA::g_a=10;
	spaceA::spaceB::teacher t1;
	t1.id = 20;
	using namespace spaceA;
	teacher t2;//这一个teacher类型是spaceC命名空间的
	t2.id = 30;
	std::cout << t1.id <<" "<<t2.id<< std::endl;
	return 0;
}