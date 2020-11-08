#include<iostream>
using namespace std;
int  change_value(int p) {
	p = 30;
	return p;
}//这一个功能函数做不到换值，实参与形参进行转化了，但是实参并没有发生改变，改变的仅是形参
void change_value2(int * p) {
	*p = 40;
}
void change_value3(int& p) {
	p = 50;
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap2(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
struct student {
	int id;
	char name[60];
};
void print(struct student s) {
	cout << s.id << "  " << s.name << endl;

}//这里是对整个结构体进行拷贝，如果有多个数据需要拷贝的话，就会造成比较大的数据冗余
void print1(struct student *s) {
	cout << s->id << "  " << s->name << endl;

}
void print2(struct student& s) {
	cout << s.id << "  " << s.name << endl;
}
int main() {
	/*
	1、引用没有定义，它是一种关系型声明，声明它和原有某一变量（实体）的关系，
	故而引用类型与原类型一致，且不分配内存，与被引用的变量有相同的地址
	2、声明的时候必须初始化，一旦声明不可变更
	3、可对引用，再次引用，多次引用的结果，是某一变量具有多个别名
	4、&符号前面如果有数据类型的话，代表的是引用，其他皆为取地址符
	*/
	int a = 10, b = 20;
	int* p = &a;
	cout <<* p << "  " << endl;
	int& c = b;//int &表示一个引用数据类型，可以将c看作是b 的别名，直接对c赋值，将会作用在b上
	c = 50;
	c = a;//对引用进行更改，c从对b的引用改为对a的引用？c=a？
	//a = 30;
	cout << b<< "  " <<c << "  " << a << endl;//引用一经定义不可更改，所以结果得出来的数就是10  10  30
	//int& d;//引用一定要初始化
	int& d = c;//c的引用为b，现在再把d的引用改为c，可对引用再次引用
	cout << d << endl;
	cout << "--------------------------------" << endl;
	cout << "a=" << a << endl;
	change_value(a);
	cout << "a=" << a << endl;
	cout << "--------------------------------" << endl;
	cout << "a=" << a << endl;
	change_value2(&a);
	cout << "a=" << a << endl;
	cout << "--------------------------------" << endl;
	cout << "a=" << a << endl;
	change_value3(a);
	cout << "a=" << a << endl;
	int m = 1,n = 2;
	swap(&m, &n);
	cout << m << "  " << n << endl;
	swap2(m, n);
	cout << m << "  " << n << endl;
	student s1 = { 10,"zhangsan" };
	print(s1);
	print1(&s1);
	print2(s1);
	return 0;
}