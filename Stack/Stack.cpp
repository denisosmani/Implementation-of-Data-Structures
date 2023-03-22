#include <iostream>
#define INITIAL_CAPACITY 3
using namespace std;
//-push
//-pop
//-print
//-getCapacity
//-empty
//-emplace - replaces the last element on stack



template<typename T>
class Stack 
{
private:
	int top;
	T* data;
	int capacity;
	void Resize() 
	{
		int newCapacity = 2 * capacity;
		T* newData = new T[newCapacity];

		for (int i = 0; i < capacity; i++) 
		{
			newData[i] = data[i];
		}
		delete[] this->data;//i liron heap locations
		this->data = newData;
		this->capacity = newCapacity;

	}
	
	//Konstruktori i kopjimit
	Stack(const Stack&) = delete;
	//Operatori i shoqërimit
	Stack& operator = (const Stack&) = delete;

public:
	Stack() 
	{
		this->top = 0;
		this->capacity = INITIAL_CAPACITY;
		this->data = new T[capacity];
	}

	Stack (Stack&& RValue) 
	{
		this->top = RValue.top;
		this->capacity = RValue.capacity;
		this->data = RValue.data;
		RValue.data = NULL;
	}

	~Stack() {
		delete[] data;
	}
	void Push(T element)
	{
		this->data[top] = element;
		top++;

		if (this->top == this->capacity) 
		{
			this->Resize();
		}
	}
	void Pop() 
	{
		this->top--;
	}
	int getCapacity() 
	{
		return this->capacity;
	}

	void Print() 
	{
		cout << "[ ";
		for (int i = 0; i < this->top; i++) 
		{
			cout << this->data[i];
			if (i != this->top - 1) {
				cout << ", ";
			}
		}
		cout << " ]\n";
	}

	bool Empty() 
	{
		bool empty;
		if (top != 0) {
			empty = false;
		}
		else
		{
			empty = true;
		}
		return empty;
	}
	void Emplace(int element) 
	{
		data[this->top - 1] = element;
	}
};

int main() {

	Stack<int> s = Stack<int>();
	Stack<string> s0 = Stack<string>();

	s.Push(3);
	s.Push(4);

	s.Print();
	cout << "Kapaciteti: " << s.getCapacity() << endl;
	
	s.Push(8);
	s.Print();
	cout << "Kapaciteti: " << s.getCapacity() << endl;

	s.Emplace(9);
	s.Print();

	s0.Push("Denis");
	s0.Push("Osmani");
	s0.Push("Stack");
	s0.Print();
	cout << "Kapaciteti: " << s0.getCapacity()<<endl;

	return 0;
}