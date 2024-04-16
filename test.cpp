#include <iostream>
#include <string>

template <typename Key, typename Value>
class ST
{
private:
    Key *KeyData;
    Value *ValueData;
    int limit;
    int capacity;

public:
    ST() : KeyData(nullptr), ValueData(nullptr), limit(0), capacity(0) {}
    ~ST()
    {
        delete KeyData;
        delete ValueData;
    }
    void put(Key key, Value value)
    {
        for (int i = 0; i < limit; i++)
        {
            if (KeyData[i] == key)
            {
                ValueData[i] = value;

                return;
            }
        }

        limit++;
        if (capacity < limit)
        {
            if (capacity)
            {
                capacity *= 2;
            }
            else
            {
                capacity++;
            }
            Key *newkeys = new Key[capacity];
            for (int i = 0; i < limit - 1; i++)
            {
                newkeys[i] = KeyData[i];
            }
            delete KeyData;
            KeyData = newkeys;
            Value *newvalues = new Value[capacity];
            for (int i = 0; i < limit - 1; i++)
            {
                newvalues[i] = ValueData[i];
            }
            delete ValueData;
            ValueData = newvalues;
        }
        KeyData[limit - 1] = key;
        ValueData[limit - 1] = value;

        return;
    }
    Value get(Key key)
    {
        for (int i = 0; i < limit; i++)
        {
            if (key == KeyData[i])
            {
                return ValueData[i];
            }
        }
    }
    bool contains(Key key)
    {
        for (int i = 0; i < limit; i++)
        {
            if (key == KeyData[i])
            {
                return true;
            }
        }
        return false;
    }
    bool isEmpty()
    {
        return !limit;
    }
    int size()
    {
        return limit;
    }
    void keys()
    {
        for (int i = 0; i < limit; i++)
        {
            std::cout << "Key: " << KeyData[i] << ", with Value: " << ValueData[i] << std::endl;
        }
    }
};
int main()
{
    ST<int, std::string> myst;
    std::cout << myst.isEmpty() << std::endl;
    for (int i = 0; i < 10; i++)
    {
        myst.put(i, "abcd");
    }
    std::cout << myst.size() << std::endl;
    std::cout << myst.contains(90) << std::endl;
    myst.keys();

    return 0;
}