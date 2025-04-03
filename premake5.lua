workspace "Gomas"
 architecture "x64"

 configurations
 {
 "Debug",
 "Release",
 "Dist"
 }

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  project "Gomas"
    location "Gomas"
    kinf "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin/" .. outputdir .. "/%{prj.name}")

    files
    {
       "%{prj.name}/src/**.h",
       "%{prj.name}/src/**.cpp",
    }

    include 
    {
       "%{prj.name}/external_lib/spdlog"
    }
