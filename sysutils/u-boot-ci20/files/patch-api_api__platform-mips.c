--- api/api_platform-mips.c.orig	2016-11-30 02:32:49 UTC
+++ api/api_platform-mips.c
@@ -0,0 +1,34 @@
+/*
+ * (C) Copyright 2007 Semihalf
+ *
+ * Written by: Rafal Jaworowski <raj@semihalf.com>
+ *
+ * SPDX-License-Identifier:	GPL-2.0+
+ *
+ * This file contains routines that fetch data from MIPS-dependent sources
+ * (bd_info etc.)
+ */
+
+#include <config.h>
+#include <linux/types.h>
+#include <api_public.h>
+
+#include <asm/u-boot.h>
+#include <asm/global_data.h>
+
+#include "api_private.h"
+
+DECLARE_GLOBAL_DATA_PTR;
+
+/*
+ * Important notice: handling of individual fields MUST be kept in sync with
+ * include/asm-mips/u-boot.h and include/asm-mips/global_data.h, so any changes
+ * need to reflect their current state and layout of structures involved!
+ */
+int platform_sys_info(struct sys_info *si)
+{
+	platform_set_mr(si, gd->bd->bi_memstart, gd->bd->bi_memsize, MR_ATTR_DRAM);
+	platform_set_mr(si, gd->bd->bi_flashstart, gd->bd->bi_flashsize, MR_ATTR_FLASH);
+
+	return 1;
+}
