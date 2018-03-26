#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"

typedef struct{
    string msg;
    int level;

    string logStr;
	string dateStr;
	string timeStr;
	string levelStr;

    long timestamp;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int seconds;
}logRecord;

class simpleLogger : public ofBaseDraws{

     public:

        simpleLogger();
        ~simpleLogger();

        void setup(string logFileName, bool overwrite);
        void setIncludeDate(bool bIncludeDate);
        void setIncludeTime(bool bIncludeTime);
        void setIncludeLevelbool(bool  bIncludeLevel);

        //--------------------------------------------------
        void log(int logLevel, const char* format, ...);

        float getWidth()const;
        float getHeight()const;

        //----------------------------------------------
        string convertToString(logRecord & record);

        void logToXml(logRecord & record);
        void saveFile();

        void draw(float x, float y) const;
        void draw(float x, float y, float width, float height) const;

        void setAnchorPercent(float xPct, float yPct){};
        
        /// \brief Set the anchor point the item is drawn around in pixels.
        ///
        /// This can be useful if you want to rotate an image around a particular
        /// point.
        ///
        /// \param x Horizontal texture position in pixels.
        /// \param y Vertical texture position in pixels.
        void setAnchorPoint(float x, float y){};
        
        /// \brief Reset the anchor point to (0, 0).
        void resetAnchor(){};
        string logFile;
        ofxXmlSettings xml;
        bool fileLoaded;

        bool bLevel;
        bool bTime;
        bool bDate;

        vector <logRecord> logs;
};
