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
	if((tail+1)%MAX==head)               //�ж϶����Ƿ�����
	cout<<"��������"<<endl;
	else
	{
		tail=(tail+1)%MAX;                //�ƶ�βָ��ָ����һ���ռ�
		data[tail]=x;
		cout<<data[tail]<<endl;  
    }
}

template <typename Datatype>
void CircleQueue<Datatype>::pull(){
	if(empty())                            //�ж϶����Ƿ�Ϊ��
		cout<<"�����ѿ�"<<endl;
	else
	{
		head=(head+1)%MAX;                //�ƶ���ͷָ��ָ����һ���ռ䣬����ɾԪ������λ��
		cout<<data[head]<<endl;
}
}

int main(){
	CircleQueue<int> test;
	int k;
	cout<<"���������Ԫ�ظ�����"<<endl;
	cin>>k;
	if(k<=20)
	{
	 cout<<"���������Ԫ�أ�"<<endl; 
	 for(int i=0;i<k;i++)
	 {
	   test.push();
     }
     cout<<"��ʼ���ӣ�"<<endl;
      for(int j=0;j<k;j++)
      {
     	test.pull();
      }
      cout<<"�������"<<endl;
	}
	else 
	cout<<"������С��"<<MAX<<"������"<<endl; 

}

