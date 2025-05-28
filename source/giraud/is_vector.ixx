export module is_vector;

import std;

export template<typename T>
struct is_vector
{
	static constexpr bool value = false;
};

export template<template<typename...> class ContainerT, typename ValueT, typename AllocT>
struct is_vector<ContainerT<ValueT, AllocT>>
{
	static constexpr bool value = std::is_same<ContainerT<ValueT, AllocT>, std::vector<ValueT, AllocT>>::value;
};