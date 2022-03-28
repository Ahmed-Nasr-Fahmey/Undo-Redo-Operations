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

	assert(pos >= 0 && pos <= count);

	if (pos == count) // to insert at last of my list 
	{

		Append(val);

	}

	else
	{


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

}

template <class T>

void linkedListStack<T>::Append(T newValue)
{

	Node* newNode = new Node;

	newNode->value = newValue;

	if (head == 0)
	{

		head = tail = newNode;

	}

	else
	{

		tail->next = newNode;

		tail = newNode;

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
		{

			tmp = tmp->next;

		}
		Node* del = tmp->next;

		tmp->next = del->next;

		delete del;

		if (pos == count - 1)
		{

			tail = tmp;

		}

	}

	count--;

}

template<class T>

void linkedListStack<T>::UndoAppend()  // delete last item Appended
{

	assert(!isEmpty());

	Node* newPtr = head;

	for (int i = 0; i < count - 2; i++)
	{

		newPtr = newPtr->next;

	}

	delete tail;

	tail = newPtr;

	tail->next = NULL;

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
		{

			tmp = tmp->next;

		}

		Node* del = tmp->next;

		tmp->next = del->next;

		delete del;

		if (index == count - 1)
		{

			tail = tmp;

		}

	}

	count--;

}

template<class T>

void linkedListStack<T>::LLswap(int pos1, int pos2) //to swap 2 values
{

	T temp;

	temp = At(pos1);


	DeleteAt(pos1);

	InsertAt(pos1, At(pos2 - 1));

	DeleteAt(pos2);

	InsertAt(pos2, temp);

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
	{

		Expand();

	}

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
	{

		tmp[i] = arr[i];

	}

	delete[] arr;

	arr = tmp;

}

template <class T>

StackArr<T>::~StackArr(void)
{

	delete[] arr;

}

