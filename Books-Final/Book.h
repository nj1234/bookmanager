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

