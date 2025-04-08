#pragma once
#include<vector>
#include"Book.h"
class Catalogue
{
public:
	void add(Attributes* const attr);
	std::vector<Book*> find(const Attributes& attr) const;
	~Catalogue();

private:
	std::vector<Book*> books;
};

