#include "pch.h"
#include <iostream>

using namespace std;

template <class INF, class FRIEND>
class ListNode {
private:
	INF d;
	ListNode* next;
	ListNode() :next(NULL) {};
	friend FRIEND;
};

template <class INF>
class MyStack {
	typedef class ListNode <INF, MyStack <INF>> Node;
	Node* top;
public:
	MyStack() :top(NULL) {}

	~MyStack() {
		while (empty() != 1) {
			pop();
		}
	}

	bool empty() {
		if (top == NULL) {
			return 1;
		}
		else {
			return 0;
		}
	} // стек пустой?

	void push(INF n) {
		Node* temp = new Node;
		temp->d = n;
		temp->next = top;
		top = temp;
	}

	void pop() {
		Node *temp = top->next;
		delete top;
		top = temp;
		temp = NULL;
	}

	INF top_inf() {
		return top->d;
	}
};

void fact(int, MyStack<int> &);

int main()
{
	int number;
	MyStack<int> stack;
	cin >> number;
	fact(number, stack);
	cout << number << "=";
	cout << stack.top_inf();
	stack.pop();
	while (stack.empty() != 1) {
		cout << "*" << stack.top_inf();
		stack.pop();
	}
	cout << endl;
	system("pause");
}

void fact(int num, MyStack<int> &stack) {
	int i = 2, j = 0;
	while ((i*i <= num) && (j != 1)) {
		if (num % i == 0) {
			j = 1;
		}
		i = i + 1;
	}
	i--;
	if (j == 1) {
		stack.push(i);
		fact(num/i, stack);
	}
	else {
		stack.push(num);
	}
}