#include <iostream>
#include <fstream>

class BookDistributor
{
	private:
		long m_Id;
		char m_Name[100];
		char m_Address[100];
		char m_Phone_number[11];

	public:
		BookDistributor() : m_Id(), m_Name(), m_Address(), m_Phone_number() {};
		BookDistributor(long id, const char* name, const char* address, const char* phone_number);
		long Getid() { return m_Id; };
		void Setid(long id) { m_Id = id; };
		char* Getname() { return m_Name; };
		void Setname(char* name) { strcpy_s(m_Name, name); };
		char* Getaddress() { return m_Address; };
		void Setaddress(char* address) { strcpy_s(m_Address, address); };
		char* Getphone_number() { return m_Phone_number; };
		void Setphone_number(char* phone_number) { strcpy_s(m_Phone_number, phone_number); };
		friend std::ostream& operator<<(std::ostream& os, const BookDistributor& book_distibutor);
		friend std::istream& operator>>(std::istream& is, BookDistributor& book_distributor);
		void write_in_file(std::ostream& file);
		void read_from_file(std::istream& file);
};


