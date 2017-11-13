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