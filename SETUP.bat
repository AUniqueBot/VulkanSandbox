@echo off
setlocal

echo ========================================
echo Vulkan Sandbox
echo ========================================

where cmake >nul 2>&1
if errorlevel 1 (
    echo ERROR: CMake was not found.
    exit /b 1
)

if "%VCPKG_ROOT%"=="" (
    echo ERROR: VCPKG_ROOT is not set.
    echo Please set VCPKG_ROOT to your vcpkg installation.
    exit /b 1
)

echo.
echo [1/3] Configuring...
cmake --preset default
if errorlevel 1 (
    echo.
    echo ERROR: CMake configuration failed.
    exit /b 1
)

echo.
echo [2/3] Building...
cmake --build --preset default
if errorlevel 1 (
    echo.
    echo ERROR: Build failed.
    exit /b 1
)

echo.
echo [3/3] Opening VS Code...
code .
if errorlevel 1 (
    echo.
    echo WARNING: VS Code could not be launched with 'code'.
)

echo.
echo ========================================
echo Build complete.
echo ========================================

endlocal