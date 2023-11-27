#pragma once
#include <iostream>

const int MaxStackSize = 100;

template <class T>
class TStack {
private:
    T* pMem;
    T* end;
    int size;
public:
	// create and destroy
	TStack(int size = 100) {
		pMem = new T[size];
		end = pMem;
	};
	TStack(const TStack<T>& a) {
		this->size = a.size;
		this->pMem = new T[this->size];
		this->end = this->pMem + (a.end - a.size);
		for (size_t i = 0; i < (a.end - a.size); i++) {
			this->pMem[i] = a.pMem[i];
		}
	};
	TStack(const T* arr, size_t sz) {
		if ((sz < 1) || (sz > MaxStackSize))
			throw std::out_of_range("Stack size not allowed");
		this->size = 100;
		this->pMem = new T[this->size];
		this->end = this->pMem + sz;
		for (size_t i = 0; i < sz; i++) {
			this->pMem[i] = arr[i];
		}
	};
	~TStack() {
		delete this->pMem;
	};

	// methods
	void push(T el) {
		if (this->end - this->pMem == this->size) {
			this->size *= 2;
			T* tmp = new T[this->size];
			for (int i = 0; i < this->size; i++) {
				tmp[i] = pMem[i];
			}
			this->end = tmp + (this->end - this->pMem);
			delete[] this->pMem;
			this->pMem = tmp;
		}
		*(this->end) = el;
		this->end++;
	};
	const T& top() {
		if (this->pMem == this->end) {
			throw std::out_of_range("Empty stack");
		}
		return *(this->end - 1);
	};
	void pop() {
		if (this->pMem == this->end) {
			throw std::out_of_range("Empty stack");
		}
		this->end--;
	};
	bool isEmpty() {
		return (this->pMem == this->end);
	};
	int els_count() {
		return (this->end - this->pMem);
	};
	int get_size() {
		return (this->size);
	};
	bool operator==(const TStack<T>& a) {
		if (this->els_count() != a.els_count()) {
			return false;
		}
		for (int i = 0; i < this->els_count(); i++) {
			if (this->pMem[i] != a.pMem[i]) {
				return false;
			}
		}
		return true;
	};
	bool operator!=(const TStack<T>& a) {
		if (this->els_count() != a.els_count()) {
			return true;
		}
		for (int i = 0; i < this->els_count(); i++) {
			if (this->pMem[i] != a.pMem[i]) {
				return true;
			}
		}
		return false;
	};

	// input and output
	friend std::ostream& operator<<(std::ostream& out, TStack<T>& a) {
		for (size_t i = 0; i < a.els_count() - 1; i++) {
			out << a.pMem[i] << "; ";
		}
		out << *(a.end);
		return out;
	}
	//friend std::ostream& operator>>(ostream& in, const TStack<T>& a);
};

//template <class T>
//std::ostream& operator>>(ostream& in, const TStack<T>& a) {
//
//};
