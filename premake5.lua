workspace "MatteoGameEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MatteoGameEngine"
    location "MatteoGameEngine"
    kind "SharedLib"
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
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src"
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
 