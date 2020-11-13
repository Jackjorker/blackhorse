#include<iostream>
using namespace std;
struct fraction {
	int member;
	int den;
	void  print() {
		cout << "(" << member << "," << den << ")" << endl;
	}
	
};
fraction sum(struct fraction &f1, struct fraction& f2) {
	fraction sum;
	if (f1.den == f2.den) {
		sum .member= f1.member + f2.member;
		sum.den = f1.den;
	}
	else {
		sum.member = f1.member * f2.den + f2.member * f1.den; 
		sum.den = f1.den * f2.den;
	}
	sum.print();
	return sum;
}
fraction mul(struct fraction& f1, struct fraction& f2) {
	fraction mul;
	mul.member = f1.member * f2.member;
	mul.den = f1.den * f2.den;
	mul.print();
	return mul;
}

void ini(struct fraction& f,int a,int b) {
	f.member = a;
	f.den = b;
}
int main() {
	struct fraction f1, f2;
	ini(f1, 3, 4);
	ini(f2, 5, 6);
	sum(f1, f2);
	mul(f1, f2);
	return 0;
}