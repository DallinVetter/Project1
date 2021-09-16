#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    Token::type = type;
    Token::tokenDescription = description;
    Token::lineNumber = line;
}

std::string Token::toString() {
    std::string outputString = "";
    switch(Token::type){
        case TokenType::COMMA:
            outputString = "(COMMA,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::PERIOD:
            outputString = "(PERIOD,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::Q_MARK:
            outputString = "(Q_MARK,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::LEFT_PAREN:
            outputString = "(LEFT_PAREN,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::RIGHT_PAREN:
            outputString = "(RIGHT_PAREN,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::COLON:
            outputString = "(COLON,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::COLON_DASH:
            outputString = "(COLON_DASH,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::MULTIPLY:
            outputString = "(MULTIPLY,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::ADD:
            outputString = "(ADD,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::SCHEMES:
            outputString = "(SCHEMES,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::FACTS:
            outputString = "(FACTS,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::RULES:
            outputString = "(RULES,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::QUERIES:
            outputString = "(QUERIES,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::ID:
            outputString = "(ID,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::UNDEFINED:
            outputString = "(UNDEFINED,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::STRING:
            outputString = "(STRING,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::COMMENT:
            outputString = "(COMMENT,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;

        case TokenType::ENDOFFILE:
            outputString = "(EOF,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")";
            break;
    }

    return outputString;
}
