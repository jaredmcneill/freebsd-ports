# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION?=	${UBOOT_VERSION}
CATEGORIES=	sysutils
PKGNAMESUFFIX?=	-${MODEL}

USE_GITHUB=	yes
GH_ACCOUNT=	MIPS
GH_PROJECT=	CI20_u-boot
GH_TAGNAME=	25f5638

MAINTAINER=	jmcneill@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for Imagination CI20

LICENSE=	GPLv2

UBOOT_VERSION?=	2013.10
BOARD_CONFIG?=	ci20_mmc
MODEL?=		ci20

NO_ARCH=	yes

WRKSRC?=	${WRKDIR}/CI20_u-boot-${GH_TAGNAME}
USES=		gmake tar:bzip2
SSP_UNSAFE=	yes # cross-LD does not support -fstack-protector

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/u-boot.img \
		${U_BOOT_DIR}/u-boot-spl.bin \
		${U_BOOT_DIR}/README

MAKE_ARGS+=	ARCH=mips \
		CROSS_COMPILE=/opt/mips-2013.11/bin/mips-linux-gnu-

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

do-configure:
	(cd ${WRKSRC}; ${MAKE_CMD} ${MAKE_ARGS} ${BOARD_CONFIG})

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/u-boot.img ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/spl/u-boot-spl.bin \
		${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.post.mk>
