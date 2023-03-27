#include <iostream>
#include <functional>
using std::cout;
using std::endl;

class A {
   public:
    int i_ = 0;

    void output(int x, int y) { std::cout << x << " " << y << std::endl; }
};

int main(void) {
    A a;
    // ע�� A::output ������һ��static�ĺ�������Ȼ����������
    std::function<void(int, int)> fr = std::bind(&A::output, &a, std::placeholders::_1, std::placeholders::_2);
    fr(1, 2);  //��� 1 2

    // vs2022�Ѿ���������
    // ����÷��õ����棬���԰���ĳ�Ա����Ҳ���һ��std::function
    std::function<int&(void)> fr_i = std::bind(&A::i_, &a);  // vs13��bug���󶨳�Ա����Ҫ����
    fr_i() = 123;

    {
        // ��һ���ֲ����������ǲ��еģ��������ҵ��÷����ԣ�����
        int test = 1024;
        // std::function<int&(void)> func = std::bind(&test, &test);
        // func() = 2024;
    }

    std::cout << a.i_ << std::endl;  //��� 123

    cout << "std::bind����ķǾ�̬��Ա�����ϵ��÷�ʾ������ĳ�Ա�ϵ��÷�ʾ��" << endl;

    system("pause");
    return 0;
}