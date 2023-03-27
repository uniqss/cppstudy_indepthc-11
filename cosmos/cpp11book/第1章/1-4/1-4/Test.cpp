#include <iostream>
using std::cout;
using std::endl;

class Foo {};

int& func_int_r(void);    //��ֵ��lvalue���ɼ����Ϊ��Ѱֵַ��
int&& func_int_rr(void);  // xֵ��xvalue����ֵ���ñ�����һ��xvalue��
int func_int(void);       //����ֵ��pvalue��

const int& func_cint_r(void);    //��ֵ
const int&& func_cint_rr(void);  // xֵ
const int func_cint(void);       //����ֵ

const Foo func_cfoo(void);  //����ֵ

int main(void) {
    int x = 0;

    // ע�������溯����ֻ�ж��壬û��ʵ���壬Ҳ����˵ decltype(func()) �ĵ��ã��ǲ���Ժ������е��õģ�ֻ��ץȡ���͡�
    decltype(func_int_r()) a1 = x;  // a1 -> int&
    x = 1024;
    ++a1;
    cout << x << endl;
    cout << a1 << endl;
    cout << typeid(a1).name() << endl;

    decltype(func_int_rr()) b1 = 0;  // b1 -> int&&
    decltype(func_int()) c1 = 0;     // c1 -> int

    decltype(func_cint_r()) a2 = x;  // a2 -> const int&
    x = 2048;
    cout << a2 << endl;
    cout << x << endl;
    // error
    //++a2;
    cout << typeid(a2).name() << endl;

    decltype(func_cint_rr()) b2 = 0;  // b2 -> const int&&
    decltype(func_cint()) c2 = 0;     // c2 -> int

    decltype(func_cfoo()) ff = Foo();  // ff -> Foo

    cout << "decltype��ȡ��������ֵ���͵��÷�չʾ��������Ҫʵ�ʵ��ú���������Ҫ����ʵ�ֲ��֣�ֻ��Ҫ����" << endl;

    system("pause");
    return 0;
}