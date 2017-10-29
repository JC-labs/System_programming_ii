#pragma once
#include <string>
namespace graph {
	struct Node {
		std::string type;
		std::string value;
		Node* left;
		Node* right;
	};

	class Graph {
		Node m_node;
	public:
		Graph(Node &&n) : m_node(n) {}
	};
}