#include <iostream>
using namespace std;
struct student {
	int id;
	int socre1, socre2, socre3;
	char name[10];
	//int average= (socre1 + socre2 + socre3) / 3;//δ��ʼ����û�а취������ֵ�����
};
void getStu(struct student& s) {
	cout << "����������ѧ���������Ϣ" << endl;
	cin >> s.id >> s.name >> s.socre1 >> s.socre2 >> s.socre3 ;
	//cout << s.id << " " << s.name << " " << s.socre1 << " " << s.socre2 << " " << s.socre3 << endl;
}
void printStu(struct student& s) {
	cout << s.id << " " << s.name << " " << s.socre1 << " " << s.socre2 << " " << s.socre3 << endl;
}
int average(struct student &s) {
	int average = (s.socre1 + s.socre2 + s.socre3) / 3;
	//cout << "ѧ�����ſγ̵�ƽ���ɼ���" <<  average<< endl;
	return average;
}

int main() {
	struct student s[10];
	struct student max ;
	int a[10];
	int m;
	for (int i = 0; i < 10; i++) {
		getStu(s[i]);
		max = s[0];
		m = average(max);
		a[i] = average(s[i]);
		if (m<a[i])
			max = s[i];
	}
	printStu(max);
	m = average(max);
		cout << "ƽ���ɼ���" << m << endl;
}