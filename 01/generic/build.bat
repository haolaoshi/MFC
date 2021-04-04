@echo off
rem  invoke from "Development command prompt for vs"
del *.obj  
del *.exe  
del *.res  
nmake generic.mak 
del *.obj  
del *.res 