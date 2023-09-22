#pragma once
#include <iostream>
struct NodeTree
{
	int  key;
};
namespace btree
{
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Node
	{
		Node* parent;            // указатель на родителя  
		Node* left;              // указатель на левую ветвь
		Node* right;             // указатель на правую ветвь
		NodeTree* data;              //  данные    
		Node(Node* p, Node* l, Node* r, NodeTree* d) // конструктор
		{
			parent = p;
			left = l;
			right = r;
			data = d;
		}
		Node* next();              // следующий по ключу
		Node* prev();              // предыдущий по ключу
		Node* min();               // минимум в поддереве
		Node* max();               // максимум в поддереве  
		void scanDown(void(*f)(void* n));    // обход поддерева сверху вниз     
		void scan(int(*f)(void* n));
		void scanLevel(void(*f)(void* n), int);
		int getLevel();
		void scanByLevel(void(*f)(void* n));
	};
	struct Object         // Интерфейс бинарного дерева 
	{
		Node* Root;                    // указатель на корень
		CMP(*compare)(void*, void*);   // функция сравнения	
		Object(CMP(*f)(void*, void*))
		{
			Root = NULL;
			compare = f;
		};
		Node* getRoot() {
			return Root;
		}
		bool isLess(void* x1, void* x2)	const
		{
			return compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2)const
		{
			return compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2)const
		{
			return compare(x1, x2) == EQUAL;
		};
		bool insert(NodeTree* data);           // добавить элемент
		Node* search(void* d, Node* n);    // найти элемент
		Node* search(void* d)
		{
			return search(d, Root);
		};
		bool deleteByNode(Node* e);         // удалить по адресу элемента 
		bool deleteByData(void* data)       // удалить по ключу
		{
			return deleteByNode(search(data));
		};
	};
	Object create(CMP(*f)(void*, void*));      // Создать бинарное дерево 

	bool countRoot(Node* current, int key, int count);
	void preOrderTraversal(Node* current, int);
	void mixedTraversal(Node* current, int);
};
