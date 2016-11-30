--- common/cmd_elf.c.orig	2016-04-04 16:21:59 UTC
+++ common/cmd_elf.c
@@ -34,6 +34,7 @@ unsigned long do_bootelf_exec(ulong (*en
 {
 	unsigned long ret;
 
+#if 0
 	/*
 	 * QNX images require the data cache is disabled.
 	 * Data cache is already flushed, so just turn it off.
@@ -41,6 +42,7 @@ unsigned long do_bootelf_exec(ulong (*en
 	int dcache = dcache_status();
 	if (dcache)
 		dcache_disable();
+#endif
 
 	/*
 	 * pass address parameter as argv[0] (aka command name),
@@ -48,8 +50,10 @@ unsigned long do_bootelf_exec(ulong (*en
 	 */
 	ret = entry(argc, argv);
 
+#if 0
 	if (dcache)
 		dcache_enable();
+#endif
 
 	return ret;
 }
