#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;


struct book
{
	char author[40];
	char title[40];
	int year;
	int pages;
};


book *menu(book *lib, int &size);

void Cyrillic() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

book GetBook() {
	book x;

	system("cls");
	cin.ignore(cin.rdbuf()->in_avail());

	cout << "           Добавить книгу." << endl;
	cout << "--------------------------------------" << endl;
	cout << "Введите имя автора: ";
	cin.getline(x.author, 40);
	
	if (strcmp(x.author,"")==0){
		return x;
	}

	cout << "Введите название книги: ";
	cin.getline(x.title, 40);

	while (1)
	{
		cout << "Введите год издния: ";
		cin >> x.year;
		if(cin.fail()){
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "--------------------------------------" << endl;
			cout << "      ***Некорректный ввод***" << endl;
			cout << "--------------------------------------" << endl;
			continue;
		}
		break;
	}

	while (1)
	{
		cout << "Введите кол-во страниц: ";
		cin >> x.pages;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "--------------------------------------" << endl;
			cout << "      ***Некорректный ввод***" << endl;
			cout << "--------------------------------------" << endl;
			continue;
		}
		break;
	}

	return x;
}

book *AddBook(book *lib, int &size) {

	if (size == 0) {
		lib = new book[size + 1];
		lib[size] = GetBook();
	}
	else {
		book *temp = new book[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = lib[i];
		}
		temp[size] = GetBook();
		delete[] lib;
		lib = temp;
	}
	size++;

	return lib;
}

book *DelBook(book *lib, int &size, int ncell) {

	if (size == 1) {
		--size;
		return NULL;
	}

	book* temp = new book[size - 1];

	for (int i = 0; i < ncell; i++) {
		temp[i] = lib[i];
	}
	for (int i = ncell; i < size - 1; i++) {
		temp[i] = lib[i + 1];
	}
	delete[] lib;
	lib = temp;

	size--;
	return lib;
}

book *SearchByPages(book *lib, int size, int &tmp_sz) {
	int Pages;
	book *tmp_lib = NULL;

	cout << endl;
	cout << "Введите кол-во страниц в искомой книге: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> Pages;

	for (int x = 0; x < size; x++) {
		if (lib[x].pages == Pages) {
			if (tmp_sz == 0) {
				tmp_lib = new book[tmp_sz + 1];
				tmp_lib[tmp_sz] = lib[x];
			}
			else {
				book *temp = new book[tmp_sz + 1];
				for (int i = 0; i < tmp_sz; i++) {
					temp[i] = tmp_lib[i];
				}
				temp[tmp_sz] = lib[x];
				delete[] tmp_lib;
				tmp_lib = temp;
			}
			tmp_sz++;
		}
	}
	return tmp_lib;
}

book *SearchByYear(book *lib, int size, int &tmp_sz) {
	int year;
	book *tmp_lib = NULL;

	cout << endl;
	cout << "Введите год издания: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> year;

	for (int x = 0; x < size; x++) {
		if (lib[x].year == year) {
			if (tmp_sz == 0) {
				tmp_lib = new book[tmp_sz + 1];
				tmp_lib[tmp_sz] = lib[x];
			}
			else {
				book *temp = new book[tmp_sz + 1];
				for (int i = 0; i < tmp_sz; i++) {
					temp[i] = tmp_lib[i];
				}
				temp[tmp_sz] = lib[x];
				delete[] tmp_lib;
				tmp_lib = temp;
			}
			tmp_sz++;
		}
	}
	return tmp_lib;
}

book *SearchByTitle(book *lib, int size, int &tmp_sz) {
	char title[40];
	book *tmp_lib = NULL;

	cout << endl;
	cout << "Введите название искомой книги: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(title, 40);

	for (int x = 0; x < size; x++) {
		if (strstr(lib[x].title, title)) {
			if (tmp_sz == 0) {
				tmp_lib = new book[tmp_sz + 1];
				tmp_lib[tmp_sz] = lib[x];
			}
			else {
				book *temp = new book[tmp_sz + 1];
				for (int i = 0; i < tmp_sz; i++) {
					temp[i] = tmp_lib[i];
				}
				temp[tmp_sz] = lib[x];
				delete[] tmp_lib;
				tmp_lib = temp;
			}
			tmp_sz++;
		}
	}
	return tmp_lib;
}

book *SearchByAuthor(book *lib, int size, int &tmp_sz) {
	char name[40];
	book *tmp_lib = NULL;

	cout << endl;
	cout << "Введите имя искомого автора: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(name, 40);

	for (int x = 0; x < size; x++) {
		if (strstr(lib[x].author, name)) {
			if (tmp_sz == 0) {
				tmp_lib = new book[tmp_sz + 1];
				tmp_lib[tmp_sz] = lib[x];
			}
			else {
				book *temp = new book[tmp_sz + 1];
				for (int i = 0; i < tmp_sz; i++) {
					temp[i] = tmp_lib[i];
				}
				temp[tmp_sz] = lib[x];
				delete[] tmp_lib;
				tmp_lib = temp;
			}
			tmp_sz++;
		}
	}
	return tmp_lib;
}


void ShowLib(book *lib, int size) {
	system("cls");
	for (int i = 0; i < size; i++) {
		cout << endl;
		cout << setw(16) << left << "Автор: " << setw(40) << left << lib[i].author << endl;
		cout << setw(16) << left << "Книга: " << setw(40) << left << lib[i].title << endl;
		cout << setw(16) << left << "Год: " << setw(40) << left << lib[i].year << endl;
		cout << setw(16) << left << "Кол-во страниц: " << setw(40) << left << lib[i].pages << endl;
		cout << "-------------------------------------------------------------------" << endl;
	}
	_getch();
}

void Search(book *lib, int size) {
	book *result_s;
	int tmp_sz = 0;

	result_s = SearchByPages(lib, size, tmp_sz);
	ShowLib(result_s, tmp_sz);

	delete[] result_s;
}

void SortLibByAuthor(book *lib, int size) {
	for (int j = size - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (strcmp(lib[i].author, lib[i + 1].author)>0) {
				book temp = lib[i];
				lib[i] = lib[i + 1];
				lib[i + 1] = temp;
			}
		}
	}
}

void SortLibByTitle(book *lib, int size) {
	for (int j = size - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (strcmp(lib[i].title, lib[i + 1].title)>0) {
				book temp = lib[i];
				lib[i] = lib[i + 1];
				lib[i + 1] = temp;
			}
		}
	}
}

void SortLibByYear(book *lib, int size) {
	for (int j = size - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (lib[i].year > lib[i + 1].year) {
				book temp = lib[i];
				lib[i] = lib[i + 1];
				lib[i + 1] = temp;
			}
		}
	}
}

void SortLibByPages(book *lib, int size) {
	for (int j = size - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (lib[i].pages > lib[i + 1].pages) {
				book temp = lib[i];
				lib[i] = lib[i + 1];
				lib[i + 1] = temp;
			}
		}
	}
}

void OutputToFile(book *lib, int size) {

	ofstream fout;
	char dir[60];

	system("cls");
	cout << "            Сохранение." << endl;
	cout << "--------------------------------------" << endl;

	int n = 1;
	while (n) {
	cout << "Введите путь: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(dir, 60);

	fout.open(dir);
		if (!(fout.is_open())) {
			cout << "--------------------------------------" << endl;
			cout << "         Неверная директория." << endl;
			cout << "--------------------------------------" << endl;
			continue;
		}
		n = 0;
	}

	for (int i = 0; i < size; i++) {
		fout << lib[i].author << endl;
		fout << lib[i].title << endl;
		fout << lib[i].year << endl;
		fout << lib[i].pages << endl;
	}

	system("cls");
	cout << "Запись в \"" << dir << "\" завершена успешно.";
	fout.close();
	_getch();
}

book GetBookFF(ifstream &n, int &f) {

	book x;
	n.getline(x.author, 40);
	if (x.author == "") {
		f = 1;
	}
	n.getline(x.title, 40);
	n >> x.year;
	n.ignore(1);
	n >> x.pages;
	n.ignore(1);

	return x;
}

book *InputFromFile(book *lib, int &size) {

	char dir[60];
	ifstream fin;
	cout << "Введите путь: ";


	int n = 1;
	while (n) {
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(dir, 60);

		fin.open(dir);
		if (!fin.is_open()) {
			cout << "Неверная директория." << endl;
			cout << "Повторить ввод? (y/n)" << endl;
			char x;
			cin >> x;

			switch (x) {
			case('y' || 'Y') :
			{
			continue;
			}
			default: {
				system("cls");	
				return lib;
			}
			}
		}
		n = 0;
	}

	size = 0;

	while (!fin.eof()) {
		int flag = 0;
		if (size == 0) {
			lib = new book[1];
			lib[size] = GetBookFF(fin, flag);
		}
		else {
			book *temp = new book[size + 1];
			for (int i = 0; i < size; i++) {
				temp[i] = lib[i];
			}
			temp[size] = GetBookFF(fin, flag);
			delete[] lib;
			lib = temp;
		}
		size++;
	}

	return lib;
}

book *load(book *lib, int &size) {
	system("cls");
	cout << "                   Загрузка." << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "ВНИМАНИЕ! Все не сохраненные данные будут утеряны." << endl;
	cout << "--------------------------------------------------" << endl;
	lib = InputFromFile(lib, size);
	return lib;
}

void menu_sort(book *lib, int size) {
	system("cls");
	cout << "           Сортировка." << endl;
	cout << "-----------------------------------" << endl;
	cout << "1) По автору." << endl;
	cout << "2) По называнию книги." << endl;
	cout << "3) По дате издания." << endl;
	cout << "4) По кол-ву страниц." << endl;

	char response[10];
	int n = 1;
	while (n) {

		cin.ignore(cin.rdbuf()->in_avail());
		cin >> response;

		if (strcmp(response, "1") == 0) {
			SortLibByAuthor(lib, size);
			break;
		}
		if (strcmp(response, "2") == 0) {
			SortLibByTitle(lib, size);
			break;
		}
		if (strcmp(response, "3") == 0) {
			SortLibByYear(lib, size);
			break;
		}
		if (strcmp(response, "4") == 0) {
			SortLibByPages(lib, size);
		}
		system("cls");
	}
	cout << "           Сортировка." << endl;
	cout << "-----------------------------------" << endl;
	cout << "Сортировка завершена." << endl;
	cout << "Вывести библиотеку на экран? (y/n)" << endl;
	char x;
	cin >> x;

	switch (x) {
	case('y' || 'Y') :
	{
		ShowLib(lib, size);
		break;
	}
	default: break;
	}
}

book *create(book *lib, int &size) {

	int n = 1;
	while (n) {
		lib = AddBook(lib, size);
		if (strcmp(lib[size - 1].author, "") == 0) {
			lib = DelBook(lib, size, size - 1);
			break;
		}
	}
	if (lib == NULL) {
		system("cls");
		cout << "Библиотека пуста." << endl;
		_getch();
		return lib;
	}
	lib = menu(lib, size);
	return lib;
}

book *menu(book *lib, int &size) {

	while (1) {
		char response[10];

		system("cls");
		cout << "             Ввод завершен." << endl;
		cout << "--------------------------------------" << endl;
		cout << "1) Создоать библиотеку." << endl;
		cout << "2) Соxранить библиотеку." << endl;
		cout << "3) Загрузить библиотеку." << endl;
		cout << "4) Вывести на экран. " << endl;
		cout << "5) Сортировать." << endl;
		cout << "6) Выход." << endl;
		if (strcmp(response, "invalid") == 0) {
			cout << "--------------------------------------" << endl;
			cout << "   Неверный ввод. Повторите попытку." << endl;
			cout << "--------------------------------------" << endl;
		}

		cin.ignore(cin.rdbuf()->in_avail());
		cin >> response;

		if (strcmp(response, "1") == 0) {
			lib = create(lib, size);
			if (lib == NULL) {
				continue;
			}
			break;
		}

		if (strcmp(response, "2") == 0) {
			OutputToFile(lib, size);
			continue;
		}
		if (strcmp(response, "3") == 0) {
			lib = load(lib, size);
			continue;
		}
		if (strcmp(response, "4") == 0) {
			ShowLib(lib, size);
			break;
		}
		if (strcmp(response, "5") == 0) {
			menu_sort(lib, size);
			continue;
		}
		if (strcmp(response, "6") == 0) {
			return 0;
		}
		strcpy_s(response, "invalid");
	}
	return lib;
}

int main() {
	Cyrillic();
	book *lib = NULL;
	int size = 0;
	lib = menu(lib, size);
	if (lib == 0) {
		return 0;
	}


	delete[] lib;
	return 0;
}