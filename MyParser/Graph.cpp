#include "Graph.hpp"
#include <sstream>
std::ostream & operator<<(std::ostream &s, Graph *n) {
	s << n->m_node;
	return s;
}
std::ostream & graph::operator<<(std::ostream &s, Node *n) {
	if (n != nullptr) {
		if (n->value == "{}")
			s << n->left << "{" << n->right << "}";
		else if (n->value == "()")
			s << "(" << n->right << ")";
		else if (n->value == "[]")
			s << n->left << "[" << n->right << "]";
		else if (n->value == "--")
			s << "--" << n->right;
		else if (n->value == "++")
			s << "++" << n->right;
		else if (n->value == "+" || n->value == "-" || n->value == "*" || n->value == "/" || n->value == "=" || n->value == "==")
			s << n->left << " " << n->value << " " << n->right;
		else
			s << n->value;
	}
	return s;
}
std::string Graph::to_string() {
	std::stringstream s;
	s << this;
	return s.str();
}

std::string to_text(NodeType n) {
	switch (n) {
		default:
		case NodeType::Unknown: return "Unknown";
		case NodeType::Empty: return "Empty";
		case NodeType::Punctuator: return "Punctuator";
		case NodeType::Bracket_op: return "Opening Bracket";
		case NodeType::Bracket_cl: return "Closing Bracket";
		case NodeType::Brackets: return "Brackets";
		case NodeType::Operator_u: return "Unary operator";
		case NodeType::Operator_b: return "Binary operator";
		case NodeType::Reserved: return "Block starting with reserved word";
		case NodeType::Literal: return "Literal";
		case NodeType::Variable: return "Variable";
	}
}

std::string graph::Node::text() {
	std::string ret;
	ret += to_text(type) + ": " + value + "\n";
	return ret;
}
