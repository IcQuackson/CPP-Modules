
#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "../includes/easyfind.hpp"

template <typename Container>
int easyfind(Container container, int element) {
	typename Container::const_iterator iterator = std::find(container.begin(),
															container.end(),
															element);
	if (iterator != container.end()) {
		return SUCCESS;
	}
	else {
		return FAIL;
	}
}

#endif