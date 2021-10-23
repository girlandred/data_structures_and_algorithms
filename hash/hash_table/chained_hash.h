#pragma once
#include <iostream>

const int TABLE_SIZE = 128; // початковий розмір таблиці

class HashNode
{
public:
	int key;
	int value;
	HashNode* next;
	HashNode(int key, int value)
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

class HashMap {
private:
	HashNode** htable;
public:
	HashMap();
	~HashMap();
	int HashFunc(int key);
	void ChainedHashInsert(int key, int value);
	void ChainedHashDelete(int key);
	int ChainedHashSearch(int key);
};