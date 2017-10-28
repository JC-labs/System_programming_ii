#pragma once
#include "Lexeme.hpp"
#include <string>
#include <list>
namespace parser {
	namespace additional {
		//std::list<std::string> parse_code(std::string source);
		//std::list<Lexeme> parse_operator(std::string source);

		std::string simplify(std::string source);
	}
	Lexeme parse(std::string source);
};