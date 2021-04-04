@echo off
rem  invoke from "Development command prompt for vs"
 
del *.exe   
cl /MT mfccon.cpp 
del *.obj 