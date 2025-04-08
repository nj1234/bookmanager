#pragma once
#include"Attributes.h"

class Book
{
public:
	Book(Attributes* const attr);
	~Book();
	Attributes* get_Attributes() const;
private:
	Attributes* attributes = nullptr;
};

inline std::ostream& operator<<(std::ostream& ostr, const Book& book) {
	ostr << *book.get_Attributes();
	return ostr;
}