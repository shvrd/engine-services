md .\dependencies

Invoke-WebRequest -Uri "https://raw.githubusercontent.com/PixarAnimationStudios/OpenSubdiv/master/cmake/FindGLFW.cmake" -OutFile ".\dependencies\FindGLFW.cmake"

git clone https://github.com/Crascit/DownloadProject.git .\dependencies\DownloadProject

md .\build
md .\out