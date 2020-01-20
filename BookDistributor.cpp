#include "BookDistributor.h"

using namespace std;

BookDistributor::BookDistributor(long id, const char* name, const char* address, const char* phone_number)
{
	m_Id = id;
	strcpy_s(m_Name, name);
	strcpy_s(m_Address, address);
	strcpy_s(m_Phone_number, phone_number);
}

ostream& operator<<(ostream& os, const BookDistributor& book_distibutor)
{
	os << "Id: " << book_distibutor.m_Id << ", Name: " << book_distibutor.m_Name << ", Address: " << book_distibutor.m_Address 
		<< ", Phone number: " << book_distibutor.m_Phone_number << endl;
	return os;
}

istream& operator>>(istream& is, BookDistributor& book_distributor)
{
	is >> book_distributor.m_Id >> book_distributor.m_Name >> book_distributor.m_Address >> book_distributor.m_Phone_number;
	return is;
}

void BookDistributor::write_in_file(ostream& file)
{
	file.write((char*)&m_Id, sizeof(m_Id));
	file.write((char*)&m_Name, sizeof(m_Name));
	file.write((char*)&m_Address, sizeof(m_Address));
	file.write((char*)&m_Phone_number, sizeof(m_Phone_number));
}

void BookDistributor::read_from_file(istream& file)
{
	file.read((char*)&m_Id, sizeof(m_Id));
	file.read((char*)&m_Name, sizeof(m_Name));
	file.read((char*)&m_Address, sizeof(m_Address));
	file.read((char*)&m_Phone_number, sizeof(m_Phone_number));
}