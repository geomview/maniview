AC_INIT(maniview, [2.0.1], Claus-Justus Heine <Claus.Heine@Mathematik.Uni-Freiburg.DE>)

GV_INIT_GEOMVIEW(=,1,>=,9)

AC_CONFIG_SRCDIR([maniview.c])

#
# Store X library link line in XLIBS
#
AC_PATH_XTRA
XLIBS="$X_LIBS $X_PRE_LIBS -lXt -lXext -lX11 $X_EXTRA_LIBS"
AC_SUBST(XLIBS)
AC_CACHE_VAL(ac_cv_XLIBS,[ac_cv_XLIBS="XLIBS='$XLIBS'"])

#
# Check for the xforms library
#
GEOMVIEW_CHECK_PACKAGE(Xpm, Xpm, ${x_libraries}, ${XLIBS},,,,optional,enabled)
GEOMVIEW_CHECK_PACKAGE(xforms, forms, ${x_libraries}, ${XLIBS} ${XPM_LIB} -lm, forms.h,,,optional,enabled)

GEOMVIEW_RESULT

########################################################################

AC_OUTPUT(Makefile)
