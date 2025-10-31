#include <exception>
#include <iostream>
#include <string>

enum class Error_Action { ignore, throwing, terminating, logging };

constexpr Error_Action Default_Error_Action = Error_Action::throwing;

enum class Error_Code { range_error, length_error };

std::string error_code_name[]{"range_error", "length_error"};

template <Error_Action action = Default_Error_Action, class C>
// Since we have constexpr most of the ones would done at compile time, if we
// set the action to ignore no action would be taken meaning that no code would
// be generated for that expect statement.
constexpr void expect(C cond, Error_Code x) {
  if constexpr (action == Error_Action::logging) {
    if (!cond())
      std::cerr << "Expect() failure: " << int(x) << ' '
                << error_code_name[int(x)] << '\n';
  }

  if constexpr (action == Error_Action::throwing) {
    if (!cond())
      throw x;
  }

  if constexpr (action == Error_Action::terminating) {
    if (!cond())
      std::terminate();
  }
}
