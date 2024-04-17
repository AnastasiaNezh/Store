#pragma once
#include "Store.h"
namespace Func {
	Store* Read();
	Store* Delete(Store* arr, int size, int answer);
	Store* Edit(Store* arr, int size, int answer);
	void Save(Store* arr, int size);
	void Add(Store* arr, int size);
	void Search(Store* arr, int size, int answer);
	int getLenghtMassiv();
}