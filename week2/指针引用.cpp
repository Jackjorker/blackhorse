#include<iostream>
using namespace std;

struct Person {
	int m_age;
};

void allocate(Person** p) {//**p具体的Person对象    *p对象的指针     p指针的指针


	*p = (Person *)malloc(sizeof(Person));
	(*p)->m_age = 100;
}

void test() {
	Person* p = NULL;
	allocate(&p);
	cout << "p的年龄" << p->m_age << endl;
}

void allocateByref(Person*& p) {//指针引用在使用的时候就要比双指针要方便很多
	p =(Person *) malloc(sizeof(Person));
	p->m_age = 1000;
}

void test2() {
	Person* p = NULL;
	allocateByref(p);
	cout << "p的年龄" << p->m_age << endl;
}

int main() {
	test();
	test2();
	return 0;
}