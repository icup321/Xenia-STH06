project_root = "../../.."
include(project_root.."/tools/build")

group("src")
project("xenia-vfs")
  uuid("395c8abd-4dc9-46ed-af7a-c2b9b68a3a98")
  kind("StaticLib")
  language("C++")
  links({
    "xenia-base",
  })
  defines({
  })
  includedirs({
    project_root.."/third_party/gflags/src",
  })
  recursive_platform_files()
