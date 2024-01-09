/**
 * @file
 * @author Pavel Siska <siska@cesnet.cz>
 * @brief Auxiliary logger functions
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma once

#include <spdlog/spdlog.h>
#include <string_view>

namespace nm {

/**
 * @brief Perform default initialization of spdlog library.
 *
 * The function loads logger configuration from environment and modifies
 * default output message format.
 */
void LoggerInit();

/**
 * @brief Get a logger of the given name
 *
 * If the logger doesn't exist in spdlog registry, a new logger of default
 * type is created. Otherwise the existing one is returned.
 *
 * @param[in] name Name of the logger
 */
std::shared_ptr<spdlog::logger> LoggerGet(std::string_view name);

} // namespace nm
