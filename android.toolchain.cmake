set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_VERSION 35)
set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)

# Use the native Clang already installed in Termux
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# Point to the NDK sysroot only, so it knows what Android APIs are
set(NDK_ROOT "$ENV{ANDROID_NDK_HOME}")
set(CMAKE_SYSROOT "${NDK_ROOT}/toolchains/llvm/prebuilt/linux-x86_64/sysroot")

