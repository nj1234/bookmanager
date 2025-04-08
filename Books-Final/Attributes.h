#pragma once
#include<cassert>
#include<map>
#include<variant>

#include"Enums.h"

typedef std::variant<int, std::string,  Kind, Genre, Region, Subject> AttributeValue;
typedef std::map<Key, AttributeValue> AttributeMap;

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




