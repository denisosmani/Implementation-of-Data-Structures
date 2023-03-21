#include <iostream>
using namespace std;

//1.Te krijohet ne ArrayList qe mban integer me kapacitet fiks
//- > Kapaciteti 100 anetar jodinamik
//- > Metoda at(int index), returns the number at index
//- > Metoda set(int index, int element), sets the element at index, by deleting the existing member
//- > Metoda length(), returns the actual length of the ArrayList
//- > Metoda remove(int index), removes the element at index, and shifts other members
//- > Metoda add(int element), adds an element, pushing back
//- > Metoda shtyp(), i shtyp anetaret

class ArrayList
{
private:
	int data[100];
	int n;
public:
	ArrayList()
	{
		this->n = 0;

		for (int i = 0; i < n; i++) {
			this->data[i] = 0;
		}
	}

	void add(int element)
	{
		this->data[n] = element;
		this->n++;
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

};

int main() {
	ArrayList lista = ArrayList();

	lista.shtyp();
	// [ ]

	lista.add(2);
	lista.shtyp();
	//[ 2 ]

	lista.add(4);
	lista.shtyp();
	//[ 2, 4 ]

	lista.add(-3);
	lista.shtyp();
	//[ 2, 4, -3 ]

	//cout << lista.at(1) << endl;
	// 4

	lista.set(1, 5);
	lista.shtyp();
	//[ 2, 5, -3]

	//cout << lista.at(1) << endl;
	//5

	lista.remove(1);
	lista.shtyp();
	//[ 2, -3]


	return 0;
}