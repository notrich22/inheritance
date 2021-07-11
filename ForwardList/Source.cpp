#include <iostream>
using namespace std;
#define tab "\t"
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
	List() {
		this->Head = nullptr;
		this->size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~List() {
		cout << "LDestructor:\t" << this << endl;
	}
	// Adding elements
	void push_front(int Data) {
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
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
		New->pNext= Temp->pNext;
		Temp->pNext = New;
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
		Element* Temp = Head;
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
		cout << "Кол-во элементов списка: " << size << endl;
		cout << "Кол-во элементов всех списков: " << Element::count << endl;
	}
};
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

}