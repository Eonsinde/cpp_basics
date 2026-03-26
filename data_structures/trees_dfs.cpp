#include <iostream>

template <typename T>
struct Node {
	friend std::ostream& operator<<(std::ostream&, Node<int>*);

	T value;
	Node* left = nullptr;
	Node* right = nullptr;

	explicit Node(const T& v) : value(v) {}

	explicit Node(T&& v) : value(std::move(v)) {}

	~Node() {
		if (left) delete left;
		if (right) delete right;
	}

	Node(const Node<T>& other)
		: value(other.value),
		left(other.left ? new Node(*other.left) : nullptr),
		right(other.right ? new Node(*other.right) : nullptr)
	{
	}

	Node(const Node<T>&& other)
		: value{ std::move(other.value) },
		left{ other.left },
		right{ other.right } {
		other.left = nullptr;
		other.right = nullptr;
	}

	Node<T>& operator=(Node<T>& other) {
		// prevent copying self
		if (this == &other)
			return *this;

		this->value = other.value;
		// deep copy left pointer's data
		if (other.left) this->left = new Node<T>(*other.left);
		// deep copy right pointer's data
		if (other.right) this->right = new Node<T>(*other.right);

		return *this;
	}

	Node<T>& operator=(Node<T>&& other) {
		// prevent copying self
		if (this == &other)
			return *this;

		// free up current data in memory
		if (left) delete left;
		if (right) delete right;

		// steal data
		this->value = std::move(other.value);
		// steal left pointer's data
		this->left = other.left;
		other.left = nullptr;
		// steal right pointer's data
		this->right = other.right;
		other.right = nullptr;

		return *this;
	}
};

int main_dfs() {
	Node<int> testNode{ 12 };
	Node<int> testNode2 = Node<int>{ 15 };

	Node<int>* node = new Node{ 1 };
	// left side of root node
	node->left = new Node{ 4 };
	node->left->right = new Node{ 2 };
	node->left->right->left = new Node{ 1 };
	// right side of the root node
	node->right = new Node{ 4 };
	node->right->left = new Node{ 2 };
	node->right->left->left = new Node{ 6 };
	node->right->left->right = new Node{ 8 };
	node->right->left->right->left = new Node{ 1 };
	node->right->left->right->right = new Node{ 3 };

	std::cout << "Node: " << node << "\n";

	return 0;
}

std::ostream& operator<<(std::ostream& os, Node<int>* pNode)
{
	os << pNode->value;
	return os;
}


