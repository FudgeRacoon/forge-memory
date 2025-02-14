#ifndef MEMORY_UTILITIES_INL_HPP
#define MEMORY_UTILITIES_INL_HPP

#include <utility>
#include <cstring>
#include <exception>
#include <type_traits>

#include <forge-base/Core/Types.hpp>
#include <forge-base/Core/System.hpp>

namespace Forge
{
	FORGE_FORCE_INLINE Void MemoryZero(VoidPtr destination, Size size)
	{
		MemorySet(destination, 0, size);
	}

	FORGE_FORCE_INLINE Void MemorySet(VoidPtr destination, Byte value, Size size)
	{
		if (!destination)
			throw std::invalid_argument("The address arguments must not be a nullptr");

		memset(destination, value, size);
	}

	FORGE_FORCE_INLINE Void MemoryMove(VoidPtr destination, VoidPtr source, Size size)
	{
		if (!destination || !source)
			throw std::invalid_argument("The address arguments must not be a nullptr");

		memcpy(destination, source, size);
		memset(source, 0, size);
	}

	FORGE_FORCE_INLINE Void MemoryCopy(VoidPtr destination, ConstVoidPtr source, Size size)
	{
		if (!destination || !source)
			throw std::invalid_argument("The address arguments must not be a nullptr");

		memcpy(destination, source, size);
	}

	FORGE_FORCE_INLINE Bool MemoryCompare(ConstVoidPtr self, ConstVoidPtr other, Size size)
	{
		if (!self || !other)
			throw std::invalid_argument("The address arguments must not be a nullptr");

		return memcmp(self, other, size) == 0 ? true : false;
	}

	FORGE_FORCE_INLINE Size MemoryDistance(VoidPtr start, VoidPtr final)
	{
		return reinterpret_cast<Size>(start) - reinterpret_cast<Size>(final);
	}


	template<typename InType>
	FORGE_FORCE_INLINE Void MoveObject(InType& self, InType& other)
	{
		if(::std::is_pod<InType>::value)
			MemoryMove(&self, &other, sizeof(InType));
		else
			self = ::std::move(other);
	}

	template<typename InType>
	FORGE_FORCE_INLINE Void MoveArray(InType* destination, InType* source, Size count)
	{
		if(::std::is_pod<InType>::value)
			MemoryMove(destination, source, sizeof(InType) * count);
		else
			for(Size counter = 0; counter < count; counter++)
				*(destination + counter) = ::std::move(*(source + counter));
	}


	template<typename InType>
	FORGE_FORCE_INLINE Void CopyObject(InType& destination, const InType& object)
	{
		if(::std::is_pod<InType>::value)
			MemoryCopy(&destination, &object, sizeof(InType));
		else
			destination = object;
	}

	template<typename InType>
	FORGE_FORCE_INLINE Void CopyArray(InType* destination, const InType* source, Size count)
	{
		if(::std::is_pod<InType>::value)
			MemoryCopy(destination, source, sizeof(InType) * count);
		else
			for(Size counter = 0; counter < count; counter++)
				*(destination + counter) = *(source + counter);
	}


	template<typename InType>
	FORGE_FORCE_INLINE Void MoveConstructObject(InType* destination, InType object)
	{
		if(::std::is_pod<InType>::value)
			MemoryCopy(destination, &object, sizeof(InType));
		else
			new (destination) InType(::std::move(object));
	}

	template<typename InType>
	FORGE_FORCE_INLINE Void MoveConstructArray(InType* destination, InType* source, Size count)
	{
		if(::std::is_pod<InType>::value)
			MemoryCopy(destination, source, sizeof(InType) * count);
		else
			for(Size counter = 0; counter < count; counter++)
				new (destination + counter) InType(::std::move(*(source + counter)));
	}


	template<typename InType>
	FORGE_FORCE_INLINE Void CopyConstructObject(InType* destination, InType object)
	{
		if(::std::is_pod<InType>::value)
			MemoryCopy(destination, &object, sizeof(InType));
		else
			new (destination) InType(object);
	}

	template<typename InType>
	FORGE_FORCE_INLINE Void CopyConstructArray(InType* destination, InType* source, Size count)
	{
		if(::std::is_pod<InType>::value)
			MemoryCopy(destination, source, sizeof(InType) * count);
		else
			for(Size counter = 0; counter < count; counter++)
				new (destination + counter) InType(*(source + counter));
	}


	template<typename InType>
	FORGE_FORCE_INLINE Void ConstructObject(InType* destination)
	{
		if(::std::is_pod<InType>::value) {}
		else
			new (destination) InType();
	}
	template<typename InType, typename... InArgs>
	FORGE_FORCE_INLINE Void ConstructObject(InType* destination, InArgs&&... arguments)
	{
		if(::std::is_pod<InType>::value) {}
		else
			new (destination) InType(::std::forward(arguments...));
	}

	template<typename InType>
	FORGE_FORCE_INLINE Void ConstructArray(InType* destination, Size count)
	{
		if(::std::is_pod<InType>::value) {}
		else
			for(Size counter = 0; counter < count; counter++)
				new (destination + counter) InType();
	}
	template<typename InType, typename... InArgs>
	FORGE_FORCE_INLINE Void ConstructArray(InType* destination, Size count, InArgs&&... arguments)
	{
		if(::std::is_pod<InType>::value) {}
		else
			for(Size counter = 0; counter < count; counter++)
				new (destination + counter) InType(::std::forward(arguments...));
	}


	template<typename InType>
	FORGE_FORCE_INLINE Void DestructObject(InType* destination)
	{
		if(::std::is_pod<InType>::value)
			MemoryZero(destination, sizeof(InType));
		else
			destination->~InType();
	}

	template<typename InType>
	FORGE_FORCE_INLINE Void DestructArray(InType* destination, Size count)
	{
		if(::std::is_pod<InType>::value)
			MemoryZero(destination, sizeof(InType) * count);
		else
			for(Size counter = 0; counter < count; counter++)
				(destination + counter)->~InType();
	}
}

#endif