#include "FileIO.h"

using namespace std;


void FileIO::write_author_to_file(Author& author)
{
	m_File.open(m_File_name, ios::app | ios::binary);
	if (!m_File)
	{
		cerr << "Error in opening the file! " << m_File_name << endl;
		exit(1);
	}
	m_File.write((char*)&author, sizeof(author));
	m_File.close();
	cout << "New author saved." << endl;
}

void FileIO::write_book_distributor_to_file(BookDistributor& book_distributor)
{
	m_File.open(m_File_name, ios::app | ios::binary);
	if (!m_File)
	{
		cerr << "Error in opening the file!" << m_File_name << endl;
		exit(1);
	}
	m_File.write((char*)&book_distributor, sizeof(book_distributor));
	m_File.close();
	cout << "New book distributor saved." << endl;
}

void FileIO::write_textbook_to_file(Textbook& textbook)
{
	m_File.open(m_File_name, ios::app | ios::binary);
	if (!m_File)
	{
		cerr << "Error in opening the file!" << m_File_name << endl;
		exit(1);
	}
	textbook.write_in_file(m_File);
	m_File.close();
	cout << "New textbook saved." << endl;
}

vector<Author> FileIO::read_authors_from_file()
{
	vector<Author> authors;
	m_File.open(m_File_name, ios::in | ios::binary);
	if (!m_File)
	{
		cerr << "Error in opening the file!" << endl;
	}
	Author temp;
	while (m_File.read((char*)&temp, sizeof(temp)))
	{
		authors.push_back(temp);
	}
	m_File.close();
	return authors;
}

vector<BookDistributor> FileIO::read_book_distributors_from_file()
{
	vector<BookDistributor> book_distributors;
	m_File.open(m_File_name, ios::in | ios::binary);
	if (!m_File)
	{
		cerr << "Error in opening the file!" << endl;
	}
	BookDistributor temp;
	while(m_File.read((char*)&temp, sizeof(temp)))
	{
		book_distributors.push_back(temp);
	}
	m_File.close();
	return book_distributors;
}

vector<Textbook> FileIO::read_textbooks_from_file()
{
	vector<Textbook> textbooks;
	m_File.open(m_File_name, ios::in | ios::binary);
	if (!m_File)
	{
		cerr << "Error in opening the file!" << endl;
	}
	Textbook temp;
	while (m_File.peek() != EOF)
	{
		temp.read_from_file(m_File);
		textbooks.push_back(temp);
	}
	m_File.close();
	return textbooks;
}