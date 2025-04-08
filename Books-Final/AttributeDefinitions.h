/*
   This file contains the definitions of various enumerations and type aliases 
   related to attributes used within the application. It includes:
    - Enumerations for different categories such as Key, Kind, Genre, Region, and Subject.
    - Type definitions for AttributeValue and AttributeMap to facilitate flexible 
     attribute handling and mapping.

   The purpose of this file is to centralize the declarations of attributes, 
    ensuring consistent and organized usage across the project.
*/

#pragma once
#include<ostream>
#include<map>
#include<variant>

enum class Key { KIND, TITLE, FIRST_NAME, LAST_NAME, YEAR, GENRE, REGIN, SUBJECT };
enum class Kind { FICTION, COOKBOOK, HOWTO ,NONFICTION };
enum class Genre { ADVENTURE, CLASSICS, DETECTIVE, FANTASY, HISTORIC, HORROR, ROMANCE, SCIFI, DYSTOPIA , PHILOSOPY, TECHNICAL};
enum class Region { CHINA, FRANCE, INDIA, ITALY, MEXICO, PERSIA, US };
enum class Subject { DRAWING, PAINTING, WRITING };

enum class Type_Indexes { INT_INDEX, STRING_INDEX, KIND_INDEX, GENRE_INDEX, REGION_INDEX, SUBJECT_INDEX }; //<-- defines the indexes corresponding to the data types used in the AttributeValue variant
typedef std::variant<int, std::string, Kind, Genre, Region, Subject> AttributeValue; // IMPORTANT !!! THE ORDER OF DATA-TYPES MUST MATCH THE ORDER OF ENUM CLASS Type_Indexes  

typedef std::map<Key, AttributeValue> AttributeMap;

/***************************************************************************
*
*				          OPERATOR << OVERLOADS
*
* **************************************************************************/

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
	case Key::LAST_NAME:
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
	case Kind::NONFICTION:
		ostr << "Non Fiction ";
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
	case Genre::DYSTOPIA:
		ostr << "Dystopia ";
		break;
	case Genre::PHILOSOPY:
		ostr << "Philosopy ";
		break;
	case Genre::TECHNICAL:
		ostr << "Technical ";
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