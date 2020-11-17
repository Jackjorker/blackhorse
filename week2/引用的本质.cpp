#include<iostream>
using namespace std;
struct typeA {
	int& a;
};
struct typeB {
	int *a;
};
void modify(int* const a) {
	*a = 300;
}
void modify2(int & a) {
	a = 300;
	//在研究引用的时候可以将引用看作是常指针
	//但是在使用引用的时候就不能看作是指针了，直接将引用看作是变量的别名来使用
}
int getA1() {
	int a = 10;
	return a;
}//这个函数使用了拷贝，对于数组以及大型结构体来说很不友好，造成很大的空间浪费
int  getA2(int * a) {
	
	*a = 10;
	return *a;
}
char * getmem(int nums) {
	char* p = NULL;
	p = (char*)malloc(nums);
	return p;
}
int&   getA3() {
	int a = 10;
	return a;
}//返回a值相当于int &temp=a;，就好像是a的别名
int& getA4() {
	static int a = 10;
	return a;
}
int main() {
	//引用所占用的空间大小和指针是一样的
	cout << "sizeof(typeA)" << sizeof(typeA) << endl;
	cout << "sizeof(typeB)" << sizeof(typeB) << endl;
	//int& a;//引用就好像const int 一样，是需要初始化的
	int a = 0;
	int& re=a;
	int* const p=&a;//常指针与取地址
	a = getA1();
	re = getA2(&a);
	int main_a;
	main_a = getA3();
	cout << "main_a" << main_a << endl;
	//禁止套娃
	//int& main_a_re = getA3();
	//cout << "main_a_re" << main_a_re<< endl;//getA3()函数中a的值是会被释放的，所以在第二次调用的时候就出现了
	//cout << "main_a_re" << main_a_re << endl;//乱码现象，也就是说用引用变量去接纳引用的函数返回值是不安全的
	int &main_a_re = getA4();
	cout << "main_a_re" << main_a_re << endl;
	cout << "main_a_re" << main_a_re << endl;
	getA4() = 1000;//引用如果当函数的返回值的话，可以当等号的左值
	return 0;
}