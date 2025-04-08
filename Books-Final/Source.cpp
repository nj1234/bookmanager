#include<iostream>
#include<crtdbg.h>
#include "Catalogue.h"

void fill(Catalogue& c);
void search(const Catalogue& c, const Attributes& attr );
void test(const Catalogue& c);
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	Catalogue catalogue;
	fill(catalogue);
	test(catalogue);
	
}
void fill(Catalogue& c) {
	AttributeMap pairs1 =
	{
		{ Key::KIND,  Kind::FICTION },
		{ Key::TITLE, std::string("War and Peace") },
		{ Key::LAST_NAME, std::string("Tolstoy") },
		{ Key::FIRST_NAME, std::string("Leo") },
		{ Key::YEAR, 1869 },
		{ Key::GENRE, Genre::HISTORIC }
	};
	AttributeMap pairs2 =
	{
		{Key::KIND,  Kind::FICTION},
		{Key::TITLE, std::string("To Kill a Mockingbird")},
		{Key::LAST_NAME,  std::string("Lee")},
		{Key::FIRST_NAME, std::string("Harper")},
		{Key::YEAR,  1960},
		{Key::GENRE, Genre::CLASSICS}
	};
	AttributeMap pairs3 =
	{
		{ Key::KIND,  Kind::FICTION },
		{ Key::TITLE, std::string("1984") },
		{ Key::LAST_NAME, std::string("Orwell") },
		{ Key::FIRST_NAME, std::string("George") },
		{ Key::YEAR, 1949 },
		{ Key::GENRE, Genre::DYSTOPIA }
	};
	AttributeMap pairs4 =
	{
		{ Key::KIND, Kind::FICTION },
		{ Key::TITLE, std::string("Brave New World") },
		{ Key::LAST_NAME, std::string("Huxley") },
		{ Key::FIRST_NAME, std::string("Aldous") },
		{ Key::YEAR, 1932 },
		{ Key::GENRE, Genre::DYSTOPIA }
	};
	AttributeMap pairs5 =
	{
		{Key::KIND,  Kind::NONFICTION},
		{Key::TITLE, std::string("The C++ Programming Language")},
		{Key::LAST_NAME, std::string("Stroustrup")},
		{Key::FIRST_NAME, std::string("Bjarne")},
		{Key::YEAR, 1985},
		{Key::GENRE, Genre::TECHNICAL}
	};
	AttributeMap pairs6 =
	{
		{Key::KIND,  Kind::NONFICTION},
		{Key::TITLE, std::string("Thus Spoke Zarathustra")},
		{Key::LAST_NAME, std::string("Nietzsche")},
		{Key::FIRST_NAME, std::string("Friedrich")},
		{Key::YEAR, 1883},
{		Key::GENRE, Genre::PHILOSOPY}
	};
	c.add(new Attributes(new AttributeMap(pairs1)));
	c.add(new Attributes(new AttributeMap(pairs2)));
	c.add(new Attributes(new AttributeMap(pairs3)));
	c.add(new Attributes(new AttributeMap(pairs4)));
	c.add(new Attributes(new AttributeMap(pairs5)));
	c.add(new Attributes(new AttributeMap(pairs6)));
}

void search(const Catalogue& c,const Attributes&  attr) {
	auto temp = c.find(attr);
	for (const auto& t: temp)
	{
		std::cout << *t;
	}
	std::cout << "\n";
}
void test(const Catalogue& c) {
	AttributeMap test1 = { {Key::GENRE,Genre::DYSTOPIA } };
	AttributeMap test2 = { {Key::TITLE,std::string("Thus Spoke Zarathustra")} };
	search(c, Attributes(new AttributeMap(test1)));
	search(c, Attributes(new AttributeMap(test2)));
}