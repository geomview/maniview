/** Header file generated with fdesign on Sun Jul 30 00:11:16 2006.**/

#ifndef FD_MainForm_h_
#define FD_MainForm_h_

/** Callbacks, globals and object handlers **/
extern void SaveButtonProc(FL_OBJECT *, long);
extern void DisplayButtonProc(FL_OBJECT *, long);
extern void InfoButtonProc(FL_OBJECT *, long);
extern void EnumerateButtonProc(FL_OBJECT *, long);
extern void TileButtonProc(FL_OBJECT *, long);
extern void HelpButtonProc(FL_OBJECT *, long);
extern void QuitButtonProc(FL_OBJECT *, long);
extern void LoadButtonProc(FL_OBJECT *, long);

extern void DisplayProc(FL_OBJECT *, long);
extern void DisplayOKButtonProc(FL_OBJECT *, long);
extern void Attenuation2SliderProc(FL_OBJECT *, long);
extern void Attenuation3SliderProc(FL_OBJECT *, long);
extern void SoftshadeProc(FL_OBJECT *, long);
extern void Attenuation1SliderProc(FL_OBJECT *, long);

extern void WorddepthProc(FL_OBJECT *, long);
extern void RadiusProc(FL_OBJECT *, long);
extern void EnumOKButtonProc(FL_OBJECT *, long);
extern void DrawRadiusProc(FL_OBJECT *, long);

extern void DDZProc(FL_OBJECT *, long);
extern void DDXYProc(FL_OBJECT *, long);
extern void DDResetProc(FL_OBJECT *, long);
extern void DDScaleProc(FL_OBJECT *, long);
extern void TileOKButtonProc(FL_OBJECT *, long);
extern void TileModeProc(FL_OBJECT *, long);

extern void InfoOKButtonProc(FL_OBJECT *, long);

extern void LoadOKButtonProc(FL_OBJECT *, long);
extern void LoadCancelButtonProc(FL_OBJECT *, long);
extern void LoadProc(FL_OBJECT *, long);
extern void LoadShowBrowserProc(FL_OBJECT *, long);

extern void HelpOKButtonProc(FL_OBJECT *, long);

extern void SaveOKButtonProc(FL_OBJECT *, long);
extern void SaveCancelButtonProc(FL_OBJECT *, long);
extern void SaveGeomButtonProc(FL_OBJECT *, long);
extern void SaveGroupButtonProc(FL_OBJECT *, long);


/**** Forms and Objects ****/
extern FL_FORM *MainForm;

extern FL_OBJECT
        *SaveButton,
        *DisplayButton,
        *InfoButton,
        *EnumerateButton,
        *TileFormButton,
        *HelpButton,
        *QuitButton,
        *LoadButton;

extern FL_FORM *DisplayForm;

extern FL_OBJECT
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

extern FL_FORM *EnumForm;

extern FL_OBJECT
        *WorddepthCounter,
        *RadiusSlider,
        *EnumOKButton,
        *DrawRadiusSlider;

extern FL_FORM *TileForm;

extern FL_OBJECT
        *DDZDial,
        *DDXYPositioner,
        *DDResetButton,
        *DDScaleSlider,
        *TileOKButton,
        *DirichletDomainButton,
        *UsergeometryButton;

extern FL_FORM *InfoForm;

extern FL_OBJECT
        *InfoFormLabel,
        *InfoOKButton;

extern FL_FORM *LoadForm;

extern FL_OBJECT
        *LoadInput,
        *LoadOKButton,
        *LoadCancelButton,
        *loadtypegroup,
        *LoadGeomButton,
        *LoadCameraGeomButton,
        *LoadGroupButton,
        *LoadShowBrowser;

extern FL_FORM *HelpForm;

extern FL_OBJECT
        *HelpBrowser,
        *HelpOKButton;

extern FL_FORM *SaveForm;

extern FL_OBJECT
        *SaveInput,
        *SaveOKButton,
        *SaveCancelButton,
        *savetypegroup,
        *SaveGeomButton,
        *SaveGroupButton;


/**** Creation Routine ****/
extern void create_the_forms(void);

#endif /* FD_MainForm_h_ */
