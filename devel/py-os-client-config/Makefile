# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	os-client-config
PORTVERSION=	1.21.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Client Configuation Library

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3.1.0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}appdirs>=1.3.0:devel/py-appdirs \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.1.0:devel/py-keystoneauth1 \
		${PYTHON_PKGNAMEPREFIX}requestsexceptions>=1.1.1:devel/py-requestsexceptions

USES=		python
USE_PYTHON=	distutils autoplist noegginfo
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,install_requires.*,,' ${WRKSRC}/setup.py

.include <bsd.port.mk>
