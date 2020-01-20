#include <iostream>
#include <fstream>
#include <vector>
#include "Textbook.h"

class FileIO
{
	private:
		char m_File_name[21];
		std::fstream m_File;

	public:
		FileIO(): m_File_name() {};
		char* Getfile_name() { return m_File_name; };
		void Setfile_name(const char* file_name) { strcpy_s(m_File_name, file_name); };
		void write_author_to_file(Author& author);
		void write_book_distributor_to_file(BookDistributor& book_distributor);
		void write_textbook_to_file(Textbook& textbook);
		std::vector<Author> read_authors_from_file();
		std::vector<BookDistributor> read_book_distributors_from_file();
		std::vector<Textbook> read_textbooks_from_file();
};

