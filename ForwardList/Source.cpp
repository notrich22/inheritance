#include <iostream>
using namespace std;
#define tab "\t"
using std::cin;
using std::cout;
using std::endl;
class Element
{
	int Data;
	Element* pNext;
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext) {
		cout << "EConst:\t" << this << endl;
		count++;
	}
	~Element() {
		cout << "EDestr:\t"<< this << endl;
		count--;
	}
	friend class List;
};
int Element::count = 0;
class List {
	Element* Head;
	size_t size;
public:
	List(size_t size) :List() {
		while (size--)push_front(0);
	}
	List() {
		this->Head = nullptr;
		this->size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~List() {
		cout << "LDestructor:\t" << this << endl;
	}
	List(const List& other) :List() {
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LCopyConstructor: " << this << endl;
	}
	//Operators
	List& operator=(const List& other) {
		if (this == &other) return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LCopyAssignment: " << this << endl;
		return *this;
	}
	int& operator[](size_t index) {
		if (index >= size)throw std::exception("Error: Out of range");
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
		return Temp->Data;
	}
	//int operator=()
	// Adding elements
	void push_front(int Data) {
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data) {
		if (Head == nullptr)return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		Temp->pNext = new Element(Data);
		size++;
	}
	void pop_front() {
		Element* Temp = Head;
		Head = Head->pNext;
		delete Temp;
		size--;
	}
	void pop_back() {
		if (Head == nullptr)return;
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void insert(int index, int data) {
		if (index > size)return;
		if (!index)return push_front(data);
		Element* New = new Element(data);
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)Temp = Temp->pNext;
		Temp->pNext = new Element(data, Temp->pNext);
		size++;
	}
	void erase(int index) {
		if (index > size)return;
		if (!index)return pop_front();
		Element* Temp = Head;
		Element* pnext_temp = nullptr;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		pnext_temp->pNext = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = pnext_temp->pNext;
		delete pnext_temp;
	}
	void print()const {
		/*Element* Temp = Head;
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}*/
		for(Element* Temp=Head; Temp; Temp=Temp->pNext)	
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Кол-во элементов списка: " << size << endl;
		cout << "Кол-во элементов всех списков: " << Element::count << endl;
	}
};
#define COPY_METHODS
//#define LIST_METHODS_CHECK
int main() {
	setlocale(LC_ALL, "ru");
#ifdef LIST_METHODS_CHECK
	int n; cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++) {
		list.push_front(rand() % 100);
	}
	list.print();
	list.push_back(5);
	list.print();
	list.pop_back();
	list.print();
	int index;
	int value;
	cout << "Enter index: "; cin >> index;
	cout << "Enter value: "; cin >> value;
	//Insert
	list.insert(index, value);
	list.print();
	List list2;
	list2.push_back(1024);
	list2.push_back(2048);
	list2.push_back(3072);
	list2.print();
	int del_index;
	//Erase
	cout << "Enter index to delete: "; cin >> del_index;
	list2.erase(del_index);
	list2.print();
#endif // LIST_METHODS_CHECK
#ifdef DEBUG
	int n; cout << "Введите размер списка: "; cin >> n;
	List list(n);
	try
	{

		for (int i = 0; i < n; i++) {
			list[i] = rand() % 100;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	list.print();
#endif // DEBUG
#ifdef COPY_METHODS
	int n; cout << "Введите размер списка: "; cin >> n;
	List list(n);
	list.push_back(3);
	list.push_back(5);
	list.push_back(8);
	list.push_back(13);
	list.push_back(21);
	list.print();
	List list2 = list;
	list2.print();
	List list3;
	list3 = list2;
	list3.print();
	
#endif // COPY_METHODS
}