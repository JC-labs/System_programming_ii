#pragma once
#include <string>
enum class NodeType {
	Unknown = 0,
	Empty = 1,
	Punctuator = 2,
	Bracket = 3,
	Operator = 4,
	Reserved = 5,
	Literal = 6,
	Variable = 7
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
	};
}
class Graph {
	graph::Node *m_node;
public:
	Graph(graph::Node *n) : m_node(n) {}
};