#include <iostream>
#include <vector>
#define INITIAL_CAPACITY 10
using namespace std;

// 3. Tipi i te dhenave te jete i cfaredoshem

template<typename T>
class ArrayList {
private:
    T* data;
    int n;
    int capacity;

    void resize() {
        int newCapacity = 2 * capacity;
        T* newData = new T[newCapacity];
        for (int i = 0; i < this->n; i++) {
            newData[i] = this->data[i];
        }

        delete[] this->data;
        this->data = newData;
        this->capacity = newCapacity;
    }

    // Konstruktori i kopjimit.
    ArrayList(const ArrayList&) = delete;
    // Operatori i shoqërimit.
    ArrayList& operator=(const ArrayList&) = delete;

public:
    ArrayList() {
        this->n = 0;
        this->capacity = INITIAL_CAPACITY;
        this->data = new T[INITIAL_CAPACITY];
    }

    ArrayList(ArrayList&& rval) {
        this->n = rval.n;
        this->capacity = rval.capacity;
        this->data = rval.data;
        rval.data = NULL;
    }

    ~ArrayList() {
        cout << "Duke fshire vargun." << endl;
        delete[] this->data;
    }

    T at(int index) {
        if (index < 0 || index >= this->n) {
            throw "Jashte kufijve."; // cout << "Jashte kufijve." << endl;
        }

        return this->data[index];
    }

    void set(int index, int element) {
        if (index < 0 || index >= this->n) {
            throw "Jashte kufijve.";
        }

        this->data[index] = element;
    }

    int length() {
        return this->n;
    }

    int getCapacity() {
        return this->capacity;
    }

    void remove(int index) {
        if (index < 0 || index >= this->n) {
            throw "Jashte kufijve.";
        }

        // 1 2 3 4 5 6
        //   ^
        // 1 3 4 5 6
        for (int i = index; i < n - 1; i++) {
            this->data[i] = this->data[i + 1];
        }

        this->n--;
    }

    ArrayList<T>& add(T element) {
        if (this->n >= this->capacity) {
            this->resize();
        }

        data[n] = element;
        this->n++;
        return *this;
    }

    void shtyp() {
        cout << "[ ";
        for (int i = 0; i < this->n; i++) {
            cout << this->data[i];
            if (i < this->n - 1) {
                cout << ", ";
            }
            else {
                cout << " ";
            }
        }

        cout << "]" << endl;
    }
};

int main() {
    ArrayList<int> lista_int = ArrayList<int>();
    lista_int.add(1);
    lista_int.add(2);
    lista_int.add(3);
    lista_int.shtyp();

    ArrayList<int> lista = ArrayList<int>();
    lista.add(5).add(3).add(10).add(11).shtyp();
    // 5 3 10 11

    ArrayList<string> lista_str = ArrayList<string>();
    lista_str.add("Hello");
    lista_str.add("Howdy");
    lista_str.add("Hi");
    lista_str.shtyp();

    ArrayList<char> lista_char;
    lista_char.add('a');
    lista_char.add('b');
    lista_char.add('c');
    cout << lista_char.length() << endl; // 3
    cout << lista_char.at(1) << endl;

    std::vector<int> v = { 7, 5, 16, 8 };

    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << endl;
    }

    auto v2 = v;
    v.push_back(100);
    cout << v.back() << endl;
    cout << v2.back() << endl;

    return 0;
}

// [ 1, 2, 3 ]
// [ Hello, Howdy, Hi ]
