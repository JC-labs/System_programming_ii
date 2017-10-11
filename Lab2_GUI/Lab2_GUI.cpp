#include "Lab2_GUI.h"
#include <sstream>
#include "../MyGraph/MyParseGraph.hpp"
#include "../MyGraph/MyMachine.hpp"

Lab2_GUI::Lab2_GUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.start, &QPushButton::clicked, this, &Lab2_GUI::start);

	auto a = new Node("a");
	auto b = new Node("b");
	auto n = new Node("n");
	
	auto a_n = new Node("[]", a, n);
	auto b_eq_a_n = new Node("==", b, a_n);
	auto if_break = new Node("if", b_eq_a_n, new Node("break"));
	auto loop_block = new Node("{}", new Node("--", n), if_break);
	auto loop = new Node("do_while", loop_block, n);
	
	MyParseGraph g(loop);
	//MyParseGraph g(new Node("do_while", new Node("{}", new Node("--", new Node("n")), new Node("if", new Node("==", new Node("b"), new Node("[]", new Node("a"), new Node("n"))), new Node("break"))), new Node("n")));

	std::stringstream s;
	Node::output_language = Language::cpp;
	s << g << std::endl;
	Node::output_language = Language::pascal;
	s << g << std::endl;

	ui.code->setText(QString::fromStdString(s.str()));
}

void Lab2_GUI::start() {
	MyMachine m(1, 7);
	m.addRule(1, State::ltr, 1);
	m.addRule(3, State::cfr, 3);
	m.addRule(7, State::dlm, 7);

	QString result;

	auto lambda = [&result](size_t current, State state, size_t next) {
		switch (state) {
			case State::cfr: result += "cfr "; break;
			case State::dlm: result += "dlm "; break;
			case State::ltr: result += "ltr "; break;
		}
		result += QString::number(current) + " -> " + QString::number(next) + '\n';
	};

	auto input_signals = ui.input->text();
	for (auto c : input_signals)
		if (c == 'c' && !m.step(State::cfr, lambda))
			break;
		else if (c == 'd' && !m.step(State::dlm, lambda))
			break;
		else if (c == 'l' && !m.step(State::ltr, lambda))
			break;

	ui.output->setText(result);
}