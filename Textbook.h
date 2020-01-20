#include "Author.h"
#include "Date.h"
#include "BookDistributor.h"

class Textbook
{
	private:
		long m_Id;
		char m_Title[100];
		char m_ISBN[18];
		std::vector<Author> m_Authors;
		int m_Edition;
		Date m_Print_date;
		bool m_Is_approved;
		Date m_Approved_date;
		BookDistributor m_Book_distributor;
		double m_Price;

	public:
		Textbook() : m_Id(), m_Title(), m_ISBN(), m_Authors(), m_Edition(), m_Print_date(), m_Is_approved(), m_Approved_date(), 
			m_Book_distributor(), m_Price() {};
		Textbook(long id, const char* title, const char* isbn, std::vector<Author> authors, int edition_count, Date print_date, 
			bool is_approved, Date approved_date, BookDistributor book_distributor, double price);
		long Getid() { return m_Id; };
		void Setid(long id) { m_Id = id; };
		char* Gettitle() { return m_Title; };
		void Settitle(const char* title) { strcpy_s(m_Title, title); };
		char* Getisbn() { return m_ISBN; };
		void Setisbn(const char* isbn) { strcpy_s(m_ISBN, isbn); };
		std::vector<Author> Getauthors() { return m_Authors; };
		void Setauthors(std::vector<Author> authors) { m_Authors = authors; };
		int Getedition() { return m_Edition; };
		void Setedition(int edition) { m_Edition = edition; };
		Date Getprint_date() { return m_Print_date; };
		void Setprint_date(Date print_date) { m_Print_date = print_date; };
		bool Getis_approved() { return m_Is_approved; };
		void Setis_approved(bool is_approved) { m_Is_approved = is_approved; };
		Date Getapproved_date() { return m_Approved_date; };
		void Setapproved_date(Date approved_date) { m_Approved_date = approved_date; };
		BookDistributor Getbook_distributor() { return m_Book_distributor; };
		void Setbook_distributor(BookDistributor book_distributor) { m_Book_distributor = book_distributor; };
		double Getprice() { return m_Price; };
		void Setprice(double price) { m_Price = price; };
		friend std::ostream& operator<<(std::ostream& os, const Textbook& textbook);
		void write_in_file(std::ostream& file);
		void read_from_file(std::istream& file);
};
