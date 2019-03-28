#include <iostream>

using namespace std;


template <typename Datatype>
class Linkstack{
	private:
    struct linkstack
    {
	 struct linkstack *next;
	 Datatype data;
    }; 
    linkstack *top;
    public :
     Linkstack(){this->top=NULL;};             
	 ~Linkstack(){};		         //��������   �������ʱ���ٹ��캯�������� 
     void create();                 //����ջ 
     void push();                   //ѹջ
	 void pull();                    //��ջ
	 bool empty();
};
    
    
    template <typename Datatype>
     bool Linkstack<Datatype>::empty(){
     	if(top==NULL)
     	return true;
     	else 
     	return false;
     }
     
    template <typename Datatype>
     void Linkstack<Datatype>::push(){
     	Datatype d;
     	cin>>d;
     	linkstack *now;
     	now=new linkstack;
     	now->data=d;
     	now->next=top;
     	this->top=now; 
     	cout<<d<<endl;
     }
     
    template <typename Datatype>                                    //������(��ʱ)
     void Linkstack<Datatype>::pull(){
    	if(empty())
		throw"ջ�ѿ�";
		Datatype d=this->top->data;
    	linkstack *now=this->top;
    	this->top=this->top->next;
    	cout<<d<<endl;
    	delete now; 
    }
    
    int main(){
    	int i,k;
    	Linkstack<int> test;           //int���Ի�float double char...
    	cout<<"������ջ�ĳ��ȣ�"<<endl;                
    	cin>>i;                                           //����Ϊ����int�Ϳɴﵽ�ĳ���   ������5 
    	k=i;
    	cout<<"������ջԪ�أ�"<<endl;                     //��������  1 5 9 3 6 or  a s d f g or 1.1 2.2 3.3 4.4 5.5 
    	while(i--)
		{
	      test.push(); 
		} 
        cout<<"��ʼ��ջ"<<endl; 
		while(k--)
		{
			test.pull();
	    }
		cout<<"��ջ�ɹ�!"<<endl;
    }
    
    
    
    
 
