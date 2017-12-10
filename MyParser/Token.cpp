#include "Token.hpp"
#include <list>
using List = std::list<std::string>;
List brackets = { "(", ")", "[", "]", "{", "}" };
List operators = { "+", "-", "*", "/", "=", "%", "+=", "-=", "*=", "/=", "%=", "++", "--", "==", "<", ">", "<=", ">=", ":=", "," };
List reserved = { "do", "while", "if", "break", "then", "end", "else", "begin" };
List type_name = { "int", "float" };

bool is_(std::string source, List list) {
	for (auto it : list)
		if (source == it)
			return true;
	return false;
}
bool parser::additional::is_bracket(std::string source) { 
	return is_(source, brackets);
}
bool parser::additional::is_operator(std::string source) {
	return is_(source, operators);
}
bool parser::additional::is_reserved(std::string source) {
	return is_(source, reserved);
}
bool parser::additional::is_type_name(std::string source) {
	return is_(source, type_name);
}
parser::Token parser::generate_token(std::string source) {
	if (source == ";")
		return Token("Punctuator", source);
	else if (additional::is_bracket(source))
		return Token("Bracket", source);
	else if (additional::is_operator(source))
		return Token("Operator", source);
	else if (additional::is_reserved(source))
		return Token("Reserved word", source);
	else if (additional::is_type_name(source))
		return Token("Typename", source);
	else if (additional::is_literal(source))
		return Token("Literal", source);
	else if (additional::is_variable(source))
		return Token("Variable", source);
	else
		return Token("Unknown", source);
}
std::string parser::Token::text() const {
	return " " + type + ":\t" + name;
}
#include <cctype>
bool parser::additional::is_variable(std::string source) {
	if (!isalpha(source[0]))
		return false;
	for (size_t i = 1; i < source.size(); i++)
		if (!(isalpha(source[i]) || isdigit(source[i]) || source[i] == '_'))
			return false;
	return true;
}
bool parser::additional::is_literal(std::string source) {
	for (size_t i = 0; i < source.size(); i++)
		if (!(isdigit(source[i])))
			return false;
	return true;
}