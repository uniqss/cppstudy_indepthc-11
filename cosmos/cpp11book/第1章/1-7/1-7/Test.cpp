#include <iostream>
using std::cout;
using std::endl;

// ���3��ô�������е���ࣿ�����Ǵ����
int i_arr[3] = {1, 2, 3};  //��ͨ����

// �����Ǵ��
int i_arr2[] = {1, 2, 3};  //��ͨ����

struct A {
    int x;
    struct B {
        int i;
        int j;
    } b;
} a = {1, {2, 3}};  // POD����

int i = 0;

class Foo {
   public:
    Foo(int) {}
} foo = 123;

int j(0);

Foo bar(123);

int main(void) {
    cout << "�����ֱ�Ӹ�ֵ���÷�չʾ����POD��Ƕ�׻��ߴ��ι��캯����" << endl;
    system("pause");
    return 0;
}