// Лаб 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <functional>
#include<array>
#include<set>
#include<algorithm>
#include<Windows.h>



 
int main()
{
	// Задание №1.
	setlocale(LC_ALL, "ru");
	auto print2 = [](const std::pair<int, std::string> a) {
		std::cout << "<" << a.first << ", " << a.second << ">  ";
	};
	std::map<int, std::string> myMap;
	std::unordered_multimap<int, std::string> myMulmap;
	myMulmap.insert(std::pair<int, std::string>(1, "астрономия"));
	myMulmap.insert(std::pair<int, std::string>(2, "информатика"));
	myMulmap.insert(std::pair<int, std::string>(4, "физика"));
	myMulmap.insert(std::pair<int, std::string>(4, "химия"));
	myMulmap.erase(2);
	myMap.insert(myMulmap.begin(), myMulmap.end());
	std::for_each(myMap.cbegin(), myMap.cend(), print2);
	std::cout << std::endl;
	// Задача №2.
	std::vector<int> v;
	auto function = [](const std::pair<int, std::string> n) {return n.first > 0; };
	int b0 = 0;
	b0 = std::count_if(myMap.begin(), myMap.end(), function);
	std::cout << b0;
	auto make_vctr = [](std::pair<int, std::string> a) {return a.first; };
	std::transform(myMap.begin(), myMap.end(), std::back_inserter(v), make_vctr);
	// Задача 3.
	auto print = [](const int& n) { std::cout << " " << n; };
	auto ravn1 = std::find(std::begin(v), std::end(v), 1);
	if (ravn1 != std::end(v)) {
		std::cout << std::endl;
		std::cout << "Есть" << 1 << '\n';
	}
	else {
		std::cout << std::endl;
		std::cout << "Нет" << 1 << '\n'; 
	}

	std::replace_if(v.begin(), v.end(),
		std::bind(std::less<int>(), std::placeholders::_1, 0), 0);
	std::for_each(v.cbegin(), v.cend(), print);
	std::cout << std::endl;

	std::sort(v.begin(), v.end(), std::greater<int>());
	std::for_each(v.cbegin(), v.cend(), print);
	std::cout << std::endl;

	std::set<int> mySet;
	mySet.insert(v.begin(), v.end() );
	std::for_each(mySet.cbegin(),mySet.cend(), print);
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
