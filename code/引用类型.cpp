#include<iostream>
using namespace std;
int  change_value(int p) {
	p = 30;
	return p;
}//��һ�����ܺ�����������ֵ��ʵ�����βν���ת���ˣ�����ʵ�β�û�з����ı䣬�ı�Ľ����β�
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

}//�����Ƕ������ṹ����п���������ж��������Ҫ�����Ļ����ͻ���ɱȽϴ����������
void print1(struct student *s) {
	cout << s->id << "  " << s->name << endl;

}
void print2(struct student& s) {
	cout << s.id << "  " << s.name << endl;
}
int main() {
	/*
	1������û�ж��壬����һ�ֹ�ϵ����������������ԭ��ĳһ������ʵ�壩�Ĺ�ϵ��
	�ʶ�����������ԭ����һ�£��Ҳ������ڴ棬�뱻���õı�������ͬ�ĵ�ַ
	2��������ʱ������ʼ����һ���������ɱ��
	3���ɶ����ã��ٴ����ã�������õĽ������ĳһ�������ж������
	4��&����ǰ��������������͵Ļ�������������ã�������Ϊȡ��ַ��
	*/
	int a = 10, b = 20;
	int* p = &a;
	cout <<* p << "  " << endl;
	int& c = b;//int &��ʾһ�������������ͣ����Խ�c������b �ı�����ֱ�Ӷ�c��ֵ������������b��
	c = 50;
	c = a;//�����ý��и��ģ�c�Ӷ�b�����ø�Ϊ��a�����ã�c=a��
	//a = 30;
	cout << b<< "  " <<c << "  " << a << endl;//����һ�����岻�ɸ��ģ����Խ���ó�����������10  10  30
	//int& d;//����һ��Ҫ��ʼ��
	int& d = c;//c������Ϊb�������ٰ�d�����ø�Ϊc���ɶ������ٴ�����
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