
#include <iostream>
#include<string>
#define Max 1000

using namespace std;

struct Person {//联系人结构体
	string m_Name;//姓名
	int m_Sex;//性别，1为男2为女
	int m_Age;//年龄
	string m_Phone;//联系方式
	string m_Addr;//家庭住址
};

struct Addressbooks {//通讯录结构体
	struct Person personarray[Max];//联系人结构体数组
	int m_size;//通讯录所存储的联系人数量
};

void addPerson(Addressbooks &a) {
	if (a.m_size == Max)
		cout << "通讯录已满，无法添加联系人" << endl;
	else {//添加具体的联系人
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		a.personarray[a.m_size].m_Name = name;
		int sex;
		cout << "请输入性别：" << endl;
		cout << "输入1为男，2为女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				a.personarray[a.m_size].m_Sex = sex; 
				break;
			}
			 else cout << "输入有误，请重新输入性别" << endl;
		}
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		a.personarray[a.m_size].m_Age = age;
		string phone;
		cout << "请输入联系方式：" << endl;
		cin >> phone;
		a.personarray[a.m_size].m_Phone = phone;
		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		a.personarray[a.m_size].m_Addr = address;
		a.m_size++;
		cout << "添加联系人成功" << endl;
	}
	system("pause");
	system("cls");
}

//显示所有的联系人
void showPerson(Addressbooks& a) {
	//判断通讯录是否为空，如果为空则报错，如果不为空则显示所有的通讯录联系人
	if (a.m_size == 0)cout << "通讯录为空，不存在联系人，无法显示" << endl;
	else {
		for (int i = 0; i < a.m_size; i++) {
			cout << "姓名为：" << a.personarray[i].m_Name << "\t";
			cout << "性别为：" << (a.personarray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄为：" << a.personarray[i].m_Age << "\t";
			cout << "联系方式为：" << a.personarray[i].m_Phone << "\t";
			cout << "家庭住址为：" << a.personarray[i].m_Addr << "\t";
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks& a, string name) {
	for (int i = 0; i < a.m_size; i++) {
		//找到该联系人的在数组中的位置，并返回
		if (a.personarray[i].m_Name == name)
			return i;
		else return -1;//如果没有找到，则返回失败

	}
}

void delPerson(Addressbooks& a) {
	cout << "请输入你需要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(a, name);
	if (ret != -1) {
		//查找到人，进行数组删除操作
		for (int i = ret; i < a.m_size; i++) {
			//数据前移
			a.personarray[i] = a.personarray[i + 1];
		}
		a.m_size--;//更新联系人的人数
		cout << "删除联系人成功" << endl;
	}
	else cout << "查无此人" << endl;
	system("pause");
	system("cls");
}

void findPerson(Addressbooks& a) {
	cout << "请输入你需要查找的姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(a, name);
	if (ret != -1) {
		cout << "姓名为：" << a.personarray[ret].m_Name << "\t";
		cout << "性别为：" << a.personarray[ret].m_Sex << "\t";
		cout << "年龄为：" << a.personarray[ret].m_Age << "\t";
		cout << "联系方式为：" << a.personarray[ret].m_Phone << "\t";
		cout << "家庭住址为：" << a.personarray[ret].m_Addr << "\t";
	}
	else cout << "查无此人" << endl;
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks& a) {
	cout << "请输入要进行修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(a, name);
	if (ret != -1) {
		cout << "重新修改信息，需要用户输入联系人信息"<< endl;
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		a.personarray[ret].m_Name = name;
		int sex;
		cout << "请输入性别：" << endl;
		cout << "输入1为男，2为女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				a.personarray[ret].m_Sex = sex;
				break;
			}
			else cout << "输入有误，请重新输入性别" << endl;
		}
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		a.personarray[ret].m_Age = age;
		string phone;
		cout << "请输入联系方式：" << endl;
		cin >> phone;
		a.personarray[ret].m_Phone = phone;
		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		a.personarray[ret].m_Addr = address;
	}
	else cout << "查无此人，无法进行修改" << endl;
	system("pause");
	system("cls");
}

void emptyAddressbooks(Addressbooks& a) {
	a.m_size = 0;//逻辑上对通讯录进行置空
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

void showmenu() {
	//菜单功能
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
}  

int main() {
	int select=0;//创建一个选择的变量
	Addressbooks abs;//创建一个通讯录结构体变量
	abs.m_size = 0;
	while(true){
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(abs);
			break;
		case 2://显示联系人
			showPerson(abs);
			break; 
		case 3://删除联系人
			delPerson(abs);
			break;
		case 4://查找联系人
			findPerson(abs);
			break;
		case 5://修改联系人
			modifyPerson(abs);
			break;
		case 6://清空联系人
			emptyAddressbooks(abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
