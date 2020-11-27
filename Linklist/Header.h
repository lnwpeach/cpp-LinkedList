#include <iostream>
#include <string>
using namespace std;
template <class object>
class List;

template <class object>
class ListItr;

template <class object>
class ListNode
{
	ListNode(const object &theElement = object(), ListNode *n = NULL)
	:element(theElement), next(n) {}

	object element;
	ListNode *next;

	friend class List<object>;
	friend class ListItr<object>;

};
////////////////////////listitr////////////////////
template <class object>
class ListItr {

public:
	ListItr() : current(NULL) { }

	bool isPastEnd()const {
		return current == NULL;
	}
	void advance() {
		if (!isPastEnd())
			current = current->next;
	}
	const object & retrieve()const
	{
		if (isPastEnd())
			return 0;
		return current->element;
	}
private:
	ListNode<object> *current;
	ListItr(ListNode<object> *theNode) :current(theNode) {}
	friend class List<object>;

};

/////////////////////////list//////////////////
template <class object>
class List
{
public:
	List();
	List(const List &rhs);
	~List();


	bool isEmptry()const;
	void makeEmptry();
	ListItr<object> zeroth() const;
	ListItr<object> first() const;
	void insert(const object & x, const ListItr<object> &p);
	ListItr<object> find(const object &x)const;
	ListItr<object> findback()const;
	ListItr<object> findPrevious(const object &x)const;
	void remove(const object &x);
	object findcount();
	object findposition(const object &x)const;
	const List & operator=(const List &rhs);

private:
	ListNode<object> *header;
};

template <class object>
List<object>::List()
{
	header = new ListNode<object>;
}

template <class object>
bool List<object>::isEmptry()const
{
	return header->next == NULL;
}

template <class object>
ListItr<object>List<object>::zeroth()const
{
	return ListItr<object>(header);
}

template <class object>
ListItr<object>List<object>::first()const
{
	return ListItr<object>(header->next);
}

template <class object>
void printList(const List<object> &theList)
{
	string line(50, '*');
	cout << line << endl;
	if (theList.isEmptry()) {

		cout << "\t\t----Empty List---" << endl;

	}
	else
	{
		ListItr<object> itr = theList.first();
		printf("Linked List = ");
		for (; !itr.isPastEnd(); itr.advance())
			cout << itr.retrieve() << " ";
	}
	cout << endl << line << endl;

}

template <class object>
ListItr<object>List<object>::find(const object &x)const
{
	ListNode<object> *itr = header->next;
	while (itr != NULL&&itr->element != x)
		itr = itr->next;
	return ListItr<object>(itr);
}

template <class object>
void List<object>::remove(const object &x)
{
	ListItr<object> p = findPrevious(x);
	if (p.current->next != NULL) {
		ListNode<object> *oldNode = p.current->next;
		p.current->next = p.current->next->next;
		delete oldNode;
	}
}

template <class object>
ListItr<object>List<object>::findPrevious(const object &x)const
{
	ListNode<object> *itr = header;
	while (itr->next != NULL&&itr->next->element != x)
		itr = itr->next;
	return ListItr<object>(itr);
}

template <class object>
void List<object>::insert(const object &x, const ListItr<object> &p)
{
	if (p.current != 0)
		p.current->next = new ListNode<object>(x, p.current->next);
}

template <class object>
void List<object>::makeEmptry() {
	while (!isEmptry())
		remove(first().retrieve());
}

template <class object>
List<object>::~List() {
	makeEmptry();
	delete header;
}

template<class Object>
Object List<Object>::findcount()
{
	Object count = 0;
	ListNode<Object> *itr = header->next;

	while (itr != NULL)
	{
		count++;
		itr = itr->next;
	}
	return count;
}
template<class Object>
Object List<Object>::findposition(const Object &x)const
{
	Object result;
	ListNode<Object> *itr = header->next;
	if (itr != NULL) {

		for (int i = 1; i <x; i++)
			itr = itr->next;
		result = itr->element;
	}
	else
		result = 0;

	return result;
}

template<class Object>
ListItr<Object>List<Object>::findback()const
{
	ListNode<Object> *itr = header->next;

	while (itr->next != NULL)
		itr = itr->next;

	return ListItr<Object>(itr);
}
