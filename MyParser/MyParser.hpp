#pragma once
#include "Token.hpp"
#include "Graph.hpp"
#include <list>
namespace parser {
	namespace additional {
		bool is_token(char c);

		std::string simplify(std::string source);
		std::list<std::string> parse_code(std::string source);
		std::list<std::string> unite(std::list<std::string> source);
		std::list<Token> classify(std::list<std::string> source);

		graph::Node parse_graph(std::list<std::string> source);
	}
	std::list<Token> parse_tokens(std::string source);
	std::list<Graph> parse_syntax(std::string source);
};