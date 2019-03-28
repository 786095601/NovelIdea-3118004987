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
	 ~Linkstack(){};		         //构析函数   程序结束时销毁构造函数内数据  
     void push();                   //压栈
	 void pull();                    //出栈
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
     
    template <typename Datatype>                                    //有问题(暂时)
     void Linkstack<Datatype>::pull(){
    	if(empty())
		throw"栈已空";
		Datatype d=this->top->data;
    	linkstack *now=this->top;
    	this->top=this->top->next;
    	cout<<d<<endl;
    	delete now; 
    }
    
    int main(){
    	int i,k;
    	Linkstack<int> test;           //int可以换float double char...
    	cout<<"输入链栈的长度："<<endl;                
    	cin>>i;                                           //长度为任意int型可达到的长度   测试用5 
    	k=i;
    	cout<<"请输入栈元素："<<endl;                     //测试用例  1 5 9 3 6 or  a s d f g or 1.1 2.2 3.3 4.4 5.5 
    	while(i--)
		{
	      test.push(); 
		} 
        cout<<"开始出栈"<<endl; 
		while(k--)
		{
			test.pull();
	    }
		cout<<"出栈成功!"<<endl;
    }
    
    
    
    
 
