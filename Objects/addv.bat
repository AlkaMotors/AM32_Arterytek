@echo off
set /p vn= "Enter Version Number :"

del *.lnp
del *.axf
del *.o
del *.d
del *.htm
del *.dep

rename *F421.hex *F421_%vn%.hex
rename *F415.hex *F415_%vn%.hex