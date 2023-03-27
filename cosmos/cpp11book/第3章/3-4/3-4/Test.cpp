#include <iostream>
using std::cout;
using std::endl;

// ��ͳд��ȷʵ�Ƚ϶��ģ�һ��һ��ģ�����Ҫ֧�ֵĲ���Խ�࣬Խ����
template <typename T>
T* Instance() {
    return new T();
}

template <typename T, typename T0>
T* Instance(T0 arg0) {
    return new T(arg0);
}

template <typename T, typename T0, typename T1>
T* Instance(T0 arg0, T1 arg1) {
    return new T(arg0, arg1);
}

template <typename T, typename T0, typename T1, typename T2>
T* Instance(T0 arg0, T1 arg1, T2 arg2) {
    return new T(arg0, arg1, arg2);
}

template <typename T, typename T0, typename T1, typename T2, typename T3>
T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3) {
    return new T(arg0, arg1, arg2, arg3);
}

template <typename T, typename T0, typename T1, typename T2, typename T3, typename T4>
T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4) {
    return new T(arg0, arg1, arg2, arg3, arg4);
}

struct A {
    A(int) {}
};

struct B {
    B(int, double) {}
};

struct C {
    C(){}
};

// ��Լд��
//template <typename T>
//T* MyInstance() {
//    return new T();
//}
template <typename T, typename... Args>
T* MyInstance(Args&&... args) {
    return new T(std::forward<Args&&>(args)...);
}

template<class T>
class TTT {
    template<typename T1>
    void con() {

    }
};

int main(void) {
    A* pa = Instance<A>(1);
    B* pb = Instance<B>(1, 2);
    C* pc = MyInstance<C>();

    A* mya = MyInstance<A>(1);
    B* myb = MyInstance<B>(1, 2);

    cout << "��Ĺ�������ͳ��ģ�����д��������ת��д���ĶԱ�" << endl;

    delete pa;
    delete pb;
    delete mya;
    delete myb;

    system("pause");
    return 0;
}