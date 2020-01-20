#include <regex>

class Controller
{
	private:
		Controller();

	public:
		static void print_all_authors();
		static void print_all_book_distributors();
		static void print_all_textbooks();
		static void add_new_author_menu();
		static void add_new_book_distributor_menu();
		static void add_new_textbook_menu();
		static void order_textbooks_for_book_distributor_menu();
};
