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

TEST(LeptJSONTest, parseNumber) {
  typedef std::pair<double, std::string> p;
  std::vector<p> datas{
      p{0.0, "0"},
      p{0.0, "-0"},
      p{0.0, "-0.0"},
      p{1.0, "1"},
      p{-1.0, "-1"},
      p{1.5, "1.5"},
      p{-1.5, "-1.5"},
      p{3.1416, "3.1416"},
      p{1E10, "1E10"},
      p{1e10, "1e10"},
      p{1E+10, "1E+10"},
      p{1E-10, "1E-10"},
      p{-1E10, "-1E10"},
      p{-1e10, "-1e10"},
      p{-1E+10, "-1E+10"},
      p{-1E-10, "-1E-10"},
      p{1.234E+10, "1.234E+10"},
      p{1.234E-10, "1.234E-10"},
      p{0.0, "1e-10000"}, /* must underflow */
  };
  for (const auto &i : datas) {
    lept_value v;
    EXPECT_EQ(LEPT_PARSE_OK, lept_parse(&v, i.second.data()));
    EXPECT_EQ(LEPT_NUMBER, lept_get_type(&v));
    EXPECT_DOUBLE_EQ(i.first, lept_get_number(&v));
  }
}

TEST(LeptJSONTest, parseInvalidNumber) {
  std::vector<std::string> datas{
      "+0",  "+1",  ".123", /* at least one digit before '.' */
      "1.",                 /* at least one digit after '.' */
      "INF", "inf", "NAN",  "nan",
  };
  for (const auto &i : datas) {
    lept_value v;
    auto res = lept_parse(&v, i.data());
    EXPECT_EQ(LEPT_PARSE_INVALID_VALUE, res);
  }
}

} // namespace leptjson

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
