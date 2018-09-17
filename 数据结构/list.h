#pragma once

template<typename T>
class List;

template<typename T>
class ListNode {
	friend class List<T>;
private:
	T * data;
	ListNode<T> * next;
	ListNode() : data(nullptr), next(nullptr) {}
	ListNode(const T& item) : data(new T(item)), next(nullptr) {}
	ListNode(const ListNode& listNode) : next(nullptr) {
		if (listNode.data == nullptr)
			data = nullptr;
		else
			data = new T(*(listNode.data));
	}

	~ListNode() {
		delete data;
	}
};

template<typename T>
class List {
public:
	List() : head(nullptr), pCurrent(nullptr) {}
	~List() {
		while (head != nullptr) Delete_Head();
	}

	void InsertToFront(const T& item) {
		ListNode<T> * pNewListNode = new ListNode<T>(item);
		pNewListNode->next = head;
		head = pNewListNode;
	}
	
	void InitIteration() {
		pCurrent = head;
	}

	bool Next() const {
		return pCurrent != nullptr;
	}

	void IterationStep() {
		pCurrent = pCurrent->next;
	}

	T * GetCurrentItemPointer() {
		return pCurrent->data;
	}
	T& GetCurrentItem() {
		return (*(pCurrent->data));
	}

	const T& GetConstCurrentItem() const {
		return (*(pCurrent->data));
	}

	void Sort(bool(*compare)(const T& lhs, const T& rhs)) {
		if (head == nullptr) return;
		Bubble_Sort(head, compare);
	}

	T * Search(const T& _data,
			   bool(*compare)(const T& lhs, const T& rhs) = [](const T& lhs, const T& rhs)->bool
			   { return lhs == rhs;}) {
		ListNode<T> * pListNode;
		for (pListNode = head; pListNode != nullptr; pListNode = pListNode->next) {
			if (compare(_data, *(pListNode->data)))
				return pListNode->data;
		}
		return nullptr;
	}

private:

	ListNode<T> * head;
	ListNode<T> * pCurrent;
	void Delete_Head() {
		if (head == nullptr)
			return;
		else {
			pCurrent = head;
			head = head->next;
			delete pCurrent;
		}
	}
	void Swap_Data(ListNode<T> * one, ListNode<T> * two) {
		T * pTemp = one->data;
		one->data = two->data;
		two->data = pTemp;
	}

	void Bubble_Sort(ListNode<T> * EndPos, bool(*compare)(const T& lhs, const T& rhs)) {
		if (EndPos == nullptr) return;
		Bubble_Sort(EndPos->next, compare);
		for (ListNode<T> * BeginPos = head; BeginPos != EndPos; BeginPos = BeginPos->next) {
			if (!compare(*(BeginPos->data), *(BeginPos->next->data))) {
				Swap_Data(BeginPos, BeginPos->next);
			}
		}
	}
};
