#include <iostream>

using std::cout;
using std::endl;

class Foo {
   public:
    static int get(void) { return 0; }
};

class Bar {
   public:
    static const char* get(void) { return "0"; }
};

template <class A>
void func(void) {
    // ģ�庯����ʹ�� auto ��ȡ��ľ�̬��Ա�����ķ�������
    auto val = A::get();

    //...
    cout << "val:" << val << " type:" << typeid(val).name() << endl;
}

int main(void) {
    func<Foo>();
    func<Bar>();

    cout << "ģ�庯����ʹ�� auto ��ȡ��ľ�̬��Ա�����ķ������� ���÷�չʾ" << endl;

    system("pause");
    return 0;
}