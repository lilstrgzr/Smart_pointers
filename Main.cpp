#include <iostream>
#include <memory>
#include "shared_ptr.hpp"



int main() {
	setlocale(LC_ALL, "russian");
	int n;

	//Умный указатель на уникальную память
	/*

	n = 15;
	int* ptmp = new int{ 7 };
	//std::unique_ptr<int> uniq1(&n);
	std::unique_ptr<int> uniq2(ptmp);
	//std::cout << "*uniq1 = " << *uniq1 << std::endl;
	std::cout << "*uniq2 = " << *uniq2 << std::endl;
	uniq2.reset(new int[3]);
	uniq2.get();

	auto uniq5(std::make_unique<int>(10));

*/

	//Общий указатель
	/*
	std::shared_ptr<int> shared1(new int);
	std::shared_ptr<int> shared2 = shared1;
	*shared1 = 50;
	std::cout << *shared2 << std::endl;
*/

	//Слабый указатель
	std::weak_ptr<int> weak(std::make_shared<int>(50));
	//std::weak_ptr<int> weak(std::make_weak<int>(50))  //Ошибка


	//проверка собственного общего указателя
	my::shared_ptr_test(new int{ 10 });

	return 0;
}