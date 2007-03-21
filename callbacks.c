/* Copyright (C) 1992-1998 The Geometry Center
 * Copyright (C) 1998-2000 Stuart Levy, Tamara Munzner, Mark Phillips
 *
 * This file is part of Geomview.
 * 
 * Geomview is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * Geomview is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with Geomview; see the file COPYING.  If not, write
 * to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139,
 * USA, or visit http://www.gnu.org.
 */

#if HAVE_CONFIG_H
# include "config.h"
#endif

#if 0
static char copyright[] = "Copyright (C) 1992-1998 The Geometry Center\n\
Copyright (C) 1998-2000 Stuart Levy, Tamara Munzner, Mark Phillips";
#endif

/* We include the C code generated by the forms designer (fdesign2). */
#include <stdlib.h>
/*#include "discgrpP.h"*/
#include "dgflag.h"
#include "maniview.h"

#include "forms.h"
#include "xforms-compat.h"
#include "controlpanel.h"

  static int display_winid = -1,
	enum_winid = -1,
	load_winid = -1,
	save_winid = -1,
	dirdom_winid = -1,
	info_winid = -1,
	help_winid = -1;



#define TOGGLE(xxx, bit, button) 	\
	xxx = fl_get_button(button) ? (xxx | bit) : (xxx & ~bit)

static int oldspace = DG_EUCLIDEAN;

int loadstuff();
void savegroup();

/* This is the callback procedure we must write. It's the interface
   between our program and the forms code.
 */

void DspyattrProc(FL_OBJECT *obj, long val)
{
  unsigned flag;
  
  GeomGet((Geom *)dg, DGCR_FLAG, &flag);
  TOGGLE(flag,  val, obj);
  GeomSet((Geom *)dg, DGCR_FLAG, flag, CR_END);
  changed = CHANGED;
}

void SoftshadeProc(FL_OBJECT *obj, long val)
{
  softshade = 1 - softshade;
  changed = SOFTSHADE;
}

void RadiusProc(FL_OBJECT *obj, long val)
{
  GeomSet((Geom *)dg, DGCR_ENUMDIST, (float)fl_get_slider_value(obj), CR_END);
  changed = CHANGED;
}

void DrawRadiusProc(FL_OBJECT *obj, long val)
{
  GeomSet((Geom *)dg, DGCR_DRAWDIST, (float)fl_get_slider_value(obj), CR_END);
  changed = CHANGED;
}


void DisplayProc(FL_OBJECT *obj, long val)
{
  unsigned flag;
  
  GeomGet((Geom *)dg, DGCR_FLAG, &flag);
  TOGGLE(flag, val, obj); 
  GeomSet((Geom *)dg, DGCR_FLAG, flag, CR_END);
  changed = CHANGED;
}


void TileModeProc(FL_OBJECT *obj, long val)
{
  tilemode = val;
  fl_set_button(DirichletDomainButton, tilemode & DIRDOM_MODE );
  fl_set_button(UsergeometryButton, tilemode & USER_GEOM );
}

void DDXYProc(FL_OBJECT *obj, long val)
{
  HPoint3 cpoint;
  
  GeomGet((Geom *)dg, DGCR_CPOINT, &cpoint);
  cpoint.x = fl_get_positioner_xvalue(obj);
  cpoint.y = fl_get_positioner_yvalue(obj);
  GeomSet((Geom *)dg, DGCR_CPOINT, &cpoint, CR_END);
  changed = DIRDOM | CHANGED;
}

void DDZProc(FL_OBJECT *obj, long val)
{
  HPoint3 cpoint;
  
  GeomGet((Geom *)dg, DGCR_CPOINT, &cpoint);
  cpoint.z = fl_get_dial_value(obj);
  GeomSet((Geom *)dg, DGCR_CPOINT, &cpoint, CR_END);
  changed = DIRDOM | CHANGED;
}

void DDResetProc(FL_OBJECT *obj, long val)
{
  HPoint3 cpoint;
  
  GeomGet((Geom *)dg, DGCR_CPOINT, &cpoint);
  cpoint.x = 0.0;
  cpoint.y = 0.0;
  cpoint.z = 0.0;
  cpoint.w = 1.0;
  GeomSet((Geom *)dg, DGCR_CPOINT, &cpoint, CR_END);
  fl_update_from_dg();
  changed = DIRDOM | CHANGED;
}

void WorddepthProc(FL_OBJECT *obj, long val)
{
  GeomSet((Geom *)dg, DGCR_ENUMDEPTH, (int)fl_get_counter_value(obj), CR_END);
  changed = CHANGED;
}

void DDScaleProc(FL_OBJECT *obj, long val)
{
  myscale = fl_get_slider_value(obj);
  if (tilemode == DIRDOM_MODE) {
    GeomSet((Geom *)dg, DGCR_SCALE, myscale, CR_END);
  }
  changed = DIRDOM | CHANGED;
}

void Attenuation1SliderProc(FL_OBJECT *obj, long val)
{
  atk[myindex][0] = fl_get_slider_value(obj);
  changed = NEW_AP;
}

void Attenuation2SliderProc(FL_OBJECT *obj, long val)
{
  atk[myindex][1] = fl_get_slider_value(obj);
  changed = NEW_AP;
}

void Attenuation3SliderProc(FL_OBJECT *obj, long val)
{
  atk[myindex][6] = fl_get_slider_value(obj);
  changed = NEW_AP;
}

void DisplayButtonProc(FL_OBJECT *obj, long val)
{
  if (display_winid < 0)	/* not currently active */
  	display_winid = fl_show_form(DisplayForm,displayplacement,TRUE,"Maniview Display Window");
  else {
 	winset(display_winid);
	(void)winpop();
	}
}

void EnumerateButtonProc(FL_OBJECT *obj, long val)
{
  if (enum_winid < 0)	/* not currently active */
  	enum_winid = fl_show_form(EnumForm,enumplacement,TRUE,"Maniview Enum Window");
  else {
 	winset(enum_winid);
	(void)winpop();
	}
}

void TileButtonProc(FL_OBJECT *obj, long val)
{
  if (dirdom_winid < 0)	/* not currently active */
  	dirdom_winid = fl_show_form(TileForm,dirdomplacement,TRUE,"Maniview Tile Window");
  else {
 	winset(dirdom_winid);
	(void)winpop();
	}
}

void HelpButtonProc(FL_OBJECT *obj, long val)
{
  if (help_winid < 0)	/* not currently active */
  	help_winid = fl_show_form(HelpForm,helpplacement,TRUE,"Maniview Help Window");
  else {
 	winset(help_winid);
	(void)winpop();
	}
}

void LoadButtonProc(FL_OBJECT *obj, long val)
{
  if (load_winid < 0)	/* not currently active */
  	load_winid = fl_show_form(LoadForm,loadplacement,TRUE,"Maniview Load Window");
  else {
 	winset(load_winid);
	(void)winpop();
	}
}

void SaveButtonProc(FL_OBJECT *obj, long val)
{
  if (save_winid < 0)	/* not currently active */
  	save_winid = fl_show_form(SaveForm,loadplacement,TRUE,"Maniview Save Window");
  else {
 	winset(save_winid);
	(void)winpop();
	}
}

void InfoButtonProc(FL_OBJECT *obj, long val)
{
  if (info_winid < 0)	/* not currently active */
  	info_winid = fl_show_form(InfoForm,infoplacement,TRUE,"Maniview Info Window");
  else {
 	winset(info_winid);
	(void)winpop();
	}
}

void QuitButtonProc(FL_OBJECT *obj, long val)
{
  exit(0); 
}

void HelpOKButtonProc(FL_OBJECT *obj, long val)
{
  fl_hide_form(HelpForm);
  help_winid = -1;
}

static int loadtypechanged = 1;	/* Flag: when to change filebrowser dir? */

void LoadProc(FL_OBJECT *obj, long val)
{
  loadtypechanged = 1;
  if(fl_get_button(obj))
    loadtype = val;
}

void LoadOKButtonProc(FL_OBJECT *obj, long val)
{
  char filename[128];
  IOBFILE *fp;

  sprintf(filename,"%s",fl_get_input(LoadInput));
  /* get new group */
  if((fp = get_input_fp(filename, loadtype)) != NULL &&
     loadstuff(fp, filename, loadtype)) {
    fl_hide_form(LoadForm);
    load_winid = -1;
  } else {
    strcat(filename, "?");
    fl_set_input(LoadInput, filename);
  }
}

void LoadShowBrowserProc(FL_OBJECT *obj, long val)
{
  char dirname[512];
  char *stem = getenv("GEOMDATA");
  char *subdir = "geom";
  char *pat = "*.dgp";
  char *msg = NULL;
  const char *fname;

  if(stem == NULL) stem = ".";
 
  switch(loadtype) {
    case LOAD_GROUP:   msg = "Select Group File"; subdir = "groups";   break;
    case LOAD_CAMGEOM: msg = "Select Camera Geometry File"; pat = "*"; break;
    case LOAD_GEOM:    msg = "Select Geometry File";        pat = "*"; break;
  }
  sprintf(dirname, "%s/%s", stem, subdir);
  fname = fl_show_file_selector(msg,
			loadtypechanged ? dirname : NULL,
			pat, NULL);
  loadtypechanged = 0;
  if(fname) {
    fl_set_input(LoadInput, fname);
    LoadOKButtonProc(LoadOKButton, 0);
  }
}

void SaveOKButtonProc(FL_OBJECT *obj, long val)
{
  char filename[128];

  fl_hide_form(SaveForm);
  save_winid = -1;
  sprintf(filename,"%s",fl_get_input(SaveInput));
  /* get new group */
  savegroup(filename);
}

void SaveGeomButtonProc(FL_OBJECT *obj, long val)
{
  unsigned flag;
  GeomGet((Geom *)dg, DGCR_FLAG, &flag);
  TOGGLE(flag, DG_SAVEDIRDOM, obj); 
  GeomSet((Geom *)dg, DGCR_FLAG, flag, CR_END);
}

void SaveGroupButtonProc(FL_OBJECT *obj, long val)
{
  unsigned flag;
  GeomGet((Geom *)dg, DGCR_FLAG, &flag);
  TOGGLE(flag, DG_SAVEBIGLIST, obj); 
  GeomSet((Geom *)dg, DGCR_FLAG, flag, CR_END);
}

void DisplayOKButtonProc(FL_OBJECT *obj, long val)
{
  fl_hide_form(DisplayForm);
  display_winid = -1;
}

void EnumOKButtonProc(FL_OBJECT *obj, long val)
{
  fl_hide_form(EnumForm);
  enum_winid = -1;
}

void TileOKButtonProc(FL_OBJECT *obj, long val)
{
  fl_hide_form(TileForm);
  dirdom_winid = -1;
}

void InfoOKButtonProc(FL_OBJECT *obj, long val)
{
  fl_hide_form(InfoForm);
  info_winid = -1;
}

void LoadCancelButtonProc(FL_OBJECT *obj, long val)
{
  fl_hide_form(LoadForm);
  load_winid = -1;
}

void SaveCancelButtonProc(FL_OBJECT *obj, long val)
{
  fl_hide_form(SaveForm);
  save_winid = -1;
}

/* little routine to basically compute log base 2 of the space bit for use
as index into above atk array */
int
index_from_bit(int bit)
{
    if (bit == 1) return(0);
    if (bit == 2) return (1);
    if (bit == 4) return (2);
    else return (1);
}

IOBFILE *
get_input_fp(char *filename, int lt)
{
    char *geomdata, mystr[128];
    IOBFILE *myf;

    if (filename == NULL) return NULL;
    /* try opening the file as given */
    strncpy(mystr, filename, 128);
    if ( (myf = iobfopen(mystr, "rb")) == NULL)	{
	/* now tack on the geomdata environment variable */
    	geomdata = getenv("GEOMDATA");
	if (geomdata == NULL) 	{
	    fprintf(stderr,"GEOMDATA environment variable not set\n");
	    return(NULL);
	    }
	else {
    	    strncpy(mystr, geomdata, 128);
	    if (lt & LOAD_GROUP) strcat(mystr, "/groups/");
	    else  strcat(mystr,"/geom/");
	    strcat(mystr, filename);
	    myf = iobfopen(mystr, "rb");
	    }
	}
    if (myf == NULL) {
	fprintf(stderr,"Maniview: Unable to open file %s\n", mystr);
	}
    return (myf);
}

int
loadstuff(IOBFILE  *myf, char *filename, int lt)
{
  int ok = 0;
  DiscGrp *olddg = dg;
  int attrib;
    
  oldspace = space;

  if (lt & (LOAD_GROUP | CHECK_PIPE) )	{	
    if ( (dg = (DiscGrp *) GeomFLoad(myf, filename)) == NULL)	{
      fprintf(stderr,"Unable to load file %s\n",filename);
      goto OUT;
    }
    if (olddg) GeomDelete((Geom *) olddg); 
    GeomGet((Geom *)dg, DGCR_ATTRIBUTE, &attrib);
    space = attrib & DG_METRIC_BITS;
    myindex = index_from_bit(space);

    if (oldspace != space ) changed = NEW_SPACE;
    changed |= (CHANGED | NEW_AP );

    if (changed & NEW_SPACE) fl_set_bounds();
  }

  else if (lt & LOAD_GEOM) { 
    Geom *geom = NULL;
    Transform t1;

    if ((geom = GeomFLoad(myf, filename)) == NULL)	{
      fprintf(stderr,"Unable to load file %s\n",filename);
      goto OUT;
    }
    /* create an inst with geom, use CR_NOCOPY s.t. the Inst owns geom and
     * dg owns the Inst.
     */
    TmIdentity(t1);
    GeomSet((Geom *)dg, CR_NOCOPY, CR_GEOM, 
	    GeomCreate("inst", CR_NOCOPY,
		       CR_GEOM, geom, CR_AXIS, t1, CR_END), CR_END);
    changed |= DIRDOM | CHANGED;
  }

  else if (lt & LOAD_CAMGEOM) { 
    Geom *camgeom;
    if ((camgeom = GeomFLoad(myf, filename)) == NULL)	{
      fprintf(stderr,"Unable to load file %s\n",filename);
      goto OUT;
    }
    GeomSet((Geom *)dg, CR_NOCOPY, DGCR_CAMGEOM, camgeom, CR_END);
    
    changed |= CHANGED;
  }
  ok = 1;
 OUT:
  if (myf) {
    if (iobfile(myf) != stdin) {
      iobfclose(myf);
    } else {
      iobfileclose(myf);
      }
  }
  return ok;
}

void
savegroup(char *filename)
{
    if (dg) GeomSave( (Geom *) dg,filename);
}



/*
 * Local Variables: ***
 * mode: c ***
 * c-basic-offset: 2 ***
 * End: ***
 */
