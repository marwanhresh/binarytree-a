#pragma once

#include <iostream>
#include <queue>
namespace ariel{
	template <class T>
	class BinaryTree
	{
	private:

		class node
		{
		public:
			T data;
			node *left, *right;
			node(const T& data, node *left, node *right) :
				data(data), left(left), right(right){}
		};

		node* root;

		node* findNode(node* root, const T& value)
		{
			if (root == nullptr)
				return nullptr;

			if (root->data == value)
				return root;
			node* l = findNode(root->left, value);
			if (l)
				return l;
			node* r = findNode(root->left, value);
			if (r)
				return r;
			return nullptr;
		}

	public:
		BinaryTree()
		{
			root = nullptr;
		}

		~BinaryTree(){
			deleteAll(root);
		}

		void deleteAll(node* n){
			if (n == nullptr)
				return;
			if (n->left)
				deleteAll(n->left);
			delete n;
			if (n->right)
				deleteAll(n->right);
		}

		BinaryTree& add_root(const T& value)
		{
			if (root == nullptr)
			{
				root = new node(value, nullptr, nullptr);
			}
			else
			{
				root->data = value;
			}
			return *this;
		}

		BinaryTree& add_left(const T& value, const T& left_value)
		{
			node *n = findNode(root, value);
			if (n->left == 0)
			{
				n->left = new node(left_value, nullptr, nullptr);
			}
			else
			{
				n->left->data = left_value;
			}
			return *this;
		}

		BinaryTree& add_right(T value, T right_value)
		{
			node *n = findNode(root, value);
			if (n->right == 0)
			{
				n->right = new node(right_value, nullptr, nullptr);
			}
			else
			{
				n->right->data = right_value;
			}
			return *this;
		}


		friend ostream& operator<<(ostream& o, const BinaryTree<T>& b){
			printWithLevels(o, b.root);
			return o;
		}

		static void printWithLevels(ostream& o, node* p, int indent = 0)
		{
			if (p != nullptr) {
				if (indent) {
					for (int i = 0; i < indent; i++)
						o << ' ';
				}
				o << p->data << "\n";
				if (p->left)
					printWithLevels(o, p->left, indent + 4);
				if (p->right)
					printWithLevels(o, p->right, indent + 4);

			}
		}


		class iterator{
		protected:
			std::queue<node*> q;
			node* current_node;
		public:
			iterator()	{
				current_node = nullptr;
			}

			virtual void fill(node* n) = 0;

			T& operator*() const {
				return current_node->data;
			}

			T* operator->() const {
				return &current_node->data;
			}

			bool operator==(const iterator& rhs) const {
				return current_node == rhs.current_node;
			}

			bool operator!=(const iterator& rhs) const {
				return current_node != rhs.current_node;
			}

			iterator& operator++() {
				if (q.empty()){
					current_node = nullptr;
				}
				else{
					current_node = q.front();
					q.pop();
				}
				return *this;
			}

		};


		class inorder_iterator : public iterator{
		public:
			inorder_iterator(node* ptr)
			{
				fill(ptr);
				++(*this);
			}

			void fill(node* n){
				if (n == nullptr)
					return;
				if (n->left)
					fill(n->left);
				this->q.push(n);
				if (n->right)
					fill(n->right);
			}
		};

		inorder_iterator begin_inorder(){
			return inorder_iterator(root);
		}

		inorder_iterator end_inorder(){
			return inorder_iterator(nullptr);
		}

		class preorder_iterator : public iterator{
		public:
			preorder_iterator(node* ptr)
			{
				fill(ptr);
				++(*this);
			}

			void fill(node* n){
				if (n == nullptr)
					return;
				this->q.push(n);
				if (n->left)
					fill(n->left);
				if (n->right)
					fill(n->right);

			}
		};

		preorder_iterator begin_preorder(){
			return preorder_iterator(root);
		}

		preorder_iterator end_preorder(){
			return preorder_iterator(nullptr);
		}

		class postorder_iterator : public iterator{
		public:
			postorder_iterator(node* ptr)
			{
				fill(ptr);
				++(*this);
			}

			void fill(node* n){
				if (n == nullptr)
					return;
				if (n->left)
					fill(n->left);
				if (n->right)
					fill(n->right);
				this->q.push(n);
			}
		};

		postorder_iterator begin_postorder(){
			return postorder_iterator(root);
		}

		postorder_iterator end_postorder(){
			return postorder_iterator(nullptr);
		}

		inorder_iterator begin(){
			return inorder_iterator(root);
		}

		inorder_iterator end(){
			return inorder_iterator(nullptr);
		}

	};
}