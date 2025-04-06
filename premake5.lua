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
    kind "SharedLib"
    language "C++"

   targetdir("bin/" .. outputdir .. "/%{prj.name}") -- Project specific subfolder
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
       "%{prj.name}/src/**.h",
       "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
       "%{prj.name}/external_lib/spdlog/include"
    }

    filter "system:windows"
    cppdialect "C++17"
    staticruntime "Off"
    systemversion "latest"
    defines
    {
       "GM_BUILD_DLL",
       "GOMAS_API",
       "GM_PLATFORM_WINDOWS"
    }
    
    buildoptions "/utf-8"

    postbuildcommands
        {
            -- Corrected command: create the directory first, then copy the file.
            "if not exist \"../bin/" .. outputdir .. "/Sandbox\" mkdir \"../bin/" .. outputdir .. "/Sandbox\"",
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/%{cfg.buildtarget.name}")
        }

    filter "configurations:Debug"
    defines "GM_DEBUG"
    symbols "On"

        filter "configurations:Release"
    defines "GM_RELEASE"
    optimize "On"

      filter "configurations:Dist"
    defines "GM_DIST"
    optimize "On"

    filter 
    {
     "system:windows",
     "configurations:Release"
    }
    buildoptions "/MT"

                              --Sandbox

     project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
       "%{prj.name}/src/**.h",
       "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
       "Gomas/external_lib/spdlog/include",
       "Gomas/src"
    }

    links
    {
     "Gomas"
    }

    filter "system:windows"
    cppdialect "C++17"
    staticruntime "Off"
    systemversion "latest"
    defines
    {
       "GM_BUILD_DLL",
       "GM_PLATFORM_WINDOWS"
    }
     
    buildoptions "/utf-8"

    filter "configurations:Debug"
    defines "GM_DEBUG"
    symbols "On"

        filter "configurations:Release"
    defines "GM_RELEASE"
    optimize "On"

      filter "configurations:Dist"
    defines "GM_DIST"
    optimize "On"

    dependson "Gomas"




                                 --TESTS

project "GoogleTests"
location "GoogleTests"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "%{prj.name}/external_lib/include",
        "Gomas/external_lib/spdlog/include",
        "Gomas/src"
    }

        defines {
    
       "GM_BUILD_DLL",
       "GM_PLATFORM_WINDOWS"
    }
    
        links {
     "Gomas"
    }

     filter "configurations:Debug"
        libdirs { "%{prj.name}/external_lib/lib/Debug" }
        links { "gtestd", "gtest_maind" }

    filter "configurations:Release"
        libdirs { "%{prj.name}/external_lib/lib/Release" }
        links { "gtest", "gtest_main" }



    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"


    filter "configurations:Debug"
    defines "GM_DEBUG"
    symbols "On"

        filter "configurations:Release"
    defines "GM_RELEASE"
    optimize "On"

      filter "configurations:Dist"
    defines "GM_DIST"
    optimize "On"

      buildoptions "/MT"
      buildoptions "/utf-8"

      dependson "Gomas"

