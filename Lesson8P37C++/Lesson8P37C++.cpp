#include <iostream>
using namespace std;
//реалізувати з допомогою template
template<typename T>
struct Element
{
	T data;
	Element<T>* next;
	Element(T value)
	{
		data = value;
		next = nullptr;
	}
};
template<typename T>
class Queue
{
private:
	Element<T>* head;
	Element<T>* tail;
public:
	Queue() {
		head = tail = nullptr;
	}
	//додавання елемента до черги
	void enqueue(T value)
	{
		Element<T>* newElement = new Element<T>(value);
		if (tail == nullptr)
		{
			head = tail = newElement;
			return;
		}
		tail->next = newElement;
		tail = newElement;

	}
	//видалити елемент з черги
	T dequeue()
	{
		Element<T>* tmp = head;
		head = head->next;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		T val = tmp->data;
		delete tmp;
		tmp = nullptr;
		return val;
	}
	//перевірити чи черга не порожня
	bool isEmpty() const
	{
		return head == nullptr;
	}
	//метод який повертає вершину
	Element<T>* getHead() const
	{
		return head;
	}
	//отримати елемент з початку черги
	T peek()
	{
		return head->data;
	}
	//реалізувати деструктор
	~Queue()
	{
		while (this->isEmpty()==false)
		{
			this->dequeue();
		}
		head = tail = nullptr;
	}
};
//допоміжна рекурсивна ф-ція для друку
template<typename T>
void printReverse(Element<T>* element)
{
	if (element == nullptr)
		return;
	printReverse(element->next);
	cout << element->data << endl;
}

//написати ф-цію, яка роздруковує елементи черги в зворотньому порядку без видалення
template<typename T>
void  printQueueReverse(const Queue<T> &q)
{
	Element<T>* head = q.getHead();
	printReverse(head);
}

int main()
{
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	/*while (q.isEmpty()==false)
	{
		cout << q.dequeue() << endl;
	}*/
	printQueueReverse(q);

}


