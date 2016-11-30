--- common/cmd_test.c.orig	2016-04-04 16:21:59 UTC
+++ common/cmd_test.c
@@ -23,8 +23,10 @@ static int do_test(cmd_tbl_t *cmdtp, int
 	int left, adv, expr, last_expr, neg, last_cmp;
 
 	/* args? */
-	if (argc < 3)
+	if (argc < 2)
 		return 1;
+	else if (argc == 2)
+		return !(strcmp(argv[1], "-z") == 0);
 
 #ifdef DEBUG
 	{
