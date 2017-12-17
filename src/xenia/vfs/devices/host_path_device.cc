/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/vfs/devices/host_path_device.h"

#include "xenia/base/filesystem.h"
#include "xenia/base/logging.h"
#include "xenia/base/math.h"
#include "xenia/kernel/xfile.h"
#include "xenia/vfs/devices/host_path_entry.h"

namespace xe {
namespace vfs {

HostPathDevice::HostPathDevice(const std::string& mount_path,
                               const std::wstring& local_path, bool read_only)
    : Device(mount_path), local_path_(local_path), read_only_(read_only) {}

HostPathDevice::~HostPathDevice() = default;

bool HostPathDevice::Initialize() {
  if (!xe::filesystem::PathExists(local_path_)) {
    if (!read_only_) {
      // Create the path.
      xe::filesystem::CreateFolder(local_path_);
    } else {
      XELOGE("Host path does not exist");
      return false;
    }
  }

  auto root_entry = new HostPathEntry(this, nullptr, "", local_path_);
  root_entry->attributes_ = kFileAttributeDirectory;
  root_entry_ = std::unique_ptr<Entry>(root_entry);
  PopulateEntry(root_entry);

  return true;
}

void HostPathDevice::PopulateEntry(HostPathEntry* parent_entry) {
  auto child_infos = xe::filesystem::ListFiles(parent_entry->local_path());
  for (auto& child_info : child_infos) {
    auto child = HostPathEntry::Create(
        this, parent_entry,
        xe::join_paths(parent_entry->local_path(), child_info.name),
        child_info);
    parent_entry->children_.push_back(std::unique_ptr<Entry>(child));

    if (child_info.type == xe::filesystem::FileInfo::Type::kDirectory) {
      PopulateEntry(child);
    }
  }
}

}  // namespace vfs
}  // namespace xe
