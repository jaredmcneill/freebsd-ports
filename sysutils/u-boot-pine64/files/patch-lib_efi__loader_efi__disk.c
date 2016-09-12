--- lib/efi_loader/efi_disk.c.orig	2016-08-22 21:30:42.000000000 -0300
+++ lib/efi_loader/efi_disk.c	2016-09-10 08:35:27.028578000 -0300
@@ -196,7 +196,8 @@ static void efi_disk_add_dev(const char 
 			     const char *if_typename,
 			     const struct blk_desc *desc,
 			     int dev_index,
-			     lbaint_t offset)
+			     disk_partition_t *info,
+			     int logical_partition)
 {
 	struct efi_disk_obj *diskobj;
 	struct efi_device_path_file_path *dp;
@@ -217,15 +218,23 @@ static void efi_disk_add_dev(const char 
 	diskobj->ops = block_io_disk_template;
 	diskobj->ifname = if_typename;
 	diskobj->dev_index = dev_index;
-	diskobj->offset = offset;
+	if (info)
+		diskobj->offset = info->start;
 	diskobj->desc = desc;
 
 	/* Fill in EFI IO Media info (for read/write callbacks) */
 	diskobj->media.removable_media = desc->removable;
 	diskobj->media.media_present = 1;
-	diskobj->media.block_size = desc->blksz;
-	diskobj->media.io_align = desc->blksz;
-	diskobj->media.last_block = desc->lba - offset;
+	if (logical_partition) {
+		diskobj->media.logical_partition = 1;
+		diskobj->media.block_size = info->blksz;
+		diskobj->media.io_align = info->blksz;
+		diskobj->media.last_block = info->size - 1;
+	} else {
+		diskobj->media.block_size = desc->blksz;
+		diskobj->media.io_align = desc->blksz;
+		diskobj->media.last_block = desc->lba;
+	}
 	diskobj->ops.media = &diskobj->media;
 
 	/* Fill in device path */
@@ -261,8 +270,7 @@ static int efi_disk_create_eltorito(stru
 	while (!part_get_info(desc, part, &info)) {
 		snprintf(devname, sizeof(devname), "%s:%d", pdevname,
 			 part);
-		efi_disk_add_dev(devname, if_typename, desc, diskid,
-				 info.start);
+		efi_disk_add_dev(devname, if_typename, desc, diskid, &info, 0);
 		part++;
 		disks++;
 	}
@@ -271,6 +279,30 @@ static int efi_disk_create_eltorito(stru
 	return disks;
 }
 
+static int efi_disk_create_mbr(struct blk_desc *desc,
+				const struct blk_driver *cur_drvr,
+				int diskid)
+{
+	int disks = 0;
+	char devname[32] = { 0 }; /* dp->str is u16[32] long */
+	disk_partition_t info;
+	int part = 1;
+
+	if (desc->part_type != PART_TYPE_DOS)
+		return 0;
+
+	while (!part_get_info(desc, part, &info)) {
+		snprintf(devname, sizeof(devname), "%s%d:%d", cur_drvr->if_typename,
+		    diskid, part);
+
+		efi_disk_add_dev(devname, cur_drvr->if_typename, desc, diskid, &info, 1);
+		part++;
+		disks++;
+	}
+
+	return disks;
+}
+
 /*
  * U-Boot doesn't have a list of all online disk devices. So when running our
  * EFI payload, we scan through all of the potentially available ones and
@@ -331,7 +363,7 @@ int efi_disk_register(void)
 
 			snprintf(devname, sizeof(devname), "%s%d",
 				 if_typename, i);
-			efi_disk_add_dev(devname, if_typename, desc, i, 0);
+			efi_disk_add_dev(devname, if_typename, desc, i, NULL, 0);
 			disks++;
 
 			/*
@@ -340,6 +372,7 @@ int efi_disk_register(void)
 			 */
 			disks += efi_disk_create_eltorito(desc, if_typename,
 							  i, devname);
+			disks += efi_disk_create_mbr(desc, cur_drvr, i);
 		}
 	}
 #endif
