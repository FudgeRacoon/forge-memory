#ifndef MEMORY_UTILITIES_HPP
#define MEMORY_UTILITIES_HPP

#include <forge-base/Core/Types.hpp>
#include <forge-base/Core/System.hpp>

namespace Forge {
	/**
	 * @brief Sets the destination memory block to zero.
	 *
	 * @param[out] destination The memory block where data will be set.
	 * @param[in]  size The number of bytes of the memory block to be set to zero
	 */
	Void MemoryZero(VoidPtr destination, Size size);

	/**
	 * @brief Sets the destination memory block to the value specified.
	 *
	 * @param[out] destination The memory block where data will be set.
	 * @param[in]  value The value to set each byte of the memory block to.
	 * @param[in]  size  The number of bytes of the memory block to be set to the specified value.
	 */
	Void MemorySet(VoidPtr destination, Byte value, Size size);

	/**
	 * @brief Moves the data from the source memory block to the destination memory block.
	 *
	 * @param[out] destination The memory block where data will be moved to.
	 * @param[in]  source The memory block where data will be moved from.
	 * @param[in]  size The number of bytes of the memory block to be set to the specified value.
	 */
	Void MemoryMove(VoidPtr destination, VoidPtr source, Size size);

	/**
	 * @brief Copies the data from the source memory block to the destination memory block.
	 *
	 * @param[out] destination The memory block where data will be copied to.
	 * @param[in]  source The memory block where data will be copied from.
	 * @param[in]  size The number of bytes of the memory block to be set to the specified value.
	 */
	Void MemoryCopy(VoidPtr destination, ConstVoidPtr source, Size size);

	/**
	 * @brief Compares the data stored in the comparand1 memory block and the comparand2 memory block for equality.
	 *
	 * @param[in] comparand1 The memory block where data will be comapred.
	 * @param[in] comparand2 The memory block where data will be comapred.
	 * @param[in] size The number of bytes of the memory block to compare.
	 *
	 * @returns True if the data stored in the memory buffers are equal, otherwise false.
	 */
	Bool MemoryCompare(ConstVoidPtr self, ConstVoidPtr other, Size size);

	/**
	 * @brief Calculates the number of bytes between the start and final address.
	 *
	 * @param[in] start The start address.
	 * @param[in] final the final address.
	 *
	 * @returns The number of bytes between the start and final address.
	 */
	Size MemoryDistance(VoidPtr start, VoidPtr final);


	/** @brief Moves an object of type InType to another specified object.
	 *
	 * @tparam InType The type of object to move.
	 *
	 * @param[out] self The object that will be moved to.
	 * @param[in] other The object to move to another specified object.
	 */
	template<typename InType>
	Void MoveObject(InType& self, InType& other);

	/**
	 * @brief Moves an array of objects of type InType to the specified memory location.
	 *
	 * @tparam InType The type of object to copy.
	 *
	 * @param[out] destination The memory location where the objects will be moved to.
	 * @param[in]  source The memory location where the objects will be moved from.
	 * @param[in]  count The number of objects to move to the specified memory location.
	 */
	template<typename InType>
	Void MoveArray(InType* destination, InType* source, Size count);


	/** @brief Copies an object of type InType to another specified object.
	 *
	 * @tparam InType The type of object to move.
	 *
	 * @param[out] self The object that will be copied to.
	 * @param[in] other The object to copy to another specified object.
	 */
	template<typename InType>
	Void CopyObject(InType& destination, const InType& object);

	/**
	 * @brief Copies an array of objects of type InType to the specified memory location.
	 *
	 * @tparam InType The type of object to copy.
	 *
	 * @param[out] destination The memory location where the objects will be copied to.
	 * @param[in]  source The memory location where the objects will be copied from.
	 * @param[in]  count  The number of objects to copy to the specified memory location.
	 */
	template<typename InType>
	Void CopyArray(InType* destination, const InType* source, Size count);


	/**
	 * @brief Default constructs an object of type InType at the specified memory location.
	 *
	 * If InType is not default constructible, the behavior is undefined.
	 *
	 * @tparam InType The type of object to construct.
	 *
	 * @param[out] destination The memory location where the object will be constructed at.
	 */
	template<typename InType>
	Void ConstructObject(InType* destination);

	/**
	 * @brief Constructs an object of type InType at the specified memory location.
	 *
	 * @tparam InType The type of object to construct.
	 * @tparam InArgs The type of constructor arguments.
	 *
	 * @param[out] destination The memory location where the object will be constructed at.
	 * @param[in] arguments  The constructor arguments to forward to the constructor of InType.
	 */
	template<typename InType, typename... InArgs>
	Void ConstructObject(InType* destination, InArgs&&... arguments);

	/**
	 * @brief Default constructs an array of objects of type InType at the specified memory location.
	 *
	 * If InType is not default constructible, the behavior is undefined.
	 *
	 * @tparam InType The type of objects to construct.
	 *
	 * @param[out] destination The memory location where the objects will be constructed at.
	 * @param[in] count The number of objects to construct at the specified memory location.
	 */
	template<typename InType>
	Void ConstructArray(InType* destination, Size count);

	/**
	 * @brief Constructs an array of objects of type InType at the specified memory location.
	 *
	 * @tparam InType The type of objects to construct.
	 * @tparam InArgs The type of constructor arguments.
	 *
	 * @param[out] destination The memory location where the objects will be constructed at.
	 * @param[in] count The number of objects to construct at the specified memory location.
	 * @param[in] arguments The constructor arguments to forward to the constructor of InType.
	 */
	template<typename InType, typename... InArgs>
	Void ConstructArray(InType* destination, Size count, InArgs&&... arguments);


	/** @brief Constructs an object of type InType at the specified memory location by moving.
	 *
	 * @tparam InType The type of object to move construct.
	 *
	 * @param[out] destination The memory location where the object will be constructed at.
	 * @param[in]  object  The object to construct at the specified memory location.
	 */
	template<typename InType>
	Void MoveConstructObject(InType* destination, InType& object);

	/** @brief Constructs an array of objects of type InType at the specified memory location by moving.
	 *
	 * @tparam InType The type of object to move construct.
	 *
	 * @param[out] destination The memory location where the objects will be constructed at.
	 * @param[in]  source The memory location where the objects will be moved from.
	 * @param[in]  count The number of objects to move to the specified memory location.
	 */
	template<typename InType>
	Void MoveConstructArray(InType* destination, InType* source, Size count);


	/** @brief Constructs an object of type InType at the specified memory location by copying.
	 *
	 * @tparam InType The type of object to copy construct.
	 *
	 * @param[out] destination The memory location where the object will be constructed at.
	 * @param[in]  object The object to construct at the specified memory location.
	 */
	template<typename InType>
	Void CopyConstructObject(InType* destination, const InType& object);

	/** @brief Constructs an array of objects of type InType at the specified memory location by copying.
	 *
	 * @tparam InType The type of object to move construct.
	 *
	 * @param[out] destination The memory location where the objects will be constructed at.
	 * @param[in]  source The memory location where the objects will be copied from.
	 * @param[in]  count The number of objects to copy to the specified memory location.
	 */
	template<typename InType>
	Void CopyConstructArray(InType* destination, const InType* source, Size count);


	/**
	 * @brief Destructs an object of type InType at the specified memory location.
	 *
	 * @tparam InType The type of object to destruct.
	 *
	 * @param[out] destination The memory location where the object will be destructed at.
	 */
	template<typename InType>
	Void DestructObject(InType* destination);

	/**
	 * @brief Destructs an array of objects of type InType at the specified memory location.
	 *
	 * @tparam InType The type of objects to destruct.
	 *
	 * @param[out] destination The memory location where the objects will be destructed at.
	 * @param[in]  count The number of objects to destruct at the specified memory location.
	 */
	template<typename InType>
	Void DestructArray(InType* destination, Size count);
}

#include "../Private/MemoryUtilities.inl"

#endif