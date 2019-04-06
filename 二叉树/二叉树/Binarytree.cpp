#include "pch.h"
#include <iostream>
#include <cstdlib>


using namespace std;

// ����������ɾ���
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
	void createTree();											//����������
	bool add(Datatype newData);									//������Ҷ
	void deleteTree(Datatype deletedata);						//ɾ��
	bool search(Datatype newData);								//����
	void preOrder(binaryTree *p);								//�������
	void inOrder(binaryTree *p);								//�������
	void beOrder(binaryTree *p);								//��������
	void tierOrder(binaryTree *p);								//�������
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
	binaryTree *temp[100];								//����ָ��������ָ��
	int in = 0;
	int out = 0;
	temp[in++] = p;                                     //��ָ�����������
	while (in > out)									//in����outʱ ��������ͷ
	{
		if (temp[out])									//��Ҷ�ӽڵ��ʱ�������in����out
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
	if (root != NULL) {							//�ж����ǲ��ǿ���
		binaryTree *now = root;					//��������ʼ
		while (now != NULL)
		{
			if (newData < now->data)			//С�ڸ������ݾͽ������
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
			else {								//������Ҷ���

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
			father = kid, kid = kid->left;			//kid��Ǳ������λ��

		else if (newData > kid->data)
			father = kid, kid = kid->right;

		else
			return false;
	}
													//�ҵ�����λ��֮���жϲ����ڸ��ڵ����߻����ұ�
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
	binaryTree* parent = root;                   //���ø�ָ�� �������ɾ����ָ����գ�������ָ��δ����ռ�
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