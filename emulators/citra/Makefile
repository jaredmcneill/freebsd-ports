# $FreeBSD$

PORTNAME=	citra
PORTVERSION=	s20161007
PORTREVISION?=	1
CATEGORIES=	emulators

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Nintendo 3DS emulator/debugger

LICENSE=	BSD2CLAUSE BSD3CLAUSE BSL GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/externals/dynarmic/externals/fmt/LICENSE.rst
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/externals/inih/inih/LICENSE.txt
LICENSE_FILE_BSL=	${WRKSRC}/externals/catch/LICENSE_1_0.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/license.txt

LIB_DEPENDS=	libpng.so:graphics/png

# backend_x64/hostloc.h:93:8: fatal error: no type named 'Reg64' in namespace 'Xbyak'
BROKEN_i386=	https://github.com/MerryMage/dynarmic/issues/35

USE_GITHUB=	yes
# XXX Switch to system Boost after ports/199601
GH_TUPLE=	citra-emu:${PORTNAME}:136cbbe \
		citra-emu:ext-boost:f005c95:boost/externals/boost \
		citra-emu:ext-soundtouch:5274ec4:soundtouch/externals/soundtouch \
		MerryMage:dynarmic:943487e:dynarmic/externals/dynarmic \
		fmtlib:fmt:3.0.0-108-g2ae6bca:fmt/externals/dynarmic/externals/fmt \
		herumi:xbyak:v3.71-424-g4cc35db:xbyak/externals/dynarmic/externals/xbyak \
		neobrain:nihstro:26a0a04:nihstro/externals/nihstro \
		philsquared:Catch:v1.4.0:catch/externals/catch \
		svn2github:inih:603729d:inih/externals/inih/inih

USES=		cmake:outsource compiler:c++14-lang iconv localbase:ldflags
FAVORITE_COMPILER=	${COMPILER_TYPE} # c++14-lib
CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528
LDFLAGS+=	-Wl,--as-needed # GL

OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	QT5 SDL
OPTIONS_SLAVE?=	SDL
OPTIONS_EXCLUDE:=	${OPTIONS_MULTI_GUI}

SDL_USE=	SDL=sdl2
SDL_CMAKE_BOOL=	ENABLE_SDL2
SDL_PLIST_FILES=bin/${PORTNAME}

QT5_USES=	desktop-file-utils shared-mime-info
QT5_USE=	QT5=qmake_build,buildtools_build,core,gui,opengl,widgets
QT5_CMAKE_BOOL=	ENABLE_QT
QT5_PLIST_FILES=bin/${PORTNAME}-qt \
		share/applications/${PORTNAME}.desktop \
		share/mime/packages/${PORTNAME}.xml \
		share/pixmaps/${PORTNAME}.svg

.include <bsd.port.mk>
