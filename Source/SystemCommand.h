/*
  ==============================================================================

    SystemCommand.h
    Created: 29 Mar 2021 3:04:29pm
    Author:  migizo

  ==============================================================================
*/

#pragma once
// #define TARGET_WIN32

struct juceUtil {
    inline static string systemCommand(const string& command) {
         FILE * ret = nullptr;

    #ifdef TARGET_WIN32 // JUCE_WINDOWS
        ret = _popen(command.c_str(),"r");
    #else
        ret = popen(command.c_str(),"r");
    #endif
            string strret;
        int c;

        if (ret == nullptr){
            cout << ("ofUtils") << "system(): errdor opening return file for command \"" << command  << "\"" << endl; // TODO: error log
        }else{
            c = fgetc (ret);
            while (c != EOF) {
                strret += c;
                c = fgetc (ret);
            }
    #ifdef TARGET_WIN32 // JUCE_WINDOWS
            _pclose (ret);
    #else
            pclose (ret);
    #endif
        }
        return strret;
    }

};

