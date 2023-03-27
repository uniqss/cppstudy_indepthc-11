#include <iostream>
using std::cout;
using std::endl;

class Foo {
   public:
    Foo(int) {}

   private:
    Foo(const Foo&);
};

int main(void) {
    Foo a1(123);

    // Foo a2 = a1;  //error C2248: ��Foo::Foo��: �޷����� private ��Ա(�ڡ�Foo����������)
    // Foo a2(a1); // error as above

    Foo a3 = {123};
    Foo a4{123};

    // assign ok.
    a4 = a1;

    int a5 = {3};
    int a6{3};

    cout << "���������ʹ�ã������๹�캯�������б���г�ʼ����ʹ��" << endl;

    system("pause");
    return 0;
}