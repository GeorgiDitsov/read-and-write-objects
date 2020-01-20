#include "Textbook.h"

using namespace std;

Textbook::Textbook(long id, const char* title, const char* isbn, vector<Author> authors, int edition, Date print_date, bool is_approved, Date approved_date,
	BookDistributor book_distributor, double price)
{
	m_Id = id;
	strcpy_s(m_Title, title);
	strcpy_s(m_ISBN, isbn);
	m_Authors = authors;
	m_Edition = edition;
	m_Print_date = print_date;
	m_Is_approved = is_approved;
	m_Approved_date = approved_date;
	m_Book_distributor = book_distributor;
	m_Price = price;
}

ostream& operator<<(ostream& os, const Textbook& textbook)
{
	os << "Textbook\nId: " << textbook.m_Id << "\nTitle: " << textbook.m_Title << "\nISBN: " << textbook.m_ISBN  
		<< "\nEdition: " << textbook.m_Edition << "\nDate of printing: " << textbook.m_Print_date 
		<< "\nIs it approved: " << textbook.m_Is_approved << "\nDate of approving: " << textbook.m_Approved_date 
		<< "\nBook distributor: " << textbook.m_Book_distributor << "Price: " << textbook.m_Price << endl;
	return os;
}

void Textbook::write_in_file(ostream& file)
{
	int authors_count = m_Authors.size();
	file.write((char*)&m_Id, sizeof(m_Id));
	file.write((char*)&m_Title, sizeof(m_Title));
	file.write((char*)&m_ISBN, sizeof(m_ISBN));
	file.write((char*)&m_Edition, sizeof(m_Edition));
	file.write((char*)&m_Is_approved, sizeof(m_Is_approved));
	file.write((char*)&m_Price, sizeof(m_Price));
	file.write((char*)&authors_count, sizeof(authors_count));
	m_Print_date.write_in_file(file);
	m_Approved_date.write_in_file(file);
	m_Book_distributor.write_in_file(file);
	for (int i = 0; i < authors_count; ++i)
	{
		m_Authors[i].write_in_file(file);
	}
}

void Textbook::read_from_file(istream& file)
{
	int authors_count = 0;
	Author author;
	vector<Author> textbook_authors;
	file.read((char*)&m_Id, sizeof(m_Id));
	file.read((char*)&m_Title, sizeof(m_Title));
	file.read((char*)&m_ISBN, sizeof(m_ISBN));
	file.read((char*)&m_Edition, sizeof(m_Edition));
	file.read((char*)&m_Is_approved, sizeof(m_Is_approved));
	file.read((char*)&m_Price, sizeof(m_Price));
	file.read((char*)&authors_count, sizeof(authors_count));
	m_Print_date.read_from_file(file);
	m_Approved_date.read_from_file(file);
	m_Book_distributor.read_from_file(file);
	for (int i = 0; i < authors_count; ++i)
	{
		author.read_from_file(file);
		textbook_authors.push_back(author);
	}
	m_Authors = textbook_authors;
}