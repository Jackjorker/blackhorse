#include<iostream>
using namespace std;

struct student {
	int id;
};
//在函数的定义，返回值以及传实参方面，C++都做了更严格的要求，声明了一些C语言不清楚的灰色地带
int a(int b) {
	cout << b << endl;
	return 0;//main函数没有返回值是可以运行的，但是其余自己定义的函数没有返回类型就会报错
}
#if(0)
a() {//c语言中就算是有返回值，也能编译通过，默认函数类型为int型
	return 10;
}
int a(int b) {//C语言中给b传值，可以传入多个实参，虽然有警告，但是并不报错

}
#endif
void test() {
	student s1;//struct在c语言中不仅需要在定义使用，在声明使用的时候也需要，但是在C++中只需要定义时就行
	s1.id = 10;
}
void test2() {
	bool flag;//flag 有true和false两种值，但是可以用数字代表
	flag = true;
	cout << flag << "  " << endl;
	flag = false;
	cout << flag << "  " << endl;
	flag = 11;//int值赋值给bool类型可以，但是会给出警告
	cout << flag << "  " << endl;
}
void test3() {
	int  a = 10;
	int b = 20;
	//a < b ? a : b;//三目运算符判断a与b 的大小，条件为真，返回前面那个值，条件为假，返回后面的值
	//左值与右值，在c语言中三目运算符是不可以做左值进行赋值的，但是在C++语言中，对于这一个三目运算符返回的是变量
	int c = 0;
	c= a < b ? a : b;
	((a < b )? a : b)= 50;
	cout << a <<" "<< b <<" "<< c << endl;
}
void test5() {
	int const a=10;//常量必须定义的时候就进行初始化
	int* p = (int *)&a;

}
int main() {
	//对比c语言必须在初始定义，C++可以随用随定义
	//c++对于全局定义的变量的检测增强了
	/*int a;
	int a = 10;//这两个对变量a的定义在c语言里面是可以编译运行的，但是在c++里面会被报错，重定义检测是C++语言所特有的
	*/
	//test();
	//test2();
	//test3();
	
	}
/*
const int* c;//内存区不可修改，地址区可修改
int* const c;//地址区不可修改，内存区可修改
const int* const e;//地址与内存区皆是不可修改
*/