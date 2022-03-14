#pragma once

namespace leptjson {

typedef enum {
  LEPT_NULL,
  LEPT_FALSE,
  LEPT_TRUE,
  LEPT_NUMBER,
  LEPT_STRINGF,
  LEPT_ARRAY,
  LEPT_OBJECT
} lept_type;

enum {
  LEPT_PARSE_OK = 0,
  LEPT_PARSE_EXPECT_VALUE,
  LEPT_PARSE_INVALID_VALUE,
  LEPT_PARSE_ROOT_NOT_SINGULAR
};

typedef struct {
  double n;
  lept_type type;
} lept_value;

typedef struct {
  const char *json;
} lept_context;

static void lept_parse_whitespace(lept_context *c);

static int lept_parse_value(lept_context, lept_value *v);

static int lept_parse_null(lept_context *c, lept_value *v);

static int lept_parse_false(lept_context *c, lept_value *v);

static int lept_parse_true(lept_context *c, lept_value *v);

static int lept_parse_number(lept_context *c, lept_value *v);

double lept_get_number(const lept_value *v);

int lept_parse(lept_value *v, const char *json);

lept_type lept_get_type(const lept_value *v);

} // namespace leptjson
