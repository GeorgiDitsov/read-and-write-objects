#include "Service.h"

#define AUTHORS_FILE_NAME "authors.dat"
#define BOOK_DISTRIBUTORS_FILE_NAME "bookDistributors.dat"
#define TEXTBOOKS_FILE_NAME "textbooks.dat"

using namespace std;

FileIO fio;

vector<Author> Service::load_all_authors()
{
	fio.Setfile_name(AUTHORS_FILE_NAME);
	return fio.read_authors_from_file();
}

vector<BookDistributor> Service::load_all_book_distributors()
{
	fio.Setfile_name(BOOK_DISTRIBUTORS_FILE_NAME);
	return fio.read_book_distributors_from_file();
}

vector<Textbook> Service::load_all_textbooks()
{
	fio.Setfile_name(TEXTBOOKS_FILE_NAME);
	return fio.read_textbooks_from_file();
}

void Service::add_author(Author& author)
{
	fio.Setfile_name(AUTHORS_FILE_NAME);
	fio.write_author_to_file(author);
}

void Service::add_book_distributor(BookDistributor& book_distributor)
{
	fio.Setfile_name(BOOK_DISTRIBUTORS_FILE_NAME);
	fio.write_book_distributor_to_file(book_distributor);
}

void Service::add_textbook(Textbook& textbook)
{
	fio.Setfile_name(TEXTBOOKS_FILE_NAME);
	fio.write_textbook_to_file(textbook);
}

Author Service::get_author_by_id(long id)
{
	Author found_author;
	for (auto& author : load_all_authors())
	{
		if(author.Getid() == id)
		{
			found_author = author;
			return found_author;
		}
	}
	cerr << "No author found with this id." << endl;
}

BookDistributor Service::get_book_distributor_by_id(long id)
{
	for (auto& book_distributor : load_all_book_distributors())
	{
		if (book_distributor.Getid() == id)
		{
			BookDistributor found_book_distributor;
			found_book_distributor = book_distributor;
			return found_book_distributor;
		}
	}
	cerr << "No book distributor found with this id." << endl;
}

Textbook Service::get_textbook_by_id(long id)
{
	Textbook found_textbook;
	for (auto& textbook : load_all_textbooks())
	{
		if (textbook.Getid() == id)
		{
			found_textbook = textbook;
			return found_textbook;
		}
	}
	cerr << "No textbook found with this id." << endl;
}

long Service::get_next_author_id()
{
	vector<Author> authors = load_all_authors();
	if (authors.empty())
	{
		return 1;
	}
	return authors[authors.size() - 1].Getid() + 1;
}

long Service::get_next_book_distributor_id()
{
	vector<BookDistributor> book_distributors = load_all_book_distributors();
	if (book_distributors.empty())
	{
		return 1;
	}
	return book_distributors[book_distributors.size() - 1].Getid() + 1;
}

long Service::get_next_textbook_id()
{
	vector<Textbook> textbooks = load_all_textbooks();
	if (textbooks.empty())
	{
		return 1;
	}
	return textbooks[textbooks.size() - 1].Getid() + 1;
}

vector<Textbook> Service::get_textbooks_by_book_distributor(BookDistributor& book_distributor)
{
	vector<Textbook> found_textbooks;
	for (auto& textbook : load_all_textbooks())
	{
		if (textbook.Getbook_distributor().Getid() == book_distributor.Getid())
		{
			found_textbooks.push_back(textbook);
		}
	}
	return found_textbooks;
}

Textbook Service::get_textbook_in_given_vector_by_id(vector<Textbook>& given_vector_of_textbooks, long textbook_id)
{
	for (auto& textbook : given_vector_of_textbooks)
	{
		if (textbook.Getid() == textbook_id)
		{
			return textbook;
		}
	}
	cerr << "No textbook found with this id in the given list of textbooks." << endl;
}

double Service::calculate_textbooks_price(vector<Textbook>& textbooks)
{
	double price = 0;
	for (auto& textbook : textbooks)
	{
		price += textbook.Getprice();
	}
	return price;
}
