#pragma once

struct undoOperations
{

	int numOfOperation; // 1) to Append && 2) to Insert && 3) Delete

	int index = -1; // To control opeations 

	int deletedValue = -1; // To store value befor deleting it to undo it after deleting  

};


template<class T>

class linkedListStack // LinkdList using stack
{

private:

	struct Node
	{

		T value;

		Node* next;

	};

	int count;

	Node* head;

	Node* tail;

public:

	linkedListStack(void); // constractor

	int Length();  // return number of elements

	bool isEmpty(); // check if list is empty or not

	void InsertAt(int, T); // insert item to list

	void Append(T); // insert item to last of list

	T At(int); // return item using index of this item

	void DeleteAt(int); // delete item from list

	void UndoAppend(); // undo append operation

	void UndoInsertAt(int); // undo insert operation

	~linkedListStack(void); // disrtactor

};

template <class T>

class StackArr     // stack class
{

	T* arr;

	int elements;

	int size;

public:

	StackArr(void);  // constractor

	int Length(); // return number of elements

	void Push(T); // push item to stack

	void Pop(); // delete last item from stack

	T Top(); // return last item from stack

	bool empty(); // check if list is empty or not

	void Expand(); // increas size of arr

	~StackArr(void);  // disrtactor

};

