#include<iostream>
using namespace std;

struct Person {
	int m_age;
};

void allocate(Person** p) {//**p�����Person����    *p�����ָ��     pָ���ָ��


	*p = (Person *)malloc(sizeof(Person));
	(*p)->m_age = 100;
}

void test() {
	Person* p = NULL;
	allocate(&p);
	cout << "p������" << p->m_age << endl;
}

void allocateByref(Person*& p) {//ָ��������ʹ�õ�ʱ���Ҫ��˫ָ��Ҫ����ܶ�
	p =(Person *) malloc(sizeof(Person));
	p->m_age = 1000;
}

void test2() {
	Person* p = NULL;
	allocateByref(p);
	cout << "p������" << p->m_age << endl;
}

int main() {
	test();
	test2();
	return 0;
}