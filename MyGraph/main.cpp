#include "MyParseGraph.hpp"
#include "MyMachine.hpp"
#include <iostream>
int main() {
	//data initialization:
	auto a = new Node("a");
	auto b = new Node("b");
	auto n = new Node("n");

	auto a_n = new Node("[]", a, n);
	auto b_eq_a_n = new Node("==", b, a_n);
	auto if_break = new Node("if", b_eq_a_n, new Node("break"));
	auto loop_block = new Node("{}", new Node("--", n), if_break);
	auto loop = new Node("do_while", loop_block, n);

	MyParseGraph g(loop);
	Node::output_language = Language::cpp;
	std::cout << g << std::endl;
	Node::output_language = Language::pascal;
	std::cout << g << std::endl;

	//Machine simulation:
	//MyMachine m({"", "", "", "", ""});
	//m.start();
	//m.print();
	getchar();
	return 0;
}