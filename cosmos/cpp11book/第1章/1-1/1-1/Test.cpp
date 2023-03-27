#include <iostream>
using std::cout;
using std::endl;

class MyParam {
   public:
    MyParam(int p) : m_param(p) { cout << "MyParam ctor" << endl; }
    MyParam(const MyParam& mp) {
        cout << "MyParam copy ctor" << endl;
        this->m_param = mp.m_param;
    }
    MyParam& operator=(const MyParam& p) {
        cout << "MyParam assign ctor" << endl;
        if (this == &p) return *this;
        this->m_param = p.m_param;
        return *this;
    }
    MyParam(MyParam&& p) noexcept : m_param(p.m_param) {
        cout << "MyParam move ctor" << endl;
        p.m_param = 0;
    }
    ~MyParam() { cout << "MyParam dtor" << endl; }
    int m_param;
};

std::ostream& operator<<(std::ostream& os, const MyParam& p) {
    os << p.m_param << endl;
    return os;
}

// function����c++20��׼�ǿ���auto��
void func(auto a = 1);  // error:auto�������ں�������

// c++20�� auto �ں���������������Ѿ��ǳ�����������ģ��������Ƶ�
void func2(auto param) {
    cout << param << endl;
    cout << typeid(param).name() << endl;
}

// ���ﻹ���Ը��Ż�һ�㣬ʡȥһ�ο�������һ������
void func3(const auto& param) {
    cout << param << endl;
    cout << typeid(param).name() << endl;
}

// ������ֱ��move�����ˣ����´������Ҳ���ḳֵ����
void func4(auto&& param) {
    cout << param << endl;
    cout << typeid(param).name() << endl;
}

struct Foo {
    // auto var1_ = 0;  // error:auto�������ڷǾ�̬��Ա����
    static const auto var2_ = 0;
};

template <typename T>
struct Bar {};

int main(void) {
    int arr[10] = {0};
    auto aa = arr;  // OK: aa -> int *
    cout << typeid(aa).name() << endl;
    // auto rr[10] = arr;  // error:auto�޷���������
    Bar<int> bar;
    // Bar<auto> bb = bar;  // error:auto�޷��Ƶ���ģ�����
    auto bb2 = bar;
    cout << typeid(bb2).name() << endl;

    func2(1234);
    func2("asdf");
    std::string str = "hello world";
    func2(str);

    {
        MyParam mp(123);
        func2(mp);
    }

    cout << "================================" << endl << endl;
    {
        MyParam mp(456);
        func3(mp);
    }

    cout << "================================" << endl << endl;
    {
        MyParam mp(789);
        func4(mp);
    }

    cout << "auto�Ļ���ʹ�� �ƶ�������ʱ�������Ż�չʾ" << endl;

    system("pause");
    return 0;
}