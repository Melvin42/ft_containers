#include <utility>
#include <string>
#include <iostream>
#include <deque>
#if STD
#include <stack>
#include <map>
#include <vector>
namespace ft = std;
#else
#include "../../../../stack.hpp"
#include "../../../../pair.hpp"
#include "../../../../vector.hpp"
#include "../../../../map.hpp"
#endif
#include "../fn_key_comp.hpp"
int main(void) {

	fn_key_comp();

	return 0;
}
