#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // для работы с итераторами

class MyClass
{
private:
	int _data;   // доступно для модификации объектам класса  приватные поля с землёй.
public:
	int data;   // доступно для модификации только внутри класса
	//protected:
	//	int data;  // доступно для модификации внутри класса и внутри классов-наследников.


public:
	int Summ(int data) {
		return _data + data;
	}
};


class Tovar {
private:
	std::string _name;
	float _price;
public:
	Tovar(std::string name, float price) {   // конструктор , работает один раз. Всегда в публичном поле.
		_name = name;
		_price = price;
	}
	void Print() {
		std::cout << "Имя:   " << _name << '\n';
		std::cout << "Цена:  " << _price << '\n';
	}
	void SetName(std::string name) {
		_name = name;
	}
	void SetPrice(float price) {
		_price = price;
	}
	std::string GetName() {
		return _name;
	}
	float GetPrice() {
		return _price;
	}
};
class Employer {
private:
	std::string _name;
	int _id;
public:
	Employer(int id, std::string name) {
		_name = name;
		_id = id;
	}
	void Print() {
		std::cout << "ID    " << _id << '\n';
		std::cout << "Имя   " << _name << '\n';
	}
	void SetName(std::string name) {
		_name = name;
	}
	void SetId(int id) {
		_id = id;
	}
	int GetId() {
		return _id;
	}
	std::string GetName() {
		return _name;
	}
};
class Person {
private:
	std::string _name;
	int _age;
public:
	Person(std::string name, int age) :_name(name), _age(age) {}

	std::string GetName() {
		return _name;
	}

	void ShowData() {
		std::cout << "Имя     :" << _name << '\n';
		std::cout << "Возраст :" << _age << '\n';
	}
};
//void SearchByName(std::string x) {   // пример поиска по базе 
//	BasaData.Search(x);     
//}
void Foo() {
	int a;
}
int main() {
	setlocale(LC_ALL, "Russian");

	//MyClass myObject;
	//myObject.data = 100;

	Tovar tovar1("Morkov", 99.99f);
	Tovar* tovar4 = new Tovar("Bread", 25.6f);   // ещё один синтаксис
	tovar4->Print();

	delete(tovar4);
	//tovar1.SetName("hghg");  // изменение имени

	//tovar1.SetName("Morkov");
	//tovar1.SetPrice(99.99f);
	//std::cout << tovar1.GetName() << '\n';
	//std::cout << tovar1.GetPrice() << '\n';
	//std::string f = tovar1.GetName();
	//std::cout << f;

	Tovar tovar2("Kapusta", 500.4f);
	Tovar tovar3("Kartoshka", 200.1f);

	tovar1.Print();
	tovar2.Print();
	tovar3.Print();

	// ПРИМЕР.
	//SearchByName(tovar1.GetName());

	Employer sotr1(354512, "Andru");
	Employer sotr2(248687, "Boris");

	sotr1.Print();
	sotr2.Print();

	std::vector<int>vec = { 1,10,20 };
	vec.push_back(5);
	std::cout << vec.size() << '\n';
	//vec.pop_back();
	vec.begin();
	vec.end();
	// vec.erase(vec.begin() + 2);  // удаляет объект .
	std::cout << vec.at(0) << '\n';


	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec.at(i) << ' ';
	}
	std::cout << '\n';
	std::vector<int>::iterator it;
	it = vec.begin();
	std::cout << *it << '\n';
	std::cout << *vec.begin() << '\n';

	vec.erase(it);

	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec.at(i) << ' ';

	//vec.erase(it);

	Person* person1 = new Person("John", 20);
	Person* person2 = new Person("Bob", 30);
	Person* person3 = new Person("Alex", 35);

	std::vector<Person*>people;
	std::vector<Person*>::const_iterator it4;
	people.push_back(person1);
	people.push_back(person2);
	people.push_back(person3);
	for (int i = 0; i < people.size(); i++)
		std::cout << people.at(i) << ' ';
	std::cout << '\n';

	for (it4 = people.begin(); it4 != people.end(); it4++)
		(*it4)->ShowData();
	delete(person1);
	delete(person2);
	delete(person3);
	/*std::vector<std::string>names;
	auto it1 = names.begin();
	names.push_back(person1.GetName());
	names.push_back(person2.GetName());
	names.push_back(person3.GetName());

	for (const auto& it1 : names)
		std::cout << it1 << ' ';*/


		// надо всё делать через указатели!


	return {};  // = 0
}