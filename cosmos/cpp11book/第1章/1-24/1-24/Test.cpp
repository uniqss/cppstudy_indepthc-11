#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;

class CountEven {
    int& count_;

   public:
    CountEven(int& count) : count_(count) {}

    // ע��������������������һ�𣬵�һ���������� operator()��һ���֣��ڶ������ǲ���
    void operator()(int val) {
        if (!(val & 1))  // val % 2 == 0
        {
            ++count_;
        }
    }
};

// ���ʾ��չʾ�� std::for_each �Կɵ��ö����ʹ�÷�ʽ�����ÿ�����󶼵��ÿɵ��ö����operator()
int main(void) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    int even_count = 0;

    std::for_each(v.begin(), v.end(), CountEven(even_count));
    std::cout << "The number of even is " << even_count << std::endl;

    cout << "std::for_each �Կɵ��ö����ʹ�÷�ʽ�����ÿ�����󶼵��ÿɵ��ö����operator()" << endl;

    system("pause");
    return 0;
}