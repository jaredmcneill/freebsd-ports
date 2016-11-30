--- include/configs/ci20.h.orig	2016-04-04 16:21:59 UTC
+++ include/configs/ci20.h
@@ -315,4 +315,59 @@
 
 #endif /* !CONFIG_SPL_MMC_SUPPORT */
 
+#ifndef	CONFIG_SPL_BUILD
+#define	CONFIG_API
+#define	CONFIG_EFI_PARTITION
+//#define	CONFIG_SYS_DCACHE_OFF
+//#define	CONFIG_CMD_CACHE
+#define CONFIG_SYS_MMC_MAX_DEVICE	1
+#define CONFIG_FAT_WRITE
+#endif
+
+#if 0
+#undef  CONFIG_ENV_IS_NOWHERE
+#undef  CONFIG_ENV_IS_IN_NAND
+#undef  CONFIG_ENV_IS_IN_MMC
+#undef  CONFIG_ENV_IS_IN_SPI_FLASH
+#define CONFIG_ENV_IS_IN_FAT
+#define FAT_ENV_INTERFACE		"mmc"
+#define FAT_ENV_DEVICE			0
+#define	FAT_ENV_PART			1
+#define FAT_ENV_FILE			"u-boot.env"
+#endif
+
+#ifndef CONFIG_SPL_BUILD
+#undef	CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	"stdin=eserial0,eserial4\0" \
+	"stdout=eserial0,eserial4\0" \
+	"stderr=eserial0,eserial4\0" \
+	"ethargs=env set bootargs ${bootargs} dm9000.mac_addr=${ethaddr}\0" \
+	"fdtfile=ci20.dtb\0" \
+	"Fatboot=" \
+	  "env exists loaderdev || env set loaderdev ${fatdev}; " \
+	  "env exists UserFatboot && run UserFatboot; " \
+	  "echo Booting from: ${fatdev} ${bootfile}; " \
+	  "fatload ${fatdev} 0x88000000 ${bootfile} && bootelf || go 0x88000000; " \
+	"\0" \
+	"Netboot=" \
+	  "env exists loaderdev || env set loaderdev net; " \
+	  "env exists UserNetboot && run UserNetboot; " \
+	  "dhcp 0x88000000 ${bootfile} && bootelf; " \
+	"\0" \
+	"preboot=usb start; " \
+	  "env exists bootfile || env set bootfile ubldr.bin; " \
+	  "env exists SetupFatdev && run SetupFatdev; " \
+	  "env exists UserPreboot && run UserPreboot; " \
+	"\0" \
+	"SetupFatdev=" \
+	  "env exists fatdev || env set fatdev 'mmc 0'; " \
+	"\0"
+
+#undef  CONFIG_BOOTCOMMAND
+#define CONFIG_BOOTCOMMAND      "run Fatboot"
+#undef  CONFIG_PREBOOT
+#define CONFIG_PREBOOT          "run preboot"
+#endif
+
 #endif /* __CONFIG_CI20_H__ */
