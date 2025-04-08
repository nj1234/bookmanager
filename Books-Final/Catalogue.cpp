#include "Catalogue.h"

Catalogue::~Catalogue()
{
	for (Book* book : books)
	{
		delete book;
	}
	books.clear();
}

void Catalogue::add(Attributes* const attr)
{
    this->books.push_back(new Book(attr));
}

std::vector<Book*> Catalogue::find(const Attributes& attr) const
{
	std::vector<Book*> matches;
	std::vector<Book*>::const_iterator it;

	for (it = books.begin(); it!= books.end();it++)
	{
		if ((*it)->get_Attributes()->is_Matching(attr))
			matches.push_back(*it);
	}

    return matches;
}

