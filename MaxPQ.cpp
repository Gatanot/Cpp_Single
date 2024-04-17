#include<iostream>

template<typename FirstType>
class MaxPQ
{
private:
    int limit=0;
    int maxindex=0;
    FirstType* data=nullptr;
public:
    MaxPQ(){
        limit=0;
        int maxindex=0;
        data=nullptr;
    }
    MaxPQ(int max){
        limit=max;
        int maxindex=0;
        data = new FirstType[limit];
    }
    MaxPQ(FirstType[] array, int len){
        limit=len;
        data=new FirstType[limit];
        for(int i=0;i<len;i++){
            data[i]=array[i];
        }
        int maxindex=len-1;
    }
    void insert(FirstType value){
        if (maxindex==len-1)
        {
            /* code */
        }
        
    }
    FirstType max();
    FirstType delMax();
    bool isEmpty();
    int size()
    ~MaxPQ();
};

int main(){

    return 0;
}