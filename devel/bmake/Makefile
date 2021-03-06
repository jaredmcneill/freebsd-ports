# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	bmake
PORTVERSION=	20160818
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/sjg/ \
		http://www.gtlib.cc.gatech.edu/pub/NetBSD/misc/sjg/ \
		ftp://ftp.uk.netbsd.org/pub/NetBSD/misc/sjg/ \
		ftp://ftp.de.netbsd.org/pub/NetBSD/misc/sjg/
DISTFILES=	bmake-${PORTVERSION}.tar.gz mk-20151111.tar.gz

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Portable version of NetBSD 'make' utility

LICENSE=	BSD3CLAUSE

PORTSCOUT=	skipv:200910007

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:	.SILENT
	${REINPLACE_CMD} 's/^\.Nx/NetBSD/' ${WRKDIR}/bmake/bmake.1

do-build:
	${SETENV} ${MAKE_ENV} ${SH} ${WRKDIR}/bmake/boot-strap \
		--with-default-sys-path='.../share/mk:${PREFIX}/share/mk' \
		-m ${WRKDIR}/mk objdir=${WRKDIR}/obj prefix=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/obj/bmake ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/bmake/bmake.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${SH} ${WRKDIR}/mk/install-mk ${STAGEDIR}${PREFIX}/share/mk
	cd ${STAGEDIR}${PREFIX} ;					\
	    ${FIND} share/mk -type f -o -type l				\
		| ${SORT}						\
		>${WRKDIR}/PLIST.share-mk
	${ECHO_CMD} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.share-mk"		>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"					>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.share-mk"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-share-mk
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.mk>
