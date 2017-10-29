#pragma once
#include <string>
enum class NodeType {
	Unknown = 0,

};
namespace graph {
	struct Node {
		NodeType type;
		std::string value;
		Node* left;
		Node* right;

		Node(NodeType type = NodeType::Unknown, std::string value = "", Node *left = nullptr, Node *right = nullptr)
			: type(type), value(value), left(left), right(right) {}
	};
}
class Graph {
	graph::Node m_node;
public:
	Graph(graph::Node &&n) : m_node(n) {}
};