#include "Controller.h"
#include "Service.h"
#include "StringUtils.h"

#define NAME_REGEX "^[A-Z][a-z]{1,99}$"
#define ADDRESS_REGEX "^[A-Z][A-Za-z0-9 ]{1,99}$"
#define PHONE_NUMBER_REGEX "^[0][8-9][7-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]$"
#define TITLE_REGEX "^[A-Za-z ]{1,99}$"
#define ISBN_REGEX "^(?:-13)?:?(?=[0-9]{13}$|(?=(?:[0-9]+[- ]){4})[- 0-9]{17}$)97[89][- ]?[0-9]{1,5}[- ]?[0-9]+[- ]?[0-9]+[- ]?[0-9]$"
#define DATE_REGEX "^(([1-2][0-9])|([0][1-9])|([3][0-1]))[/](([1][0-2])|([0][1-9]))[/][0-9]{4}$"
#define YES_OR_NO_REGEX "^(y|n)$"
#define NUMBER_REGEX "[[:digit:]]+"
#define NUMBER_WITH_FLOATING_POINT_REGEX "[0-9]+(\.[0-9]+)?([Ee][+-]?[0-9]+)?"

using namespace std;

const regex name_regex(NAME_REGEX);
const regex address_regex(ADDRESS_REGEX);
const regex phone_number_regex(PHONE_NUMBER_REGEX);
const regex title_regex(TITLE_REGEX);
const regex isbn_regex(ISBN_REGEX);
const regex y_or_n_regex(YES_OR_NO_REGEX);
const regex number_regex(NUMBER_REGEX);
const regex number_with_floating_point_regex(NUMBER_WITH_FLOATING_POINT_REGEX);
const regex date_regex(DATE_REGEX);

void Controller::print_all_authors()
{
	cout << "Authors:" << endl;
	for (const auto& author : Service::load_all_authors())
	{
		cout << author;
	}
}

void Controller::print_all_book_distributors()
{
	cout << "Book distributors:" << endl;
	for (const auto& book_distributor : Service::load_all_book_distributors())
	{
		cout << book_distributor;
	}
}

void Controller::print_all_textbooks()
{
	cout << "Textbooks:" << endl;
	for (auto& textbook : Service::load_all_textbooks())
	{
		cout << textbook << "Authors:" << endl;
		for (const auto& author : textbook.Getauthors())
		{
			cout << author;
		}
	}
}

void Controller::add_new_author_menu()
{
	string input_first_name, input_last_name;
	do {
		cout << "Enter author's first name:" << endl;
		getline(cin, input_first_name);
		cout << "Enter author's last name:" << endl;
		getline(cin, input_last_name);
	} while (!regex_match(input_first_name, name_regex) || !regex_match(input_last_name, name_regex));
	Author author(Service::get_next_author_id(), input_first_name.c_str(), input_last_name.c_str());
	Service::add_author(author);
}

void Controller::add_new_book_distributor_menu()
{
	string input_name, input_address, input_phone_number;
	do {
		cout << "Enter name:" << endl;
		getline(cin, input_name);
		cout << "Enter address:" << endl;
		getline(cin, input_address);
		cout << "Enter phone number:" << endl;
		getline(cin, input_phone_number);
	} while (!regex_match(input_name, name_regex) || !regex_match(input_address, address_regex) 
		|| !regex_match(input_phone_number, phone_number_regex));
	BookDistributor book_distributor(Service::get_next_book_distributor_id(), input_name.c_str(), input_address.c_str(), 
		input_phone_number.c_str());
	Service::add_book_distributor(book_distributor);
}

void Controller::add_new_textbook_menu()
{
	int authors_count;
	string title, isbn, edition, is_approved, price, book_distributor_id, date_of_printing, date_of_approval = "01/01/1900";
	vector<Author> textbook_authors;
	Textbook textbook;
	do
	{
		cout << "Enter textbook's title:" << endl;
		getline(cin, title);
		cout << "Enter textbook's isbn:" << endl;
		getline(cin, isbn);
		cout << "Enter how many authors do textbook has:" << endl;
		cin >> authors_count;
		cin.ignore();
		for (int i = 0; i < authors_count; ++i)
		{
			printf("Enter author %d id:\n", i + 1);
			long author_id;
			cin >> author_id;
			cin.ignore();
			textbook_authors.push_back(Service::get_author_by_id(author_id));
		}
		cout << "Enter Textbook's edition:" << endl;
		getline(cin, edition);
		cout << "Enter Textbook's date of printing in format dd/mm/yyyy:" << endl;
		getline(cin, date_of_printing);
		cout << "Enter y if textbook is approved or n if it isn't approved yet:" << endl;
		getline(cin, is_approved);
		if (is_approved == "y")
		{
			textbook.Setis_approved(true);
			cout << "Enter textbook's approval date:" << endl;
			getline(cin, date_of_approval);
		}
		cout << "Enter textbook's price:" << endl;
		getline(cin, price);
		cout << "Enter textbook's book distributor id:" << endl;
		getline(cin, book_distributor_id);
	} while (!regex_match(title, title_regex) || !regex_match(isbn, isbn_regex) || !regex_match(edition, number_regex) 
		|| !regex_match(date_of_printing, date_regex) || !regex_match(is_approved, y_or_n_regex)
		|| !regex_match(date_of_approval, date_regex) || !regex_match(price, number_with_floating_point_regex)
		|| !regex_match(book_distributor_id, number_regex));
	textbook.Setbook_distributor(Service::get_book_distributor_by_id(StringUtils::string_to_int(book_distributor_id.c_str())));
	textbook.Setid(Service::get_next_textbook_id());
	textbook.Settitle(title.c_str());
	textbook.Setisbn(isbn.c_str());
	textbook.Setauthors(textbook_authors);
	textbook.Setedition(StringUtils::string_to_int(edition.c_str()));
	Date print_date;
	date_of_printing.c_str() >> print_date;
	textbook.Setprint_date(print_date);
	if (textbook.Getis_approved())
	{
		Date approved_date;
		date_of_approval.c_str() >> approved_date;
		textbook.Setapproved_date(approved_date);
	}
	textbook.Setprice(stod(price));
	Service::add_textbook(textbook);
}

void Controller::order_textbooks_for_book_distributor_menu()
{
	string book_distributor_id, textbooks_count;
	BookDistributor book_distributor;
	vector<Textbook> found_textbooks, ordered_textbooks;
	cout << "Enter book distributor's id:" << endl;
	getline(cin, book_distributor_id);
	if (regex_match(book_distributor_id, number_regex))
	{
		book_distributor = Service::get_book_distributor_by_id(StringUtils::string_to_int(book_distributor_id.c_str()));
		found_textbooks = Service::get_textbooks_by_book_distributor(book_distributor);
		if (found_textbooks.empty())
		{
			cout << "There are no textbooks for this book distributor." << endl;
		}
		else
		{
			cout << "Available textbooks for this book distributor:" << endl;
			for (auto& textbook : found_textbooks)
			{
				cout << textbook << "Authors:" << endl;
				for (const auto& author : textbook.Getauthors())
				{
					cout << author;
				}
			}
			cout << "Enter how many textbooks will you order:" << endl;
			getline(cin, textbooks_count);
			if (regex_match(textbooks_count, number_regex))
			{
				int textbooks_count_int = StringUtils::string_to_int(textbooks_count.c_str());
				for (int i = 0; i < textbooks_count_int; ++i)
				{
					string textbook_id;
					cout << "One of the above textbook's id to add this textbook to the cart:" << endl;
					getline(cin, textbook_id);
					Textbook textbook = Service::get_textbook_in_given_vector_by_id(found_textbooks, 
						StringUtils::string_to_int(textbook_id.c_str()));
					ordered_textbooks.push_back(textbook);
				}
				cout << "Your final price is: " << Service::calculate_textbooks_price(ordered_textbooks) << endl;
			}
			else
			{
				cout << "Wrong input" << endl;
			}
		}
	}
	else
	{
		cout << "Wrong input" << endl;
	}
}