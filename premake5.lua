workspace "GFSFML"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

SPDLOG_DIR = "external/spdlog"
SFML_DIR = "external/SFML"

IncludeDir = {
   spdlog = "external/spdlog/include",
   SFML = "external/SFML/include"
}

LibraryDir = {
   SFML = "external/SFML/lib"
}

Library = {
    SF_graphics   = "%{LibraryDir.SFML}/sfml-graphics.lib",
    SF_window   = "%{LibraryDir.SFML}/sfml-window.lib",
    SF_audio   = "%{LibraryDir.SFML}/sfml-audio.lib",
    SF_network   = "%{LibraryDir.SFML}/sfml-network.lib",
    SF_system   = "%{LibraryDir.SFML}/sfml-system.lib",
    SFD_graphics  = "%{LibraryDir.SFML}/sfml-graphics-d.lib",
    SFD_window  = "%{LibraryDir.SFML}/sfml-window-d.lib",
    SFD_audio  = "%{LibraryDir.SFML}/sfml-audio-d.lib",
    SFD_network  = "%{LibraryDir.SFML}/sfml-network-d.lib",
    SFD_system  = "%{LibraryDir.SFML}/sfml-system-d.lib",
}

project "GFSFML"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "src/**.h", "src/**.cpp" }

   includedirs {
      "external/spdlog/include",
      "external/SFML/include"
   }
   libdirs { "external/SFML/lib" }
   
   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   filter "system:windows"
      systemversion "latest"

   filter "configurations:Debug"
      defines { "WL_DEBUG", "SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_DEBUG" }
      runtime "Debug"
      inlining "Auto"
      symbols "On"
      links { "sfml-graphics-d", "sfml-audio-d","sfml-network-d","sfml-window-d", "sfml-system-d" }

   filter "configurations:Release"
      defines { "WL_RELEASE", "SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE" }
      runtime "Release"
      optimize "On"
      inlining "Auto"
      symbols "On"
      links { "sfml-graphics", "sfml-audio","sfml-network","sfml-window", "sfml-system" }
      flags { "LinkTimeOptimization", "MultiProcessorCompile"} 

   filter "configurations:Dist"
      defines { "WL_DIST", "SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE" }
      runtime "Release"
      optimize "On"
      inlining "Auto"
      symbols "Off"
      links { "sfml-graphics", "sfml-audio","sfml-window", "sfml-system" }
      omitframepointer "On"
      flags { "LinkTimeOptimization", "MultiProcessorCompile", "NoBufferSecurityCheck", "NoIncrementalLink" }