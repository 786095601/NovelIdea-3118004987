#学习笔记
##1.顺序栈：
###栈的储存方式就像一个杯子，先进去的东西沉到杯底，倒出来时最后才能取出来，即先进后出。
顺序栈就是按顺序将元素储存进栈中，取出时按照先进后出，后进先出的规则实现。
我用一个上限为100的整形数组实现顺序栈
<pre><code>
template    &lt;typename Datatype&gt;
class SeqStack{...}        //使用类模板 方便对某些参数做任意类型的切换
</code></pre>
<pre><code>
SeqStack(){top=-1;};    //构造函数，在类创建开始时自动执行的函数，名字同于类名
~SeqStack(){};     //构析函数，在运行过程中结束类的时候调用，销毁构造函数内数据
</code></pre>
存储数据时
<pre><code>
if(top==StackSize-1) throw"满栈";      //StackSize是用const定义的整形数据100
		cin>>x;
		data[++top]=x;         
</code></pre>
撤出数据用相似方法。

##2.链栈
###链栈，跟链表分不开关系，以链表为基础来实现链栈
tips：结构体名+*指针变量  此时指针指向结构体
<pre><code>
struct linkstack
    {
	 struct linkstack *next;
	 Datatype data;
    }; 
    linkstack *top;   //此时top指向结构体
</code></pre>


链栈压栈和出栈方式相似：  
1.压栈时，一边创建新的节点一边以top指针指向新的结构体，完成赋值和指向上一个节点的操作。这同时是为了出栈的方便。  
2.出栈时，因为要满足先进后出，后进先出，所以只能从最后一个节点开始删除，此时top指针的方便体现出来了。由压栈时指向最后一个节点的top指针来实现。（代码就不列出来了）

##3.链队列
###队列跟栈的区别就是它们的进入与退出时相反的，队列是先进先出，后进后出。
链队列在我看来跟链栈是一样的，只是创建出的节点指向刚好相反，正因为节点指向反向，所以可以用两个指针一个指向队头，一个指向队尾，删除的时候从队头开始删除。

##4.循环队列
循环队列可以用数组来实现，只不过它将数组抽象成一个环，队头跟队尾要空一个空的区域以达到抽象成环的目的。
我选择用两个伪指针来“指向”队列的头和尾，
<pre><code>
int head,tail;
</code></pre>
入队时跟顺序栈差不多，但是多了一项判断队列是否满（用“头指针”跟“尾指针”）：
<pre><code>
if((tail+1)%MAX==head) //判断是否队满
</code></pre>
入队时移动“尾指针”完成对下一个数组元素的跳转：
<pre><code>
tail=(tail+1)%MAX;    //入队时完成尾指针跳转
</code></pre>
出队时利用“头指针”跟上限的关系完成跳转：
<pre><code>
head=(head+1)%MAX;    //出队时完成头指针跳转
</code></pre>
一开始我没有想到这种用法，我想的是在main函数中定义参数来记录 当前队伍长度/已删除的队伍元素个数，再来判断是否 满队/空队。我在读别人的代码的时候看见的方法，十分好用，不用增加参数个数。