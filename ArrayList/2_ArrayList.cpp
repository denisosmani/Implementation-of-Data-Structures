#include <iostream>
#define INITIAL_CAPACITY 10

using namespace std;

//2.Te krijohet nje ArrayList qe mban integer me kapacitet dinamik

class ArrayList
{
private:
	int* data;
	int n;
	int capacity;

	void resize()
	{
		int newCapacity = 2 * capacity;
		int* newData = new int[newCapacity];

		for (int i = 0; i < this->n; i++)
		{
			newData[i] = this->data[i];
		}

		delete[] this->data;
		this->data = newData;
		this->capacity = newCapacity;

	}

	//Konstruktori i kopjimit
	ArrayList(const ArrayList&) = delete;
	//Operatori i shoqërimit
	ArrayList& operator = (const ArrayList&) = delete;

public:
	ArrayList()
	{
		this->n = 0;
		this->capacity = INITIAL_CAPACITY;
		this->data = new int[INITIAL_CAPACITY];
	}
	ArrayList(ArrayList&& rval)
	{
		this->n = rval.n;
		this->capacity = rval.capacity;
		this->data = rval.data;
		rval.data = NULL;
	}
	~ArrayList()
	{
		delete[] this->data;
	}

	void add(int element)
	{
		this->data[n] = element;
		this->n++;

		if (this->n == this->capacity - 1) {
			this->resize();
		}
	}

	void shtyp() const
	{
		cout << "[ ";
		for (int i = 0; i < n; i++)
		{
			cout << this->data[i];

			if (i <= this->n - 2)
			{
				cout << ", ";
			}
		}
		cout << " ]" << endl;
	}
	int at(int index) const
	{
		return this->data[index];
	}

	void set(int index, int element)
	{
		this->data[index] = element;
	}

	int length() { return this->n; }

	void remove(int index)
	{
		for (int i = index; i < n; i++)
		{
			this->data[index] = this->data[index + 1];
		}
		this->n--;
	}

	int getCapacity()
	{
		return this->capacity;
	}

};

int main() {
	ArrayList lista = ArrayList();
	lista.add(2);
	lista.add(3);
	lista.shtyp();
	cout << "Kapaciteti: " << lista.getCapacity() << endl;


	for (int i = 0; i < 12; i++)
	{
		lista.add(i);
	}
	lista.shtyp();
	cout << "Kapaciteti: " << lista.getCapacity();

	return 0;
}




/* Deleting the copy constructor and the assignment operator with = delete means that the class is not copyable.
This is often used when the class manages dynamically allocated resources, such as memory or file handles,
that cannot be safely copied.If you allow the class to be copied using the default copy constructor and assignment operator,
you run the risk of creating copies of the class that have shared ownership of the same resources, which can lead to issues
like memory leaks or resource exhaustion. */