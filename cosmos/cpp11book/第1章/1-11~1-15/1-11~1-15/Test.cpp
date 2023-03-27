#include "Range.hpp"

#include <iostream>

using namespace std;
using namespace detail_range;

void some_func1(auto param) {
    cout << __LINE__ << __func__ << endl;
    for (auto it : param) {
        cout << it << " ";
    }
    cout << endl;
}

void TestRange() {
    cout << "Range(15):";
    for (int i : Range(15))  //[0,15)
    {
        cout << " " << i;
    }
    cout << endl;

    cout << "Range(2,6):";
    for (auto i : Range(2, 6))  //[2,6)
    {
        cout << " " << i;
    }
    cout << endl;

    cout << "Range(10.5, 15.5):";
    for (auto i : Range(10.5, 15.5))  //[10.5,15.5),����Ϊ1
    {
        cout << " " << i;
    }
    cout << endl;

    cout << "Range(35,27,-1):";
    for (int i : Range(35, 27, -1))  //(27, 35]������Ϊ-1
    {
        cout << " " << i;
    }
    cout << endl;

    cout << "Range(2,8,0.5):";
    for (auto i : Range(2, 8, 0.5))  //[2,8),����Ϊ0.5
    {
        cout << " " << i;
    }
    cout << endl;

    cout << "Range(8,7,-0.1):";
    for (auto i : Range(8, 7, -0.1))  //(7,8]������Ϊ-0.1
    {
        cout << " " << i;
    }
    cout << endl;

    cout << "Range('a', 'z'):";
    for (auto i : Range('a', 'z'))  //['a','z'),����Ϊ1
    {
        cout << " " << i;
    }
    cout << endl;

    some_func1(Range(10));
}


int main(void) {
    TestRange();

    cout << "Range��ʵ�ּ�ʹ��" << endl;

    system("pause");
    return 0;
}