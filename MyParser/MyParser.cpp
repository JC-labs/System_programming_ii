#include "MyParser.hpp"
#include <sstream>
bool parser::additional::is_token(char c) {
	std::string tokens = "{}-;()=[]";
	for (auto it : tokens)
		if (c == it)
			return true;
	return false;
}

std::string parser::additional::simplify(std::string source) {
	for (size_t i = 0; i < source.size(); i++) {
		if (source[i] == '\n' || source[i] == '\t')
			source[i] = ' ';
		if (parser::additional::is_token(source[i])) {
			source.insert(i + 1, " ");
			source.insert(i, " ");
			i += 2;
		}
	}
	return source;
}

std::list<std::string> parser::additional::parse_code(std::string source) {
	std::list<std::string> ret;
	std::istringstream s(source);
	std::string temp;
	while (std::getline(s, temp, ' '))
		ret.push_back(temp);
	ret.remove_if([](std::string it) { return it == ""; });
	return ret;
}

std::list<std::string> parser::additional::unite(std::list<std::string> source) {
	auto it1 = source.begin();
	auto it2 = it1; it2++;
	for (; it2 != source.end(); it1++, it2++)
		if (*it1 == *it2) {
			*it1 += *it1;
			source.erase(it2);
			it2 = it1;
			it2++;
		} else if (*it2 == "=" && (*it1 == "+" || *it1 == "-" 
			|| *it1 == "*" || *it1 == "/" || *it1 == "<" 
			|| *it1 == ">" || *it1 == "%")) {

			*it1 += *it2;
			source.erase(it2);
			it2 = it1;
			it2++;
		}
	return source;
}

std::list<parser::Token> parser::additional::classify(std::list<std::string> source) {
	std::list<Token> ret;
	for (auto token : source) 
		ret.push_back(generate_token(token));
	return ret;
}

std::list<parser::Token> parser::parse(std::string source) {
	auto simplified = additional::simplify(source);
	auto tokens = additional::parse_code(simplified);
	auto united = additional::unite(tokens);
	auto classified = additional::classify(united);
	return classified;
}