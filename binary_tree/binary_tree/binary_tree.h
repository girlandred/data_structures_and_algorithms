#pragma once

#include <iostream>

typedef int datatype;

/* оголошення вузла бінарного дерева */
struct Node {
	datatype key = NULL; // ключ вузла
	Node* parent = NULL; // вказівник на батьківський вузол
	Node* left = NULL; // вказівник на лівого нащадка
	Node* right = NULL; // вказівник на правого нащадка
};

extern Node* pNode; // вказівник на корінь дерева

void CreateTree(Node*& pNode, int n);
void ShowTree(Node*& pNode, int L);
void PrefixOrder(Node*& pNode);
void PostfixOrder(Node*& pNode);
void InfixOrder(Node*& pNode);
bool SearchNodeBST(Node* pNode, datatype key);
Node* CreateRootBST(datatype key);
Node* InsertNodeBST(Node*& root, datatype key);
void PredSucNodeBST(Node* pNode, Node*& predecessor, Node*& successor, datatype key);
Node* MinimumNodeBST(Node* pNode);
Node* MaximumNodeBST(Node* pNode);
Node* DeleteNodeBST(Node*& delNode, datatype key);
