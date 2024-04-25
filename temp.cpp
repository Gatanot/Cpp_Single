#include<iostream>
using namespace std;
void display();
bool check();
int main(){
    while(1){
        display();
        if (check())
        {
            return 0;
        }else{
            continue;;
        }
        
    }
}
void display(){
    cout<<"Hello World"<<endl;
}
bool check(){
    int n;
    cin>>n;
    return n%2==1;
}