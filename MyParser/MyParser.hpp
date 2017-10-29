#pragma once
#include "Token.hpp"
#include <list>
namespace parser {
	namespace additional {
		bool is_token(char c);

		std::string simplify(std::string source);
		std::list<std::string> parse_code(std::string source);
		std::list<std::string> unite(std::list<std::string> source);
		std::list<Token> classify(std::list<std::string> source);
	}
	std::list<Token> parse(std::string source);
};