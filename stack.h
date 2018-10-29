#pragma once

#include <iostream>
#include <iomanip>
#include <cassert>
#include <fstream>

using namespace std;

template<class T>
class Stack
{
public:
	Stack();                            // ����������� �� ���������
	Stack(const Stack<T> &other_stack); // ����������� �����������
	~Stack();                           // ����������
	inline void push(const T &value);   // ����� ���������� ���������
	inline T pop();                     // ����� �������� ��������
	void print_stack();                 // ����� ����� �� �����
	inline int get_stack_size() const;  // ����������� ������� �����
	inline T* get_ptr() const;          // ���������� ��������� �� ����
	inline int get_top() const;         // ���������� ����� �������� �������� � �����
	inline T* begin() const;
	inline T* end() const;

	bool is_empty();
	void del();
	void write_to_file(const char* file_name);
	void read_from_file(const char* file_name);

	T* operator * ();                   // �������� ����������� ��������� �� ��������� ������� � �����
	bool operator == (Stack& st);

	//typedef T* pub_iterator;
private:
	T *stack_ptr;                       // ��������� �� ����
	const int size;                     // ������������ ���������� ��������� � �����
	int top;                            // ����� �������� �������� �����
	T* iterator;                        // �������� ������ ��������� �� ��������� ������� + 1
};

template<class T>
Stack<T>::Stack() : size(100){
	stack_ptr = new T[size];            // �������� ������ ��� ����
	//stack_ptr = nullptr;
	top = 0;                            // �������������� ������� ������� �����;
	iterator = stack_ptr;
}

template<class T>
Stack<T>::Stack(const Stack<T> &other_stack) : size(other_stack.size)    // ����������� �����������
{
	//size = other_stack.size;
	stack_ptr = new T[size];                    // �������� ������ ��� ����� ����
	top = other_stack.get_top();
	iterator = other_stack.iterator;            // �������� ������ ��������� �� ��������� ������� + 1

	for (int ix = 0; ix < top; ix++)
		stack_ptr[ix] = other_stack.get_ptr()[ix];
}

template<class T>
Stack<T>::~Stack()        // ����������
{
	iterator = nullptr;
	top = 0;
	delete[] stack_ptr;    // ������� ����
}

template<class T>
inline void Stack<T>::push(const T &value)     // ��������� ������� � ������� �����
{                                   // ��������� ������ �����
	assert(top < size);             // ����� �������� �������� ������ ���� ������ ������� �����
	*(iterator++) = value;
	top++;
}

template<class T>
inline T Stack<T>::pop()    // ������� ������� �� ������� ����� � ������� ���
{	                        // ��������� ������ �����
	assert(top > 0);        // ����� �������� �������� ������ ���� ������ 0
	--top;

	return *(--iterator);   // ������� ������� �� �����
}

template<class T>
void Stack<T>::print_stack()    // ����� ����� �� �����
{
	int i;
	/*for (T it : *this){
	cout << "|" << setw(4) << it.print() << endl;
	}*/
	for (i = 0; i < top; ++i) {
		cout << i + 1 << ")" << endl;
		stack_ptr[i].print();
		cout << endl;
	}
}

template<class T>
inline int Stack<T>::get_stack_size() const { return size; } // �������� ������ �����

template<class T>
inline T* Stack<T>::get_ptr() const{ return stack_ptr; }     // �������� ��������� �� ����

template<class T>
inline int Stack<T>::get_top() const{ return top; }          // �������� ����� �������� �������� � �����

template<class T>
inline T* Stack<T>::begin() const{ return stack_ptr; }

template<class T>
inline T* Stack<T>::end() const{ return iterator; }

template<class T>
bool Stack<T>::is_empty(){ return (top == 0); }

template<class T>
void Stack<T>::del(){
	iterator = stack_ptr;
	top = 0;
}

template<class T>
void Stack<T>::write_to_file(const char* file_name){
	FILE* f = fopen(file_name, "wb");
	//fprintf(f, "d", top);
	fwrite(&top, sizeof(int), 1, f);
	for (int i = 0; i < top; ++i)
		fwrite(stack_ptr + i, sizeof(T), 1, f);
	fclose(f);
}

template<class T>
void Stack<T>::read_from_file(const char* file_name){
	FILE* f = fopen(file_name, "rb");
	if (!f)return;
	//fscanf(f, "d", &top);
	fread(&top, sizeof(int), 1, f);
	for (int i = 0; i < top; ++i){
		fread(stack_ptr + i, sizeof(T), 1, f);
	}
	fclose(f);
}

template<class T>
T* Stack<T>::operator * (){ return iterator - 1; } // �������� ����������� ��������� �� ��������� ������� � �����

template<class T>
bool Stack<T>::operator == (Stack& st){
	if (size == st.size && top == st.top){
		for (int i = 0; i < top; ++i){
			assert(stack_ptr + i != nullptr && st.stack_ptr + i != nullptr);
			if (stack_ptr[i] == st.stack_ptr[i]){
				continue;
			}
			else return false;
		}
	}
	else return false;
	return true;
}