#pragma once
#include <iostream>
#include <iomanip>
#include "Users.h"

template<typename T>
struct Node { // Структура узла данных
	Node()
		:next{}, data{}
	{}

	Node(const T& d, Node<T>* Node = nullptr)
		:data{ d }, next{ Node }
	{}

	T data;
	Node<T>* next;
};

template <typename T>
class MyQueue { // Класс очереди
	Node<T>* first;
	Node<T>* last;
	size_t count;
	std::string title; // Название очереди
	std::string fileName; // Путь к исходному файлу очереди
	std::string adminPassword;
	Date date;

	void clear();
	void copy(const MyQueue<T>&);

	template <typename T>
	friend std::ostream& operator<<(std::ostream&, const MyQueue<T>&);

	template <typename T>
	friend std::istream& operator>>(std::istream&, MyQueue<T>&);

public:
	//Constructors
	MyQueue();
	MyQueue(const T&);
	MyQueue(const MyQueue&);
	MyQueue(MyQueue&&) noexcept;
	const MyQueue<T>& operator=(const MyQueue<T>&);
	~MyQueue();

	//Methods
	void queue(const T&); // Добавление элемента в очередь
	void dequeue(); // Удаление элемента из очереди (первого)
	bool isEmpty() const { return first == nullptr; } // Проверка очереди на пустоту

	Node<T>* beg() const { return first; } // Возвращает указатель на первый элемент очереди
	Node<T>* end() const { return last; } // Возвращает указатель на последний элемент очереди
	size_t length() const { return count; } // Возвращает общую длинну очереди (количество элементов в очереди)
	std::string GetTitle() const { return title; } // Возвращает название очереди
	std::string GetFileName() const { return fileName; } // Возвращает имя файла, в котором хранится очередь.
	std::string GetAdminPassword() const { return adminPassword; }
	double GetCongestion() const { return congestion; }
	std::string SetTitle(std::string title) { return this->title = title; } // Возвращает название очереди
	std::string SetFileName(std::string fileName) { return this->fileName = fileName; } // Возвращает имя файла, в котором хранится очередь.
	std::string SetAdminPassword(std::string adminPassword) { return this->adminPassword = adminPassword; } // Возвращает имя файла, в котором хранится очередь.
	double SetCongestion(double congestion) { return this->congestion = congestion; } // Возвращает имя файла, в котором хранится очередь.
	size_t Day() { return date.day; }
	size_t Month() { return date.month; }
	size_t Year() { return date.year; }
	void Day(size_t day) { date.day = day; }
	void Month(size_t month) { date.month = month; }
	void Year(size_t year) { date.year = year; }
	bool SetData(size_t, std::string);
	Node<T>* find(size_t);
};

template<typename T>
std::ostream& operator<<(std::ostream& out, MyQueue<T>& que) {
	out << que.GetFileName() << std::endl << que.GetTitle() << std::endl << que.GetAdminPassword() << std::endl << que.length() << std::endl << que.Day() << ' ' << que.Month() << ' ' << que.Year() << std::endl;
	Node<T>* it{ que.beg() };
	while (it) {
		out << it->data.ownNumber << " | " << it->data.time.hours << " : " << it->data.time.minutes << " |" << it->data.surnameNP << std::endl;
		it = it->next;
	}
	out << std::endl;

	return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, MyQueue<T>& que) {
	size_t tmpCount{};
	in >> que.fileName >> que.title >> que.adminPassword >> tmpCount >> que.date.day >> que.date.month >> que.date.year;
	for (size_t i = 0; i < tmpCount; i++) {
		queueData data;
		que.queue(data);
	}
	Node<T>* it{ que.beg() };
	while (it) {
		char tempChar;
		in >> it->data.ownNumber >> tempChar >> it->data.time.hours >> tempChar >> it->data.time.minutes >> tempChar;// >> data.surnameNP;
		char tempCharArr[60];
		in.getline(tempCharArr, 60, '\n');
		it->data.surnameNP = tempCharArr;
		//in >> it->data;
		it = it->next;
	}

	return in;
}

template <typename T>
MyQueue<T>::MyQueue()
	:first{}, last{}, count{}
{}

template <typename T>
MyQueue<T>::MyQueue(const T& v)
	: first{ new Node<T>{v} }, last{ first }, count{ 1 }
{}

template <typename T>
MyQueue<T>::MyQueue(const MyQueue<T>& B) {
	//cout << "Copy constructor...\n";
	if (!B.isEmpty()) {
		count = B.count;
		cout << B.first->data << endl;
		first = new Node<T>{ B.first->data };

		Node<T>* pB{ B.first->next };
		Node<T>* pA{ first };
		while (pB) {
			//cout << pB->data << endl;
			pA->next = new Node<T>{ pB->data };
			pB = pB->next;
			pA = pA->next;
		}

		last = pA;
		pA = nullptr;
		pB = nullptr;
	}
}

template <typename T>
MyQueue<T>::MyQueue(MyQueue<T>&& B) noexcept {
	//cout << "Move constructor...\n";
	first = B.first;
	last = B.last;
	count = B.count;

	B.first = B.last = nullptr;
	B.count = 0;
}

template <typename T>
void MyQueue<T>::clear() {

	//cout << "Method clear...\n";
	MyQueue<T>* curr{};
	while (first) {
		curr = first;
		first = first->next;
		//cout << curr->data << endl;
		delete curr;
	}

	curr = last = nullptr;
	count = 0;
}

template <typename T>
void MyQueue<T>::copy(const MyQueue<T>& B) {
	if (!B.isEmpty()) {
		MyQueue<T>* pOther{ B.first };
		first = new Node<T>{ pOther->data };
		Node<T>* pThis{ first };
		pOther = pOther->next;

		while (pOther) {
			pThis->next = new Node<T>{ pOther->data, pThis };
			pOther = pOther->next;
			pThis = pThis->next;
		}

		count = B.count;
		last = pThis;
		pThis = pOther = nullptr;
	}
}

template <typename T>
const MyQueue<T>& MyQueue<T>::operator=(const MyQueue<T>& B) {
	//cout << "operator=()...\n";
	if (this != &B) {
		Node<T>* ptr{};
		while (first) {
			ptr = first;
			first = first->next;
			//cout << "free memory: " << ptr->data << endl;
			delete ptr;
		}
		last = nullptr;
		count = 0;

		if (!B.isEmpty()) {
			count = B.count;
			Node<T>* ptrB{ B.first };
			first = new Node<T>{ ptrB->data };
			Node<T>* ptrA{ first };
			ptrB = ptrB->next;
			while (ptrB) {
				ptrA->next = new Node<T>{ ptrB->data };
				ptrB = ptrB->next;
				ptrA = ptrA->next;
			}
			last = ptrA;
			ptrA = nullptr;
		}
	}
	return *this;
}

template <typename T>
MyQueue<T>::~MyQueue() {
	//cout << "Destructor...\n";
	Node<T>* del{};
	while (first) {
		del = first;
		//cout << del->data << endl;
		first = first->next;
		delete del;
	}
	last = nullptr;
	count = 0;
}

template <typename T>
void MyQueue<T>::queue(const T& d) {
	if (isEmpty()) {
		first = last = new Node<T>{ d };
	}
	else {
		last->next = new Node<T>{ d };
		last = last->next;
	}

	count++;
}

template <typename T>
void MyQueue<T>::dequeue() {
	Node<T>* toDel{ first };

	first = first->next;
	if (toDel == last)
		last = nullptr;

	delete toDel;
	count--;
}

template <typename T>
bool MyQueue<T>::SetData(size_t search, std::string data) {
	Node<queueData>* toSet{ first };

	while (toSet && toSet->data.ownNumber != search)
		toSet = toSet->next;
	
	if (toSet->data.ownNumber == search)
		toSet->data.surnameNP = data;

	return toSet->data.surnameNP == data;
}

template <typename T>
Node<T>* MyQueue<T>::find(size_t search) {
	Node<queueData>* toSet{ first };

	while (toSet && toSet->data.ownNumber != search)
		toSet = toSet->next;

	return toSet->data.ownNumber == search ? toSet : nullptr;
}