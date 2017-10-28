#pragma once
struct Lexeme {
	Lexeme() {}
	virtual ~Lexeme() {}
};
struct Condition_Lexeme : public Lexeme {
	Lexeme condition;
	Lexeme body;
	Condition_Lexeme(Lexeme &&c, Lexeme &&b) : condition(c), body(b) {}
};

struct Do_While : public Condition_Lexeme {
	using Condition_Lexeme::Condition_Lexeme;
};