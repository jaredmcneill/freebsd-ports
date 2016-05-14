--- tools/mkimage.c.orig	2016-04-12 02:22:25 UTC
+++ tools/mkimage.c
@@ -243,44 +243,15 @@ static void process_args(int argc, char 
 		case 'x':
 			params.xflag++;
 			break;
-		case 1:
-			if (expecting == type || optind == argc) {
-				params.imagefile = optarg;
-				expecting = IH_TYPE_INVALID;
-			} else if (expecting == IH_TYPE_INVALID) {
-				fprintf(stderr,
-					"%s: Unknown content type: use -b before device tree files",
-					params.cmdname);
-				exit(EXIT_FAILURE);
-			} else {
-				if (add_content(expecting, optarg)) {
-					fprintf(stderr,
-						"%s: Out of memory adding content '%s'",
-						params.cmdname, optarg);
-					exit(EXIT_FAILURE);
-				}
-			}
-			break;
 		default:
 			usage("Invalid option");
 		}
 	}
 
-	/*
-	 * For auto-generated FIT images we need to know the image type to put
-	 * in the FIT, which is separate from the file's image type (which
-	 * will always be IH_TYPE_FLATDT in this case).
-	 */
-	if (params.type == IH_TYPE_FLATDT) {
-		params.fit_image_type = type;
-		if (!params.auto_its)
-			params.datafile = datafile;
-	} else if (type != IH_TYPE_INVALID) {
-		params.type = type;
-	}
-
-	if (!params.imagefile)
+	if (optind >= argc)
 		usage("Missing output filename");
+
+	params.imagefile = argv[optind];
 }
 
 
