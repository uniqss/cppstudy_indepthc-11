#include <iostream>
#include <vector>
using std::cout;
using std::endl;

template <class ContainerT>
class Foo {
#if 0
    typename ContainerT::iterator it_;  //���Ͷ������������
                                        //������ const ContainerT ��ͨ��������ʹ������it_���壺
                                        // decltype(std::declval<ContainerT>().begin()) it_;
#else
    // ����ֻ��ʾ����ʵ����Ŀ�в�Ҫ�����д�ȡIterator����Ϊc++��������Iterator���ǻ�ʧЧ��
    decltype(std::declval<ContainerT>().begin()) it_;
#endif
   public:
    void func(ContainerT& container) {
        // ʵ����Ӧ���������ã��ǿ��Եģ���Ҫ�洢���У�����������ʧ��������Щ���붼�Ƿ��̰߳�ȫ��
        it_ = container.begin();
    }

    //...
};

int main(void) {
#if 1
    typedef const std::vector<int> container_t;  //������const���ԣ�����ᱨһ��Ѵ�����Ϣ
#else
    typedef std::vector<int> container_t;  //������const���ԣ�����ᱨһ��Ѵ�����Ϣ
#endif
    container_t arr;

    Foo<container_t> foo;
    foo.func(arr);

    cout << "decltype���declval��ȡ����Iterator���͵��÷�չʾ,declval�ܻ�ȡ����const����Ϣ" << endl;

    system("pause");
    return 0;
}
