#ifndef COMPILER_RULES_SYMBOL_H_
#define COMPILER_RULES_SYMBOL_H_

#include <string>
#include "compiler/rules/rule.h"

namespace tree_sitter {
namespace rules {

typedef enum {
  SymbolOptionToken = 1 << 0,
  SymbolOptionAuxiliary = 1 << 1,
} SymbolOption;

extern SymbolOption SymbolOptionAuxToken;

class Symbol : public Rule {
 public:
  explicit Symbol(int index);
  Symbol(int index, SymbolOption options);

  bool operator==(const Symbol &other) const;
  bool operator==(const Rule &other) const;

  size_t hash_code() const;
  rule_ptr copy() const;
  std::string to_string() const;
  void accept(Visitor *visitor) const;

  bool operator<(const Symbol &other) const;
  bool is_token() const;
  bool is_built_in() const;
  bool is_auxiliary() const;

  int index;
  SymbolOption options;
};

}  // namespace rules
}  // namespace tree_sitter

namespace std {

template <>
struct hash<tree_sitter::rules::Symbol> {
  size_t operator()(const tree_sitter::rules::Symbol &rule) const {
    return rule.hash_code();
  }
};

}  // std

#endif  // COMPILER_RULES_SYMBOL_H_
