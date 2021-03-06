#pragma once
#include "Token.hpp"
#include "Graph.hpp"
#include <list>
#include <map>
namespace parser {
	namespace additional {
		bool is_token(char c);

		std::string simplify(std::string source);
		std::list<std::string> parse_code(std::string source);
		std::list<std::string> unite(std::list<std::string> source);
		std::list<Token> classify(std::list<std::string> source);

		std::list<graph::Node> parse_brackets(std::list<graph::Node> source);
		graph::Node parse_operators(std::list<graph::Node> source);
		graph::Node* parse_graph(std::list<graph::Node> source);
		graph::Node* parse_graph(std::list<Token> source);
		graph::Node* parse_graph_pascal(std::list<graph::Node> source);
		graph::Node* parse_graph_pascal(std::list<Token> source);
		graph::Node parse_operators_pascal(std::list<graph::Node> source);
		std::list<graph::Node> parse_brackets_pascal(std::list<graph::Node> source);

		graph::Node* parse_variables(std::list<graph::Node> source);

		void addVariables(std::map<std::string, std::pair<std::string, size_t>> &variables, graph::Node *node, std::string type);
		void isVariable(std::map<std::string, std::pair<std::string, size_t>> const& variables, graph::Node *node);
		std::pair<std::string, size_t> determine_type(std::map<std::string, std::pair<std::string, size_t>> const& variables, graph::Node *node);
	}
	std::list<Token> parse_tokens(std::string source);
	std::list<Graph> parse_syntax(std::string source);
	Graph parse_syntax_pascal(std::string source);
	void semantics_check(std::list<Graph>);
};