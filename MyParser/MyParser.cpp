#include "MyParser.hpp"
#include <sstream>
bool parser::additional::is_token(char c) {
	std::string tokens = "{}-;()=[]+-*/%<>:,";
	for (auto it : tokens)
		if (c == it)
			return true;
	return false;
}
std::string parser::additional::simplify(std::string source) {
	for (size_t i = 0; i < source.size(); i++) {
		if (source[i] == '\n' || source[i] == '\t')
			source[i] = ' ';
		if (parser::additional::is_token(source[i]) || source[i] == ' ') {
			source.insert(i + 1, " ");
			source.insert(i, " ");
			i += 2;
		} else if (isalnum(source[i])) {

		} else
			throw std::exception((std::string("Unknown symbol '") + source[i] + "' was found.").c_str());
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
		if (*it1 == *it2 && (*it1 == "+" || *it1 == "-" || *it1 == "=")) {
			*it1 += *it1;
			source.erase(it2);
			it2 = it1;
			it2++;
		} else if (*it2 == "=" && (*it1 == "+" || *it1 == "-" 
			|| *it1 == "*" || *it1 == "/" || *it1 == "<" 
			|| *it1 == ">" || *it1 == "%" || *it1 == "=" || *it1 == ":")) {

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
std::list<graph::Node> parser::additional::parse_brackets(std::list<graph::Node> source) {
	for (auto it = source.begin(); it != source.end(); it++) {
		if (it->type == NodeType::Bracket_op) {
			auto temp = it; 
			auto nodes = parse_brackets({ ++temp, source.end() });
			source = { source.begin(), it };
			source.insert(source.end(), nodes.begin(), nodes.end());
			it = source.begin();
		} else if (it->type == NodeType::Bracket_cl) {
			graph::Node ret;
			ret.type = NodeType::Operator_u;
			if (it->value == ")")
				ret.value = "()";
			else if (it->value == "}")
				ret.value = "{}";
			else if (it->value == "]")
				ret.value = "[]";
			if (it == source.begin())
				ret.right = new graph::Node(NodeType::Empty);
			else
				ret.right = parse_graph(std::list<graph::Node>{ source.begin(), it });

			source = { ++it, source.end() };
			source.push_front(ret);
			return source;
		}
	}
	//if (source.size() == 1 || source.front().type == NodeType::Operator_u)
		return source;
	//else
	//	throw std::exception("Something's wrong with brackets.");
}

graph::Node parser::additional::parse_operators(std::list<graph::Node> source) {
	for (auto it = source.begin(); it != source.end(); it++) {
		if (it->type == NodeType::Operator_b) {
			graph::Node ret;
			ret.type = NodeType::Operator_b;
			ret.value = it->value;
			ret.left = parse_graph(std::list<graph::Node>{source.begin(), it});
			ret.right = parse_graph(std::list<graph::Node>{++it, source.end()});
			return ret;
		} else if (it->type == NodeType::Operator_u) {
			if (it->value == "+" || it->value == "-" || it->value == "*" || it->value == "/"
				|| it->value == "!" || it->value == "++" || it->value == "--") {

				graph::Node ret;
				ret.type = NodeType::Operator_u;
				ret.value = it->value;
				auto temp = it;
				ret.left = nullptr;
				ret.right = parse_graph(std::list<graph::Node>{++temp, source.end()});
				return ret;
			} else if (it->value == "[]") {
				graph::Node ret;
				ret.type = NodeType::Operator_u;
				ret.value = it->value;
				ret.left = parse_graph(std::list<graph::Node>{source.begin(), it});
				ret.right = it->right;
				return ret;
			} /*else if (it->value == "()" || it->value == "{}") {
				graph::Node ret;
				ret.type = NodeType::Operator_u;
				ret.value = it->value;
				ret.right = it->right;
				return ret;
			}*/
		} else if (it->type == NodeType::Typename) {
			graph::Node ret;
			ret.type = NodeType::Typename;
			ret.value = it->value;
			auto temp = it;
			ret.left = nullptr;
			ret.right = parse_variables(std::list<graph::Node>{++temp, source.end()});
			return ret;
		}
	}
	if (source.size() == 1)
		return source.front();
	else
		throw std::exception("Something's wrong with syntax.");
}
graph::Node* parser::additional::parse_variables(std::list<graph::Node> source) {
	for (auto it = source.begin(); it != source.end(); it++)
		if (it->type == NodeType::Operator_b && it->value == ",") {
			graph::Node *ret = new graph::Node;
			ret->type = NodeType::Operator_b;
			ret->value = it->value;
			ret->left = parse_variables(std::list<graph::Node>{source.begin(), it});
			ret->right = parse_variables(std::list<graph::Node>{++it, source.end()});
			return ret;
		}
	for (auto it = source.begin(); it != source.end(); it++)
		if (it->type == NodeType::Operator_u && it->value == "[]") { 
			auto temp = it;
			if (--temp != source.begin())
				throw std::exception(("Unexpected code was met before []-brackets: " + (*(--temp)).value).c_str());
			if (it != --source.end())
				throw std::exception(("Unexpected code was met after []-brackets: " + (*(++it)).value).c_str());
			graph::Node *ret = new graph::Node;
			ret->type = NodeType::Operator_u;
			ret->value = it->value;
			ret->left = &*source.begin();
			ret->right = nullptr;
			return ret;
		}
	if (source.size() == 1)
		return &source.front();
	else
		throw std::exception(("Unexpected code was met during variable initialization: " + (*(++source.begin())).value).c_str());
}
graph::Node* parser::additional::parse_graph(std::list<graph::Node> source) {
	source = parse_brackets(source);
	auto res = parse_operators(source);
	return new graph::Node(res);
}
graph::Node* parser::additional::parse_graph(std::list<Token> source) {
	std::list<graph::Node> nodes;
	for (auto it = source.begin(); it != source.end(); it++)
		if (it->type == "Punctuator")
			nodes.push_back(graph::Node(NodeType::Punctuator, it->name));
		else if (it->type == "Bracket") {
			if (it->name == "{" || it->name == "[" || it->name == "(")
				nodes.push_back(graph::Node(NodeType::Bracket_op, it->name));
			else if (it->name == "}" || it->name == "]" || it->name == ")")
				nodes.push_back(graph::Node(NodeType::Bracket_cl, it->name));
			else if (it->name == "{}" || it->name == "[]" || it->name == "()")
				nodes.push_back(graph::Node(NodeType::Brackets, it->name));
			else
				nodes.push_back(graph::Node(NodeType::Unknown, it->name));
		} else if (it->type == "Operator") {
			auto pre_it = it; if (it != source.begin()) pre_it--;
			auto post_it = it; if (it != source.end()) post_it++;
			if (((pre_it->type == "Variable" || pre_it->type == "Literal" || pre_it->name == "(" || pre_it->name == ")") &&
				(post_it->type == "Variable" || post_it->type == "Literal") || post_it->name == "(" || post_it->name == ")") ||
				it->name == ",")

				nodes.push_back(graph::Node(NodeType::Operator_b, it->name));
			else
				nodes.push_back(graph::Node(NodeType::Operator_u, it->name));
		} else if (it->type == "Reserved word")
			nodes.push_back(graph::Node(NodeType::Reserved, it->name));
		else if (it->type == "Literal")
			nodes.push_back(graph::Node(NodeType::Literal, it->name));
		else if (it->type == "Variable")
			nodes.push_back(graph::Node(NodeType::Variable, it->name));
		else if (it->type == "Typename")
			nodes.push_back(graph::Node(NodeType::Typename, it->name));
		else
			nodes.push_back(graph::Node(NodeType::Unknown, it->name));
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
			start = it; if (it != tokens.end()) start++;
		}
	return ret;
}

Graph parser::parse_syntax_pascal(std::string source) {
	auto tokens = parse_tokens(source);
	if (tokens.back().name != ";")
		throw std::exception("';' was expected at the end of the program.");
	for (auto it : tokens)
		if (it.type == "Unknown")
			throw std::exception(("Unknown token was met:\n" + it.text()).c_str());
	return additional::parse_graph_pascal(tokens);
}
graph::Node* parser::additional::parse_graph_pascal(std::list<graph::Node> source) {
	source = parse_brackets_pascal(source);
	auto res = parse_operators_pascal(source);
	return new graph::Node(res);
}
graph::Node* parser::additional::parse_graph_pascal(std::list<Token> source) {
	std::list<graph::Node> nodes;
	for (auto it = source.begin(); it != source.end(); it++)
		if (it->type == "Punctuator")
			nodes.push_back(graph::Node(NodeType::Punctuator, it->name));
		else if (it->type == "Bracket") {
			if (it->name == "{" || it->name == "[" || it->name == "(")
				nodes.push_back(graph::Node(NodeType::Bracket_op, it->name));
			else if (it->name == "}" || it->name == "]" || it->name == ")")
				nodes.push_back(graph::Node(NodeType::Bracket_cl, it->name));
			else if (it->name == "{}" || it->name == "[]" || it->name == "()")
				nodes.push_back(graph::Node(NodeType::Brackets, it->name));
			else
				nodes.push_back(graph::Node(NodeType::Unknown, it->name));
		} else if (it->type == "Operator") {
			auto pre_it = it; if (it != source.begin()) pre_it--;
			auto post_it = it; if (it != source.end()) post_it++;
			if ((pre_it->type == "Variable" || pre_it->name == "(" || pre_it->name == ")") &&
				(post_it->type == "Variable" || post_it->type == "Literal") || post_it->name == "(" || post_it->name == ")")

				nodes.push_back(graph::Node(NodeType::Operator_b, it->name));
			else
				nodes.push_back(graph::Node(NodeType::Operator_u, it->name));
		} else if (it->type == "Reserved word")
			nodes.push_back(graph::Node(NodeType::Reserved, it->name));
		else if (it->type == "Literal")
			nodes.push_back(graph::Node(NodeType::Literal, it->name));
		else if (it->type == "Variable")
			nodes.push_back(graph::Node(NodeType::Variable, it->name));
		else
			nodes.push_back(graph::Node(NodeType::Unknown, it->name));
	auto ret = parse_graph_pascal(nodes);
	return ret;
}
graph::Node parser::additional::parse_operators_pascal(std::list<graph::Node> source) {
	for (auto it = source.begin(); it != source.end(); it++) {
		if (it->type == NodeType::Punctuator) {
			graph::Node ret;
			ret.type = NodeType::Punctuator;
			ret.value = it->value;
			ret.left = parse_graph_pascal(std::list<graph::Node>{source.begin(), it});
			ret.right = parse_graph_pascal(std::list<graph::Node>{++it, source.end()});
			return ret;
		}
	}
	for (auto it = source.begin(); it != source.end(); it++) {
		if (it->type == NodeType::Operator_b) {
			graph::Node ret;
			ret.type = NodeType::Operator_b;
			ret.value = it->value;
			ret.left = parse_graph_pascal(std::list<graph::Node>{source.begin(), it});
			ret.right = parse_graph_pascal(std::list<graph::Node>{++it, source.end()});
			return ret;
		} else if (it->type == NodeType::Operator_u) {
			if (it->value == "+" || it->value == "-" || it->value == "*" || it->value == "/"
				|| it->value == "!" || it->value == "++" || it->value == "--") {

				graph::Node ret;
				ret.type = NodeType::Operator_u;
				ret.value = it->value;
				auto temp = it;
				ret.left = nullptr;
				ret.right = parse_graph_pascal(std::list<graph::Node>{++temp, source.end()});
				return ret;
			} else if (it->value == "[]") {
				graph::Node ret;
				ret.type = NodeType::Operator_u;
				ret.value = it->value;
				ret.left = parse_graph_pascal(std::list<graph::Node>{source.begin(), it});
				ret.right = it->right;
				return ret;
			} 
		} else if (it->value == "if") {
			graph::Node ret;
			ret.type = NodeType::Reserved;
			ret.value = "if";
			auto eit = it;
			do { eit++; } while (eit->value != "then");
			ret.left = parse_graph_pascal(std::list<graph::Node>{++it, eit});
			ret.right = parse_graph_pascal(std::list<graph::Node>{++eit, source.end()});
			return ret;
		} else if (it->value == "else") {
			graph::Node ret;
			ret.type = NodeType::Reserved;
			ret.value = it->value;
			ret.left = parse_graph_pascal(std::list<graph::Node>{source.begin(), it});
			if (ret.left->type == NodeType::Empty)
				throw std::exception("'else' block wasn't able to find its 'if'");
			ret.right = parse_graph_pascal(std::list<graph::Node>{++it, source.end()});
			return ret;
		}
	}
	if (source.size() == 1)
		return source.front();
	else if (source.size() == 0)
		return graph::Node(NodeType::Empty);
	else {
		std::string error;
		error += "Something wrong with syntax, these nodes aren't connected:\n";
		for (auto it : source)
			error += it.text();
		throw std::exception(error.c_str());
	}
}
std::list<graph::Node> parser::additional::parse_brackets_pascal(std::list<graph::Node> source) {
	for (auto it = source.begin(); it != source.end(); it++) {
		if (it->type == NodeType::Bracket_op || it->value == "begin") {
			auto temp = it;
			auto nodes = parse_brackets_pascal({++temp, source.end()});
			source = {source.begin(), it};
			source.insert(source.end(), nodes.begin(), nodes.end());
			it = source.begin();
		} else if (it->type == NodeType::Bracket_cl || it->value == "end") {
			graph::Node ret;
			ret.type = NodeType::Operator_u;
			if (it->value == ")")
				ret.value = "()";
			else if (it->value == "}")
				ret.value = "{}";
			else if (it->value == "]")
				ret.value = "[]";
			else if (it->value == "end")
				ret.value = "be";
			if (it == source.begin())
				ret.right = new graph::Node(NodeType::Empty);
			else
				ret.right = parse_graph_pascal(std::list<graph::Node>{ source.begin(), it });

			source = {++it, source.end()};
			source.push_front(ret);
			return source;
		}
	}
	//if (source.size() == 1 || source.front().type == NodeType::Operator_u)
		return source;
	//else
	//	throw std::exception("Something's wrong with brackets.");
}