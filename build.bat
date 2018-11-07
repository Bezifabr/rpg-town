

IF NOT EXIST "build/rpg-town.sln" (
    set firstTime="t"
    echo %firstTime%
    mkdir build
    cd build
    set /P version=Enter Visual Studio version:
    cmake .. -G "Visual Studio %version%"
)
IF EXIST "build/rpg-town.sln" (
    cd build
    cmake ..set 
    set firstTime="f"
)


MSBuild rpg-town.sln

cd debug

IF %firstTime%=="t" (
    xcopy /s "..\ext\sfml\lib\Debug\*.dll"
    xcopy /s "..\ext\sfml\extlibs\bin\x86\openal32.dll"
    mkdir resources
    cd resources
    xcopy /s "..\..\..\resources\*.*"
    cd ..
)

rpg-town.exe
cd ../..
