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
	//���о����õ�ʱ����Խ����ÿ����ǳ�ָ��
	//������ʹ�����õ�ʱ��Ͳ��ܿ�����ָ���ˣ�ֱ�ӽ����ÿ����Ǳ����ı�����ʹ��
}
int getA1() {
	int a = 10;
	return a;
}//�������ʹ���˿��������������Լ����ͽṹ����˵�ܲ��Ѻã���ɺܴ�Ŀռ��˷�
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
}//����aֵ�൱��int &temp=a;���ͺ�����a�ı���
int& getA4() {
	static int a = 10;
	return a;
}
int main() {
	//������ռ�õĿռ��С��ָ����һ����
	cout << "sizeof(typeA)" << sizeof(typeA) << endl;
	cout << "sizeof(typeB)" << sizeof(typeB) << endl;
	//int& a;//���þͺ���const int һ��������Ҫ��ʼ����
	int a = 0;
	int& re=a;
	int* const p=&a;//��ָ����ȡ��ַ
	a = getA1();
	re = getA2(&a);
	int main_a;
	main_a = getA3();
	cout << "main_a" << main_a << endl;
	//��ֹ����
	//int& main_a_re = getA3();
	//cout << "main_a_re" << main_a_re<< endl;//getA3()������a��ֵ�ǻᱻ�ͷŵģ������ڵڶ��ε��õ�ʱ��ͳ�����
	//cout << "main_a_re" << main_a_re << endl;//��������Ҳ����˵�����ñ���ȥ�������õĺ�������ֵ�ǲ���ȫ��
	int &main_a_re = getA4();
	cout << "main_a_re" << main_a_re << endl;
	cout << "main_a_re" << main_a_re << endl;
	getA4() = 1000;//��������������ķ���ֵ�Ļ������Ե��Ⱥŵ���ֵ
	return 0;
}