/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "mcrouter/CarbonRouterClient.h"
#include "mcrouter/mcrouter_sr_deps.h"

namespace facebook::memcache::mcrouter::detail {

bool srHostInfoPtrFuncCarbonRouterClient(
    const HostInfoPtr& host,
    const RequestClass& requestClass,
    uint64_t& hash) {
  if (!requestClass.is(RequestClass::kShadow) && host &&
      host->location().getTWTaskID()) {
    hash = *host->location().getTWTaskID();
    return true;
  }
  return false;
}

} // namespace facebook::memcache::mcrouter::detail
