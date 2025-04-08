#pragma once
#include<cassert>
#include<ostream>
#include<map>
#include<variant>

enum class Key{KIND,TITLE ,FIRST_NAME,LAST_NAME,YEAR, GENRE, REGIN ,SUBJECT};
enum class Kind{FICTION,COOKBOOK,HOWTO};
enum class Genre{ADVENTURE, CLASSICS, DETECTIVE, FANTASY, HISTORIC,HORROR, ROMANCE, SCIFI};
enum class Region { CHINA, FRANCE, INDIA, ITALY, MEXICO, PERSIA, US };
enum class Subject { DRAWING, PAINTING, WRITING };

typedef std::variant<int, std::string,  Kind, Genre, Region, Subject> AttributeValue;
typedef std::map<Key, AttributeValue> AttributeMap;

enum class Type_Indexes{INT_INDEX,STRING_INDEX,KIND_INDEX,GENRE_INDEX,REGION_INDEX,SUBJECT_INDEX};
class Attributes
{
public:
	Attributes(AttributeMap* const pairs);
	~Attributes();
	bool is_Matching(const Attributes& target_attr) const;
	friend std::ostream& operator<<(std::ostream& ostr, const Attributes& attr);
private:
	AttributeMap* attributeMap;
	bool is_Matching_pair(const Key& key, const AttributeValue& value) const;
	bool equal_ignore_case(std::string s1, std::string s2) const;
	
};

/***************************************************************************
* 
*				OPERATOR << OVERLOADS 			
* 
* **************************************************************************
*/

inline std::ostream& operator<<(std::ostream& ostr, const Key& key) {

	switch (key)
	{
		case Key::KIND: 
			ostr << "KIND : ";
			break;
		case Key::TITLE:
			ostr << "TITLE : ";
			break;
		case Key::FIRST_NAME:
			ostr << "FIRST_NAME : ";
			break;
		case Key::LAST_NAME :
			ostr << "LAST_NAME : ";
			break;
		case Key::YEAR:
			ostr << "YEAR : ";
			break;
		case Key::GENRE:
			ostr << "GENRE : ";
			break;
		case Key::REGIN:
			ostr << "REGION : ";
			break;
		case Key::SUBJECT:
			ostr << "SUBJECT : ";
			break;
	default:
		break;
	}
	return ostr;
}

inline std::ostream& operator<<(std::ostream& ostr, const Kind& kind) {
	switch (kind)
	{
		case Kind::FICTION:
			ostr << "Fiction ";
			break;
		case Kind::COOKBOOK:
			ostr << "Cook Book ";
			break;
		case Kind::HOWTO:
			ostr << "How to ";
			break;
	default:
		break;
	}
	return ostr;
}

inline std::ostream& operator<<(std::ostream& ostr, const Genre& genre) {
	switch (genre)
	{
	case Genre::ADVENTURE:
		ostr << "Adventure ";
		break;
	case Genre::CLASSICS:
		ostr << "Classics ";
		break;
	case Genre::DETECTIVE:
		ostr << "Detective ";
		break;
	case Genre::FANTASY:
		ostr << "Fantasy ";
		break;
	case Genre::HISTORIC:
		ostr << "Histpric ";
		break;
	case Genre::HORROR:
		ostr << "Horror ";
		break;
	case Genre::ROMANCE:
		ostr << "Romance ";
		break;
	case Genre::SCIFI:
		ostr << "Sci-Fi ";
		break;
	default:
		break;
	}
	return ostr;
}

inline std::ostream& operator<< (std::ostream& ostr, const Region& region) {

	switch (region)
	{
	case Region::CHINA:
		ostr << "China ";
		break;
	case Region::FRANCE:
		ostr << "France ";
		break;
	case Region::INDIA:
		ostr << "India ";
		break;
	case Region::ITALY:
		ostr << "Italy ";
		break;
	case Region::MEXICO: 
		ostr << "Mexico ";
		break;
	case Region::PERSIA:
		ostr << "Persia ";
		break;
	case Region::US:
		ostr << "Us ";
		break;

	default:
		break;
	}
	return ostr;
}
//enum class Subject { DRAWING, PAINTING, WRITING };

inline std::ostream& operator<<(std::ostream& ostr, const Subject& subject) {

	switch (subject)
	{
	case Subject::DRAWING:
		ostr << "Drawing  ";
		break;
	case Subject::PAINTING:
		ostr << "Painting  ";
		break;
	case Subject::WRITING:
		ostr << "Writing  ";
		break;
	default:
		break;
	}
	return ostr;
}


