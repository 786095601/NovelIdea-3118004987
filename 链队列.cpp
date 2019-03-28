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
	  bool noempty();            //���ǿսڵ� 
	  void push();	            //���
	  void pull();      	    //����		
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
        cout<<"�����Ѿ�����"; 
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

template <typename Datatype>                                //�����⣨��ʱ�� 
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
	cout<<"������г��ȣ�"<<endl;
	cin>>i;
	j=i;
	cout<<"���������Ԫ�أ�"<<endl; 
	while(i--)
		{
	     test.push(); 
		} 
	cout<<"������"<<endl;
	cout<<"��ʼ����"<<endl; 
		while(j--)
		{
			test.pull();
	    }
	cout<<"�������"<<endl;
}




