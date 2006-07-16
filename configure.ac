AC_PREREQ(2.59)
AC_INIT(maniview, [2.0.1-rc1], Claus-Justus Heine <Claus.Heine@Mathematik.Uni-Freiburg.DE>)
AC_CONFIG_AUX_DIR([../../..])
AM_INIT_AUTOMAKE([dist-bzip2 1.9])
AM_MAINTAINER_MODE
AC_MSG_RESULT([configuring $PACKAGE $VERSION])
GEOM_REQUIRE_GEOMVIEW_VERSION($srcdir/../../..,=,1,>=,8)
AC_PREFIX_DEFAULT(/usr/local/Geomview)
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL

top_geom_builddir=../../..
AC_SUBST(top_geom_builddir)

GEOM_CHECK_XFORMS
AC_SUBST(XFORMSLIBS)
AC_SUBST(XFORMSINCLUDE)
AM_CONDITIONAL(HAVE_XFORMS,    test x$have_xforms = xyes)

GEOM_GET_CACHED_VALUE(moduledir)
AC_SUBST(moduledir)

GEOM_GET_CACHED_VALUE(geomdatadir)
AC_SUBST(geomdatadir)

GEOM_GET_CACHED_VALUE(OOGLLIB)
AC_SUBST(OOGLLIB)

GEOM_GET_CACHED_VALUE(XLIBS)
AC_SUBST(XLIBS)

########################################################################

AC_OUTPUT(Makefile)
