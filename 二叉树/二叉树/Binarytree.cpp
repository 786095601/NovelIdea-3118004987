#include "pch.h"
#include <iostream>
#include <cstdlib>


using namespace std;

// 二叉树的增删查改
template <typename Datatype>
class tree {
	struct binaryTree {
		Datatype data;
		binaryTree *left;
		binaryTree *right;
	};

public:
	binaryTree *root;
	tree() {};
	~tree() {};
	void createTree();											//创建二叉树
	bool add(Datatype newData);									//增加树叶
	void deleteTree(Datatype deletedata);						//删除
	bool search(Datatype newData);								//查找
	void preOrder(binaryTree *p);								//先序遍历
	void inOrder(binaryTree *p);								//中序遍历
	void beOrder(binaryTree *p);								//后续遍历
	void tierOrder(binaryTree *p);								//层序遍历
};

template <typename Datatype>
void tree<Datatype>::preOrder(binaryTree *p) {
	if (p != NULL) {
		cout << p->data << " ";
		preOrder(p->left);
		preOrder(p->right);
	}
}

template <typename Datatype>
void tree<Datatype>::inOrder(binaryTree *p) {
	if (p != NULL) {
		preOrder(p->left);
		cout << p->data << " ";
		preOrder(p->right);
	}
}

template <typename Datatype>
void tree<Datatype>::beOrder(binaryTree *p) {
	if (p != NULL) {
		preOrder(p->left);
		preOrder(p->right);
		cout << p->data << " ";
	}
}

template <typename Datatype>
void tree<Datatype>::tierOrder(binaryTree *p) {
	binaryTree *temp[100];								//建立指针数组存放指针
	int in = 0;
	int out = 0;
	temp[in++] = p;                                     //将指针存入数组内
	while (in > out)									//in等于out时 遍历到尽头
	{
		if (temp[out])									//在叶子节点的时候可以令in等于out
		{
			cout << temp[out]->data << " ";
			temp[in++] = temp[out]->left;
			temp[in++] = temp[out]->right;
		}
		out++;
	}
}

template <typename Datatype>
void tree<Datatype>::createTree()
{
	Datatype newData;
	cin >> newData;
	cout << newData << endl;
	binaryTree *node = (binaryTree*)malloc(sizeof(binaryTree));
	node->data = newData;
	node->right = NULL;
	node->left = NULL;
	if (root != NULL) {							//判断树是不是空树
		binaryTree *now = root;					//从树根开始
		while (now != NULL)
		{
			if (newData < now->data)			//小于父内数据就进左儿子
			{
				if (now->left == NULL)
				{
					now->left = node;
					return;
				}
				else {
					now = now->left;
				}
			}
			else {								//否则进右儿子

				if (now->right == NULL)
				{
					now->right = node;
					return;
				}
				else {
					now = now->right;
				}
			}
		}
	}
	else {
		root = node;
	}
}

template <typename Datatype>
bool tree<Datatype>::add(Datatype newData) {
	if (root == nullptr)
	{
		root = (binaryTree*)malloc(sizeof(binaryTree));
		return true;
	}

	binaryTree* kid = root;
	binaryTree* father = nullptr;

	while (kid != nullptr)
	{
		if (newData < kid->data)
			father = kid, kid = kid->left;			//kid标记被插入的位置

		else if (newData > kid->data)
			father = kid, kid = kid->right;

		else
			return false;
	}
													//找到插入位置之后，判断插入在父节点的左边还是右边
	if (newData < father->data) {
		father->left = (binaryTree*)malloc(sizeof(binaryTree));
		father->left->data = newData;
		father->left->left = NULL;
		father->left->right = NULL;
	}
	if (newData > father->data) {
		father->right = (binaryTree*)malloc(sizeof(binaryTree));
		father->right->data = newData;
		father->right->left = NULL;
		father->right->right = NULL;
	}
	return true;
}

template<typename Datatype>
void tree<Datatype>::deleteTree(Datatype deleteData)
{
	binaryTree* deletePoint = root;
	binaryTree* parent = root;                   //设置父指针 如果不把删除的指针设空，遍历会指向未定义空间
	while (deletePoint != nullptr)
	{

		if (deleteData < deletePoint->data) {
			parent = deletePoint;
			deletePoint = deletePoint->left;
		}
		else if (deleteData > deletePoint->data) {
			parent = deletePoint;
			deletePoint = deletePoint->right;
		}
		else {
			break;
		}
	}

	if (deletePoint->left == nullptr&&deletePoint->right == nullptr) {
		parent->left = nullptr;
		parent->right = nullptr;
		free(deletePoint);
	}
	else if (nullptr != deletePoint->left && nullptr == deletePoint->right) {
		deleteTree(deletePoint->left->data);
	}
	else if (nullptr == deletePoint->left && nullptr == deletePoint->right) {
		deleteTree(deletePoint->right->data);
	}
}

template <typename Datatype>
bool tree<Datatype>::search(Datatype newData) {
	binaryTree* searchPoint = root;
	while (searchPoint != nullptr)
	{

		if (newData < searchPoint->data)
			searchPoint = searchPoint->left;

		else if (newData > searchPoint->data)
			searchPoint = searchPoint->right;
		else
			return true;
	}
	return false;

}