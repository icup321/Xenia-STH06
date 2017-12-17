/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2014 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/kernel/xam/app_manager.h"

#include "xenia/kernel/kernel_state.h"
#include "xenia/kernel/xam/apps/xgi_app.h"
#include "xenia/kernel/xam/apps/xlivebase_app.h"
#include "xenia/kernel/xam/apps/xmp_app.h"

namespace xe {
namespace kernel {
namespace xam {

App::App(KernelState* kernel_state, uint32_t app_id)
    : kernel_state_(kernel_state),
      memory_(kernel_state->memory()),
      app_id_(app_id) {}

void AppManager::RegisterApps(KernelState* kernel_state, AppManager* manager) {
  manager->RegisterApp(std::make_unique<apps::XgiApp>(kernel_state));
  manager->RegisterApp(std::make_unique<apps::XLiveBaseApp>(kernel_state));
  manager->RegisterApp(std::make_unique<apps::XmpApp>(kernel_state));
}

void AppManager::RegisterApp(std::unique_ptr<App> app) {
  assert_zero(app_lookup_.count(app->app_id()));
  app_lookup_.insert({app->app_id(), app.get()});
  apps_.push_back(std::move(app));
}

X_RESULT AppManager::DispatchMessageSync(uint32_t app_id, uint32_t message,
                                         uint32_t buffer_ptr,
                                         uint32_t buffer_length) {
  const auto& it = app_lookup_.find(app_id);
  if (it == app_lookup_.end()) {
    return X_STATUS_UNSUCCESSFUL;
  }
  return it->second->DispatchMessageSync(message, buffer_ptr, buffer_length);
}

X_RESULT AppManager::DispatchMessageAsync(uint32_t app_id, uint32_t message,
                                          uint32_t buffer_ptr,
                                          uint32_t buffer_length) {
  const auto& it = app_lookup_.find(app_id);
  if (it == app_lookup_.end()) {
    return X_ERROR_NOT_FOUND;
  }
  return it->second->DispatchMessageSync(message, buffer_ptr, buffer_length);
}

}  // namespace xam
}  // namespace kernel
}  // namespace xe
