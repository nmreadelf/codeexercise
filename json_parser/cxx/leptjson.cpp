#include "leptjson.h"
#include <assert.h> /* assert() */
#include <errno.h>  /* errno, ERANGE */
#include <math.h>   /* HUGE_VAL */
#include <stdlib.h> /* NULL, strtod() */

#define EXPECT(c, ch)                                                          \
  do {                                                                         \
    assert(*c->json == (ch));                                                  \
    c->json++;                                                                 \
  } while (0)

namespace leptjson {

/* ws = *(%x20 / %x09 / %x0A / %x0D) */
static void lept_parse_whitespace(lept_context *c) {
  const char *p = c->json;
  while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') {
    p++;
  }
  c->json = p;
}

static int lept_parse_literal(lept_context *c, lept_value *v,
                              const char *literal, lept_type type) {
  size_t i;
  EXPECT(c, literal[0]);
  for (i = 0; literal[i + 1]; i++) {
    if (c->json[i] != literal[i + 1]) {
      return LEPT_PARSE_INVALID_VALUE;
    }
  }
  c->json += i;
  v->type = type;
  return LEPT_PARSE_OK;
}

/* value = null / false / true */
static int lept_parse_value(lept_context *c, lept_value *v) {
  switch (*c->json) {
  case 'n':
    return lept_parse_literal(c, v, "null", LEPT_NULL);
  case 'f':
    return lept_parse_literal(c, v, "false", LEPT_FALSE);
  case 't':
    return lept_parse_literal(c, v, "true", LEPT_TRUE);
  case '\0':
    return LEPT_PARSE_EXPECT_VALUE;
  default:
    return lept_parse_number(c, v);
  }
}

static bool isdigit(const char p) {
  if (p >= '0' && p <= '9') {
    return true;
  }
  return false;
}

static int lept_parse_number(lept_context *c, lept_value *v) {
  const char *p = c->json;
  if (*p == '-') {
    p++;
  }
  if (*p == '0') {
    p++;
  } else {
    if (!(*p >= '1' && *p <= '9')) {
      return LEPT_PARSE_INVALID_VALUE;
    }
    for (p++; isdigit(*p); p++) {
    }
  }
  if (*p == '.') {
    p++;
    if (!isdigit(*p)) {
      return LEPT_PARSE_INVALID_VALUE;
    }
    for (p++; isdigit(*p); p++) {
    }
  }
  if (*p == 'e' || *p == 'E') {
    p++;
    if (*p == '+' || *p == '-') {
      p++;
    }
    if (!isdigit(*p)) {
      return LEPT_PARSE_INVALID_VALUE;
    }
    for (p++; isdigit(*p); p++) {
    }
  }
  errno = 0;
  v->n = strtod(c->json, NULL);
  if (errno == ERANGE && (v->n == HUGE_VAL || v->n == -HUGE_VAL)) {
    return LEPT_PARSE_NUMBER_TOO_BIG;
  }
  v->type = LEPT_NUMBER;
  c->json = p;
  return LEPT_PARSE_OK;
}

int lept_parse(lept_value *v, const char *json) {
  lept_context c;
  assert(v != NULL);
  c.json = json;
  v->type = LEPT_NULL;
  lept_parse_whitespace(&c);
  int ret;
  if ((ret = lept_parse_value(&c, v)) == LEPT_PARSE_OK) {
    lept_parse_whitespace(&c);
    if (*c.json != 0) {
      v->type = LEPT_NULL;
      ret = LEPT_PARSE_ROOT_NOT_SINGULAR;
    }
  }
  return ret;
}

lept_type lept_get_type(const lept_value *v) {
  assert(v != NULL);
  return v->type;
}

double lept_get_number(const lept_value *v) {
  assert(v != NULL && v->type == LEPT_NUMBER);
  return v->n;
}

} // namespace leptjson
