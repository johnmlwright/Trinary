#include "element.h"

Element::Element(char d)
{
	display = d;
	type = "Element";
	health = 1;
}

Element::~Element()
{


}

std::ostream& operator<<(std::ostream& ostream, const Element& input_element)
{
	ostream << input_element.display;
	return ostream;
}