#include <iostream>

int count = 0;

using namespace std;

void display_message(const char ch);
void display_message(const string &str);
void display_message(const string &str, int time);
template <typename elemtype>
void display_message(const string &str, const elemtype &vec);

int main(void)
{
    display_message('*');
    display_message("Nibal");
    display_message("Paul", 6);
    display_message("Alice", 23);
    display_message("Boy", 23.46);
    display_message("Carri", 'd');
    display_message("Daci", "sda");
}

void display_message(char ch)
{
    cout << "standard message " << ch << endl;
    count++;
    cout << "same_name_function has been called "
         << count
         << " times" << endl;
}
void display_message(const string &str)
{
    cout << "hello "
         << str
         << ", welcome to log in" << endl;
    count++;
    cout << "same_name_function has been called "
         << count
         << " times" << endl;
}
void display_message(const string &str, int time)
{
    cout << "hello "
         << str
         << ", welcome to log in. "
         << "you've loged "
         << time
         << " times today" << endl;
    count++;
    cout << "same_name_function has been called "
         << count
         << " times" << endl;
}
template <typename elemtype>
void display_message(const string &str, const elemtype &vec)
{
    cout << "hello "
         << str
         << ", welcome to log in" << endl;
    cout << "nice "
         << vec << endl;
    count++;
    cout << "same_name_function has been called "
         << count
         << " times" << endl;
}