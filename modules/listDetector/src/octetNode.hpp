/**
 * @file
 * @author Damir Zainullin <zaidamilda@gmail.com>
 * @brief Declares the OctetNode structure used to match IP addresses against prefixes.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma once

namespace ListDetector {

/**
 * @brief Keeps one octet of IP prefix as ip and mask octet.
 */
struct OctetNode {
public:
	bool operator==(const OctetNode& other) const noexcept
	{
		return value == other.value && mask == other.mask && !isLast;
	}

	inline static const uint16_t NO_INDEX = 0;

	std::byte value; ///< Value of IP prefix octet
	std::byte mask; ///< Value of IP prefix mask octet corresponing to "value" octet
	bool isLast; ///< True if this octet is last one for prefix (at maximum 4. for IPv4 and 16. for
				 ///< IPv6)
	union {
		uint16_t nextNode; ///< Index of next node
		uint16_t rule; ///< Index of rule
	} index; ///< Union that keeps index of next node for that IP prefix or index of rule which this
			 ///< prefix belongs to
};

} // namespace ListDetector