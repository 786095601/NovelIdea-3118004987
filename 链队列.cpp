#include <iostream>

using namespace std;

template <typename Datatype>
class LinkQueue{
	struct Queue{
		Datatype data;
		Queue *next;
	};
	private :
	  Queue *head;
	  Queue *tail;
	public :
	  LinkQueue(); 
	  ~LinkQueue();
	  bool noempty();            //不是空节点 
	  void push();	            //入队
	  void pull();      	    //出队		
}; 

template <typename Datatype>                              
    LinkQueue<Datatype>::LinkQueue(){
	Queue *p=new Queue;
	p->next=NULL;
    tail=p;
	head=tail;
}

template <typename Datatype>
     LinkQueue<Datatype>::~LinkQueue(){
	  Queue *p;
      while (head!= NULL) {
        p=head;
        head=head->next;
        delete p;
        cout<<"队列已经销毁"; 
      }	 
}

template <typename Datatype>
     bool LinkQueue<Datatype>::noempty(){
       if(head!=NULL)
       return true;
       else return false;
}

template <typename Datatype>
     void LinkQueue<Datatype>::push(){
		Datatype d;
     	cin>>d;
     	tail->next = new Queue;
     	tail->next->data=d;
        tail = tail->next;
     	cout<<d<<endl;
}

template <typename Datatype>                                //有问题（暂时） 
     void LinkQueue<Datatype>::pull(){
     if(noempty())
	 {
	   Queue *q=head;
       Datatype d=q->next->data;
       cout<<d<<endl;
       head=head->next;
       delete q;
     }
}

int main(){
	LinkQueue<double> test;
	int i,j;
	cout<<"请输队列长度："<<endl;
	cin>>i;
	j=i;
	cout<<"请输入队列元素："<<endl; 
	while(i--)
		{
	     test.push(); 
		} 
	cout<<"入队完成"<<endl;
	cout<<"开始出队"<<endl; 
		while(j--)
		{
			test.pull();
	    }
	cout<<"出队完成"<<endl;
}




