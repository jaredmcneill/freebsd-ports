--- common/env_fat.c.orig	2016-04-04 16:21:59 UTC
+++ common/env_fat.c
@@ -7,6 +7,7 @@
  * SPDX-License-Identifier:	GPL-2.0+ 
  */
 
+#include <config.h>
 #include <common.h>
 
 #include <command.h>
