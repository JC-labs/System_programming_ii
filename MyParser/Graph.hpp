#pragma once
#include <string>
#include <ostream>
enum class NodeType {
	Unknown = 0,
	Empty = 1,
	Punctuator = 2,
	Bracket_op = 3,
	Bracket_cl = 4,
	Brackets = 5,
	Operator_u = 6,
	Operator_b = 7,
	Reserved = 8,
	Literal = 9,
	Variable = 10
};
namespace graph {
	struct Node {
		NodeType type;
		std::string value;
		Node* left;
		Node* right;

		Node(NodeType type = NodeType::Unknown, std::string value = "", Node *left = nullptr, Node *right = nullptr)
			: type(type), value(value), left(left), right(right) {}
		Node(Node const& other) : Node(other.type, other.value, other.left, other.right) {}
		//~Node() {
		//	if (left) delete left;
		//	if (right) delete right;
		//}
		friend std::ostream& operator<<(std::ostream &s, Node *n);
		std::string text();
	};
}
class Graph {
	graph::Node *m_node;
public:
	Graph(graph::Node *n) : m_node(n) {}
	friend std::ostream& operator<<(std::ostream &s, Graph *n);
	std::string to_string();
};

