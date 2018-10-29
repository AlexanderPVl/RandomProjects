#include "stack.h"
#include "papersheet.h"
#include <algorithm>

int add_paper(Stack<PaperSheet> &st, PaperSheet &ps);

void check_function(const char* file_name);

int main()
{
	const char* file_name = "STACK.BIN";
	check_function(file_name);

	return 0;
}

int add_paper(Stack<PaperSheet> &st, PaperSheet &ps){
	if (st.is_empty()){
		st.push(ps);
		return 1;
	}
	if (!ps.match_with(**st)){
		cout << "Paper can not be added!" << endl;
		return -1;
	}
	else st.push(ps);

	cout << "Paper has been added succesfully" << endl;
	return 0;
}

void check_function(const char* file_name){
	cout << "Hello World!" << endl;

	Stack<PaperSheet> stack;
	Stack<PaperSheet> copy_stack(stack);
	cout << endl << "Stacks are equal? " << (stack == copy_stack);
	stack.push(PaperSheet(5, 5, 5, 5, 5));
	cout << endl << "Stacks are equal? " << (stack == copy_stack) << '\n' << endl;

	for (int i = 0; i < 5; ++i){
		stack.push(PaperSheet(1, 2, 3, 5, 8));
	}

	for (int i = 0; i < 5; ++i){
		stack.push(PaperSheet(2, 3, 4, 7, 9));
	}

	for_each(stack.begin(), stack.end(), [](PaperSheet ps){cout << ps.get_coord_x(); });

	cout << "Print stack: " << endl;
	stack.print_stack();

	cout << "First element equals to second?  " << (*(stack.begin()) == *(stack.begin() + 1));
	cout << endl << "Last element equals to himself? " << (**stack == **stack);

	stack.write_to_file(file_name);
	stack.del();
	stack.read_from_file(file_name);

	cout << endl << "Print stack: " << endl;
	stack.print_stack();

	cout << endl;
}