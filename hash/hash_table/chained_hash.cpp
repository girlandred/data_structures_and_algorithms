#include "chained_hash.h"

HashMap::HashMap()
{
	htable = new HashNode * [TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
		htable[i] = NULL;
}
HashMap::~HashMap()
{
	for (int i = 0; i < TABLE_SIZE; ++i)
	{
		HashNode* entry = htable[i];
		while (entry != NULL)
		{
			HashNode* prev = entry;
			entry = entry->next;
			delete prev;
		}
	}
	delete[] htable;
}

/* функція, для обчислення хешу значення */
int HashMap::HashFunc(int key)
{
	return key % TABLE_SIZE;
}

/* функція, що вставляє елемент до списку*/
void HashMap::ChainedHashInsert(int key, int value)
{
	int hash_val = HashFunc(key);
	HashNode* prev = NULL;
	HashNode* entry = htable[hash_val];
	while (entry != NULL)
	{
		prev = entry;
		entry = entry->next;
	}
	if (entry == NULL)
	{
		entry = new HashNode(key, value);
		if (prev == NULL)
		{
			htable[hash_val] = entry;
		}
		else
		{
			prev->next = entry;
		}
	}
	else
	{
		entry->value = value;
	}
}

/* функція для видалення елемента з списку*/
void HashMap::ChainedHashDelete(int key)
{
	int hash_val = HashFunc(key);
	HashNode* entry = htable[hash_val];
	HashNode* prev = NULL;
	if (entry == NULL || entry->key != key)
	{
		std::cout << "No Element found at key " << key << std::endl;
		return;
	}
	while (entry->next != NULL)
	{
		prev = entry;
		entry = entry->next;
	}
	if (prev != NULL)
	{
		prev->next = entry->next;
	}
	delete entry;
	std::cout << "Element Deleted" << std::endl;
}

/* функція для пошуку елементів за ключем */
int HashMap::ChainedHashSearch(int key)
{
	bool flag = false; // за замовчуванням, елемент масива видалений
	int hash_val = HashFunc(key);
	HashNode* entry = htable[hash_val];
	// проходимо масив, доки він не залишиться порожнім
	while (entry != NULL)
	{
		if (entry->key == key)
		{
			std::cout << entry->value << " ";
			flag = true;
		}
		entry = entry->next;
	}
	if (!flag)
		return -1;
}