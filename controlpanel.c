/* Form definition file generated with fdesign. */

#include "maniview.h"
#include <stdlib.h>
#include "controlpanel.h"

FL_FORM *MainForm;

FL_OBJECT
        *SaveButton,
        *DisplayButton,
        *InfoButton,
        *EnumerateButton,
        *TileFormButton,
        *HelpButton,
        *QuitButton,
        *LoadButton;

void create_form_MainForm(void)
{
  FL_OBJECT *obj;

  if (MainForm)
     return;

  MainForm = fl_bgn_form(FL_NO_BOX,250,460);
  obj = fl_add_box(FL_UP_BOX,0,0,250,460,"");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  obj = fl_add_text(FL_NORMAL_TEXT,60,10,130,50,"Maniview");
    fl_set_object_boxtype(obj,FL_FRAME_BOX);
    fl_set_object_color(obj,FL_WHITE,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE+FL_ENGRAVED_STYLE);
  SaveButton = obj = fl_add_button(FL_PUSH_BUTTON,20,150,210,40,"Save");
    fl_set_object_boxtype(obj,FL_SHADOW_BOX);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,SaveButtonProc,0);
  DisplayButton = obj = fl_add_button(FL_PUSH_BUTTON,20,190,210,40,"Display");
    fl_set_object_boxtype(obj,FL_SHADOW_BOX);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,DisplayButtonProc,0);
  InfoButton = obj = fl_add_button(FL_PUSH_BUTTON,20,350,210,40,"Info");
    fl_set_object_boxtype(obj,FL_SHADOW_BOX);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,InfoButtonProc,0);
  EnumerateButton = obj = fl_add_button(FL_PUSH_BUTTON,20,230,210,40,"Enumerate");
    fl_set_object_boxtype(obj,FL_SHADOW_BOX);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,EnumerateButtonProc,0);
  TileFormButton = obj = fl_add_button(FL_PUSH_BUTTON,20,270,210,40,"Basic Tile");
    fl_set_object_boxtype(obj,FL_SHADOW_BOX);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,TileButtonProc,0);
  HelpButton = obj = fl_add_button(FL_PUSH_BUTTON,20,310,210,40,"Help");
    fl_set_object_boxtype(obj,FL_SHADOW_BOX);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,HelpButtonProc,0);
  QuitButton = obj = fl_add_button(FL_PUSH_BUTTON,20,390,210,40,"Quit");
    fl_set_object_boxtype(obj,FL_SHADOW_BOX);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,QuitButtonProc,0);
  obj = fl_add_text(FL_NORMAL_TEXT,40,60,170,30,"A 3-Manifold Viewer");
    fl_set_object_boxtype(obj,FL_FRAME_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
  LoadButton = obj = fl_add_button(FL_PUSH_BUTTON,20,110,210,40,"Load");
    fl_set_object_boxtype(obj,FL_SHADOW_BOX);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,LoadButtonProc,0);
  fl_end_form();

}
/*---------------------------------------*/

FL_FORM *DisplayForm;

FL_OBJECT
        *CullzButton,
        *CentercamButton,
        *DirdomButton,
        *ShowcamButton,
        *DisplayOKButton,
        *Attenuation2Slider,
        *Attenuation3Slider,
        *SoftshadeButton,
        *Attenuation1Slider,
        *DrawGeomButton;

void create_form_DisplayForm(void)
{
  FL_OBJECT *obj;

  if (DisplayForm)
     return;

  DisplayForm = fl_bgn_form(FL_NO_BOX,320,380);
  obj = fl_add_box(FL_UP_BOX,0,0,320,380,"");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  CullzButton = obj = fl_add_button(FL_PUSH_BUTTON,150,180,110,30,"cull");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,DisplayProc,DG_ZCULL);
  CentercamButton = obj = fl_add_button(FL_PUSH_BUTTON,40,120,110,30,"centercam");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,DisplayProc,DG_CENTERCAM);
  DirdomButton = obj = fl_add_button(FL_PUSH_BUTTON,150,120,110,30,"draw dirdom");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,DisplayProc,DG_DRAWDIRDOM);
  ShowcamButton = obj = fl_add_button(FL_PUSH_BUTTON,40,150,110,30,"showcam");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,DisplayProc,DG_DRAWCAM);
  obj = fl_add_text(FL_NORMAL_TEXT,90,80,120,40,"Toggles");
    fl_set_object_boxtype(obj,FL_FRAME_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_lstyle(obj,FL_NORMAL_STYLE+FL_ENGRAVED_STYLE);
  DisplayOKButton = obj = fl_add_button(FL_NORMAL_BUTTON,250,25,50,45,"OK");
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_callback(obj,DisplayOKButtonProc,0);
  Attenuation2Slider = obj = fl_add_valslider(FL_HOR_SLIDER,60,280,230,30,"fogfree");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT);
    fl_set_object_callback(obj,Attenuation2SliderProc,0);
  obj = fl_add_box(FL_FRAME_BOX,10,20,210,50,"Display Settings");
    fl_set_object_color(obj,FL_WHITE,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
  Attenuation3Slider = obj = fl_add_valslider(FL_HOR_SLIDER,60,330,230,30,"fog");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT);
    fl_set_object_callback(obj,Attenuation3SliderProc,0);
  SoftshadeButton = obj = fl_add_button(FL_PUSH_BUTTON,40,180,110,30,"software shading");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,SoftshadeProc,0);
  Attenuation1Slider = obj = fl_add_valslider(FL_HOR_SLIDER,60,230,230,30,"atten1");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT);
    fl_set_object_callback(obj,Attenuation1SliderProc,0);
  DrawGeomButton = obj = fl_add_button(FL_PUSH_BUTTON,150,150,110,30,"draw geom");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,DisplayProc,DG_DRAWGEOM);
  fl_end_form();

}
/*---------------------------------------*/

FL_FORM *EnumForm;

FL_OBJECT
        *WorddepthCounter,
        *RadiusSlider,
        *EnumOKButton,
        *DrawRadiusSlider;

void create_form_EnumForm(void)
{
  FL_OBJECT *obj;

  if (EnumForm)
     return;

  EnumForm = fl_bgn_form(FL_NO_BOX,400,250);
  obj = fl_add_box(FL_UP_BOX,0,0,400,250,"");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  WorddepthCounter = obj = fl_add_counter(FL_NORMAL_COUNTER,160,80,130,40,"worddepth");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT);
    fl_set_object_callback(obj,WorddepthProc,0);
  RadiusSlider = obj = fl_add_valslider(FL_HOR_SLIDER,130,140,240,30,"tesselation radius");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT);
    fl_set_object_callback(obj,RadiusProc,0);
  obj = fl_add_text(FL_NORMAL_TEXT,30,20,220,40,"Enumerate Group");
    fl_set_object_boxtype(obj,FL_FRAME_BOX);
    fl_set_object_color(obj,FL_WHITE,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
  EnumOKButton = obj = fl_add_button(FL_NORMAL_BUTTON,330,25,50,45,"OK");
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_callback(obj,EnumOKButtonProc,0);
  DrawRadiusSlider = obj = fl_add_valslider(FL_HOR_SLIDER,130,190,240,30,"draw radius");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT);
    fl_set_object_callback(obj,DrawRadiusProc,0);
  fl_end_form();

}
/*---------------------------------------*/

FL_FORM *TileForm;

FL_OBJECT
        *DDZDial,
        *DDXYPositioner,
        *DDResetButton,
        *DDScaleSlider,
        *TileOKButton,
        *DirichletDomainButton,
        *UsergeometryButton;

void create_form_TileForm(void)
{
  FL_OBJECT *obj;

  if (TileForm)
     return;

  TileForm = fl_bgn_form(FL_NO_BOX,400,320);
  obj = fl_add_box(FL_UP_BOX,0,0,400,320,"");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  obj = fl_add_box(FL_BORDER_BOX,10,140,380,170,"");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  DDZDial = obj = fl_add_dial(FL_LINE_DIAL,310,160,70,70,"z");
    fl_set_object_boxtype(obj,FL_BORDER_BOX);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,DDZProc,0);
  obj = fl_add_text(FL_NORMAL_TEXT,30,160,100,20,"Center Point");
    fl_set_object_boxtype(obj,FL_NO_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lcolor(obj,137);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
  obj = fl_add_text(FL_NORMAL_TEXT,40,180,90,20,"Chooser");
    fl_set_object_boxtype(obj,FL_NO_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lcolor(obj,137);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
  DDXYPositioner = obj = fl_add_positioner(FL_NORMAL_POSITIONER,190,160,80,70,"(x,y)");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,DDXYProc,0);
  DDResetButton = obj = fl_add_button(FL_NORMAL_BUTTON,40,200,90,30,"Reset");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,DDResetProc,0);
  obj = fl_add_text(FL_NORMAL_TEXT,20,20,130,40,"Basic Tile");
    fl_set_object_boxtype(obj,FL_FRAME_BOX);
    fl_set_object_color(obj,FL_WHITE,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
  DDScaleSlider = obj = fl_add_valslider(FL_HOR_SLIDER,120,260,240,30,"scale factor");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT);
    fl_set_object_callback(obj,DDScaleProc,0);
  TileOKButton = obj = fl_add_button(FL_NORMAL_BUTTON,330,15,50,45,"OK");
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_callback(obj,TileOKButtonProc,0);
  obj = fl_add_box(FL_BORDER_BOX,20,80,360,50,"");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  obj = fl_add_text(FL_NORMAL_TEXT,30,90,60,30,"MODE:");
    fl_set_object_boxtype(obj,FL_NO_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
  DirichletDomainButton = obj = fl_add_button(FL_NORMAL_BUTTON,110,90,120,30,"Dirichlet domain");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_callback(obj,TileModeProc,DIRDOM_MODE);
  UsergeometryButton = obj = fl_add_button(FL_NORMAL_BUTTON,260,90,110,30,"User geometry");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_callback(obj,TileModeProc,USER_GEOM);
  fl_end_form();

}
/*---------------------------------------*/

FL_FORM *InfoForm;

FL_OBJECT
        *InfoFormLabel,
        *InfoOKButton;

void create_form_InfoForm(void)
{
  FL_OBJECT *obj;

  if (InfoForm)
     return;

  InfoForm = fl_bgn_form(FL_NO_BOX,330,310);
  obj = fl_add_box(FL_UP_BOX,0,0,330,310,"");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  InfoFormLabel = obj = fl_add_text(FL_NORMAL_TEXT,80,30,150,40,"Maniview");
    fl_set_object_boxtype(obj,FL_NO_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,11,66,300,30,"by");
    fl_set_object_boxtype(obj,FL_NO_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,11,96,300,30,"Charlie Gunn");
    fl_set_object_boxtype(obj,FL_NO_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,11,126,300,30,"The Geometry Center");
    fl_set_object_boxtype(obj,FL_NO_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  InfoOKButton = obj = fl_add_button(FL_NORMAL_BUTTON,260,65,50,45,"OK");
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_callback(obj,InfoOKButtonProc,0);
  obj = fl_add_text(FL_NORMAL_TEXT,11,172,300,30,"Maniview and Geomview are ");
    fl_set_object_boxtype(obj,FL_NO_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,10,190,300,30,"available from");
    fl_set_object_boxtype(obj,FL_NO_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,12,208,300,30,"www.geomview.org");
    fl_set_object_boxtype(obj,FL_NO_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  obj = fl_add_text(FL_NORMAL_TEXT,12,270,300,30,"For usage instructions hit the ``Help'' button.");
    fl_set_object_boxtype(obj,FL_NO_BOX);
    fl_set_object_color(obj,FL_COL1,FL_COL1);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
  fl_end_form();

}
/*---------------------------------------*/

FL_FORM *LoadForm;

FL_OBJECT
        *LoadInput,
        *LoadOKButton,
        *LoadCancelButton,
        *loadtypegroup,
        *LoadGeomButton,
        *LoadCameraGeomButton,
        *LoadGroupButton,
        *LoadShowBrowser;

void create_form_LoadForm(void)
{
  FL_OBJECT *obj;

  if (LoadForm)
     return;

  LoadForm = fl_bgn_form(FL_NO_BOX,470,200);
  obj = fl_add_box(FL_UP_BOX,0,0,470,200,"");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  LoadInput = obj = fl_add_input(FL_NORMAL_INPUT,10,150,440,40,"");
    fl_set_object_color(obj,FL_INDIANRED,FL_INDIANRED);
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  LoadOKButton = obj = fl_add_button(FL_RETURN_BUTTON,360,105,95,35,"OK");
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_callback(obj,LoadOKButtonProc,0);
  LoadCancelButton = obj = fl_add_button(FL_NORMAL_BUTTON,250,105,100,35,"Cancel");
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_callback(obj,LoadCancelButtonProc,0);
  obj = fl_add_box(FL_FRAME_BOX,205,10,160,40,"Load Panel");
    fl_set_object_color(obj,FL_WHITE,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
  obj = fl_add_box(FL_FRAME_BOX,30,20,160,30,"LOAD TYPE:");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);

  loadtypegroup = fl_bgn_group();
  LoadGeomButton = obj = fl_add_button(FL_RADIO_BUTTON,30,80,160,30,"Load Geom");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,LoadProc,LOAD_GEOM);
  LoadCameraGeomButton = obj = fl_add_button(FL_RADIO_BUTTON,30,110,160,30,"Load Camera Geom");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,LoadProc,LOAD_CAMGEOM);
  LoadGroupButton = obj = fl_add_button(FL_RADIO_BUTTON,30,50,160,30,"Load Group");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,LoadProc,LOAD_GROUP);
  fl_end_group();

  LoadShowBrowser = obj = fl_add_button(FL_NORMAL_BUTTON,250,60,205,35,"Show Files");
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_callback(obj,LoadShowBrowserProc,0);
  fl_end_form();

}
/*---------------------------------------*/

FL_FORM *HelpForm;

FL_OBJECT
        *HelpBrowser,
        *HelpOKButton;

void create_form_HelpForm(void)
{
  FL_OBJECT *obj;

  if (HelpForm)
     return;

  HelpForm = fl_bgn_form(FL_NO_BOX,470,350);
  obj = fl_add_box(FL_UP_BOX,0,0,470,350,"");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  obj = fl_add_text(FL_NORMAL_TEXT,20,20,200,40,"Maniview Help");
    fl_set_object_boxtype(obj,FL_FRAME_BOX);
    fl_set_object_color(obj,FL_WHITE,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lalign(obj,FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
  HelpBrowser = obj = fl_add_browser(FL_NORMAL_BROWSER,10,70,450,270,"");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  HelpOKButton = obj = fl_add_button(FL_NORMAL_BUTTON,410,20,50,40,"OK");
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_callback(obj,HelpOKButtonProc,0);
  fl_end_form();

}
/*---------------------------------------*/

FL_FORM *SaveForm;

FL_OBJECT
        *SaveInput,
        *SaveOKButton,
        *SaveCancelButton,
        *savetypegroup,
        *SaveGeomButton,
        *SaveGroupButton;

void create_form_SaveForm(void)
{
  FL_OBJECT *obj;

  if (SaveForm)
     return;

  SaveForm = fl_bgn_form(FL_NO_BOX,490,180);
  obj = fl_add_box(FL_UP_BOX,0,0,490,180,"");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
  SaveInput = obj = fl_add_input(FL_NORMAL_INPUT,30,120,440,40,"");
    fl_set_object_color(obj,FL_INDIANRED,FL_INDIANRED);
    fl_set_object_lsize(obj,FL_MEDIUM_SIZE);
  SaveOKButton = obj = fl_add_button(FL_RETURN_BUTTON,360,75,95,35,"OK");
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_callback(obj,SaveOKButtonProc,0);
  SaveCancelButton = obj = fl_add_button(FL_NORMAL_BUTTON,240,75,100,35,"Cancel");
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_callback(obj,SaveCancelButtonProc,0);
  obj = fl_add_box(FL_FRAME_BOX,270,15,150,40,"Save Panel");
    fl_set_object_color(obj,FL_WHITE,FL_COL1);
    fl_set_object_lsize(obj,FL_LARGE_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
  obj = fl_add_box(FL_FRAME_BOX,40,20,110,30,"Options:");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);

  savetypegroup = fl_bgn_group();
  SaveGeomButton = obj = fl_add_button(FL_RADIO_BUTTON,40,50,110,30,"Save Geom");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,SaveGeomButtonProc,0);
  SaveGroupButton = obj = fl_add_button(FL_RADIO_BUTTON,40,80,110,30,"Save Matrices");
    fl_set_object_lsize(obj,FL_NORMAL_SIZE);
    fl_set_object_lstyle(obj,FL_BOLD_STYLE);
    fl_set_object_callback(obj,SaveGroupButtonProc,0);
  fl_end_group();

  fl_end_form();

}
/*---------------------------------------*/

void create_the_forms(void)
{
  create_form_MainForm();
  create_form_DisplayForm();
  create_form_EnumForm();
  create_form_TileForm();
  create_form_InfoForm();
  create_form_LoadForm();
  create_form_HelpForm();
  create_form_SaveForm();
}

