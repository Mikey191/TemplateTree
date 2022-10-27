#pragma once
#include <iostream>
using namespace std;

template<class T>
class tree
{
private:
	template<typename T>
	struct node
	{
		T value;
		node<T>* left;
		node<T>* right;
	};

	node<T>* root;
	T sumL = 0;
	T sumR = 0;
	T sum = 0;
	bool findvalue(T value, node<T>* r);
	void addvalue(T value, node<T>* r);
	void _printNLR(node<T>* r);
	void deletetree(node<T>* r);
	void _maxvalue(node<T>* r);
	void _sumelem(node<T>* r);
public:
	tree() : root{ nullptr } {}
	~tree() { deletetree(root); }
	void add(T value) { addvalue(value, root); }
	bool find(T value) { return findvalue(value, root); }
	void printNLR() { _printNLR(root); }
	void maxvalue() { _maxvalue(root); }
	void sumelem() { _sumelem(root); std::cout << "Sum elem: " << sum << std::endl; }
};

template<class T>
inline bool tree<T>::findvalue(T value, node<T>* r)
{
	if (r == nullptr)
		return false;
	if (value == r->value)
		return true;
	if (value < r->value)
		return findvalue(value, r->left);
	if (value > r->value)
		return findvalue(value, r->right);
}

template<class T>
void tree<T>::addvalue(T value, node<T>* r)
{
	if (root == nullptr)
	{
		root = new node<T>;
		root->left = nullptr;
		root->right = nullptr;
		root->value = value;
	}
	else if (value < r->value)
	{
		if (r->left != nullptr)
			addvalue(value, r->left);
		else
		{
			node<T>* n = new node<T>;
			n->left = nullptr;
			n->right = nullptr;
			n->value = value;
			r->left = n;
		}
	}
	else if (value > r->value)
		if (r->right != nullptr)
			addvalue(value, r->right);
		else
		{
			node<T>* n = new node<T>;
			n->left = nullptr;
			n->right = nullptr;
			n->value = value;
			r->right = n;
		}
}

template<class T>
void tree<T>::_printNLR(node<T>* r)
{
	if (r != nullptr)
	{
		cout << r->value << endl;
		_printNLR(r->left);
		_printNLR(r->right);
	}
}

template<class T>
void tree<T>::deletetree(node<T>* r)
{
	if (r != nullptr)
	{
		deletetree(r->left);
		deletetree(r->right);
		delete r;
	}
}

template<class T>
void tree<T>::_maxvalue(node<T>* r)
{
	if (r->right == nullptr)
		cout << "Max elem: " << r->value << endl;
	else
		_maxvalue(r->right);
}

template<class T>
void tree<T>::_sumelem(node<T>* r)
{
	if (r != nullptr)
	{
		sum += r->value;
		_sumelem(r->left);
		_sumelem(r->right);
	}
}
