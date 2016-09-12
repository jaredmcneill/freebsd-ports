--- boot0img.c.orig	2016-09-09 17:43:50.841495000 -0300
+++ boot0img.c	2016-09-09 17:44:03.816193000 -0300
@@ -24,6 +24,10 @@
 #include <fcntl.h>
 #include <errno.h>
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#endif
+
 enum header_offsets {				/* in words of 4 bytes */
 	HEADER_JUMP_INS	= 0,
 	HEADER_MAGIC	= 1,
