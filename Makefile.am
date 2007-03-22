ACLOCAL_AMFLAGS = -I m4

DEFS = -DHAVE_CONFIG_H

INCLUDES = -I$(geomviewincludes) $(default_includes) -I$(XFORMS_INCLUDE_PATH)

man_MANS = maniview.1

EXTRA_DIST = .geomview-maniview \
   spaceshipSpace.geom wholecube.geom        \
   borrom4.wa controlpanel.fd dodec.vect gvinit hook.off \
   maniview.1 maniviewhelp $(datagroups_DATA)

datagroupsdir = $(geomdatadir)/groups

datagroups_DATA = 120.dgp 3torus.dgp borrom.dgp borrom2.dgp borrom4.dgp \
                  good_klein_quick.dgp klein_bricks.dgp klein_whole.dgp \
                  notknot.dgp

if HAVE_XFORMS
module_PROGRAMS = maniview
module_DATA = .geomview-maniview

maniview_SOURCES = \
    callbacks.c controlpanel.c maniview.c controlpanel.h gvinit.h \
    maniview.h maniviewhelp.h
maniview_LDADD = $(XFORMS_ALL_LIB) $(OOGLLIB)

EMODULES = .geomview-maniview

if LOCAL_EMODULE
homedir = $(HOME)
home_DATA = $(EMODULES)
modulepath = $(moduledir)/
else
if !GEOMVIEW_QUERY
modulepath = $(moduledir)/
module_DATA = $(EMODULES)
else
modulepath =
module_DATA = $(EMODULES)
endif
endif

.geomview-maniview: .geomview
	echo '(emodule-define "Maniview" "$(modulepath)maniview")' > $@

.geomview: Makefile
	echo '(emodule-define "Maniview" "./maniview")' > $@

endif

clean-local:
	rm -f .geomview*

MAINTAINERCLEANFILES = \
  aclocal.m4 config.h.in configure stamp-h.in Makefile.in
