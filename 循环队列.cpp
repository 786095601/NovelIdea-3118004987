#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAX=20;

template <typename Datatype>
class CircleQueue{
	private:
	Datatype data[MAX];
	int head,tail;
	public:
	CircleQueue(){head=tail=0;}
	~CircleQueue(){};
	void push();
	void pull();
	bool empty();
}; 

template <typename Datatype>
bool CircleQueue<Datatype>::empty(){
	 if(head==tail)
        return true;
    else
        return false;
}

template <typename Datatype>
void CircleQueue<Datatype>::push(){
	Datatype x;
	cin>>x;
	if((tail+1)%MAX==head)               //判断队列是否已满
	cout<<"队列已满"<<endl;
	else
	{
		tail=(tail+1)%MAX;                //移动尾指针指向下一个空间
		data[tail]=x;
		cout<<data[tail]<<endl;  
    }
}

template <typename Datatype>
void CircleQueue<Datatype>::pull(){
	if(empty())                            //判断队列是否为空
		cout<<"队列已空"<<endl;
	else
	{
		head=(head+1)%MAX;                //移动队头指针指向下一个空间，即被删元素所在位置
		cout<<data[head]<<endl;
}
}

int main(){
	CircleQueue<int> test;
	int k;
	cout<<"请输入入队元素个数："<<endl;
	cin>>k;
	if(k<=20)
	{
	 cout<<"请输入入队元素："<<endl; 
	 for(int i=0;i<k;i++)
	 {
	   test.push();
     }
     cout<<"开始出队："<<endl;
      for(int j=0;j<k;j++)
      {
     	test.pull();
      }
      cout<<"出队完成"<<endl;
	}
	else 
	cout<<"请输入小于"<<MAX<<"的整数"<<endl; 

}

