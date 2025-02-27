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
-- Edit 26-02-2025 from now on we just add stuff other than GLFW includes here.
-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "MatteoGameEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "MatteoGameEngine/vendor/Glad/include"
-- "include" refers to the include path used to load the GLFW-premake5 file.  
-- This will paste the whole glfw-premake5 and will copy the definition of the glfw project.
include "MatteoGameEngine/vendor/GLFW"
include "MatteoGameEngine/vendor/Glad"
-- End GLFW Includes - and additional includes

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
        -- Adding glfw includes - and additional includes
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
    }

    -- Adding links for GLFW usage
    links
    {
        "GLFW",
        "Glad",
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
            "MATTEO_GENGINE_BUILD_DLL" --,
            --"GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "MATTEO_GENGINE_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "MATTEO_GENGINE_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "MATTEO_GENGINE_DIST"
        buildoptions "/MD"
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
        buildoptions "/MDd"
        symbols "On"
 
    filter "configurations:Release"
        defines "MATTEO_GENGINE_RELEASE"
        buildoptions "/MD"
        optimize "On"
 
    filter "configurations:Dist"
        defines "MATTEO_GENGINE_DIST"
        buildoptions "/MD"
        optimize "On"
 