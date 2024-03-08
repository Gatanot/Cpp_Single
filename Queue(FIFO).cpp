#include <set>
#include <iterator>
template <typename FirstType>
class MyBag
{
private:
    std::set<FirstType> MainBag;
    void initialize(int number);

public:
    MyBag();
    MyBag(int number);
    void add(FirstType item);
    bool IsEmpty(void);
    int size(void);
};

template <typename FirstType>
void MyBag<FirstType>::initialize(int number)
{
    MainBag.clear();
    for (int i = 0; i < number; i++)
    {
        MainBag.insert(i);
    }
    /*auto itr = MainBag.begin();
    for (itr = MainBag.begin(); itr != MainBag.end(); ++itr)
    {
        std::cout << (*itr) << std::endl;
    }
    */
}

template <typename FirstType>
MyBag<FirstType>::MyBag()
{
    initialize(0);
}

template <typename FirstType>
MyBag<FirstType>::MyBag(int number)
{
    initialize(number);
}

template <typename FirstType>
void MyBag<FirstType>::add(FirstType item)
{

    MainBag.insert(item);
}

template <typename FirstType>
bool MyBag<FirstType>::IsEmpty(void)
{
    if (MainBag.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename FirstType>
int MyBag<FirstType>::size(void)
{
    return MainBag.size();
}
