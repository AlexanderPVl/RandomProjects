#pragma once

template<class InputIt, class UnaryFunction>
InputIt maximum(InputIt first, InputIt last, UnaryFunction f)
{
	InputIt max = first;
	if (first == last)return  max;
	for (; first != last;) {
		first++;
		if (first == last) break;
		max = f(*max, *first) ? max : first;
	}
	return max;
}
