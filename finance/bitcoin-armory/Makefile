# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	BitcoinArmory
PORTVERSION=	0.93.3
DISTVERSIONPREFIX=	v
CATEGORIES=	finance

MAINTAINER=	yuri@rawbw.com
COMMENT=	Desktop bitcoin management system

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/swig3.0:devel/swig30 \
		${LOCALBASE}/bin/pyrcc4:textproc/py-qt4-xml \
		${LOCALBASE}/bin/rsync:net/rsync
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT4_VERSION}:devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT4_VERSION}:x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}twistedCore>=14.0.0:devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}psutil>1.2.1:sysutils/py-psutil \
		${LOCALBASE}/bin/bitcoind:net-p2p/bitcoin-daemon

USE_GITHUB=	yes
GH_ACCOUNT=	etotheipi

USES=		compiler:c++11-lang compiler:c++11-lib gmake python:2 shebangfix
SHEBANG_FILES=	extras/extractKeysFromWallet.py
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM -fPIC
MAKE_ENV+=	PYTHON_CONFIG=${PYTHON_CMD}-config

BROKEN_FreeBSD_9=	cannot find atomic header

MAKE_ARGS+=	CXXFLAGS="${CXXFLAGS}"
INSTALLS_ICONS=	yes
ICON_SIZES=	24x24 32x32 64x64

# When CRYPTOPP_DISABLE_ASM isn't needed any more, i386 amd64 should
# be made work through ASM code, and the other archs will still
# have CRYPTOPP_DISABLE_ASM

post-patch:
	@${REINPLACE_CMD} 's/python-config/$${PYTHON_CONFIG}/' ${WRKSRC}/cppForSwig/Makefile
	@${REINPLACE_CMD} 's/O_DSYNC/O_SYNC/' ${WRKSRC}/cppForSwig/mdb/mdb.c

post-stage:
	@${SED} -i.bak -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${STAGEDIR}/${LOCALBASE}/bin/armory && \
		${RM} -f ${STAGEDIR}/${LOCALBASE}/bin/armory.bak
	@${REINPLACE_CMD} 's|Exec=/usr/bin/armory|Exec=${LOCALBASE}/bin/armory|' ${STAGEDIR}/${LOCALBASE}/share/applications/*.desktop
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${MV} ${STAGEDIR}/${PREFIX}/share/armory/img/armory_icon_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/armoryicon.png
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/armory/_CppBlockUtils.so

.include <bsd.port.mk>
