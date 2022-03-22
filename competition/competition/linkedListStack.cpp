#include "linkedListStack.h"

#include<assert.h>

template<class T>

linkedListStack<T>::linkedListStack()  // constractor of linkedListStack
{

	head = tail = 0;

	count = 0;

}

template <class T>

int linkedListStack<T>::Length()
{

	return count;

}

template<class T>

bool linkedListStack<T>::isEmpty()
{

	return head == 0;

}

template<class T>

void linkedListStack<T>::InsertAt(int pos, T  val)
{
	
		assert(pos >= 0 && pos < count);

		Node* tmp = head;

		Node* newNode = new Node;

		if (pos == 0)
		{

			newNode->next = head;

			head = newNode;

		}

		else
		{

			for (int i = 0; i < pos - 1; i++)

				tmp = tmp->next;

			newNode->next = tmp->next;

			tmp->next = newNode;

		}

		newNode->value = val;

		count++;
	
}

template<class T>

void linkedListStack<T>::Append(T newValue)
{

	Node* newPtr = new Node;

	newPtr->value = newValue;

	if (head == 0)
	{

		head = tail = newPtr;

	}

	else
	{

		newPtr->next = head;

		head = newPtr;

	}

	count++;

}

template <class T>

T linkedListStack<T>::At(int pos)
{

	assert(pos >= 0 && pos < count);

	Node* tmp = head;

	for (int i = 0; i < pos; i++)
	{
		tmp = tmp->next;

	}

	return tmp->value;

}

template<class T>

void linkedListStack<T>::DeleteAt(int pos)
{

	assert(pos >= 0 && pos < count);

	Node* tmp = head;

	if (pos == 0)
	{

		head = head->next;

		delete tmp;

	}

	else
	{

		for (int i = 0; i < pos - 1; i++)

			tmp = tmp->next;

		Node* del = tmp->next;

		tmp->next = del->next;

		delete del;

		if (pos == count - 1)

			tail = tmp;

	}

	count--;

}

template<class T>

void linkedListStack<T>::UndoAppend()  // delete last item Appended
{

	assert(! isEmpty());

	Node* temp = head;

	head = temp->next;

	temp->next = NULL;

	delete temp;

	count--;

}

template<class T>

void linkedListStack<T>::UndoInsertAt(int index) // to undo inserted number , i used DeleteAt function 
{

	assert(index >= 0 && index < count);

	Node* tmp = head;

	if (index == 0)
	{

		head = head->next;

		delete tmp;

	}

	else
	{

		for (int i = 0; i < index - 1; i++)

			tmp = tmp->next;

		Node* del = tmp->next;

		tmp->next = del->next;

		delete del;

		if (index == count - 1)

			tail = tmp;

	}

	count--;

}



template<class T>

linkedListStack<T>::~linkedListStack()
{

	while (count != 0)
	{

		DeleteAt(0);

	}
}

template <class T>

StackArr<T>::StackArr(void)
{

	size = 10;

	elements = 0;

	arr = new T[size];

}

template <class T>

int StackArr<T>::Length()
{

	return elements;

}

template <class T>

void StackArr<T>::Push(T val)
{

	if (elements == size)

		Expand();

	arr[elements] = val;

	elements++;

}

template <class T>

void StackArr<T>::Pop()
{

	assert(!empty());

	elements--;

}

template <class T>

T StackArr<T>::Top()
{

	assert(!empty());

	return arr[elements - 1];

}

template <class T>

bool StackArr<T>::empty()
{

	return (elements == 0);

}

template <class T>

void StackArr<T>::Expand()
{

	size += 5;

	T* tmp = new T[size];

	for (int i = 0; i < elements; i++)

		tmp[i] = arr[i];

	delete[] arr;

	arr = tmp;

}

template <class T>

StackArr<T>::~StackArr(void)
{

	delete[] arr;

}

