#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*template <typename FirstType, typename SecondType>
struct MyPAir
{
    FirstType first;
    SecondType second;
};
// 注意：即便是int这样的基元类型也适用于接下来的内容，实际上，在这两段中，typename与class几乎是等价的
template <class FirstType, class SecondType>
struct MySecondPAir
{
    FirstType first;
    SecondType second;
};*/
template <typename FirstType, typename SecondType>
class MyPAir
{
private:
    FirstType first;
    SecondType second;

public:
    FirstType getFirst();
    void setFirst(FirstType newValue);

    SecondType getSecond();
    void setSecond(SecondType newValue);

    void swap(MyPAir&other);
};

template <typename FirstType, typename SecondType>
FirstType MyPAir<FirstType, SecondType>::getFirst()
{
    return first;
}
template <typename FirstType, typename SecondType>
void MyPAir<FirstType, SecondType>::setFirst(FirstType newValue)
{
    first = newValue;
}
template <typename FirstType, typename SecondType>
SecondType MyPAir<FirstType, SecondType>::getSecond()
{
    return second;
}
template <typename FirstType, typename SecondType>
void MyPAir<FirstType, SecondType>::setSecond(SecondType newValue)
{
    second = newValue;
}
template <typename FirstType, typename SecondType>
void MyPAir<FirstType,SecondType>::swap(MyPAir& other){

}
int main(void)
{
    /*MyPAir<int, string> one;
    one.first = 137;
    one.second = "hello,world";
    cout << one.first << one.second << endl;*/
    return 0;
}