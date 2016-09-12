# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2016.09.rc2
DISTVERSION=	2016.09-rc2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/:uboot \
		https://github.com/apritzel/arm-trusted-firmware/archive/:firmware \
		https://raw.githubusercontent.com/apritzel/pine64/0558929fa4964fb20725d641655f840071aa945e/tools/:imagetool \
		http://csgraf.de/agraf/pine64/:boot0
PKGNAMESUFFIX=	-pine64
ATF_FWREV=	f11ecb4af7f9f337a2bae0adc6c340236823bfbf
DISTFILES=	u-boot-${DISTVERSION}.tar.bz2:uboot \
		${ATF_FWREV}.zip:firmware \
		boot0img.c:imagetool \
		boot0.bin:boot0
EXTRACT_ONLY=	u-boot-${DISTVERSION}.tar.bz2

MAINTAINER=	brd@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for Pine64

LICENSE=	GPLv2

BUILD_DEPENDS=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc

WRKSRC=		${WRKDIR}/u-boot-${DISTVERSION}
USES=		gmake tar:bzip2
SSP_UNSAFE=	yes # cross-LD does not support -fstack-protector

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/pine64.img \
		${U_BOOT_DIR}/README

MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=aarch64-none-elf- \
		PLAT=sun50iw1p1 \
		CONFIG_EFI=y

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

post-extract:
	${CP} ${DISTDIR}/boot0.bin ${WRKSRC}
	${CP} ${DISTDIR}/boot0img.c ${WRKSRC}
	${RM} -fr ${WRKSRC}/arm-trusted-firmware
	(cd ${WRKSRC}; ${UNZIP_CMD} ${DISTDIR}/${ATF_FWREV}.zip)
	(cd ${WRKSRC}; ${MV} arm-trusted-firmware-${ATF_FWREV} arm-trusted-firmware)

do-configure:
	(cd ${WRKSRC}; ${MAKE_CMD} pine64_plus_defconfig)

post-build:
	(cd ${WRKSRC}/arm-trusted-firmware; ${GMAKE} ${MAKE_ARGS} DEBUG=1)
	(cd ${WRKSRC}; ${CC} -o boot0img boot0img.c)
	(cd ${WRKSRC}; ./boot0img -B boot0.bin -s arm-trusted-firmware/build/sun50iw1p1/debug/bl31.bin -a 0x44008 -d trampoline64:0x44000 -u u-boot-dtb.bin -e -o pine64.img)

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC}/pine64.img ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.post.mk>
