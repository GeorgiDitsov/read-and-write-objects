#include <iostream>
#include "Controller.h"

using namespace std;

short int option;

void menu();
void result();

int main()
{
	while (true)
	{
		menu();
		result();
	}
}

void menu()
{
	cout << "Menu:" << endl;
	cout << "Enter 1 to add new author" << endl;
	cout << "Enter 2 to add new book distributor" << endl;
	cout << "Enter 3 to add new textbook" << endl;
	cout << "Enter 4 to view all authors" << endl;
	cout << "Enter 5 to view all book distributors" << endl;
	cout << "Enter 6 to view all textbooks" << endl;
	cout << "Enter 7 to select book distributor and order textbooks through him" << endl;
	cout << "Enter 0 to exit the program" << endl;
	cin >> option;
	cin.ignore();
}

void result()
{
	switch (option)
	{
	case 0:
		exit(0);
		break;
	case 1:
		Controller::add_new_author_menu();
		break;
	case 2:
		Controller::add_new_book_distributor_menu();
		break;
	case 3:
		Controller::print_all_authors();
		Controller::print_all_book_distributors();
		Controller::add_new_textbook_menu();
		break;
	case 4:
		Controller::print_all_authors();
		break;
	case 5:
		Controller::print_all_book_distributors();
		break;
	case 6:
		Controller::print_all_textbooks();
		break;
	case 7:
		Controller::print_all_book_distributors();
		Controller::order_textbooks_for_book_distributor_menu();
		break;
	default:
		cout << "Wrong number enterred" << endl;
		break;
	}
}
