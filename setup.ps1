md .\dependencies

Invoke-WebRequest -Uri "https://raw.githubusercontent.com/PixarAnimationStudios/OpenSubdiv/master/cmake/FindGLFW.cmake" -OutFile ".\dependencies\FindGLFW.cmake"
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/Groovounet/glm-deprecated/master/util/FindGLM.cmake" -OutFile ".\dependencies\FindGLM.cmake"

git clone https://github.com/Crascit/DownloadProject.git .\dependencies\DownloadProject

md .\build
md .\out

Copy-Item .\dependencies\freetype.dll .\out
Copy-Item .\dependencies\glew32.dll .\out
Copy-Item .\dependencies\glfw3.dll .\out
