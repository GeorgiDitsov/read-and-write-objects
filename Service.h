#include "FileIO.h"

class Service
{
	private:
		Service();

	public:
		static std::vector<Author> load_all_authors();
		static std::vector<BookDistributor> load_all_book_distributors();
		static std::vector<Textbook> load_all_textbooks();
		static void add_author(Author& author);
		static void add_book_distributor(BookDistributor& book_distributor);
		static void add_textbook(Textbook& textbook);
		static Author get_author_by_id(long id);
		static BookDistributor get_book_distributor_by_id(long id);
		static Textbook get_textbook_by_id(long id);
		static long get_next_author_id();
		static long get_next_book_distributor_id();
		static long get_next_textbook_id();
		static std::vector<Textbook> get_textbooks_by_book_distributor(BookDistributor& book_distributor);
		static Textbook get_textbook_in_given_vector_by_id(std::vector<Textbook>& given_vector_of_textbooks, long textbook_id);
		static double calculate_textbooks_price(std::vector<Textbook>& textbooks);
};
