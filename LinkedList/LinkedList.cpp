#include <iostream>

using namespace std;

//-addFront
//-addBack
//-printNodes
//-removeHead
//-remove at index
//-Reverse
template <typename T>
struct Node
{
	T value;
	Node* next;
};

template <typename T>
class LinkedList
{

private:
	Node<T>* head;
	Node<T>* current;
	Node<T>* tail;
	int size;

public:
	LinkedList()
	{
		head = NULL;
		current = NULL;
		tail = NULL;
		this->size = 0;
	}
	~LinkedList()
	{
		Node<T>* current = this->head;

		while (1)
		{
			Node<T>* next = current->next;
			delete current;
			current = next;

			if (next == NULL)
			{
				break;
			}

		}
	}
	void addBack(T element)
	{
		Node<T>* newNode = new Node<T>{ element, NULL };
		if (head == NULL)
		{
			this->head = newNode;
			this->current = newNode;
			this->tail = newNode;
		}
		this->current = newNode;
		this->tail->next = current;
		this->tail = current;

	}

	void addFront(T element)
	{
		Node<T>* newNode = new Node<T>{ element, this->head };
		this->head = newNode;
	}

	void getTail()
	{
		if (this->tail == NULL)
		{
			throw "Error!";
			return;
		}
		cout << this->tail->value << endl;
	}
	void getHead()
	{
		if (this->head == NULL)
		{
			throw "Error!";
			return;
		}

		cout << this->head->value << endl;
	}

	void printList()
	{
		Node<T>* current = this->head;
		cout << "[ ";
		while (1)
		{
			cout << current->value;
			current = current->next;

			if (current == NULL)
			{
				break;
			}
			cout << ", ";
		}
		cout << " ]" << endl;

	}

	int Size()
	{
		int n = 0;
		Node<T>* current = this->head;
		while (1)
		{
			current = current->next;
			n++;
			if (current == NULL)
			{
				break;
			}
		}
		return n;
	}


	void removeHead()
	{
		if (this->head == NULL)
		{
			return; //nothing to erase
		}

		Node<T>* newHead = this->head->next;
		delete this->head;
		this->head = newHead;
	}

	void remove(int index)
	{
		Node<T>* current = this->head;
		Node<T>* oneBefore = NULL;
		while (index != 0)
		{
			oneBefore = current; //pointer i nyjes perpara asaj qe fshihet
			current = current->next;//pointer i nyjes qe fshihet
			index--;
		}
		oneBefore->next = current->next;

		delete current; //dealokohet lokacioni i nyjes qe fshihet
	}

	void Reverse()
	{
		int size = Size();
		Node<T>* tempLeft = this->head; //pointon te 0
		Node<T>* current = tempLeft->next;//pointon te 1
		Node<T>* tempRight = current->next; //pointon te 2

		while (size != 0)
		{
			if (current != NULL)//check if tail
			{
				current->next = tempLeft;//1 pointon te 0
			}

			tempLeft = current;          //0 behet 1
			current = tempRight;         //1 behet 2

			if (tempRight != NULL) //check if tail
			{
				tempRight = tempRight->next; //2 behet 3
			}
			size--;
		}

		this->head->next = NULL;
		current = this->head;
		this->head = this->tail;
		this->tail = current;

	}
};


int main()
{

	LinkedList<int> lista;
	LinkedList<string> lista_string;

	//--------------------------------------
	lista.addBack(5);
	lista.addBack(9);
	lista.addBack(15);
	lista.addBack(68);
	lista.printList();
	//[5, 9, 15, 68]

	cout << "Tail: ";
	lista.getTail();
	cout << "Head: ";
	lista.getHead();
	cout << "Size: " << lista.Size() << endl << endl;

	//--------------------------------------
	lista.addFront(1);
	lista.printList();
	//[1, 5, 9, 15, 68]

	cout << "Tail: ";
	lista.getTail();
	cout << "Head: ";
	lista.getHead();

	cout << "Size: " << lista.Size() << endl << endl;

	//--------------------------------------
	lista.removeHead();
	lista.printList();
	cout << "Head: ";
	lista.getHead();
	cout << "Size: " << lista.Size() << endl << endl;

	//--------------------------------------

	lista.remove(1);
	lista.printList();
	cout << "Head: ";
	lista.getHead();
	cout << "Tail: ";
	lista.getTail();
	cout << "Size: " << lista.Size() << endl << endl;
	//-------------------------------------
	lista.addBack(13);
	lista.addBack(19);
	lista.addBack(67);
	lista.addBack(74);

	cout << "Reverse: " << endl;
	lista.printList();
	lista.Reverse();
	lista.printList();
	//--------------------------------------
	lista_string.addBack("First");
	lista_string.addBack("Second");
	lista_string.addBack("Third");
	cout << endl;
	cout << "String list:" << endl;
	lista_string.printList();

	return 0;
}