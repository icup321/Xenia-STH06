/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/base/logging.h"
#include "xenia/kernel/kernel_state.h"
#include "xenia/kernel/notify_listener.h"
#include "xenia/kernel/util/shim_utils.h"
#include "xenia/kernel/xam/xam_private.h"
#include "xenia/xbox.h"

namespace xe {
namespace kernel {
namespace xam {

dword_result_t XamNotifyCreateListener(qword_t mask, dword_t one) {
  // r4=1 may indicate user process?

  auto listener =
      object_ref<NotifyListener>(new NotifyListener(kernel_state()));
  listener->Initialize(mask);

  // Handle ref is incremented, so return that.
  uint32_t handle = listener->handle();

  return handle;
}
DECLARE_XAM_EXPORT(XamNotifyCreateListener, ExportTag::kImplemented);

// http://ffplay360.googlecode.com/svn/Test/Common/AtgSignIn.cpp
dword_result_t XNotifyGetNext(dword_t handle, dword_t match_id,
                              lpdword_t id_ptr, lpdword_t param_ptr) {
  if (!handle) {
    return 0;
  }

  // Grab listener.
  auto listener =
      kernel_state()->object_table()->LookupObject<NotifyListener>(handle);
  if (!listener) {
    return 0;
  }

  bool dequeued = false;
  uint32_t id = 0;
  uint32_t param = 0;
  if (match_id) {
    // Asking for a specific notification
    id = match_id;
    dequeued = listener->DequeueNotification(match_id, &param);
  } else {
    // Just get next.
    dequeued = listener->DequeueNotification(&id, &param);
  }

  if (dequeued) {
    *id_ptr = id;
    *param_ptr = param;
  } else {
    *id_ptr = 0;
    *param_ptr = 0;
  }

  return dequeued ? 1 : 0;
}
DECLARE_XAM_EXPORT(XNotifyGetNext, ExportTag::kImplemented);

dword_result_t XNotifyDelayUI(dword_t delay_ms) {
  // Ignored.
  return 0;
}
DECLARE_XAM_EXPORT(XNotifyDelayUI, ExportTag::kStub);

void XNotifyPositionUI(dword_t position) {
  // Ignored.
}
DECLARE_XAM_EXPORT(XNotifyPositionUI, ExportTag::kStub);

void RegisterNotifyExports(xe::cpu::ExportResolver* export_resolver,
                           KernelState* kernel_state) {}

}  // namespace xam
}  // namespace kernel
}  // namespace xe