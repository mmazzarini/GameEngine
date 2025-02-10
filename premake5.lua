workspace "MatteoGameEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Begin GLFW Includes:
-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "MatteoGameEngine/vendor/GLFW/include"
-- "include" refers to the include path used to load the GLFW-premake5 file.  
-- This will paste the whole glfw-premake5 and will copy the definition of the glfw project.
include "MatteoGameEngine/vendor/GLFW"
-- End GLFW Includes

project "MatteoGameEngine"
    location "MatteoGameEngine"
    kind "SharedLib"
    language "C++"

    targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "GenginePCH.h"
    pchsource "MatteoGameEngine/src/GenginePCH.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        -- Adding glfw includes
        "%{IncludeDir.GLFW}"
    }

    -- Adding links for GLFW usage
    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"
    
        defines
        {
            "MATTEO_GENGINE_PLATFORM_WINDOWS",
            "MATTEO_GENGINE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "MATTEO_GENGINE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "MATTEO_GENGINE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "MATTEO_GENGINE_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
       
    targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "MatteoGameEngine/vendor/spdlog/include",
        "MatteoGameEngine/src"
    }
    
    links
    {
        "MatteoGameEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"

        defines
        {
            "MATTEO_GENGINE_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "MATTEO_GENGINE_DEBUG"
        symbols "On"
 
    filter "configurations:Release"
        defines "MATTEO_GENGINE_RELEASE"
        optimize "On"
 
    filter "configurations:Dist"
        defines "MATTEO_GENGINE_DIST"
        optimize "On"
 