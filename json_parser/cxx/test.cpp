#include "leptjson.h"
#include <gtest/gtest.h>

namespace leptjson {

TEST(LeptJSONTest, ParseNULL) {
  lept_value v;
  v.type = LEPT_FALSE;
  EXPECT_EQ(LEPT_PARSE_OK, lept_parse(&v, "null"));
  EXPECT_EQ(LEPT_NULL, lept_get_type(&v));
}

TEST(LeptJSONTest, parseExpectValue) {
  lept_value v;

  v.type = LEPT_FALSE;
  EXPECT_EQ(LEPT_PARSE_EXPECT_VALUE, lept_parse(&v, ""));
  EXPECT_EQ(LEPT_NULL, lept_get_type(&v));

  v.type = LEPT_FALSE;
  EXPECT_EQ(LEPT_PARSE_EXPECT_VALUE, lept_parse(&v, " "));
  EXPECT_EQ(LEPT_NULL, lept_get_type(&v));
}

TEST(LeptJSONTest, parseInvalidValue) {
  lept_value v;
  v.type = LEPT_FALSE;
  EXPECT_EQ(LEPT_PARSE_INVALID_VALUE, lept_parse(&v, "nul"));
  EXPECT_EQ(LEPT_NULL, lept_get_type(&v));

  v.type = LEPT_FALSE;
  EXPECT_EQ(LEPT_PARSE_INVALID_VALUE, lept_parse(&v, "?"));
  EXPECT_EQ(LEPT_NULL, lept_get_type(&v));
}

TEST(LeptJSONTest, parseRootNotSingular) {
  lept_value v;
  v.type = LEPT_FALSE;
  EXPECT_EQ(LEPT_PARSE_ROOT_NOT_SINGULAR, lept_parse(&v, "null x"));
  EXPECT_EQ(LEPT_NULL, lept_get_type(&v));
}

TEST(LeptJSONTest, parseTrue) {
  lept_value v;
  v.type = LEPT_FALSE;
  EXPECT_EQ(LEPT_PARSE_OK, lept_parse(&v, "true"));
  EXPECT_EQ(LEPT_TRUE, lept_get_type(&v));
}

TEST(LeptJSONTest, parseFalse) {
  lept_value v;
  v.type = LEPT_TRUE;
  EXPECT_EQ(LEPT_PARSE_OK, lept_parse(&v, "false"));
  EXPECT_EQ(LEPT_FALSE, lept_get_type(&v));
}

} // namespace leptjson

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
