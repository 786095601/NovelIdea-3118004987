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
    	~SeqStack(){};                        //构析函数清除top数据 
    	void push(Datatype x);
    	Datatype pull();
    	bool empty();
    	void printlist();
             };
		
    template <typename Datatype>
	void SeqStack<Datatype>::push(Datatype x){
		if(top==StackSize-1) throw"满栈";
		cin>>x;
		data[++top]=x; 
	}  
	
	template <typename Datatype>
	Datatype SeqStack<Datatype>::pull(){
		if(top==-1) throw "空栈";
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
		if(empty())throw"到底了"; 
		 for (int i=0; i<=top; i++)
		 {
		   cout<<data[i]<<endl;
	     }
	}
	

	int main(){     
	int n;                                    //double可以改成任意类型
	 SeqStack<int> test;                  //测试用例：1 2 3 4 5...  a b c d e f g.... 
	 cout<<"输入栈长度"<<endl;
	 cin>>n;
	 cout<<"输入栈内元素："<<endl;
	 for (int i=0; i<n;i++) {
        test.push(i);
    }
    cout<<"显示栈内元素：" <<endl;
    test.printlist();
    cout<<"出栈测试："<<endl; 
    for(int j=0;j<n;j++)
	{
      test.pull();
      cout<<endl;
    }
    cout<<"出栈成功！"<<endl;
    
}
	
