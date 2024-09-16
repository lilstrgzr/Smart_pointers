#pragma once
#include<map>
#include <iostream>

namespace my{
	template <typename ANY>
class Shared_ptr {
private:
	ANY* data;
	std::map<ANY*, unsigned> all_ptrs;
	void clear();
public:
	Shared_ptr();
	Shared_ptr(ANY* address);
	~Shared_ptr();
	void reset(ANY* address = nullptr);
	ANY* get() const;
	ANY& operator*();
	const ANY& operator*() const;
	ANY& operator->();
	const ANY& operator->()const;
};
template <typename T>
void shared_ptr_test(T* address);
}

template<typename ANY>
void my::Shared_ptr<ANY>::clear() {
	all_ptrs.erase(data);
	delete[] data;
	data = nullptr;
}

template<typename ANY>
my::Shared_ptr<ANY>::Shared_ptr() {
	data = nullptr;
}

template<typename ANY>
my::Shared_ptr<ANY>::Shared_ptr(ANY* address) {
	reset(address);
}


template<typename ANY>
my::Shared_ptr<ANY>::~Shared_ptr() {
	if (data != nullptr) {
		all_ptrs[data] -= 1;
		if (all_ptrs[data] <= 0)
			clear();
	}
}


template<typename ANY>
void my::Shared_ptr<ANY>::reset(ANY* address) {
	if (data != nullptr) {
		all_ptrs[data] -= 1;
		if (all_ptrs[data] <= 0)
			clear();
	}
	if (address == nullptr) return;

	if (all_ptrs.count(data) > 0)
		all_ptrs[data] += 1;

	else
		all_ptrs[data] = 1;

	data = address;
}

template<typename ANY>
ANY* my::Shared_ptr<ANY>::get() const {
	return data;
}

template<typename ANY>
ANY& my::Shared_ptr<ANY>::operator*() {
	return *data;
}

template<typename ANY>
const ANY& my::Shared_ptr<ANY>::operator*() const {
	return *data;
}

//TODO: Добавить кое-что.

template<typename ANY>
ANY& my::Shared_ptr<ANY>::operator->() {
	return *data;
}

template<typename ANY>
const ANY& my::Shared_ptr<ANY>::operator->() const {
	return *data;
}

template <typename T>
void my::shared_ptr_test(T* address) {
	my::Shared_ptr<T> ptr;
	ptr.reset(address);
	std::cout << "TEST: ptr (beg) = " << ptr.get() << std::endl;
	std::cout << "TEST: *ptr (beg) = " << *ptr.get() << std::endl;
	{
		my::Shared_ptr<T> tmp(ptr.get());
		std::cout << "TEST: tmp = " << tmp.get() << std::endl;
		std::cout << "TEST: *tmp = " << *tmp.get() << std::endl;
	}
	std::cout << "TEST: ptr (end) = " << ptr.get() << std::endl;
	std::cout << "TEST: *ptr (end) = " << *ptr.get() << std::endl;

}