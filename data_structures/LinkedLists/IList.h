#ifndef __ILIST_H__
#define __ILIST_H__

#include "../Utilities/Node.h"

#include <initializer_list>

/**
* IList: Interface which list classes can implement
*/

namespace Learning {
	template<typename T>
	class IList
	{
	public:
		enum class ListType
		{
			SINGLY_LINKED,
			DOUBLY_LINKED
		};

	public:
		IList(ListType type = ListType::DOUBLY_LINKED)
			: rootNodePtr{ new Node<T>() }, m_numOfNodes{ 1 } {
			tailNodePtr = rootNodePtr;

			if (type == ListType::DOUBLY_LINKED) {
				rootNodePtr->left = nullptr;
				rootNodePtr->right = nullptr;
			}
			else {
				rootNodePtr->right = nullptr;
			}
		}

		IList(std::initializer_list<T> data, ListType type = ListType::DOUBLY_LINKED)
			: m_numOfNodes{ data.size() } {
			// if doubly linked, make sure to set prev to null because only it has a previously linked node
		}

		virtual ~IList()
		{
			// using linear traversal from the HEAD to the TAIL and clear each node's data
			Node<T>* currentPtr = rootNodePtr;

			while (currentPtr) {
				next = currentPtr->right;

				delete currentPtr;

				currentPtr = next;
			}

			rootNodePtr = nullptr;
		}

		virtual size_t	Append(T value) = 0;
		virtual size_t	Insert(T value, size_t pos) = 0;
		virtual int		Find(T item) const = 0;
		virtual bool	Remove(T item) = 0;

		// implement this as the mechanism can be shared
		T At() const
		{

		}

		size_t GetLength() const
		{
			return m_numOfNodes;
		}

		T operator[](const size_t index)
		{

		}

	protected:
		// root node/head of the list
		Node<T>* rootNodePtr;
		// last node/tail of the list
		Node<T>* tailNodePtr;

		size_t m_numOfNodes;

		Node<T>* GetHead() const { return rootNodePtr; }

		Node<T>* GetTail() const
		{
			// TODO(ILIst): modify the return type of this function to use an std::pair
			//  Node<T>* -> { index/iterator, Node<T>* }: so we can use the index to where we are in the list
			return HandleGetTail(rootNodePtr);
		}

	private:
		// uses line traversal via recursion from the HEAD through list
		Node<T>* HandleGetTail(Node<T>* nodePtr) const
		{
			// base case
			if (!nodePtr->right)
				return nodePtr;

			return HandleGetTail(nodePtr->right);
		}
	};
}


#endif