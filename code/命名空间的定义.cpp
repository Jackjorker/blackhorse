#include<iostream>
//using namespace std;//��׼�����ռ�Ķ�������
namespace spaceA {
	int g_a;
	//using namespace spaceC;//�����ռ��ʹ�ñ���Ҫ�������ռ�֮�󣬼���һ�б������spaceC�Ķ���֮��
	namespace spaceB {
		//�����ռ����ѭ��Ƕ��
		struct teacher {
			int id;
			char name[60];
		};
	}
	namespace spaceC {
		//�����ռ����ѭ��Ƕ��
		struct teacher {
			int id;
			char name[60];
		};
	}
	using namespace spaceC;
}
#if(0)
//�����ռ䶨���������ʽ
using namespace std;
ʹ�þֲ�������std::��������
ʹ��ȫ�ֱ�������main����֮ǰ��������Ҫʹ�õ������ռ�ı�����using spaceA::g_a;
#endif//һ��ע�ͷ���
int main() {
	spaceA::g_a=10;
	spaceA::spaceB::teacher t1;
	t1.id = 20;
	using namespace spaceA;
	teacher t2;//��һ��teacher������spaceC�����ռ��
	t2.id = 30;
	std::cout << t1.id <<" "<<t2.id<< std::endl;
	return 0;
}