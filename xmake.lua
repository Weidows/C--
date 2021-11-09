-- 配置API: https://xmake.io/#/zh-cn/manual/project_target
-- ##########################################################################

-- 引用.lib形式的静态库会报错,所以要用shared动态链接库版本
add_requires("freeglut",{configs = {shared = true}})
add_requires("glew")
add_requires("opencv")
add_requires("opengl")

-- 全局添加依赖
add_packages("freeglut")
add_packages("opencv")
add_packages("glew")
add_packages("opengl")


-- 更改编译器,比如 gcc/clang/msvc...
-- add_toolchains("gcc")

-- 项目本地依赖
add_includedirs("include")
add_linkdirs("lib")


-- 同一 target 只能有一个 main(),否则需要另起名字
target("test")
    set_kind("binary")
      -- target("test")
      -- phony	假的目标程序
      -- binary	二进制程序
      -- static	静态库程序
      -- shared	动态库程序
      -- object	仅仅编译对象集合
      -- headeronly	仅仅头文件集合
    add_files("src/test/*.cpp")

    -- 单个添加依赖,当已经全局添加时,会产生歧义,添加静态版本
    add_packages("freeglut")



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


target("MazeGame")
    set_kind("binary")
    add_files("src/OpenGL/MazeGame/main.cpp")
target_end()
