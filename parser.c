#include "parser.h"
#include <string.h>
#include <stdlib.h>

static int is_whitespace(char ch)
{
    switch (ch) {
    case ' ':
    case '\n':
    case '\r':
    case '\t':
    case '\f':
    case '\v':
        return 1;
    default:
        return 0;
    }
}

static void skip_whitespace(struct parser *parser)
{
    while (is_whitespace(*parser->cursor)) {
        parser->cursor++;
    }
}

static int advance_op(struct parser *parser, char const *test, size_t test_n)
{
    int success = 0;
    int ch;

    size_t size = test_n - 1;

    if (strncmp(parser->cursor, test, size) == 0) {
        ch = parser->cursor[size];
        if (ch == 0 || is_whitespace(ch)) {
            success = 1;
            parser->cursor += size;
        }
    }

    return success;
}

static int parse_num(struct parser *parser, double *output)
{
    char *end;
    int success = 0;

    *output = strtod(parser->cursor, &end);

    if (end > parser->cursor) {
        success = 1;
        parser->cursor = end;
    }

    return success;
}

static int parse_op(struct parser *parser, enum operation *output)
{
    char const *end= parser->cursor;
    int success = 1;

    if (advance_op(parser, OP_ADD_SYM, sizeof(OP_ADD_SYM))) {
        *output = op_add;
    } else if (advance_op(parser, OP_SUB_SYM, sizeof(OP_SUB_SYM))) {
        *output = op_sub;
    } else if (advance_op(parser, OP_MUL_SYM, sizeof(OP_MUL_SYM))) {
        *output = op_mul;
    } else if (advance_op(parser, OP_DIV_SYM, sizeof(OP_DIV_SYM))) {
        *output = op_div;
    } else if (advance_op(parser, OP_SIN_SYM, sizeof(OP_SIN_SYM))) {
        *output = op_sin;
    } else if (advance_op(parser, OP_COS_SYM, sizeof(OP_COS_SYM))) {
        *output = op_cos;
    } else if (advance_op(parser, OP_TAN_SYM, sizeof(OP_TAN_SYM))) {
        *output = op_tan;
    } else if (advance_op(parser, OP_ARCSIN_SYM, sizeof(OP_ARCSIN_SYM))) {
        *output = op_arcsin;
    } else if (advance_op(parser, OP_ARCCOS_SYM, sizeof(OP_ARCCOS_SYM))) {
        *output = op_arccos;
    } else if (advance_op(parser, OP_ARCTAN_SYM, sizeof(OP_ARCTAN_SYM))) {
        *output = op_arctan;
    } else if (advance_op(parser, OP_POW_SYM, sizeof(OP_POW_SYM))) {
        *output = op_pow;
    } else if (advance_op(parser, OP_LOG_SYM, sizeof(OP_LOG_SYM))) {
        *output = op_log;
    } else if (advance_op(parser, OP_LN_SYM, sizeof(OP_LN_SYM))) {
        *output = op_ln;
    } else if (advance_op(parser, OP_EXP_SYM, sizeof(OP_EXP_SYM))) {
        *output = op_exp;
    } else {
        success = 0;
    }

    return success;
}

struct token parse_token(struct parser *parser)
{
    struct token token;

    skip_whitespace(parser);

    if (*parser->cursor == 0) {
        token.kind = token_end;
    } else if (parse_num(parser, &token.data.num)) {
        token.kind = token_num;
    } else if (parse_op(parser, &token.data.op)) {
        token.kind = token_op;
    } else {
        token.kind = token_error;
    }

    return token;
}
