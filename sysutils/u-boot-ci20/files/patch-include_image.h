--- include/image.h.orig	2016-04-04 16:21:59 UTC
+++ include/image.h
@@ -17,7 +17,6 @@
 #define __IMAGE_H__
 
 #include "compiler.h"
-#include <asm/byteorder.h>
 
 /* Define this to avoid #ifdefs later on */
 struct lmb;
@@ -34,6 +33,7 @@ struct lmb;
 
 #else
 
+#include <asm/byteorder.h>
 #include <lmb.h>
 #include <asm/u-boot.h>
 #include <command.h>
