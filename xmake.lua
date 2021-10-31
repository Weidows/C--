-- 引用.lib形式的静态库会报错,所以要用shared动态链接库版本
add_requires("freeglut",{configs = {shared = true}})
-- 全局添加依赖
add_packages("freeglut")

-- 项目本地依赖
add_includedirs("include")
add_linkdirs("bin")
add_linkdirs("lib")


-- 同一 target 只能有一个 main(),否则需要另起名字
target("test")
    set_kind("binary")
    add_files("src/test/*.cpp")

    -- 单个添加依赖,当已经全局添加时,会产生歧义,添加静态版本
    add_packages("freeglut")

    -- 更改编译器,比如 gcc/clang/msvc...
    add_toolchains("gcc")

target("opengl-1-cube")
    set_kind("binary")
    add_files("src/OpenGL/1.概述/cube.cpp")
target("opengl-2-1")
    set_kind("binary")
    add_files("src/OpenGL/2.变换三角形/1.cpp")
target("opengl-2-2")
    set_kind("binary")
    add_files("src/OpenGL/2.变换三角形/2.cpp")
target("opengl-3-1")
    set_kind("binary")
    add_files("src/OpenGL/3.图形建模/绘制奥运五环.cpp")
target("opengl-3-2")
    set_kind("binary")
    add_files("src/OpenGL/3.图形建模/绘制二维几何体.cpp")
