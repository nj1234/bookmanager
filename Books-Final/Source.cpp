#include<iostream>
#include "Attributes.h"

int main() {
	
	Attributes attr(new AttributeMap{
		{Key::KIND,Kind::FICTION},
		{Key::LAST_NAME,"Tester"},
		{Key::FIRST_NAME,"ohoho"},
		{Key::GENRE,Genre::HORROR}
		});

	std::cout << attr;
}