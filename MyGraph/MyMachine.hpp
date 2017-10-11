#pragma once
#include <map>
#include <functional>
enum class State { dlm, cfr, ltr };
class MyMachine {
	size_t start_state;
	size_t end_state;
	size_t current_state;
	std::map<std::pair<size_t, State>, size_t> rules;
	using Point = std::pair<size_t, State>;
	using Rule = std::pair<Point, size_t>;
public:
	MyMachine(size_t start_state, size_t end_state)
		: start_state(start_state), end_state(end_state), current_state(start_state) {

	}
	void addRule(size_t current, State state, size_t next) {
		rules.insert(Rule(Point(current, state), next));
	}
	bool step(State state, std::function<void(size_t, State, size_t)> lambda) {
		bool changed = false;
		for (auto rule : rules) 
			if (current_state == rule.first.first && state == rule.first.second) {
				lambda(current_state, state, rule.second);
				current_state = rule.second;
				changed = true;
				break;
			}
		if (!changed) {
			if (current_state >= end_state || current_state < start_state)
				return false;
			lambda(current_state++, state, current_state);
		}
		return true;
	}
	~MyMachine() {

	}
};