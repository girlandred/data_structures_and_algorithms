#include <iostream>
#include "binary_tree.h"

/* функція, що створює бінарне дерево*/
void CreateTree(Node*& pNode, int n) {
	if (pNode == NULL) // якщо дерево порожнє, то зупиняємо рекурсію
		return;
	else
	{
		pNode = new Node; // новий вузол дерева
		datatype data;
		std::cin >> data; // заповнюємо дерево
		pNode->key = data;
		pNode->left = pNode->right = NULL; 
		int left = n / 2 - 1; // створення лівого піддерева
		int right = n - left - 1; // створення правого піддерева
		CreateTree(pNode->left, left);
		CreateTree(pNode->right, right);
	}
};

/* функція, що відповідає за відображення дерева */
void ShowTree(Node*& pNode, int L) {
	if (pNode == NULL)
		return;
	ShowTree(pNode->left, L + 1); // виведення лівого піддерева
	for (int i = 0; i < L; i++)
	{
		std::cout << "    ";
	}
	std::cout << pNode->key << std::endl;
	ShowTree(pNode->right, L + 1); // виведення правого піддерева
};

/* функція, що здійснює обхід дерева у прямому порядку*/
void PrefixOrder(Node*& pNode)
{
	if (pNode == NULL)
		return; // перевіряємо чи не порожнє дерево
	std::cout << pNode->key << std::endl; // обробляємо данні у вузлі
	PrefixOrder(pNode->left); // обхід лівого піддерева
	PrefixOrder(pNode->right); // обхід правого піддерева
};

/* функція, що здійснює обхід дерева у зворотньому порядку*/
void PostfixOrder(Node*& pNode)
{
	if (pNode == NULL)
		return; // перевіряємо чи не порожнє дерево
	PostfixOrder(pNode->left); // обхід лівого піддерева
	PostfixOrder(pNode->right); // обхід правого піддерева
	std::cout << pNode->key << std::endl; // обробляємо данні у вузлі
};

/* функція, що здійснює обхід дерева у внутрішньому порядку*/
void InfixOrder(Node*& pNode)
{
	if (pNode == NULL)
		return;
	InfixOrder(pNode->left); // обхід лівого піддерева
	std::cout << pNode->key << std::endl; // обробляємо данні у вузлі
	InfixOrder(pNode->right); // обхід правого піддерева
};

/* функція, що здійснює пошук даних за ключем*/
bool SearchNodeBST(Node* pNode, datatype key)
{
	if (pNode == NULL)
		return false;
	else if (pNode->key == key) // ключ поточного вузла співпадає з ключем пошуку
		return true;
	else if (key < pNode->key) // ключ поточного вузла більший ніж ключ пошуку
		return SearchNodeBST(pNode->left, key);
	else // ключ поточного вузла менший ніж ключ пошуку
		return SearchNodeBST(pNode->right, key);
};

/* функція, що створює вузол у бінарному дереві*/
Node* CreateRootBST(datatype key)
{
	Node* pNode = new Node; // виділяю динамічну пам'ять
	pNode->key = key; // заповнюю поле
	pNode->parent = pNode->left = pNode->right = NULL;
	return pNode;
};

/* функція, що вставляє новий вузол у бінарному дереві*/
Node* InsertNodeBST(Node*& root, datatype key)
{
	if (root == NULL)
	{
		root = CreateRootBST(key);
		return root;
	}
	else
		if (key <= root->key)
			root->left = InsertNodeBST(root->left, key);
		else
			root->right = InsertNodeBST(root->right, key);
	return root;
};

/* функція, що знаходить термінальні вузли*/
void PredSucNodeBST(Node* pNode, Node*& predecessor, Node*& successor, datatype key)
{
	if (pNode==NULL)
	{
		return;
	}
	if(pNode->key == key) // якщо даний ключ є коренем
	{
		if (pNode->left != NULL) {
			Node* temp = pNode->left;
			while (temp->right != NULL)
			{
				temp = temp->right;
			}
			predecessor = temp;
		}
		if (pNode->right != NULL)
		{
			Node* temp = pNode->right;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			successor = temp;
		}
		return;
	}
	if (pNode->key > key) // якщо даний ключ є меншим ніж корінь
	{
		successor = pNode;
		PredSucNodeBST(pNode->left, predecessor, successor, key);
	}
	else // якщо ключ є більшим ніж корінь
	{
		predecessor = pNode;
		PredSucNodeBST(pNode->right, predecessor, successor, key);
	}
};

/* функція, що знаходить мінімальний вузол*/
Node* MinimumNodeBST(Node* pNode)
{
	if (pNode == NULL) return NULL;
	while (pNode->left)
	{
		pNode = pNode->left;
	}
	return pNode;
};

/* метод, що знаходить максимальний вузол*/
Node* MaximumNodeBST(Node* pNode)
{
	while (pNode->right)
		pNode = pNode->right;
	return pNode;
};

/* метод, що видаляє вузол з бінарного дерева*/
Node* DeleteNodeBST(Node*& delNode, datatype key)
{
	if (delNode == NULL) //перевіряємо, чи є дерево порожнім
		return delNode;
	/*визначаємо, якого нащадка має вузол - лівого чи правого*/
	if (delNode->key > key)
		delNode->left = DeleteNodeBST(delNode->left, key);
	else
		if (delNode->key < key)
			delNode->right = DeleteNodeBST(delNode->right, key);
		else
		{
			if (delNode->left == NULL && delNode->right == NULL)
			{
				delete delNode;
				delNode = NULL;
				return delNode;
			}
			else
				if (delNode->left == NULL)
				{
					Node* temp = delNode;
					delNode = delNode->right;
					delete temp;
					return delNode;
				}
				else
					if (delNode->right == NULL)
					{
						Node* temp = delNode;
						delNode = delNode->left;
						delete temp;
						return delNode;
					}
			Node* temp = MinimumNodeBST(delNode->right);
			delNode->key = temp->key; // оновлюємо ключ вузла
			delNode->right = DeleteNodeBST(delNode->right, temp->key); // рекурсивно видаляємо вузол
		}
	return delNode;
};
