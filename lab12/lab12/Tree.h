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
		Node* parent;            // ��������� �� ��������  
		Node* left;              // ��������� �� ����� �����
		Node* right;             // ��������� �� ������ �����
		NodeTree* data;              //  ������    
		Node(Node* p, Node* l, Node* r, NodeTree* d) // �����������
		{
			parent = p;
			left = l;
			right = r;
			data = d;
		}
		Node* next();              // ��������� �� �����
		Node* prev();              // ���������� �� �����
		Node* min();               // ������� � ���������
		Node* max();               // �������� � ���������  
		void scanDown(void(*f)(void* n));    // ����� ��������� ������ ����     
		void scan(int(*f)(void* n));
		void scanLevel(void(*f)(void* n), int);
		int getLevel();
		void scanByLevel(void(*f)(void* n));
	};
	struct Object         // ��������� ��������� ������ 
	{
		Node* Root;                    // ��������� �� ������
		CMP(*compare)(void*, void*);   // ������� ���������	
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
		bool insert(NodeTree* data);           // �������� �������
		Node* search(void* d, Node* n);    // ����� �������
		Node* search(void* d)
		{
			return search(d, Root);
		};
		bool deleteByNode(Node* e);         // ������� �� ������ �������� 
		bool deleteByData(void* data)       // ������� �� �����
		{
			return deleteByNode(search(data));
		};
	};
	Object create(CMP(*f)(void*, void*));      // ������� �������� ������ 

	bool countRoot(Node* current, int key, int count);
	void preOrderTraversal(Node* current, int);
	void mixedTraversal(Node* current, int);
};
