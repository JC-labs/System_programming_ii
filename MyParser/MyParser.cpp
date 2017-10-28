#include "MyParser.hpp"
#include <sstream>
//std::list<std::string> MyParser::parse_code(std::string source) {
//	std::list<std::string> ret;
//	std::istringstream s(source);
//	std::string temp;
//	while (std::getline(s, temp, ' '))
//		ret.push_back(temp);
//	ret.remove_if([](std::string it) { return it == ""; });
//	return ret;
//}

std::string parser::additional::simplify(std::string source) {
	for (size_t i = 0; i < source.size(); i++)
		if (source[i] == '\n' || source[i] == '\t')
			source[i] = ' ';
	return source;
}

Lexeme parser::parse(std::string source) {
	source = additional::simplify(source);
	std::istringstream s(source);
	std::string temp;
	std::getline(s, temp, ' ');
	if (temp == "do") {
		//Do_While *temp = new Do_While(parser::parse(source), parser::parse(source));
	}
	return Lexeme();
}