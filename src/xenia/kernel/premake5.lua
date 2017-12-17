project_root = "../../.."
include(project_root.."/tools/build")

group("src")
project("xenia-kernel")
  uuid("ae185c4a-1c4f-4503-9892-328e549e871a")
  kind("StaticLib")
  language("C++")
  links({
    "xenia-apu",
    "xenia-base",
    "xenia-cpu",
    "xenia-hid",
    "xenia-vfs",
  })
  defines({
  })
  includedirs({
    project_root.."/third_party/gflags/src",
  })
  recursive_platform_files()
  files({
    "debug_visualizers.natvis",
  })
