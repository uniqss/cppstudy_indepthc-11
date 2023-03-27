#include <iostream>
using std::cout;
using std::endl;

template <typename T>
void Print(T t) {
	std::cout << t << std::endl;
}

template <typename T1, typename T2>
void Print(T1 t1, T2 t2) {
	std::cout << t1 << t2 << std::endl;
}

template <typename T1, typename T2, typename T3>
void Print(T1 t1, T2 t2, T3 t3) {
	std::cout << t1 << t2 << t3 << std::endl;
}

template <typename T1, typename T2, typename T3, typename T4>
void Print(T1 t1, T2 t2, T3 t3, T4 t4) {
	std::cout << t1 << t2 << t3 << t4 << std::endl;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
void Print(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5) {
	std::cout << t1 << t2 << t3 << t4 << t5 << std::endl;
}

// ��Լд����֧�����޲���
void MyPrint() {
	cout << endl;
}
template <typename T, typename... Args>
void MyPrint(T t, Args&&... args) {
	cout << t << " ";
	MyPrint(std::forward<Args&&>(args)...);
}

// ����¯�����д����ע�ⴧĦ������ţ������㣬ǰ��С���ţ�����С���ŵ��÷�
template<typename... Args>
void MyPrint2(Args&&... args) {
	((cout << args << " " << "|"), ...);
	cout << endl;
}

template<typename... Args>
int sum(Args&&... args) {
	return (args + ... + (100 * 2));
	//return (args + ... + 100 * 2);
	//return (args + ... + 100 + 2);
}

int main(void) {
	Print(1);
	Print(1, 2);
	Print(1, 2, 3);
	Print(1, 2, 3, 4);
	Print(1, 2, 3, 4, 5);

	{
		MyPrint(1);
		MyPrint(1, "asdf");
		MyPrint(1, 2);
		MyPrint(1, 2, "asdf", "jkl", 345, "hello");
	}

	{
		MyPrint2();
		MyPrint2(1024);
		MyPrint2(1024, "hello");
	}

	MyPrint(sum(1, 2, 3, 4, 5));

	cout << "����չʾ��û��c++11�Ŀɱ�ģ�����֮ǰ���ж��ٸ�������Ҫ���ض��ٷݵ�����д���������˼�Լд��" << endl;

	system("pause");
	return 0;
}