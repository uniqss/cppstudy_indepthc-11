#include <iostream>
using std::cout;
using std::endl;

class Foo {
   public:
    static const int Number = 0;
    int x;
};

int main(void) {
    int n = 0;
    volatile const int &x = n;

    decltype(n) a = n;  // a -> int
    cout << typeid(a).name() << endl;
    decltype(x) b = n;  // b -> const volatile int &
    cout << typeid(b).name() << endl;

    decltype(Foo::Number) c = 0;  // c -> const int
    cout << typeid(c).name() << endl;

    Foo foo;
    decltype(foo.x) d = 1024;  // d -> int
    cout << typeid(d).name() << endl;

    // Ϊʲô��ӡ����һ����������int������
    // ��c��һ��,,,������const int��Ϊʲô��ӡ������int???
    // c = 2048; // �ᱨ��
    // ����һ�£�c++�� type_info �ǻ�Ե� const volatile �ģ�ֻ�д�ָ��ʱ�Ż����ֳ��� �μ���������ӣ�
    // https://stackoverflow.com/questions/10007596/type-info-doesnt-account-for-cv-qualifiers-is-this-right

    cout << "decltype���÷�չʾ typeid���ܻ�ȡconst volatile������չʾ(�ڶ������л�ȡcv�ķ�ʽ)" << endl;

    system("pause");
    return 0;
}