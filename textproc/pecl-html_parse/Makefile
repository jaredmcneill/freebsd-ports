# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	html_parse
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PECL extension for the ekhtml library

DEPRECATED=	Works only with EOL php 5.5
EXPIRATION_DATE=	2016-10-20

LICENSE=	PHP30

BUILD_DEPENDS=	${LOCALBASE}/lib/libekhtml.a:textproc/ekhtml
RUN_DEPENDS=	${LOCALBASE}/lib/libekhtml.a:textproc/ekhtml

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	56 70

CONFIGURE_ARGS=	--enable-html_parse

.include <bsd.port.mk>
