#include <iostream>
#include <functional>
using std::cout;
using std::endl;

void output(int x, int y) {
    std::cout << x << " " << y << std::endl;
}

int main(void) {
    std::bind(output, 1, 2)();
    {
        // ����д������һ�㣬��ͬ
        std::function<void()> func = std::bind(output, 1, 2);
        func();
        cout << endl;
    }
    std::bind(output, std::placeholders::_1, 2)(1);
    {
        std::function<void(int)> func = std::bind(output, std::placeholders::_1, 2);
        func(1);
        cout << endl;
    }
    std::bind(output, 2, std::placeholders::_1)(1);
    {
        std::function<void(int)> func = std::bind(output, 2, std::placeholders::_1);
        func(1);
        cout << endl;
    }

    // std::bind(output, 2, std::placeholders::_2)(1);  //error:����ʱû�еڶ�������

    std::bind(output, 2, std::placeholders::_2)(1, 2);  //��� 2 2   ����ʱ��һ���������̵���
    {
        std::function<void(int, int)> func = std::bind(output, 1024, std::placeholders::_2);
        // ��һ��������㴫ɶ�����ᱻ�Ե�
        func(1, 2);
        func(2048, 2);
        cout << endl;
    }

    std::bind(output, std::placeholders::_1, std::placeholders::_2)(1, 2);  //��� 1 2
    {
        // �й��о�
        std::function<void(int, int)> func = std::bind(output, std::placeholders::_1, std::placeholders::_2);
        func(1, 2);
        cout << endl;
    }
    std::bind(output, std::placeholders::_2, std::placeholders::_1)(1, 2);  //��� 2 1
    {
        // �����Ե��� std::placeholders::��˳�����ߵ�����˳��
        std::function<void(int, int)> func = std::bind(output, std::placeholders::_2, std::placeholders::_1);
        func(1, 2);
        cout << endl;
    }
    {
        // �����ܵߵ������ܸ��ã��е��� fmtlib {1} {1}���÷���  ������ʱ���2������Ҳ�Ǳ�������
        std::function<void(int, int)> func = std::bind(output, std::placeholders::_1, std::placeholders::_1);
        func(1, 2);
        cout << endl;
    }

    cout << "std::bindʹ����placeholders�ĸ߼��÷�ʾ��" << endl;

    system("pause");
    return 0;
}