# $FreeBSD$

PKGNAMESUFFIX=	-${MODEL}

COMMENT=	Cross-build U-Boot loader for NanoPi NEO

LICENSE=	GPLv2

MASTERDIR=	${.CURDIR}/../u-boot-olimex-a20-som-evb
DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo
UBOOT_VERSION=	2016.11-rc1
DISTNAME=	u-boot-${UBOOT_VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}
PATCHDIR=	${.CURDIR}/files
MODEL=		nanopi-neo
BOARD_CONFIG=	nanopi_neo_defconfig
PORTVERSION=	2016.11.rc1

.include "${MASTERDIR}/Makefile"

