#include"linkedListStack.cpp"

#include<iostream>

using namespace std;

void testFunctionUndo()
{

	cout << "-------------- Welcom to my undo task --------------\n\n\n";

	linkedListStack<int>myList;         // A list to make operations on 

	undoOperations operation;           // Struct to push all operations on 

	undoOperations lastOperationDid;    // Just struct to store last operation done on

	StackArr<undoOperations>myStack;    // A stack to push operations and pop last operation as top 


	while (true)
	{

		cout << "1 )  Append item to your list . " << endl;

		cout << "2 )  Insert item to your list . " << endl;

		cout << "3 )  Delete item from your list . " << endl;

		cout << "4 )  Undo operation from your list . " << endl;

		cout << "5 )  Display your item list . " << endl;

		cout << "6 )  Exit .\n" << endl;

		cout << "Please enter your choice from 1 to 6 : ";

		int choice;

		cin >> choice;

		if (choice == 1) // Operation number one ===> Append 
		{

			operation.numOfOperation = choice;

			cout << "\n\nPlease enter number you want to append in your list : ";

			int number;

			cin >> number;

			myList.Append(number); // Append number to my list

			cout << endl << endl;

			myStack.Push(operation);  // Push operation to my stack

		}

		else if (choice == 2) // Operation number two ===> Insert number with index to my list
		{

			operation.numOfOperation = choice;

			cout << "\n\nPlease enter index of item you want to insert : ";

			cin >> operation.index; // index for inserted value

			cout << "\nPlease enter value you want to insert : ";

			int value;

			cin >> value;

			myList.InsertAt(operation.index, value);  // Insert number to my list

			cout << endl << endl;

			myStack.Push(operation); // Push operation to my stack

		}

		else if (choice == 3) // Operation number three ===> Delete number with index from my list
		{

			operation.numOfOperation = choice;

			cout << "\n\nPlease enter index of item you want to delete : ";

			cin >> operation.index;

			operation.deletedValue = myList.At(operation.index); // Store number with index befor deleting it 

			myList.DeleteAt(operation.index); // detete number

			myStack.Push(operation); // Push operation to my stack

			cout << "\n\nItem is deleted successfuly . \n" << endl;

		}

		else if (choice == 4) // Undo functions 
		{

			lastOperationDid = myStack.Top(); // Store data of last operation 

			if (lastOperationDid.numOfOperation == 1)  // Undo Append operation
			{

				myList.UndoAppend();   // Delete number was appended

			}

			else if (lastOperationDid.numOfOperation == 2)  // Undo InsertAt operation
			{

				myList.UndoInsertAt(lastOperationDid.index); // Delete number was inserted

			}

			else if (lastOperationDid.numOfOperation == 3) //Undo DeleteAt operaation
			{

				myList.InsertAt(lastOperationDid.index, lastOperationDid.deletedValue);  // Insert number was deleted

			}

			myStack.Pop(); // pop (Delete) last operation from my stack 

			cout << endl << endl;

		}

		else if (choice == 5) // Display my list 
		{

			cout << "\n\nYour item list is = [ ";

			for (int i = 0; i < myList.Length(); i++)
			{

				cout << myList.At(i) << "  ";

			}

			cout << "]\n" << endl;

		}

		else if (choice == 6) // Exit
		{

			break;

		}

		else // Case user enter invaled choice 
		{

			cout << "\n\nOOOPS!! , Invaled operation , Please enter choice from 1 to 7 only!\n\n";

		}

	}

}

int main()
{

	testFunctionUndo();

	system("pause");

}