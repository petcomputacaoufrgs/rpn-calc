#ifndef PARSER_H
#define PARSER_H

#include "ops.h"

struct parser {
    char const *cursor;
};

enum token_kind {
    token_num,
    token_op,
    token_end,
    token_error
};

union token_data {
    enum operation op;
    double num;
};

struct token {
    union token_data data;
    enum token_kind kind;
};

struct token parse_token(struct parser *parser);

#endif
