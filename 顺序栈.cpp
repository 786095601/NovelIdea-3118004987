#include <iostream>

using namespace std; 
const int StackSize=100;
 
template <typename Datatype>
class SeqStack{
	private :
		int top;
		Datatype data[StackSize];
    public :
    	SeqStack(){top=-1;};
    	~SeqStack(){};                        //�����������top���� 
    	void push(Datatype x);
    	Datatype pull();
    	bool empty();
    	void printlist();
             };
		
    template <typename Datatype>
	void SeqStack<Datatype>::push(Datatype x){
		if(top==StackSize-1) throw"��ջ";
		cin>>x;
		data[++top]=x; 
	}  
	
	template <typename Datatype>
	Datatype SeqStack<Datatype>::pull(){
		if(top==-1) throw "��ջ";
		Datatype x=data[top--];
		cout<<x;
		return x; 
	}
	
	template <typename Datatype>
	bool SeqStack<Datatype>:: empty(){
		if(top==-1)
		return true;
		else
	    return false;
	}
	
	template <typename Datatype>
	void SeqStack<Datatype>:: printlist(){
		if(empty())throw"������"; 
		 for (int i=0; i<=top; i++)
		 {
		   cout<<data[i]<<endl;
	     }
	}
	

	int main(){     
	int n;                                    //double���Ըĳ��������� (char int float...) 
	 SeqStack<int> test;    //����������0.0 1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9...  a b c d e f g.... 
	 cout<<"����ջ����"<<endl;
	 cin>>n;
	 cout<<"����ջ��Ԫ�أ�"<<endl;
	 for (int i=0; i<n;i++) {
        test.push(i);
    }
    cout<<"��ʾջ��Ԫ�أ�" <<endl;
    test.printlist();
    cout<<"��ջ���ԣ�"<<endl; 
    for(int j=0;j<n;j++)
	{
      test.pull();
      cout<<endl;
    }
    cout<<"��ջ�ɹ���"<<endl;
    
}
	
