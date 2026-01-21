#include<iostream>
#include<string>
using namespace std;

class Stack {
private:
	int* arr;
	int top;
	int size;
public:
	Stack(int size)
		: size{ size }, top{ -1 } {
		arr = new int[size];
	}
	~Stack() {
		delete[] arr;
	}
	void push(int x) {
		if (top + 1 < size) {
			arr[++top] = x;
		}
		else {
			cout << "용량 초과";
			return;
		}
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			return arr[top--];
		}
	}
	int gettop() const {
		if (empty()) {
			return -1;
		}
		else {
			return arr[top];
		}
	}
	bool empty() const {
		if (top == -1)
			return 1;
		else
			return 0;
	}
	int getsize() const {
		return top + 1;
	}
};
void stackc(string fun,Stack& stack) {
	if (fun == "push") {
		int x;
		cin >> x;
		stack.push(x);
	}
	else if (fun == "top")
		cout<<stack.gettop()<<endl;
	else if (fun == "pop")
		cout << stack.pop() << endl;
	else if (fun == "empty")
		cout << stack.empty() << endl;
	else if (fun == "size")
		cout << stack.getsize() << endl;
}
int main() {
	int x;
	cin >> x;
	Stack stack(x);
	for (int i = 0; i < x; i++) {
		string y;
		cin >> y;
		stackc(y, stack);
	}
}