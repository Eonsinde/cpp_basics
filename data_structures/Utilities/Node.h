#ifndef __BASE_NODE_H__
#define __BASE_NODE_H__

namespace Learning {
	template<typename T>
	class Node
	{
	public:
		Node()
			: data{ new T() }, left{ nullptr }, right{ nullptr } {

		}

		Node(T tT)
			: data{ new T(tT) }, left{ nullptr }, right{ nullptr } {

		}

		~Node()
		{
			// delete just data here, let whatever structures or algorithms using a node instance
			// handle clean ups for the left and right nodes reference by a given node instance if any
			delete data;
			left = nullptr;
			right = nullptr;
		}

		T* data;

		Node<T>* left;
		Node<T>* right;
	};
}

#endif