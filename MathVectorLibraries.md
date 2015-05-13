# Alternatives for Math Vector Libraries #

There are many alternatives to use math vector & matrix libraries with OpenGL. These ones have been considered:

  * [vmath](http://bartipan.net/vmath/) is simple and worked easily. Currently used in the code.
  * I used [SVL](http://www.cs.cmu.edu/~ajw/doc/svl.html) in the past. It gave me some problems compiling ¿LibSVL.do? on Linux. It is old and currently has no maintenace.
  * [vmmlib](http://vmmlib.sourceforge.net/) reported link error on Linux, missed -lclapk and -lf2c. Only needs a .hpp file. SVL autor is involved and it seems quite new.
  * Haven't tested [Eigen](http://eigen.tuxfamily.org). It has version 2 and 3.