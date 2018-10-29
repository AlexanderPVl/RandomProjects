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
	Stack();                            // конструктор по умолчанию
	Stack(const Stack<T> &other_stack); // конструктор копирования
	~Stack();                           // деструктор
	inline void push(const T &value);   // метод добавления элементов
	inline T pop();                     // метод удаления элемента
	void print_stack();                 // вывод стека на экран
	inline int get_stack_size() const;  // возвращение размера стека
	inline T* get_ptr() const;          // возвращает указатель на стек
	inline int get_top() const;         // возвращает номер текущего элемента в стеке
	inline T* begin() const;
	inline T* end() const;

	bool is_empty();
	void del();
	void write_to_file(const char* file_name);
	void read_from_file(const char* file_name);

	T* operator * ();                   // оператор возвращения указателя на последний элемент в стеке
	bool operator == (Stack& st);

	//typedef T* pub_iterator;
private:
	T *stack_ptr;                       // указатель на стек
	const int size;                     // максимальное количество элементов в стеке
	int top;                            // номер текущего элемента стека
	T* iterator;                        // итератор хранит указатель на последний элемент + 1
};

template<class T>
Stack<T>::Stack() : size(100){
	stack_ptr = new T[size];            // выделить память под стек
	//stack_ptr = nullptr;
	top = 0;                            // инициализируем текущий элемент нулем;
	iterator = stack_ptr;
}

template<class T>
Stack<T>::Stack(const Stack<T> &other_stack) : size(other_stack.size)    // конструктор копирования
{
	//size = other_stack.size;
	stack_ptr = new T[size];                    // выделить память под новый стек
	top = other_stack.get_top();
	iterator = other_stack.iterator;            // итератор хранит указатель на последний элемент + 1

	for (int ix = 0; ix < top; ix++)
		stack_ptr[ix] = other_stack.get_ptr()[ix];
}

template<class T>
Stack<T>::~Stack()        // деструктор
{
	iterator = nullptr;
	top = 0;
	delete[] stack_ptr;    // удаляем стек
}

template<class T>
inline void Stack<T>::push(const T &value)     // поместить элемент в вершину стека
{                                   // проверяем размер стека
	assert(top < size);             // номер текущего элемента должен быть меньше размера стека
	*(iterator++) = value;
	top++;
}

template<class T>
inline T Stack<T>::pop()    // удалить элемент из вершины стека и вернуть его
{	                        // проверяем размер стека
	assert(top > 0);        // номер текущего элемента должен быть больше 0
	--top;

	return *(--iterator);   // удаляем элемент из стека
}

template<class T>
void Stack<T>::print_stack()    // вывод стека на экран
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
inline int Stack<T>::get_stack_size() const { return size; } // получить размер стека

template<class T>
inline T* Stack<T>::get_ptr() const{ return stack_ptr; }     // получить указатель на стек

template<class T>
inline int Stack<T>::get_top() const{ return top; }          // получить номер текущего элемента в стеке

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
T* Stack<T>::operator * (){ return iterator - 1; } // оператор возвращения указателя на последний элемент в стеке

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
