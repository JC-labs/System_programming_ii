#pragma once
#include <string>
#include <ostream>
enum class Language {
	cpp, pascal
};
struct Node {
	std::string value;
	Node* left;
	Node* right;
	static Language output_language;

	Node(std::string const& value, Node *left = nullptr, Node *right = nullptr) :
				value(value), left(left), right(right) {}

	friend std::ostream& operator<<(std::ostream &s, Node *n) {
		if (output_language == Language::cpp) {
			if (n->value == "do_while")
				s << "do " << n->left << " while(" << n->right << ");\n";
			else if (n->value == "{}")
				s << "{\n    " << n->left << ";\n    " << n->right << ";\n}";
			else if (n->value == "--")
				s << "--" << n->left;
			else if (n->value == "if")
				s << "if (" << n->left << ") " << n->right;
			else if (n->value == "==")
				s << n->left << " == " << n->right;
			else if (n->value == "[]")
				s << n->left << "[" << n->right << "]";
			else
				s << n->value;
		} else if (output_language == Language::pascal) {
			if (n->value == "do_while")
				s << "repeat " << n->left << " until " << n->right << ";\n";
			else if (n->value == "{}")
				s << "begin\n    " << n->left << ";\n    " << n->right << ";\nend";
			else if (n->value == "--")
				s << n->left << " := " << n->left << " - 1";
			else if (n->value == "if")
				s << "if " << n->left << " then " << n->right;
			else if (n->value == "==")
				s << n->left << " = " << n->right;
			else if (n->value == "[]")
				s << n->left << "[" << n->right << "]";
			else
				s << n->value;
		}
		return s;
	}
};
Language Node::output_language = Language::cpp;

class MyParseGraph {
	Node* m_root;
public:
	MyParseGraph(Node* root = nullptr) : m_root(root) {}
	~MyParseGraph() {}

	void setRoot(Node* root) {
		m_root = root;
	}

	friend std::ostream& operator<<(std::ostream &s, MyParseGraph &g) {
		s << g.m_root << std::endl;
		return s;
	}
};