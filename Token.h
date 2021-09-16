#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    // TODO: add the other types of toke

    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    ENDOFFILE

};

class Token
{
private:
    // member variables for information needed by Token
    TokenType type;
    std::string tokenDescription;
    int lineNumber;

public:
    Token(TokenType type, std::string description, int line);

    std::string toString();
};

#endif // TOKEN_H

