workspace "Potato"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Potato"
	location "Potato"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name)/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PO_PLATFORM_WINDOWS",
			"PO_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PO_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Potato/vendor/spdlog/include",
		"Potato/src"
	}

	links
	{
		"Potato"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PO_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PO_DIST"
		optimize "On"