#pragma once

#include "simpleColor.h"
#include "guiColor.h"
#include "guiValue.h"
#include "guiTextBase.h"
#include "guiCallback.h"

typedef enum{
SG_STATE_NORMAL,
SG_STATE_SELECTED
}sgState;

static bool isInsideRect(float x, float y, ofRectangle rect){
    return ( x >= rect.x && x <= rect.x + rect.width && y >= rect.y && y <= rect.y + rect.height );
}

class guiBaseObject{

    public:
        guiBaseObject();

        //this should be called in your gui element setup function - if you gui element has ofParameters
        //otherwise set the display name manually
        //--------------------------------------------
        void setupNamesFromParams();

        //--------------------------------------------
        virtual void setFont(ofTrueTypeFont * fontPtr);

        //should be called on mousedown
        //-------------------------------------------
        virtual bool checkHit(float x, float y, bool isRelative);

        //this is the equivilant of mouse moved if the gui element has been selected
        //this is empty as it really should be specified by
        //the extending class (gui element).
        //------------------------------------------------
        virtual void updateGui(float x, float y, bool firstHit, bool isRelative);
        virtual void mouseMoved(float x, float y);

        //should  be called on mouse up
        //-------------------------------------------
        virtual void release(float x, float y, bool isRelative);
	
		//should be called when a key is pressed; return true if we consume the key
		virtual bool keyPressed(int k);
		virtual bool keyReleased(int k);
		
        //these are here for the custom control types
        //we notify all elements about these actions
        virtual void saveSettings(string filename);
        virtual void loadSettings(string filename);

        virtual void reloadSettings(){
            ofLogWarning() << " reloadSettings() is deprecated " << endl;
        }
        virtual void saveSettings(){
            ofLogWarning() << " saveSettings() is deprecated " << endl;
        }
    

        virtual void lock();
        virtual void unlock();
        bool isLocked();
    

        //------------------------------------------------
		virtual void makeXmlNameFromDisplayName(){
			xmlName = name;
			size_t found;
			found=xmlName.find_first_of(" ");
			while (found!=string::npos){
				xmlName[found]='_';
				found=xmlName.find_first_of(" ",found+1);
			}
			transform(xmlName.begin(), xmlName.end(), xmlName.begin(), ::toupper);
		}

        //------------------------------------------------
        virtual void setShowText(bool showText);

        //-----------------------------------------------
        virtual void setPosition(float x, float y);

        //------------------------------------------------
        virtual void setDimensions(float width, float height);

        //-----------------------------------------------
        virtual float getPosX();
		
        //------------------------------------------------
        virtual float getPosY();
		
        //------------------------------------------------
        virtual float getWidth();

        //-----------------------------------------------
        virtual float getHeight();

        //-----------------------------------------------
        virtual void update();

		//-----------------------------------------------
		virtual void notify();
		
        //-----------------------------------------------
        virtual void checkPrescison();
		
//        //-----------------------------------------------
//        virtual void setIsRelative( bool bIsRelative ){
//            isRelative = bIsRelative;
//        }

        //-----------------------------------------------
		string getVarsAsString();

        //every time we update the value of our text
        //-----------------------------------------------
        virtual void updateText();

        //---------------------------------------------
        virtual void updateBoundingBox();

        //---------------------------------------------
        virtual void renderText(float offsetX = 0.0, float offsetY = 0.0);

        //this also needs to be specified by the extending class
        //--------------------------------------------
        virtual void render();

         //-------------------------------------------
         virtual void setSelected();

         //-------------------------------------------
         virtual void setNormal();
		 
         //-------------------------------------------
         virtual void setForegroundColor( int norR, int norG, int norB, int norA);

         //-------------------------------------------
         virtual void setForegroundSelectColor(int selR, int selG, int selB, int selA);

         //-------------------------------------------
         virtual void setBackgroundColor( int norR, int norG, int norB, int norA);

         //-------------------------------------------
         virtual void setBackgroundSelectColor(int selR, int selG, int selB, int selA);

         //-------------------------------------------
         virtual void setOutlineColor( int norR, int norG, int norB, int norA);

         //-------------------------------------------
         virtual void setOutlineSelectColor(int selR, int selG, int selB, int selA);

         //-------------------------------------------
         virtual void setTextColor( int norR, int norG, int norB, int norA);

         //-------------------------------------------
         virtual void setTextSelectColor(int selR, int selG, int selB, int selA);

         virtual void setValue(float _value, int whichParam);

        virtual void updateValue();
    
        virtual float getVerticalSpacing();
        virtual float getHorizontalSpacing();
    
        virtual float getDefaultColumnWidth(); 

        //list of properties
        //------------------
        string name;
        string drawStr;
		string varsString;
        string xmlName;

        ofRectangle boundingBox;
        ofRectangle hitArea;

        guiColor fgColor;
        guiColor bgColor;
        guiColor outlineColor;
        guiColor textColor;

        int numDecimalPlaces;

        //------------------
        guiTextBase displayText;

        //-------------------
        vector <guiBaseObject *>children;

		ofEvent <guiCallbackData> guiEvent;		

        //bool isRelative;
        bool locked;
		bool bRemoveFromLayout;

        float storedTextWidth;
        float titleSpacing;
        float fontSize;
        bool bShowText;
        bool readOnly;
        int  state;

//protected:

        guiValue value;

};

