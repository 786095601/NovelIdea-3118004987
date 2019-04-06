// 哈夫曼1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

template <typename Datatype>
class huffman {
	struct huffmanNode
	{
		Datatype data;                  //节点权值
		HuffmanNode<Datatype>* left; 
		HuffmanNode<Datatype>* right; 
		int flag;					  //标志　判断是否从森林中删除
	};
public:
	void sort(int size);
private:
	huffmanNode<Datatype>* forest[100];
};

template <typename Datatype>
void huffman<Datatype>::sort(int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (forest[i]->data > forest[j]->data)
			{
				swap(forest[i], forest[j]);
			}
			else
				continue;
		}
	}
}

int main()
{
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
