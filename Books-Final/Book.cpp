#include "Book.h"

Book::Book(Attributes* const attr):
    attributes(attr)
{
}

Book::~Book()
{
    delete this->attributes;
    this->attributes = nullptr;
}

Attributes* Book::get_Attributes() const
{
    return this->attributes;
}
