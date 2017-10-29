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
		if (*it1 == *it2 && *it1 == "+" && *it1 == "-" && *it1 == "=") {
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

NodeType switch_(std::string s) {
	if (s == "Punctuator") return NodeType::Punctuator;
	if (s == "Bracket") return NodeType::Bracket;
	if (s == "Operator") return NodeType::Operator;
	if (s == "Reserved word") return NodeType::Reserved;
	if (s == "Literal") return NodeType::Literal;
	if (s == "Variable") return NodeType::Variable;
	else return NodeType::Unknown;
}

std::list<graph::Node> parser::additional::parse_brackets(std::list<graph::Node> source) {
	for (auto it = source.begin(); it != source.end(); it++) {
		if (it->type == NodeType::Bracket && (it->value == "(" || it->value == "{" || it->value == "[")) {
			auto temp = it; temp++;
			auto nodes = parse_brackets({ temp, source.end() });
			source = { source.begin(), it };
			source.insert(source.end(), nodes.begin(), nodes.end());
			it = source.begin();
		} else if (it->type == NodeType::Bracket && (it->value == ")" || it->value == "}" || it->value == "]")) {
			graph::Node ret;
			ret.type = NodeType::Bracket;
			if (it->value == ")")
				ret.value = "()";
			else if (it->value == "}")
				ret.value = "{}";
			else if (it->value == "]")
				ret.value = "[]";
			if (it == source.begin())
				ret.left = new graph::Node(NodeType::Empty);
			else
				ret.left = parse_graph(std::list<graph::Node>{ source.begin(), it });

			source = { ++it, source.end() };
			source.push_front(ret);
			return source;
		}
	}
	return source;
}

graph::Node* parser::additional::parse_graph(std::list<graph::Node> source) {
	source = parse_brackets(source);
	return new graph::Node(source.front());
}

graph::Node* parser::additional::parse_graph(std::list<Token> source) {
	std::list<graph::Node> nodes;
	for (auto it : source)
		nodes.push_back(graph::Node(switch_(it.type), it.name));
	auto ret = parse_graph(nodes);
	return ret;
}

std::list<parser::Token> parser::parse_tokens(std::string source) {
	auto simplified = additional::simplify(source);
	auto tokens = additional::parse_code(simplified);
	auto united = additional::unite(tokens);
	auto classified = additional::classify(united);
	return classified;
}

std::list<Graph> parser::parse_syntax(std::string source) {
	auto tokens = parse_tokens(source);

	std::list<Graph> ret;
	auto start = tokens.begin();
	for (auto it = tokens.begin(); it != tokens.end(); it++)
		if (it->type == "Punctuator") {
			ret.push_back(additional::parse_graph(std::list<Token>{start, it}));
			start = it; start++;
		}
	return ret;
}
