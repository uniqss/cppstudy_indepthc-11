#include <iostream>
using std::cout;
using std::endl;

void func(void) {
    //...
    cout << __LINE__ << __func__ << endl;
}

struct Foo {
    void operator()(void) {
        //...
        cout << __LINE__ << __func__ << endl;
    }
};

struct Bar {
    using fr_t = void (*)(void);

    static void func(void) {
        //...
        cout << __LINE__ << __func__ << endl;
    }

    // ��ʽת�����˾�̬����ָ�� Bar::func
    operator fr_t(void) {
        cout << __LINE__ << __func__ << " implicit conversion." << endl;
        return func;
    }
};

struct A {
    int a_;

    void mem_func(void) {
        //...
        cout << __LINE__ << __func__ << endl;
    }
};

int main(void) {
    void (*func_ptr)(void) = &func;  //����ָ��
    func_ptr();

    Foo foo;  //�º���
    foo();

    Bar bar;  //�ɱ�ת��Ϊ����ָ��������
    bar();

    void (A::*mem_func_ptr)(void) = &A::mem_func;  //���Ա����ָ��
    int A::*mem_obj_ptr = &A::a_;                  //���Աָ��

    A aa;
    (aa.*mem_func_ptr)();
    aa.*mem_obj_ptr = 123;

    cout << "����ָ������÷����º��������÷����ɱ�ת��Ϊ����ָ��������Ļ����÷������Ա����ָ�����Աָ��Ļ����÷�"
         << endl;

    system("pause");
    return 0;
}