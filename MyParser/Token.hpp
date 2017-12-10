#pragma once
#include <string>
namespace parser {
	struct Token {
		std::string type;
		std::string name;
		Token(std::string type, std::string name)
			: type(type), name(name) {}
		std::string text() const;
	};
	namespace additional {
		bool is_bracket(std::string source);
		bool is_operator(std::string source);
		bool is_reserved(std::string source);
		bool is_variable(std::string source);
		bool is_literal(std::string source);
		bool is_type_name(std::string source);
	}
	Token generate_token(std::string source);
}