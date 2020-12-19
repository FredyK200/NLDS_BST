#pragma once
#include <memory>
#include <string>
#include <iostream>
using namespace std;
template <class T>
class Tree
{
	struct Node 
	{
		shared_ptr<Node> left = nullptr, right = nullptr;
		shared_ptr<Node> parent;
		T datum; 
	};

protected:
	void inOrderTraversalName(ostream& ostr, shared_ptr<Node> node);
	void inOrderTraversalAll(ostream& ostr, shared_ptr<Node> node);
	void preOrderTraversal(ostream& ostr, shared_ptr<Node> node);
	void transplant(shared_ptr<Node> u, shared_ptr<Node> v);
	shared_ptr<Node> min(shared_ptr<Node> u);
	void clearTree(shared_ptr<Node> node);
	shared_ptr<Node> root;

public:
	Tree() { root = nullptr; }  
	bool isEmpty() { return root == nullptr; }
	shared_ptr<Node> find(string value); 
	shared_ptr<Node> del(string value);
	void save(ofstream &file);
	void insert(T value);      
	void traverse();
	void clear();
};

