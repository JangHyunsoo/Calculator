#pragma once
#include "Mecro.h"

template<typename T>
void SafeDeleteVec(T& p) {
	auto iterEnd = p.end();

	for (auto iter = p.begin(); iter != iterEnd; iter++) {
		SAFE_DELETE((*iter));
	}

	p.clear();
}