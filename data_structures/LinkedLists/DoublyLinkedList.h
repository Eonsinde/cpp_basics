#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

#include "IList.h"

namespace Learning {
	template<typename T>
	class DoublyLinkedList : public IList<T>
	{
	public:
		DoublyLinkedList() = default;

		DoublyLinkedList(std::initializer_list<T> data)
			: IList<T>(data) {

		}

		virtual ~DoublyLinkedList()
		{

		}

		virtual size_t Append(T value) override
		{
			// if the HEAD node's data is not set
			//if (!(*(this->rootNodePtr->data)))


			// create new node
			Node<T>* newNode = new Node<T>(value);
			// set the left node reference for the new node to the current tail node
			newNode->left = this->tailNodePtr;
			// set the right node reference of the current tail to the new node
			newNode->left->right = newNode;
			// make new node the tail node by setting its right/next to null
			newNode->right = nullptr;

			// update the tail node to the new node
			this->tailNodePtr = newNode;

			++m_numOfNodes;

			// returns the index of the newNode in the list
			return m_numOfNodes - 1;
		}

		virtual size_t Insert(T value, size_t pos) override
		{
			return 0;
		}

		virtual int Find(T item) const override
		{
			// use index to keep track of the position of the nodes in the list
			int index = 0;

			return HandleFind(this->rootNodePtr, item, index);
		}

		virtual bool Remove(T item) override
		{
			return 1;
		}

	private:
		// uses line traversal from the HEAD move through list
		int HandleFind(Node<T>* nodePtr, T item, int& index) const
		{
			// firstly check if the item is found on the current node, then return the index in the list
			if (*(nodePtr->data) == item)
				return index;

			// base case: if the tail is reached
			if (!nodePtr->right) {
				index = -1;
				return index;
			}

			// increment index here
			index++;

			return HandleFind(nodePtr->right, item, index);
		}
	};
}

#endif