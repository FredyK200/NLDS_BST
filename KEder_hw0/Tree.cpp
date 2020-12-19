#include "Tree.h"
#include "Satellite.h"

void Tree<Satellite>::transplant(shared_ptr<Node> node1, shared_ptr<Node> node2)
{
	if (node1->parent == nullptr) // Trying to check if the parent doesnt exist ie root node
	{
		root = node2;
	}
	else if (node1 == node1->parent->left)
	{
		node1->parent->left = node2;
	}
	else
	{
		node1->parent->right = node2;
	}
	if (node2 != nullptr)
	{
		node2->parent = node1->parent;
	}
}
void Tree<Satellite>::inOrderTraversalName(ostream& ostr, shared_ptr<Node> node)
{
	if (node != nullptr) {
		inOrderTraversalName(ostr, node->left);
		ostr << node->datum.getName() << endl;
		inOrderTraversalName(ostr, node->right);
	}
}
void Tree<Satellite>::inOrderTraversalAll(ostream& ostr, shared_ptr<Node> node)
{
	if (node != nullptr) {
		inOrderTraversalAll(ostr, node->left);
		ostr << node->datum.getSatalliteInfo();
		inOrderTraversalAll(ostr, node->right);
	}
}
void Tree<Satellite>::preOrderTraversal(ostream& ostr, shared_ptr<Node> node)
{
	if (node != nullptr) {
		ostr << node->datum.getSatalliteInfo() << endl;
		inOrderTraversalAll(ostr, node->left);
		inOrderTraversalAll(ostr, node->right);
	}
}
shared_ptr<Tree<Satellite>::Node> Tree<Satellite>::min(shared_ptr<Node> node) {
	shared_ptr<Node> item = nullptr;

	if (isEmpty()) {
		return item;
	}
	shared_ptr<Node> current = node;
	while (current->left != nullptr) {
		current = current->left;
	}
	return current;
}
shared_ptr<Tree<Satellite>::Node> Tree<Satellite>::find(string value) {
	shared_ptr<Node> item = nullptr;

	if (isEmpty()) {
		return item;
	}
	shared_ptr<Node> current = root;
	while (current != nullptr) {
		if (current->datum.getName() == value) {
			return current;
		}
		else if (current->datum.getName() < value) {
			current = current->right;
		}
		else {
			current = current->left;
		}
	}
	return item;
}
shared_ptr<Tree<Satellite>::Node> Tree<Satellite>::del(string value)
{
	auto result = find(value);
	auto item = result;
	if (result == nullptr)
	{
		return item;
	}
	if (result->left == nullptr)
	{
		transplant(result, result->right);
	}
	else if (result->right == nullptr)
	{
		transplant(result, result->left);
	}
	else
	{
		auto result_min = min(result->right);
		if (result_min->parent != result)
		{
			transplant(result_min, result_min->right);
			result_min->right = result->right;
			result_min->right->parent = result_min;
		}
		transplant(result, result_min);
		result_min->left = result->left;
		result_min->left->parent = result_min;
	}
	return item;
}
void Tree<Satellite>::clearTree(shared_ptr<Node> node)
{
	if (node != nullptr) {
		clearTree(node->left);
		node->parent = nullptr;
		clearTree(node->right);
		node->right = nullptr;
		node->left = nullptr;
	}
}
void Tree<Satellite>::insert(Satellite value)
{
	shared_ptr<Node> nptr(new Node);
	nptr->datum = value;
	if (isEmpty()) {
		root = nptr;
	}
	else {
		shared_ptr<Node> previous = nullptr;
		shared_ptr<Node> current = root;
		while (current != nullptr) {
			previous = current;
			if (current->datum.getName() > value.getName()) {
				current = current->left;
			}
			else {
				current = current->right;
			}

		}
		if (previous->datum.getName() > value.getName()) {
			previous->left = nptr;
		}
		else {
			previous->right = nptr;
		}
		nptr->parent = previous;
		previous = nullptr;
	}
	nptr = nullptr;
}
void Tree<Satellite>::save(ofstream &file)
{
	inOrderTraversalAll(file, root);
}
void Tree<Satellite>::traverse()
{
	inOrderTraversalName(cout, root);
}
void Tree<Satellite>::clear()
{
	clearTree(root);
}