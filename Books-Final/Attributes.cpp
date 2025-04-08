#include "Attributes.h"

Attributes::Attributes(AttributeMap* const pairs):
	attributeMap(pairs)
{
	AttributeMap::iterator it;
	for (it = pairs->begin(); it != pairs->end(); it++) {

		Key key = it->first;
		int index =static_cast<int> (it->second.index());

		switch (key)
		{
		case Key::KIND:
			assert(index == static_cast<int>(Type_Indexes::KIND_INDEX));
			break;
		case Key::TITLE:
			assert(index == static_cast<int>(Type_Indexes::STRING_INDEX));
			break;
		case Key::FIRST_NAME:
			assert(index == static_cast<int>(Type_Indexes::STRING_INDEX));
			break;
		case Key::LAST_NAME:
			assert(index == static_cast<int>(Type_Indexes::STRING_INDEX));
			break;
		case Key::YEAR:
			assert(index == static_cast<int>(Type_Indexes::INT_INDEX));
			break;
		case Key::GENRE:
			assert(index == static_cast<int>(Type_Indexes::GENRE_INDEX));
			break;
		case Key::REGIN:
			assert(index == static_cast<int>(Type_Indexes::REGION_INDEX));
			break;
		case Key::SUBJECT:
			assert(index == static_cast<int>(Type_Indexes::SUBJECT_INDEX));
			break;
		default:
			break;
		}

	}
}

Attributes::~Attributes()
{
	delete this->attributeMap;
}

bool Attributes::is_Matching(const Attributes& target_attr) const
{
	AttributeMap* target_pairs = target_attr.attributeMap;
	AttributeMap::iterator it;
	for (it = target_pairs->begin(); it != target_pairs->end(); it++) {
		Key key = it->first;
		AttributeValue value = it->second;

		if (!this->is_Matching_pair(key, value))
			return false;
	}
	return true;
}

bool Attributes::is_Matching_pair(const Key& key, const AttributeValue& value) const
{

	if(this->attributeMap->find(key) == this->attributeMap->end())
	return false;

	if ((*attributeMap)[key] == value) {
		return true;
	}
	if (value.index() == static_cast<int> (Type_Indexes::STRING_INDEX)) {
		return this->equal_ignore_case(
			std::get<std::string>((*attributeMap)[key]),
			std::get<std::string>(value));
	}
	return false;
}

bool Attributes::equal_ignore_case(std::string s1, std::string s2) const
{
	if (s1.size() != s2.size())
		return false;

	for (size_t i = 0; i < s1.size() ; i++) {

		if (tolower(s1[i]) != tolower(s2[i]))
			return false;
	}
	return true;
}
std::ostream& operator<<(std::ostream& ostr, const Attributes& attr) {

	AttributeMap* map = attr.attributeMap;


	AttributeMap::iterator it;
	Key k;
	AttributeValue value;

	ostr << "{ ";

	for (it = map->begin(); it != map->end(); it++)
	{
		k = it->first;
		value = it->second;

		if (it != map->begin()) {
			ostr << " , ";
		}
		ostr << k;

		switch (k)
		{
		case Key::KIND:
			ostr << std::get<Kind>(value);
			break;
		case Key::TITLE:
			ostr << std::get<std::string>(value);
			break;
		case Key::FIRST_NAME:
			ostr << std::get<std::string>(value);
			break;
		case Key::LAST_NAME:
			ostr << std::get<std::string>(value);
			break;
		case Key::YEAR:
			ostr << std::get<int>(value);
			break;
		case Key::GENRE:
			ostr << std::get<Genre>(value);
			break;
		case Key::REGIN:
			ostr << std::get<Region>(value);
			break;
		case Key::SUBJECT:
			ostr << std::get<Subject>(value);
			break;
		default:
			break;
		}
		
	}
	ostr << " }";
	return ostr;
}