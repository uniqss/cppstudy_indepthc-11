#include <iostream>
#include <vector>
using std::cout;
using std::endl;

class MyString {
   private:
    char* m_data;
    size_t m_len;
    void copy_data(const char* s) {
        cout << "#### new called s:" << s << endl;
        m_data = new char[m_len + 1];
        cout << "#### memcpy called s:" << s << endl;
        memcpy(m_data, s, m_len);
        m_data[m_len] = '\0';
    }

   public:
    MyString() {
        cout << "MyString ctor" << endl;
        m_data = NULL;
        m_len = 0;
    }

    MyString(const char* p) {
        cout << "MyString ctor2" << endl;
        m_len = strlen(p);
        copy_data(p);
    }

    MyString(const MyString& str) {
        m_len = str.m_len;
        copy_data(str.m_data);
        std::cout << "Copy Constructor is called! source:" << str.m_data << std::endl;
    }

    MyString& operator=(const MyString& str) {
        if (this != &str) {
            m_len = str.m_len;
            copy_data(str.m_data);
        }
        std::cout << "Copy Assignment is called! source:" << str.m_data << std::endl;
        return *this;
    }

    virtual ~MyString() {
        cout << "MyString dtor" << endl;
        if (m_data != NULL) {
            cout << "#### delete called m_data:" << m_data << endl;
            delete[] m_data;
        }
    }
};

int main(void) {
    // ��Ӧ�þ���c++��ڸ������ʱ�������������
    MyString a;
    a = MyString("Hello");

    std::vector<MyString> vec;
    vec.push_back(MyString("World"));

    cout << "���ʾ��չʾ����c++11������ǰ��û��std::moveʱ��c++��ڸ������ʱ�������������" << endl;

    system("pause");
    return 0;
}