/*=======================================================================
 * Copyright 1991-1996, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 *
 * UNPUBLISHED -- Rights reserved under the copyright laws of the United
 * States.   Use of a copyright notice is precautionary only and does not
 * imply publication or disclosure.
 *
 * U.S. GOVERNMENT RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to restrictions
 * as set forth in FAR 52.227.19(c)(2) or subparagraph (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS 252.227-7013 and/or
 * in similar or successor clauses in the FAR, or the DOD or NASA FAR
 * Supplement.  Contractor/manufacturer is Silicon Graphics, Inc.,
 * 2011 N. Shoreline Blvd. Mountain View, CA 94039-7311.
 *
 * THE CONTENT OF THIS WORK CONTAINS CONFIDENTIAL AND PROPRIETARY
 * INFORMATION OF SILICON GRAPHICS, INC. ANY DUPLICATION, MODIFICATION,
 * DISTRIBUTION, OR DISCLOSURE IN ANY FORM, IN WHOLE, OR IN PART, IS STRICTLY
 * PROHIBITED WITHOUT THE PRIOR EXPRESS WRITTEN PERMISSION OF SILICON
 * GRAPHICS, INC.
**=======================================================================*/
/*=======================================================================
** Author      : SGI (MMM YYYY)
**=======================================================================*/

/*------------------------------------------------------------
 *  This is an example from the Inventor Mentor
 *  chapter 16, example 5.
 *
 *  This example creates a simple scene graph and attaches a
 *  browser Examiner viewer to view the data. The camera and
 *  light in the scene are automatically created by the viewer.
 *-----------------------------------------------------------*/

#include <Inventor/SoMacApp.h>

#include <Inventor/SoDB.h>         
#include <Inventor/Xt/SoXt.h>         
#include <Inventor/Xt/viewers/SoXtExaminerViewer.h>  
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoCylinder.h>
#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoScale.h>
#include <Inventor/nodes/SoTexture2.h>

int
main(int, char **argv)
{
  // Initialize Inventor and Xt
  Widget myWindow = SoXt::init(argv[0]);
  
  // Build the viewer in the applications main window
  SoXtExaminerViewer *myViewer = 
    new SoXtExaminerViewer(myWindow);

  SoSeparator *pRoot = new SoSeparator();
  pRoot->ref();

  SoCone *pCone = new SoCone();

  SoTexture2  *tBois = new SoTexture2();
  tBois->filename = "C:\\Open Inventor\\9.9.0 C++ Visual2017 x64\\textures\\bois.jpg";
  pRoot->addChild(tBois);

  pRoot->addChild(pCone);

  SoCylinder *pCylinder = new SoCylinder();
  pCylinder->height.setValue(10);

  SoTranslation *leftTranslation = new SoTranslation;
  leftTranslation->translation.setValue(0.0, -6.0, 0.0);
  pRoot->addChild(leftTranslation);


  SoTexture2  *tRouge = new SoTexture2();
  tRouge->filename = "C:\\Open Inventor\\9.9.0 C++ Visual2017 x64\\textures\\rouge.jpg";
  pRoot->addChild(tRouge);

  pRoot->addChild(pCylinder);

  SoCylinder *pCylinder2 = new SoCylinder();

  SoTranslation *leftTranslation2 = new SoTranslation;
  leftTranslation2->translation.setValue(0.0, 6.8, 0.0);
  pRoot->addChild(leftTranslation2);

  SoScale *pScale = new SoScale();
  pScale->scaleFactor.setValue(0.1, 0.3, 0.1);
  
  pRoot->addChild(pScale);

  SoTexture2  *tGraphite = new SoTexture2();
  tGraphite->filename = "C:\\Open Inventor\\9.9.0 C++ Visual2017 x64\\textures\\graphite.jpg";
  pRoot->addChild(tGraphite);

  pRoot->addChild(pCylinder2);
  
  // Attach the viewer to the scene graph
  myViewer->setSceneGraph(pRoot);
  
  // Show the main window
  myViewer->show();
  SoXt::show(myWindow);
  
  // Loop forever
  SoXt::mainLoop();
  delete myViewer;
  SoXt::finish();  
  
  return 0;
}


