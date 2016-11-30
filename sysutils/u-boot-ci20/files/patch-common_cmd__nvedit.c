--- common/cmd_nvedit.c.orig	2016-04-04 16:21:59 UTC
+++ common/cmd_nvedit.c
@@ -798,6 +798,14 @@ static int do_env_delete(cmd_tbl_t *cmdt
 	return ret;
 }
 
+static int do_env_exists(cmd_tbl_t *cmdtp, int flag,
+			 int argc, char * const argv[])
+{
+	if (argc != 2)
+		return CMD_RET_USAGE;
+	return getenv(argv[1]) ? CMD_RET_SUCCESS : CMD_RET_FAILURE;
+}
+
 #ifdef CONFIG_CMD_EXPORTENV
 /*
  * env export [-t | -b | -c] [-s size] addr [var ...]
@@ -1094,6 +1102,7 @@ static cmd_tbl_t cmd_env_sub[] = {
 	U_BOOT_CMD_MKENT(save, 1, 0, do_env_save, "", ""),
 #endif
 	U_BOOT_CMD_MKENT(set, CONFIG_SYS_MAXARGS, 0, do_env_set, "", ""),
+	U_BOOT_CMD_MKENT(exists, 2, 0, do_env_exists, "", ""),
 };
 
 #if defined(CONFIG_NEEDS_MANUAL_RELOC)
